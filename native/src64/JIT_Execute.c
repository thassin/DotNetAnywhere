// Copyright (c) 2012 DotNetAnywhere
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "Compat.h"
#include "Sys.h"

#include "JIT.h"

#include "JIT_OpCodes.h"
#include "MetaData.h"
#include "MetaDataTables.h"
#include "Heap.h"
#include "Type.h"
#include "MethodState.h"
#include "Finalizer.h"
#include "Delegate.h"
#include "PInvoke.h"

#include "System.String.h"
#include "System.Array.h"
#include "System.Reflection.MethodBase.h"
#include "System.Diagnostics.Debugger.h"

//#define CRASH_ON_TYPE_ERRORS

// Global array which stores the absolute addresses of the start and end of all JIT code
// fragment machine code.
tJITCodeInfo jitCodeInfo[JIT_OPCODE_MAXNUM];
tJITCodeInfo jitCodeGoNext;

// GET_OP_XX macros : get the next op-code.
// => the values in OPS may be either 32- or 64-bit.

// for an explanation how this works, see the LOAD_METHOD_STATE() macro:
#define CURRENT_OPS_OFFSET() ((PTR)pCurOp - (PTR)(pCurrMethodState->pJIT->pOps + pCurrMethodState->ipOffset))

static inline U64 convertOpsToU64( U32 op1, U32 op2 ) {
log_f( 3, "convertOpsToU64() :: op1=%#x op2=%#x\n", op1, op2 );
	uConvDouble convert;
	convert.u32.a = op1;
	convert.u32.b = op2;
log_f( 3, "convertOpsToU64() :: RESULT=%#llx\n", convert.u64 );
	return convert.u64;
}

#ifdef ENABLE_JITOPS_TYPEINFO

#define CHECK_OP_TYPE( checkTypes, sizeBytes ) \
	checkOpType_func( checkTypes, sizeBytes, __LINE__, (PTR)pCurOp, pCurrentMethodState )

static void checkOpType_func( int checkTypes, int sizeBytes, int line, PTR pCurOp, tMethodState *pCurrMethodState ) {

	// there is no type information related to Native or PInvoke calls (pJIT->pOpTypes is NULL).
	// => this is only related to GET_OP_64() call which is made inside the GO_NEXT() macro.
	if ( sizeBytes > 4 && pCurrMethodState->pJIT->pOpTypes == NULL ) {
		log_f( 3, "SKIP checkOpType because pJIT->pOpTypes is unset (is Native or PInvoke call).\n" );
		return;
	}

	log_f( 3, "checkOpType_func() STARTING :: checkTypes=%d sizeBytes=%d line=%d pCurOp=%#llx\n", (int)checkTypes, (int)sizeBytes, (int)line, (U64)pCurOp );

	long ofs32 = CURRENT_OPS_OFFSET();
	//log_f( 0, "checkOpType_func() CURRENT_OPS_OFFSET = %d\n", (int)ofs32 );

	long ofs8 = ofs32 >> 2;
	U8 typeInfo = *(U8*)(pCurrMethodState->pJIT->pOpTypes + ofs8);

	// 20240730 these seem to work at beginning, but later
	// will get messed up => is the OPS data updated somewhere?

/*	if ( checkTypes != 0 ) {
		if ( ( checkTypes & typeInfo ) == 0 ) {
			log_f( 0, "at line %d checkOpType_func() failed: checkTypes=%d typeInfo=%d\n", (int)line, (int)checkTypes, (int)typeInfo );
		} else {
			log_f( 0, "at line %d checkOpType_func() OK: checkTypes=%d typeInfo=%d\n", (int)line, (int)checkTypes, (int)typeInfo );
		}
		log_f( 3, "checkOpType_func() COMPLETED :: typeInfo = %d\n", (int)typeInfo );
	}	*/

/*	if ( sizeBytes == 4 ) {
		U8 types32 = JITOPS_TYPE_VAL_32;
		if ( ( types32 & typeInfo ) == 0 ) {
			log_f( 0, "at line %d checkOpType_func() failed: checkTypes=%d typeInfo=%d\n", (int)line, (int)types32, (int)typeInfo );
		}
		//else log_f( 0, "at line %d checkOpType_func() OK: checkTypes=%d typeInfo=%d\n", (int)line, (int)types32, (int)typeInfo );
	} else if ( sizeBytes == 8 ) {
		U8 types64 = JITOPS_TYPE_VAL_64 | JITOPS_TYPE_OP_64 | JITOPS_TYPE_PTR_64;
		if ( ( types64 & typeInfo ) == 0 ) {
			log_f( 0, "at line %d checkOpType_func() failed: checkTypes=%d typeInfo=%d\n", (int)line, (int)types64, (int)typeInfo );
		}
		//else log_f( 0, "at line %d checkOpType_func() OK: checkTypes=%d typeInfo=%d\n", (int)line, (int)types64, (int)typeInfo );
	}	*/

	if ( sizeBytes == 4 ) {
		U32 tmp = *(U32*)(pCurOp);
		log_f( 3, "checkOpType_func() :: current OPS_32 value is %#x\n", tmp );
	} else if ( sizeBytes == 8 ) {
		U64 tmp = convertOpsToU64( *(U32*)(pCurOp), *(U32*)(pCurOp + 4) );
		log_f( 3, "checkOpType_func() :: current OPS_64 value is %#llx\n", tmp );
	} else {
#ifdef CRASH_ON_TYPE_ERRORS
		Crash( "checkOpType_func() : sizeBytes has unexpected value %d\n", sizeBytes );
#else // CRASH_ON_TYPE_ERRORS
		log_f( 3, "checkOpType_func() WARN : sizeBytes has unexpected value %d\n", sizeBytes );
#endif // CRASH_ON_TYPE_ERRORS
	}
}

#else // ENABLE_JITOPS_TYPEINFO

#define CHECK_OP_TYPE( checkTypes, sizeBytes )

#endif // ENABLE_JITOPS_TYPEINFO

#define GET_OP_32( checkTypes ) \
	*(pCurOp); \
	CHECK_OP_TYPE( checkTypes, 4 ); \
	pCurOp++

#define GET_OP_64( checkTypes ) \
	convertOpsToU64( *(pCurOp), *(pCurOp + 1) ); \
	log_f( 3, "GET_OP_64() from address: %#llx\n", pCurOp - 2 ); \
	CHECK_OP_TYPE( checkTypes, 8 ); \
	pCurOp += 2

#ifdef ENABLE_STACKITEMS_TYPEINFO

int JIT_ParseStackTypeInfo_type( U8 typeInfo ) {
	return ( (int) typeInfo ) >> 6;
}

int JIT_ParseStackTypeInfo_size( U8 typeInfo ) {
	int size = ( (int) typeInfo ) & STACKITEM_SIZE_MASK;
	int sizeBytes = ( size + 1 ) << 2;
	return sizeBytes;
}

#define PRINT_EVALSTACK_DUMP() \
	JIT_PrintEvalStackDump( pCurrentMethodState, (int)(CURRENT_STACK_OFFSET()), __LINE__, 0 )

void JIT_PrintEvalStackDump( tMethodState* pMethodState, int upToOffsetB, int lineNumber, int printCrashDump ) {

	// upToOffsetB is the count of bytes currently stored in evalStack.
	// printCrashDump is set to non-zero to force output at loglevel-0.
	
	int tmpLogLevel = 3;
	if ( printCrashDump != 0 ) tmpLogLevel = 0;

	PTR ptrData = pMethodState->pEvalStack;
	PTR ptrInfo = pMethodState->pEvalStackTypeInfo;

	log_f( tmpLogLevel, "\n" );
	log_f( tmpLogLevel, "*** EVAL-STACK-DUMP ***    instance=%#llx    upToOffset=%d    lineNumber=%d\n", ptrData, upToOffsetB, lineNumber );

	int error = 0;

	if ( upToOffsetB < 0 ) {
		log_f( tmpLogLevel, "EVAL-stack-ERROR: upToOffsetB %d is negative\n", upToOffsetB );
		error = 1;
        }

	if ( upToOffsetB % 4 != 0 ) {
		log_f( tmpLogLevel, "EVAL-stack-ERROR: upToOffsetB %d is not 32-bit aligned\n", upToOffsetB );
		error = 1;
	}

	int type = 0;
	int size = 0;

	int prev_type = 0;
	int prev_size = 4; // default value 4 won't trigger the previous-type check.

	for ( int i = 0; i < upToOffsetB; i+= 4 ) {

		U8 typeInfo = *(U8*)ptrInfo;
		ptrInfo++;

		type = JIT_ParseStackTypeInfo_type( typeInfo );
		size = JIT_ParseStackTypeInfo_size( typeInfo );

		if ( type == 0 ) {
			log_f( tmpLogLevel, "EVAL-stack-ERROR: type not valid: %d\n", type );
			error = 1;
		}

		U32 data = *(U32*)ptrData;
		ptrData += 4;

		log_f( tmpLogLevel, "*** EVAL-STACK-DUMP : byte-offset = %d : data=%#x type=%d sizeinfo=%d\n", i, data, type, size );

		if ( prev_size != 4 ) {
			// previous type must be the same as current:
			if ( prev_type != type ) {
				log_f( tmpLogLevel, "EVAL-stack-ERROR: type-mismatch detected: %d vs %d\n", prev_type, type );
				error = 1;
			}
			// previous size must be the current size + 4 bytes:
			if ( prev_size != size + 4 ) {
				log_f( tmpLogLevel, "EVAL-stack-ERROR: size-mismatch detected: %d vs %d\n", prev_size, size );
				error = 1;
			}
		}

		prev_type = type;
		prev_size = size;
	}

	if ( size > 4 ) {
		log_f( tmpLogLevel, "EVAL-stack-ERROR: the last stackitem is truncated: size=%d\n", size );
		error = 1;
	}

	if ( printCrashDump != 0 ) Crash( "EVAL-stack-ERROR: errors detected" );

#ifdef CRASH_ON_TYPE_ERRORS
	if ( error != 0 ) {
		// call the same method again, setting the crash-flag, to get forced output.
		JIT_PrintEvalStackDump( pMethodState, upToOffsetB, lineNumber, 1 ); // this will call Crash().
	}
#endif // CRASH_ON_TYPE_ERRORS

	log_f( tmpLogLevel, "\n" );
}

void PrintPLStackDump( tMethodState* pMethodState, int upToOffsetB, int lineNumber, int printCrashDump ) {

	// upToOffsetB is the count of bytes currently stored in evalStack.
	// printCrashDump is set to non-zero to force output at loglevel-0.
	
	int tmpLogLevel = 3;
	if ( printCrashDump != 0 ) tmpLogLevel = 0;

	PTR ptrData = pMethodState->pParamsLocals;
	PTR ptrInfo = pMethodState->pParamsLocalsTypeInfo;

	log_f( tmpLogLevel, "\n" );
	log_f( tmpLogLevel, "*** PL-STACK-DUMP ***    instance=%#llx    upToOffset=%d\n", ptrData, upToOffsetB );

	int error = 0;

	if ( upToOffsetB < 0 ) {
		log_f( tmpLogLevel, "PL-stack-ERROR: upToOffsetB %d is negative\n", upToOffsetB );
		error = 1;
        }

	if ( upToOffsetB % 4 != 0 ) {
		log_f( tmpLogLevel, "PL-stack-ERROR: upToOffsetB %d is not 32-bit aligned\n", upToOffsetB );
		error = 1;
	}

	int type = 0;
	int size = 0;

	int prev_type = 0;
	int prev_size = 4; // default value 4 won't trigger the previous-type check.

	for ( int i = 0; i < upToOffsetB; i+= 4 ) {

		U8 typeInfo = *(U8*)ptrInfo;
		ptrInfo++;

		type = JIT_ParseStackTypeInfo_type( typeInfo );
		size = JIT_ParseStackTypeInfo_size( typeInfo );

		if ( type == 0 ) {
			log_f( tmpLogLevel, "EVAL-stack-ERROR: type not valid: %d\n", type );
			error = 1;
		}

		U32 data = *(U32*)ptrData;
		ptrData += 4;

		log_f( tmpLogLevel, "*** PL-STACK-DUMP : byte-offset = %d : data=%#x type=%d sizeinfo=%d\n", i, data, type, size );

		if ( prev_size != 4 ) {
			// previous type must be the same as current:
			if ( prev_type != type ) {
				log_f( tmpLogLevel, "PL-stack-ERROR: type-mismatch detected: %d vs %d\n", prev_type, type );
				error = 1;
			}
			// previous size must be the current size + 4 bytes:
			if ( prev_size != size + 4 ) {
				log_f( tmpLogLevel, "PL-stack-ERROR: size-mismatch detected: %d vs %d\n", prev_size, size );
				error = 1;
			}
		}

		prev_type = type;
		prev_size = size;
	}

	if ( size > 4 ) {
		log_f( tmpLogLevel, "PL-stack-ERROR: the last stackitem is truncated: size=%d\n", size );
		error = 1;
	}

	if ( printCrashDump != 0 ) Crash( "PL-stack-ERROR: errors detected" );

#ifdef CRASH_ON_TYPE_ERRORS
	if ( error != 0 ) {
		// call the same method again, setting the crash-flag, to get forced output.
		PrintPLStackDump( pMethodState, upToOffsetB, lineNumber, 1 ); // this will call Crash().
	}
#endif // CRASH_ON_TYPE_ERRORS

	log_f( tmpLogLevel, "\n" );
}

#define PUSH_EVALSTACKITEM_TYPE( size, shift, type ) \
	PushEvalStackItemType( (size), (shift), (type), pCurrentMethodState, (int)(CURRENT_STACK_OFFSET()) )

static void PushEvalStackItemType( int dataSize, int shift, int type, tMethodState* pMethodState, int offsetB ) {

log_f( 3, "PushEvalStackItemType() :: dataSize=%d shift=%d type=%d offsetB=%d :: ", dataSize, shift, type, offsetB );

	if ( dataSize % 4 != 0 ) Crash( "PushEvalStackItemType() :: bad dataSize %d", dataSize );
	if ( type < 1 || type > 3 ) Crash( "PushEvalStackItemType() :: bad type %d", type );

int position = offsetB + shift;
if ( position < 0 ) {
	Crash( "EVALstack underflow: %d", position );
}
int max = pMethodState->pJIT->maxStack;
if ( position >= max ) {
	Crash( "EVALstack overflow: %d vs %d", position, max );
}

	U8* pCurrentTypeInfo = pMethodState->pEvalStackTypeInfo;
	pCurrentTypeInfo += ( ( offsetB + shift ) >> 2 );

	int size = ( dataSize >> 2 );

	for ( int i = 0; i < size; i++ ) {
		int ofs = size - i - 1;
		if ( ofs > 63 ) Crash( "PushEvalStackItemType() :: ofs_overflow" );

		int typeInfo = ( type << 6 ) + ofs;

log_f( 3, "%d ", ofs );

		*pCurrentTypeInfo = (U8) typeInfo;
		pCurrentTypeInfo++;
	}

log_f( 3, "\n" );

}

static void PushPLStackItemType( int dataSize, int shift, int type, tMethodState* pMethodState, int offsetB ) {

log_f( 3, "PushPLStackItemType() :: dataSize=%d shift=%d type=%d offsetB=%d :: ", dataSize, shift, type, offsetB );

	if ( dataSize % 4 != 0 ) Crash( "PushPLStackItemType() :: bad dataSize %d", dataSize );
	if ( type < 1 || type > 3 ) Crash( "PushPLStackItemType() :: bad type %d", type );

int position = offsetB + shift;
if ( position < 0 ) {
	Crash( "PLstack underflow: %d", position );
}
int max = pMethodState->pJIT->maxStack;
if ( position >= max ) {
	Crash( "PLstack overflow: %d vs %d", position, max );
}

	U8* pCurrentTypeInfo = pMethodState->pParamsLocalsTypeInfo;
	pCurrentTypeInfo += ( ( offsetB + shift ) >> 2 );

	int size = ( dataSize >> 2 );

	for ( int i = 0; i < size; i++ ) {
		int ofs = size - i - 1;
		if ( ofs > 63 ) Crash( "PushPLStackItemType() :: ofs_overflow" );

		int typeInfo = ( type << 6 ) + ofs;

log_f( 3, "%d ", ofs );

		*pCurrentTypeInfo = (U8) typeInfo;
		pCurrentTypeInfo++;
	}

log_f( 3, "\n" );

}

int line_number = 0;
#define STORE_LINE_NUMBER() \
	line_number = __LINE__

#define CHECK_EVALSTACKITEM_TYPE( size, shift ) \
	STORE_LINE_NUMBER(); \
	CheckEvalStackItemType( size, shift, pCurrentMethodState, (int)(CURRENT_STACK_OFFSET()) )

static void CheckEvalStackItemType( int opSize, int shift, tMethodState* pMethodState, int offsetB ) {

	// the parameter "shift" is to specify the relative stack position (bytes) to start check from.
	// the parameter "count" is to specify how many repeated checks are done.

log_f( 3, "CheckEvalStackItemType() :: opSize=%d shift=%d offsetB=%d :: ", opSize, shift, offsetB );

	int offsetB_original = offsetB;

	offsetB += shift;

	// from the current position (as indicated by offsetB),
	// go backwards in stack (as indicated by opSize),
	// and see if there is a value of correct type.

	offsetB -= opSize;

	if ( offsetB < 0 ) Crash( "CheckEvalStackItemType() :: reversed outside stack! %d", offsetB );

	U8* pCurrentTypeInfo = pMethodState->pEvalStackTypeInfo;
	pCurrentTypeInfo += ( offsetB >> 2 );

	U8 typeInfo = *pCurrentTypeInfo;

	int type = JIT_ParseStackTypeInfo_type( typeInfo );
	int size = JIT_ParseStackTypeInfo_size( typeInfo );

	int error = 0;
        int tmpLogLevel = 3;

	log_f( 3, "CheckEvalStackItemType() stage-1 : typeInfo=%d type=%d size=%d at offsetB=%d\n", typeInfo, type, size, offsetB );

	if ( type == 0 ) {
#ifdef CRASH_ON_TYPE_ERRORS
		tmpLogLevel = 0;
#endif // CRASH_ON_TYPE_ERRORS
		log_f( tmpLogLevel, "CheckEvalStackItemType() FAILED-1: type not valid: %d\n", type );
		error = 1;
        }

	if ( opSize != size ) {
#ifdef CRASH_ON_TYPE_ERRORS
		tmpLogLevel = 0;
#endif // CRASH_ON_TYPE_ERRORS
		log_f( tmpLogLevel, "CheckEvalStackItemType() FAILED at stage-1 : %d vs %d\n", opSize, size );
		error = 1;
	}

	// check stage-2 is only applied if opSize == 4.
	// => not allowed to split a bigger-than-32-bit value in stack using a 32-bit POP operation.
	if ( opSize == 4 && offsetB > 0 ) {

		offsetB -= 4;

		pCurrentTypeInfo = pMethodState->pEvalStackTypeInfo;
		pCurrentTypeInfo += ( offsetB >> 2 );

		typeInfo = *pCurrentTypeInfo;

		type = JIT_ParseStackTypeInfo_type( typeInfo );
		size = JIT_ParseStackTypeInfo_size( typeInfo );

		if ( type == 0 ) {
#ifdef CRASH_ON_TYPE_ERRORS
			tmpLogLevel = 0;
#endif // CRASH_ON_TYPE_ERRORS
			log_f( tmpLogLevel, "CheckEvalStackItemType() FAILED-2: type not valid: %d\n", type );
			error = 1;
		}

		log_f( 3, "CheckEvalStackItemType() stage-2 : typeInfo=%d type=%d size=%d at offsetB=%d\n", typeInfo, type, size, offsetB );

		if ( opSize != size ) {
#ifdef CRASH_ON_TYPE_ERRORS
			tmpLogLevel = 0;
#endif // CRASH_ON_TYPE_ERRORS
			log_f( tmpLogLevel, "CheckEvalStackItemType() FAILED at stage-2 : %d vs %d\n", opSize, size );
			error = 1;
		}
	}

#ifdef CRASH_ON_TYPE_ERRORS
	if ( error != 0 ) {
		JIT_PrintEvalStackDump( pMethodState, offsetB_original, line_number, 1 ); // will call Crash().
	}
#endif // CRASH_ON_TYPE_ERRORS
	
}

#define READ_EVALSTACKITEM_TYPE( shift ) \
	ReadEvalStackItemType( shift, pCurrentMethodState, (int)(CURRENT_STACK_OFFSET()) )

static int ReadEvalStackItemType( int shift, tMethodState* pMethodState, int offsetB ) {

	offsetB += shift;

	U8* pCurrentTypeInfo = pMethodState->pEvalStackTypeInfo;
	pCurrentTypeInfo += ( offsetB >> 2 );

	U8 typeInfo = *pCurrentTypeInfo;

	int type = JIT_ParseStackTypeInfo_type( typeInfo );

	return type;
}

#else // ENABLE_STACKITEMS_TYPEINFO

#define PRINT_EVALSTACK_DUMP()
#define PUSH_EVALSTACKITEM_TYPE( size, shift, type )
#define CHECK_EVALSTACKITEM_TYPE( size, shift )

#endif // ENABLE_STACKITEMS_TYPEINFO

// Push a U32 value on the top of the stack
#define PUSH_U32(value) \
	*(U32*)pCurEvalStack = (U32)(value); \
	PUSH_EVALSTACKITEM_TYPE( 4, 0, STACKITEM_TYPE_VALUE ); \
	pCurEvalStack += 4; \
	PRINT_EVALSTACK_DUMP()

// Push a U64 value on the top of the stack
#define PUSH_U64(value) \
	*(U64*)pCurEvalStack = (U64)(value); \
	PUSH_EVALSTACKITEM_TYPE( 8, 0, STACKITEM_TYPE_VALUE ); \
	pCurEvalStack += 8; \
	PRINT_EVALSTACK_DUMP()

// Push a float value on the top of the stack
#define PUSH_FLOAT(value) \
	*(float*)pCurEvalStack = (float)(value); \
	PUSH_EVALSTACKITEM_TYPE( 4, 0, STACKITEM_TYPE_VALUE ); \
	pCurEvalStack += 4; \
	PRINT_EVALSTACK_DUMP()

// Push a double value on the top of the stack
#define PUSH_DOUBLE(value) \
	*(double*)pCurEvalStack = (double)(value); \
	PUSH_EVALSTACKITEM_TYPE( 8, 0, STACKITEM_TYPE_VALUE ); \
	pCurEvalStack += 8; \
	PRINT_EVALSTACK_DUMP()

// Push a 4-byte heap pointer on to the top of the stack
#define PUSH_O(pHeap) \
	*(void**)pCurEvalStack = (void*)(pHeap); \
	PUSH_EVALSTACKITEM_TYPE( sizeof(void*), 0, STACKITEM_TYPE_POINTER ); \
	pCurEvalStack += sizeof(void*); \
	PRINT_EVALSTACK_DUMP()

// Push a PTR value on the top of the stack
#define PUSH_PTR(ptr) \
	*(PTR*)pCurEvalStack = (PTR)(ptr); \
	PUSH_EVALSTACKITEM_TYPE( sizeof(void*), 0, STACKITEM_TYPE_POINTER ); \
	pCurEvalStack += sizeof(void*); \
	PRINT_EVALSTACK_DUMP()

// Push an arbitrarily-sized value-type onto the top of the stack
#define PUSH_VALUETYPE(ptr, valueSize, stackInc) \
	memcpy(pCurEvalStack, ptr, valueSize); \
	PUSH_EVALSTACKITEM_TYPE( stackInc, 0, STACKITEM_TYPE_VALUETYPE ); \
	pCurEvalStack += stackInc; \
	PRINT_EVALSTACK_DUMP()

// DUP4() duplicates the top 4 bytes on the eval stack
#define DUP4() \
	CHECK_EVALSTACKITEM_TYPE( 4, 0 ); \
	PUSH_EVALSTACKITEM_TYPE( 4, 0, READ_EVALSTACKITEM_TYPE( -4 ) ); \
	*(U32*)pCurEvalStack = *(U32*)(pCurEvalStack - 4); \
	pCurEvalStack += 4

// DUP8() duplicates the top 8 bytes on the eval stack
#define DUP8() \
	CHECK_EVALSTACKITEM_TYPE( 8, 0 ); \
	PUSH_EVALSTACKITEM_TYPE( 8, 0, READ_EVALSTACKITEM_TYPE( -8 ) ); \
	*(U64*)pCurEvalStack = *(U64*)(pCurEvalStack - 8); \
	pCurEvalStack += 8

// DUP() duplicates numBytes bytes from the top of the stack
#define DUP(numBytes) \
	CHECK_EVALSTACKITEM_TYPE( numBytes, 0 ); \
	PUSH_EVALSTACKITEM_TYPE( numBytes, 0, READ_EVALSTACKITEM_TYPE( -numBytes ) ); \
	memcpy(pCurEvalStack, pCurEvalStack - numBytes, numBytes); \
	pCurEvalStack += numBytes

// Pop a U32 value from the stack
#define POP_U32() \
	(*(U32*)(pCurEvalStack -= 4)); \
	CHECK_EVALSTACKITEM_TYPE( 4, 4 )

// Pop a U64 value from the stack
#define POP_U64() \
	(*(U64*)(pCurEvalStack -= 8)); \
	CHECK_EVALSTACKITEM_TYPE( 8, 8 )

// Pop a float value from the stack
#define POP_FLOAT() \
	(*(float*)(pCurEvalStack -= 4)); \
	CHECK_EVALSTACKITEM_TYPE( 4, 4 )

// Pop a double value from the stack
#define POP_DOUBLE() \
	(*(double*)(pCurEvalStack -= 8)); \
	CHECK_EVALSTACKITEM_TYPE( 8, 8 )

// Pop a PTR value from the stack
#define POP_PTR() \
	(*(PTR*)(pCurEvalStack -= sizeof(void*))); \
	CHECK_EVALSTACKITEM_TYPE( sizeof(void*), sizeof(void*) )

// Pop a Object (heap) pointer value from the stack
#define POP_O() \
	(*(HEAP_PTR*)(pCurEvalStack -= sizeof(void*))); \
	CHECK_EVALSTACKITEM_TYPE( sizeof(void*), sizeof(void*) )

// Pop an arbitrarily-sized value-type from the stack (copies it to the specified memory location)
#define POP_VALUETYPE(ptr, valueSize, stackDec) \
	memcpy(ptr, pCurEvalStack -= stackDec, valueSize); \
	CHECK_EVALSTACKITEM_TYPE( stackDec, stackDec )

// Pop 2 U32's from the stack
#define POP_U32_U32(v1,v2) \
	CHECK_EVALSTACKITEM_TYPE( 4, 0 ); \
	CHECK_EVALSTACKITEM_TYPE( 4, -4 ); \
	pCurEvalStack -= 8; \
	v1 = *(U32*)pCurEvalStack; \
	v2 = *(U32*)(pCurEvalStack + 4)

// Pop 2 U64's from the stack
#define POP_U64_U64(v1,v2) \
	CHECK_EVALSTACKITEM_TYPE( 8, 0 ); \
	CHECK_EVALSTACKITEM_TYPE( 8, -8 ); \
	pCurEvalStack -= 16; \
	v1 = *(U64*)pCurEvalStack; \
	v2 = *(U64*)(pCurEvalStack + 8)

// Pop 2 F32's from the stack
#define POP_F32_F32(v1,v2) \
	CHECK_EVALSTACKITEM_TYPE( 4, 0 ); \
	CHECK_EVALSTACKITEM_TYPE( 4, -4 ); \
	pCurEvalStack -= 8; \
	v1 = *(float*)pCurEvalStack; \
	v2 = *(float*)(pCurEvalStack + 4)

// Pop 2 F64's from the stack
#define POP_F64_F64(v1,v2) \
	CHECK_EVALSTACKITEM_TYPE( 8, 0 ); \
	CHECK_EVALSTACKITEM_TYPE( 8, -8 ); \
	pCurEvalStack -= 16; \
	v1 = *(double*)pCurEvalStack; \
	v2 = *(double*)(pCurEvalStack + 8)

// POP() returns nothing - it just alters the stack offset correctly
#define POP(numBytes) \
	CHECK_EVALSTACKITEM_TYPE( numBytes, 0 ); \
	pCurEvalStack -= numBytes

// POP_ALL() empties the evaluation stack
#define POP_ALL() \
	pCurEvalStack = pCurrentMethodState->pEvalStack

#define STACK_ADDR(type) *(type*)(pCurEvalStack - sizeof(type))

#define CURRENT_STACK_OFFSET() ((PTR)pCurEvalStack - (PTR)pCurrentMethodState->pEvalStack)

// General binary ops
#define BINARY_OP(returnType, type1, type2, op) \
	CHECK_EVALSTACKITEM_TYPE( sizeof(type2), 0 ); \
	CHECK_EVALSTACKITEM_TYPE( sizeof(type1), -sizeof(type2) ); \
	pCurEvalStack -= sizeof(type1) + sizeof(type2) - sizeof(returnType); \
	*(returnType*)(pCurEvalStack - sizeof(returnType)) = \
	*(type1*)(pCurEvalStack - sizeof(returnType)) op \
	*(type2*)(pCurEvalStack - sizeof(returnType) + sizeof(type1)); \
	PUSH_EVALSTACKITEM_TYPE( sizeof(returnType), -sizeof(returnType), STACKITEM_TYPE_VALUE ); \
	PRINT_EVALSTACK_DUMP();

// General unary ops
#define UNARY_OP(type, op) STACK_ADDR(type) = op STACK_ADDR(type)

// Set the new method state (for use when the method state changes - in calls mainly)
#define SAVE_METHOD_STATE() \
	pCurrentMethodState->stackOfs = (U32)(pCurEvalStack - pCurrentMethodState->pEvalStack); \
	pCurrentMethodState->ipOffset = (U32)(pCurOp - pOps)

#define LOAD_METHOD_STATE() \
	pCurrentMethodState = pThread->pCurrentMethodState; \
	pParamsLocals = pCurrentMethodState->pParamsLocals; \
	pCurEvalStack = pCurrentMethodState->pEvalStack + pCurrentMethodState->stackOfs; \
	pJIT = pCurrentMethodState->pJIT; \
	pOps = pJIT->pOps; \
	pOpSequencePoints = pJIT->pOpSequencePoints; \
	pCurOp = pOps + pCurrentMethodState->ipOffset

#define CHANGE_METHOD_STATE(pNewMethodState) \
	SAVE_METHOD_STATE(); \
	pThread->pCurrentMethodState = pNewMethodState; \
	LOAD_METHOD_STATE()

// Easy access to method parameters and local variables
#define PARAMLOCAL_U32(offset) *(U32*)(pParamsLocals + offset)
#define PARAMLOCAL_U64(offset) *(U64*)(pParamsLocals + offset)

#define THROW(exType) heapPtr = Heap_AllocType(exType); goto throwHeapPtr

static void CheckIfCurrentInstructionHasBreakpoint(tMethodState* pMethodState, U32 opOffset, I32* pOpSequencePoints)
{
	if (pOpSequencePoints != NULL) {
		I32 currentOpSequencePoint = pOpSequencePoints[opOffset];
		if (currentOpSequencePoint >= 0) {
			CheckIfSequencePointIsBreakpoint(pMethodState, currentOpSequencePoint);
		}
	}
}

// Note: newObj is only set if a constructor is being called
static void CreateParameters(tMethodState *pCallMethodState, tMD_MethodDef *pCallMethodDef, tMethodState *pCurrMethodState, PTR *ppCurEvalStack, HEAP_PTR newObj) {
	U32 ofs;
	PTR pParamsLocals = pCallMethodState->pParamsLocals;
	PTR pParamsLocalsTypeInfo = pCallMethodState->pParamsLocalsTypeInfo;
	PTR pEvalStackTypeInfo = pCurrMethodState->pEvalStackTypeInfo;

//int current_stack_offset_INITIAL = (int) ((PTR)*ppCurEvalStack - (PTR)pCurrMethodState->pEvalStack);
//JIT_PrintEvalStackDump( pCurrMethodState, current_stack_offset_INITIAL, __LINE__, 1234 );

	if (newObj != NULL) {
		// If this is being called from JIT_NEW_OBJECT then need to specially push the new object
		// onto parameter stack position 0
		*(HEAP_PTR*)pParamsLocals = newObj;
		ofs = sizeof(HEAP_PTR);

PushPLStackItemType( sizeof(newObj), 0, STACKITEM_TYPE_POINTER, pCallMethodState, 0 );

	} else {
		ofs = 0;
	}

int change = -(pCallMethodDef->parameterStackSize - ofs);
log_f( 3, "EXTRA_STACKPOINTER_CHANGE at line %d : change = %d    CreateParameters()\n", __LINE__, change );

	*ppCurEvalStack -= pCallMethodDef->parameterStackSize - ofs;
	memcpy(pParamsLocals + ofs, *ppCurEvalStack, pCallMethodDef->parameterStackSize - ofs);

	int current_stack_offset_BYTES = (int) ((PTR)*ppCurEvalStack - (PTR)pCurrMethodState->pEvalStack);

	int type_ofs = ofs >> 2; // 32bit to 8bit
	int from_offset = current_stack_offset_BYTES >> 2;
	int type_bytes = (pCallMethodDef->parameterStackSize - ofs) >> 2;
	memcpy(pParamsLocalsTypeInfo + type_ofs, pEvalStackTypeInfo + from_offset, type_bytes);

//PrintPLStackDump( pCallMethodState, pCallMethodDef->parameterStackSize, __LINE__, 0 );

/*	if( getLogLevel() < 3 ) return;
	// now dump the call parameters, with types and values if possible.
	log_f( 3, "DUMP_CALL_PARAMS for : %s.%s()\n", pCallMethodDef->pParentType->nameSpace, pCallMethodDef->name ); 
	for ( int p = 0; p < pCallMethodDef->numberOfParameters; p++ ) {

		tParameter *pParam = &(pCallMethodDef->pParams[p]);

		tMD_TypeDef *pTypeDef = pParam->pTypeDef;
		U32 offset = pParam->offset;
		//U32 size = pParam->size;

		if ( pTypeDef == types[TYPE_SYSTEM_INT32] ) {
			int value = *(int*)(pParamsLocals + offset);
			log_f( 3, "DUMP_CALL_PARAMS    %d => %s.%s value=%d\n", p, pTypeDef->nameSpace, pTypeDef->name, value ); 
		} else if ( pTypeDef == types[TYPE_SYSTEM_SINGLE] ) {
			float value = *(float*)(pParamsLocals + offset);
			log_f( 3, "DUMP_CALL_PARAMS    %d => %s.%s value=%f  %#x\n", p, pTypeDef->nameSpace, pTypeDef->name, value, *(U32*)&value ); 
		} else if ( pTypeDef == types[TYPE_SYSTEM_DOUBLE] ) {
			double value = *(double*)(pParamsLocals + offset);
			log_f( 3, "DUMP_CALL_PARAMS    %d => %s.%s value=%f  %#llx\n", p, pTypeDef->nameSpace, pTypeDef->name, value, *(U64*)&value ); 
		} else {
			log_f( 3, "DUMP_CALL_PARAMS    %d => %s.%s\n", p, pTypeDef->nameSpace, pTypeDef->name ); 
		}
	}	*/
}

static tMethodState* RunFinalizer(tThread *pThread) {
	HEAP_PTR heapPtr = GetNextFinalizer();
	if (heapPtr != NULL) {
		// There is a pending finalizer, so create a MethodState for it and put it as next-to-run on the stack
		tMethodState *pFinalizerMethodState;
		tMD_TypeDef *pFinalizerType = Heap_GetType(heapPtr);

		pFinalizerMethodState = MethodState_Direct(pThread, pFinalizerType->pFinalizer, pThread->pCurrentMethodState, 0);
		// Mark this methodState as a Finalizer
		pFinalizerMethodState->finalizerThis = heapPtr;
		// Put the object on the stack (the object that is being Finalized)
		// Finalizers always have no parameters
		*(HEAP_PTR*)(pFinalizerMethodState->pParamsLocals) = heapPtr;
		//log_f( 3, "--- FINALIZE ---\n" );

		return pFinalizerMethodState;
	}
	return NULL;
}

#ifdef DIAG_OPCODE_TIMES
U64 opcodeTimes[JIT_OPCODE_MAXNUM];
static __inline unsigned __int64 __cdecl rdtsc() {
	__asm {
		rdtsc
	}
}
#endif // DIAG_OPCODE_TIMES

int opCodeUseCounter = 0;

#ifdef DIAG_OPCODE_USE

U32 opcodeNumUses[JIT_OPCODE_MAXNUM];
#define OPCODE_USE(op) opcodeNumUses[op]++;

#else // DIAG_OPCODE_USE

//#define OPCODE_USE(op)
#define OPCODE_USE(op) log_f( 3, "trackControlFlow exec_OPCODE_USE  %s  (%#x)  opCodeUse=%d\n", JIT_GetOpCodeName(op), op, opCodeUseCounter++ )

#endif // DIAG_OPCODE_USE

#define CHECK_FOR_BREAKPOINT() \
	CheckIfCurrentInstructionHasBreakpoint(pCurrentMethodState, pCurOp - pOps, pOpSequencePoints)

#ifdef __GNUC__

#define GET_LABEL(var, label) var = &&label

#define GO_NEXT() \
	CHECK_FOR_BREAKPOINT(); \
	goNextAddress = (void*)GET_OP_64( JITOPS_TYPE_OP_64 ); \
	goto *goNextAddress

#else // __GNUC__
#ifdef _WIN32

#define GET_LABEL(var, label) \
	{ __asm mov edi, label \
	__asm mov var, edi }

#define GO_NEXT() \
	CHECK_FOR_BREAKPOINT(); \
	goNextAddress = (void*)GET_OP_64( JITOPS_TYPE_OP_64 ); \
	goto *goNextAddress

#endif // _WIN32
#endif // __GNUC__

#define GO_NEXT_CHECK() \
	if (--numInst == 0) goto done; \
	GO_NEXT()

#define GET_LABELS(op) \
	GET_LABEL(pAddr, op##_start); \
	jitCodeInfo[op].pStart = pAddr; \
	GET_LABEL(pAddr, op##_end); \
	jitCodeInfo[op].pEnd = pAddr; \
	jitCodeInfo[op].isDynamic = 0

#define GET_LABELS_DYNAMIC(op, extraBytes) \
	GET_LABEL(pAddr, op##_start); \
	jitCodeInfo[op].pStart = pAddr; \
	GET_LABEL(pAddr, op##_end); \
	jitCodeInfo[op].pEnd = pAddr; \
	jitCodeInfo[op].isDynamic = 0x100 | (extraBytes & 0xff)

#define RUN_FINALIZER() {tMethodState *pMS = RunFinalizer(pThread);if(pMS) {CHANGE_METHOD_STATE(pMS);}}

U32 JIT_Execute(tThread *pThread, U32 numInst) {
	tJITted *pJIT;
	tMethodState *pCurrentMethodState;
	PTR pParamsLocals;

	// Local copies of thread state variables, to speed up execution
	U32 *pOps;
	I32 *pOpSequencePoints;

	// Pointer to next op-code
	register U32 *pCurOp;

	// Pointer to eval-stack position
	register PTR pCurEvalStack;

	U32 op;
	PTR pTempPtr;

	U32 ofs;
	HEAP_PTR heapPtr;
	PTR pMem;

	// General purpose variables
		//I32 i32Value;
	U32 u32Value;
		//U32 u32Value2;
		//U64 u64Value;
		//double dValue;
		//float fValue;
		//uConvDouble convDouble;

	const U16 checkPointerTypes = JITOPS_TYPE_OP_64 | JITOPS_TYPE_PTR_64;

	void* goNextAddress;

	if (pThread == NULL) {
		void *pAddr;
		// Special case to get all the label addresses
		// Default all op-codes to noCode.
		GET_LABEL(pAddr, noCode);
		for (u32Value = 0; u32Value < JIT_OPCODE_MAXNUM; u32Value++) {
			jitCodeInfo[u32Value].pStart = pAddr;
			jitCodeInfo[u32Value].pEnd = NULL;
			jitCodeInfo[u32Value].isDynamic = 0;
		}

		// Get GoNext code
		GET_LABEL(jitCodeGoNext.pStart, JIT_GoNext_start);
		GET_LABEL(jitCodeGoNext.pEnd, JIT_GoNext_end);
		jitCodeGoNext.isDynamic = 0;

		// Get all defined opcodes
		GET_LABELS_DYNAMIC(JIT_NOP, 0);
		GET_LABELS(JIT_RETURN);
		GET_LABELS_DYNAMIC(JIT_LOAD_I32, 4);
		GET_LABELS(JIT_BRANCH);
		GET_LABELS(JIT_LOAD_STRING);
		GET_LABELS(JIT_CALLVIRT_O);
		GET_LABELS(JIT_CALL_NATIVE);
		GET_LABELS(JIT_CALL_O);
		GET_LABELS(JIT_NEWOBJECT);
		GET_LABELS(JIT_LOAD_PARAMLOCAL_ADDR);
		GET_LABELS(JIT_CALL_PTR);
		GET_LABELS(JIT_BOX_CALLVIRT);
		GET_LABELS(JIT_INIT_VALUETYPE);
		GET_LABELS(JIT_NEW_VECTOR);
		GET_LABELS(JIT_NEWOBJECT_VALUETYPE);
		GET_LABELS(JIT_IS_INSTANCE);
		GET_LABELS(JIT_LOAD_NULL);
		GET_LABELS(JIT_UNBOX2VALUETYPE);
		GET_LABELS(JIT_UNBOX2OBJECT);
		GET_LABELS(JIT_LOAD_FIELD_ADDR);
		GET_LABELS(JIT_DUP_GENERAL);
		GET_LABELS_DYNAMIC(JIT_POP, 4);
		GET_LABELS(JIT_STORE_OBJECT_VALUETYPE);
		GET_LABELS(JIT_DEREF_CALLVIRT);
		GET_LABELS(JIT_STORE_ELEMENT);
		GET_LABELS(JIT_LEAVE);
		GET_LABELS(JIT_END_FINALLY);
		GET_LABELS(JIT_THROW);
		GET_LABELS(JIT_RETHROW);
		GET_LABELS(JIT_LOADOBJECT);
		GET_LABELS(JIT_LOAD_VECTOR_LEN);
		GET_LABELS(JIT_SWITCH);
		GET_LABELS(JIT_LOAD_ELEMENT_ADDR);
		GET_LABELS(JIT_CALL_INTERFACE);
		GET_LABELS(JIT_CAST_CLASS);
		GET_LABELS(JIT_LOAD_ELEMENT);
		GET_LABELS(JIT_LOADFIELD_VALUETYPE);
		GET_LABELS(JIT_LOADFIELD);
		GET_LABELS(JIT_LOADFUNCTION);
		GET_LABELS(JIT_INVOKE_DELEGATE);
		GET_LABELS(JIT_INVOKE_SYSTEM_REFLECTION_METHODBASE);
		GET_LABELS(JIT_REFLECTION_DYNAMICALLY_BOX_RETURN_VALUE);
		GET_LABELS(JIT_CALL_PINVOKE);
		GET_LABELS_DYNAMIC(JIT_LOAD_I64, 8);
		GET_LABELS(JIT_INIT_OBJECT);
		GET_LABELS_DYNAMIC(JIT_DUP_4, 0);
		GET_LABELS_DYNAMIC(JIT_DUP_8, 0);
		GET_LABELS(JIT_LOADSTATICFIELDADDRESS_CHECKTYPEINIT);
		GET_LABELS_DYNAMIC(JIT_POP_4, 0);
		GET_LABELS_DYNAMIC(JIT_LOAD_F32, 4);

		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_INT32, 4);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_INT64, 4);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_INTNATIVE, 4);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_F32, 4);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_F64, 4);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_PTR, 4);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_O, 4);
		GET_LABELS(JIT_LOADPARAMLOCAL_VALUETYPE);

		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_0, 0);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_1, 0);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_2, 0);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_3, 0);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_4, 0);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_5, 0);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_6, 0);
		GET_LABELS_DYNAMIC(JIT_LOADPARAMLOCAL_7, 0);

		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_INT32, 4);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_INT64, 4);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_INTNATIVE, 4);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_F32, 4);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_F64, 4);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_PTR, 4);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_O, 4);
		GET_LABELS(JIT_STOREPARAMLOCAL_VALUETYPE);

		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_0, 0);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_1, 0);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_2, 0);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_3, 0);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_4, 0);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_5, 0);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_6, 0);
		GET_LABELS_DYNAMIC(JIT_STOREPARAMLOCAL_7, 0);

		GET_LABELS(JIT_STOREFIELD_INT32);
		GET_LABELS(JIT_STOREFIELD_INT64);
		GET_LABELS(JIT_STOREFIELD_INTNATIVE);
		GET_LABELS(JIT_STOREFIELD_F32);
		GET_LABELS(JIT_STOREFIELD_F64);
		GET_LABELS(JIT_STOREFIELD_PTR);
		GET_LABELS(JIT_STOREFIELD_O);
		GET_LABELS(JIT_STOREFIELD_VALUETYPE);

		GET_LABELS(JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT32);
		GET_LABELS(JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT64);
		GET_LABELS(JIT_LOADSTATICFIELD_CHECKTYPEINIT_INTNATIVE);
		GET_LABELS(JIT_LOADSTATICFIELD_CHECKTYPEINIT_F32);
		GET_LABELS(JIT_LOADSTATICFIELD_CHECKTYPEINIT_F64);
		GET_LABELS(JIT_LOADSTATICFIELD_CHECKTYPEINIT_PTR);
		GET_LABELS(JIT_LOADSTATICFIELD_CHECKTYPEINIT_O);
		GET_LABELS(JIT_LOADSTATICFIELD_CHECKTYPEINIT_VALUETYPE);

		GET_LABELS(JIT_STORESTATICFIELD_INT32);
		GET_LABELS(JIT_STORESTATICFIELD_INT64);
		GET_LABELS(JIT_STORESTATICFIELD_INTNATIVE);
		GET_LABELS(JIT_STORESTATICFIELD_F32);
		GET_LABELS(JIT_STORESTATICFIELD_F64);
		GET_LABELS(JIT_STORESTATICFIELD_PTR);
		GET_LABELS(JIT_STORESTATICFIELD_O);
		GET_LABELS(JIT_STORESTATICFIELD_VALUETYPE);

		GET_LABELS(JIT_BOX_INT32);
		GET_LABELS(JIT_BOX_INT64);
		GET_LABELS(JIT_BOX_INTNATIVE);
		GET_LABELS(JIT_BOX_F32);
		GET_LABELS(JIT_BOX_F64);
		GET_LABELS(JIT_BOX_O);
		GET_LABELS(JIT_BOX_VALUETYPE);

		GET_LABELS_DYNAMIC(JIT_CEQ_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_CGT_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_CGT_UN_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_CLT_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_CLT_UN_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_CEQ_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_CGT_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_CGT_UN_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_CLT_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_CLT_UN_I64I64, 0);

		GET_LABELS_DYNAMIC(JIT_ADD_OVF_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_ADD_OVF_UN_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_MUL_OVF_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_MUL_OVF_UN_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_SUB_OVF_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_SUB_OVF_UN_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_ADD_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_SUB_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_MUL_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_DIV_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_DIV_UN_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_REM_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_REM_UN_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_AND_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_OR_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_XOR_I32I32, 0);
		GET_LABELS_DYNAMIC(JIT_NEG_I32, 0);
		GET_LABELS_DYNAMIC(JIT_NOT_I32, 0);
		GET_LABELS_DYNAMIC(JIT_NEG_I64, 0);
		GET_LABELS_DYNAMIC(JIT_NOT_I64, 0);
		GET_LABELS_DYNAMIC(JIT_NEG_F32, 0);
		GET_LABELS_DYNAMIC(JIT_NEG_F64, 0);

		GET_LABELS(JIT_BOX_NULLABLE);
		GET_LABELS_DYNAMIC(JIT_LOAD_F64, 8);
		GET_LABELS(JIT_UNBOX_NULLABLE);

		GET_LABELS(JIT_BEQ_I32I32);
		GET_LABELS(JIT_BEQ_I64I64);
		GET_LABELS(JIT_BEQ_F32F32);
		GET_LABELS(JIT_BEQ_F64F64);

		GET_LABELS(JIT_BGE_I32I32);
		GET_LABELS(JIT_BGE_I64I64);
		GET_LABELS(JIT_BGE_F32F32);
		GET_LABELS(JIT_BGE_F64F64);
		GET_LABELS(JIT_BGE_UN_I32I32);
		GET_LABELS(JIT_BGE_UN_I64I64);
		GET_LABELS(JIT_BGE_UN_F32F32);
		GET_LABELS(JIT_BGE_UN_F64F64);

		GET_LABELS(JIT_BGT_I32I32);
		GET_LABELS(JIT_BGT_I64I64);
		GET_LABELS(JIT_BGT_F32F32);
		GET_LABELS(JIT_BGT_F64F64);
		GET_LABELS(JIT_BGT_UN_I32I32);
		GET_LABELS(JIT_BGT_UN_I64I64);
		GET_LABELS(JIT_BGT_UN_F32F32);
		GET_LABELS(JIT_BGT_UN_F64F64);

		GET_LABELS(JIT_BLE_I32I32);
		GET_LABELS(JIT_BLE_I64I64);
		GET_LABELS(JIT_BLE_F32F32);
		GET_LABELS(JIT_BLE_F64F64);
		GET_LABELS(JIT_BLE_UN_I32I32);
		GET_LABELS(JIT_BLE_UN_I64I64);
		GET_LABELS(JIT_BLE_UN_F32F32);
		GET_LABELS(JIT_BLE_UN_F64F64);

		GET_LABELS(JIT_BLT_I32I32);
		GET_LABELS(JIT_BLT_I64I64);
		GET_LABELS(JIT_BLT_F32F32);
		GET_LABELS(JIT_BLT_F64F64);
		GET_LABELS(JIT_BLT_UN_I32I32);
		GET_LABELS(JIT_BLT_UN_I64I64);
		GET_LABELS(JIT_BLT_UN_F32F32);
		GET_LABELS(JIT_BLT_UN_F64F64);

		GET_LABELS(JIT_BNE_UN_I32I32);
		GET_LABELS(JIT_BNE_UN_I64I64);
		GET_LABELS(JIT_BNE_UN_F32F32);
		GET_LABELS(JIT_BNE_UN_F64F64);

		GET_LABELS_DYNAMIC(JIT_SHL_I32, 0);
		GET_LABELS_DYNAMIC(JIT_SHR_I32, 0);
		GET_LABELS_DYNAMIC(JIT_SHR_UN_I32, 0);
		GET_LABELS_DYNAMIC(JIT_SHL_I64, 0);
		GET_LABELS_DYNAMIC(JIT_SHR_I64, 0);
		GET_LABELS_DYNAMIC(JIT_SHR_UN_I64, 0);

		GET_LABELS(JIT_BRANCH_FALSE);
		GET_LABELS(JIT_BRANCH_TRUE);
		GET_LABELS(JIT_BRANCH64_FALSE);
		GET_LABELS(JIT_BRANCH64_TRUE);

		GET_LABELS(JIT_LOADTOKEN_TYPE);
		GET_LABELS(JIT_LOADTOKEN_FIELD);

		GET_LABELS(JIT_LOADINDIRECT_I8);
		GET_LABELS(JIT_LOADINDIRECT_U8);
		GET_LABELS(JIT_LOADINDIRECT_I16);
		GET_LABELS(JIT_LOADINDIRECT_U16);
		GET_LABELS(JIT_LOADINDIRECT_I32);
		GET_LABELS(JIT_LOADINDIRECT_U32);
		GET_LABELS(JIT_LOADINDIRECT_I64);

		GET_LABELS(JIT_LOADINDIRECT_R32);
		GET_LABELS(JIT_LOADINDIRECT_R64);
		GET_LABELS(JIT_LOADINDIRECT_REF);
		GET_LABELS(JIT_STOREINDIRECT_REF);
		GET_LABELS(JIT_STOREINDIRECT_U8);
		GET_LABELS(JIT_STOREINDIRECT_U16);
		GET_LABELS(JIT_STOREINDIRECT_U32);

		GET_LABELS_DYNAMIC(JIT_CONV_I32_I32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_I32_U32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_I32_I64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_I32_U64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_I32_R32, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_I32_R64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_U32_I32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_U32_U32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_U32_I64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_U32_U64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_U32_R32, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_U32_R64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_I64_I32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_I64_U32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_I64_I64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_I64_U64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_I64_R32, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_I64_R64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_U64_I32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_U64_U32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_U64_I64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_U64_U64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_U64_R32, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_U64_R64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_R32_I32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_R32_U32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_R32_I64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_R32_U64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_R32_R32, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_R32_R64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_R64_I32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_R64_U32, 4);
		GET_LABELS_DYNAMIC(JIT_CONV_R64_I64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_R64_U64, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_R64_R32, 0);
		GET_LABELS_DYNAMIC(JIT_CONV_R64_R64, 0);

		GET_LABELS(JIT_STORE_ELEMENT_32);
		GET_LABELS(JIT_STORE_ELEMENT_64);

		GET_LABELS(JIT_LOAD_ELEMENT_I8);
		GET_LABELS(JIT_LOAD_ELEMENT_U8);
		GET_LABELS(JIT_LOAD_ELEMENT_I16);
		GET_LABELS(JIT_LOAD_ELEMENT_U16);
		GET_LABELS(JIT_LOAD_ELEMENT_I32);
		GET_LABELS(JIT_LOAD_ELEMENT_U32);
		GET_LABELS(JIT_LOAD_ELEMENT_I64);
		GET_LABELS(JIT_LOAD_ELEMENT_U64);
		GET_LABELS(JIT_LOAD_ELEMENT_R32);
		GET_LABELS(JIT_LOAD_ELEMENT_R64);

		GET_LABELS_DYNAMIC(JIT_ADD_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_SUB_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_MUL_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_DIV_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_DIV_UN_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_REM_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_REM_UN_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_AND_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_OR_I64I64, 0);
		GET_LABELS_DYNAMIC(JIT_XOR_I64I64, 0);

		GET_LABELS_DYNAMIC(JIT_CEQ_F32F32, 0);
		GET_LABELS_DYNAMIC(JIT_CGT_F32F32, 0);
		GET_LABELS_DYNAMIC(JIT_CLT_F32F32, 0);
		GET_LABELS_DYNAMIC(JIT_CEQ_F64F64, 0);
		GET_LABELS_DYNAMIC(JIT_CGT_F64F64, 0);
		GET_LABELS_DYNAMIC(JIT_CLT_F64F64, 0);

		GET_LABELS_DYNAMIC(JIT_ADD_F32F32, 0);
		GET_LABELS_DYNAMIC(JIT_ADD_F64F64, 0);
		GET_LABELS_DYNAMIC(JIT_SUB_F32F32, 0);
		GET_LABELS_DYNAMIC(JIT_SUB_F64F64, 0);
		GET_LABELS_DYNAMIC(JIT_MUL_F32F32, 0);
		GET_LABELS_DYNAMIC(JIT_MUL_F64F64, 0);
		GET_LABELS_DYNAMIC(JIT_DIV_F32F32, 0);
		GET_LABELS_DYNAMIC(JIT_DIV_F64F64, 0);

		GET_LABELS_DYNAMIC(JIT_LOAD_I4_M1, 0);
		GET_LABELS_DYNAMIC(JIT_LOAD_I4_0, 0);
		GET_LABELS_DYNAMIC(JIT_LOAD_I4_1, 0);
		GET_LABELS_DYNAMIC(JIT_LOAD_I4_2, 0);

		GET_LABELS_DYNAMIC(JIT_LOADFIELD_4, 4);

		return 0;
	}

#ifdef DIAG_OPCODE_TIMES
	U64 opcodeStartTime = rdtsc();
	U32 realOp;
#endif // DIAG_OPCODE_TIMES

	LOAD_METHOD_STATE();

	GO_NEXT();

noCode:
	Crash("No code for op-code");

JIT_NOP_start:
JIT_CONV_R32_R32_start:
JIT_CONV_R64_R64_start:
JIT_CONV_I64_I64_start:
JIT_CONV_I64_U64_start:
JIT_CONV_U64_I64_start:
JIT_CONV_U64_U64_start:
	OPCODE_USE(JIT_NOP);
JIT_NOP_end:
JIT_CONV_R32_R32_end:
JIT_CONV_R64_R64_end:
JIT_CONV_I64_I64_end:
JIT_CONV_I64_U64_end:
JIT_CONV_U64_I64_end:
JIT_CONV_U64_U64_end:
JIT_GoNext_start:
	GO_NEXT();
JIT_GoNext_end:

JIT_LOAD_NULL_start:
	OPCODE_USE(JIT_LOAD_NULL);
	PUSH_O(NULL);
JIT_LOAD_NULL_end:
	GO_NEXT();

JIT_DUP_4_start:
	OPCODE_USE(JIT_DUP_4);
	DUP4();
JIT_DUP_4_end:
	GO_NEXT();

JIT_DUP_8_start:
	OPCODE_USE(JIT_DUP_8);
	DUP8();
JIT_DUP_8_end:
	GO_NEXT();

JIT_DUP_GENERAL_start:
	OPCODE_USE(JIT_DUP_GENERAL);
	{
		U32 dupSize = GET_OP_32( 0 );
		DUP(dupSize);
	}
JIT_DUP_GENERAL_end:
	GO_NEXT();

JIT_POP_start:
	OPCODE_USE(JIT_POP);
	{
		U32 popSize = GET_OP_32( 0 );
		POP(popSize);
	}
JIT_POP_end:
	GO_NEXT();

JIT_POP_4_start:
	OPCODE_USE(JIT_POP_4);
	POP(4);
JIT_POP_4_end:
	GO_NEXT();

JIT_LOAD_I32_start:
JIT_LOAD_F32_start:
	OPCODE_USE(JIT_LOAD_I32);
	{
		I32 value = GET_OP_32( 0 );
		PUSH_U32(value);
	}
JIT_LOAD_I32_end:
JIT_LOAD_F32_end:
	GO_NEXT();

JIT_LOAD_I4_M1_start:
	OPCODE_USE(JIT_LOAD_I4_M1);
	PUSH_U32(-1);
JIT_LOAD_I4_M1_end:
	GO_NEXT();

JIT_LOAD_I4_0_start:
	OPCODE_USE(JIT_LOAD_I4_0);
	PUSH_U32(0);
JIT_LOAD_I4_0_end:
	GO_NEXT();

JIT_LOAD_I4_1_start:
	OPCODE_USE(JIT_LOAD_I4_1);
	PUSH_U32(1);
JIT_LOAD_I4_1_end:
	GO_NEXT();

JIT_LOAD_I4_2_start:
	OPCODE_USE(JIT_LOAD_I4_2);
	PUSH_U32(2);
JIT_LOAD_I4_2_end:
	GO_NEXT();

JIT_LOAD_I64_start:
JIT_LOAD_F64_start:
	OPCODE_USE(JIT_LOAD_I64);
	{
		U64 value = (U64)GET_OP_64( JITOPS_TYPE_VAL_64 );
		PUSH_U64(value);
	}
JIT_LOAD_I64_end:
JIT_LOAD_F64_end:
	GO_NEXT();

JIT_LOADPARAMLOCAL_INT32_start:
	op = JIT_LOADPARAMLOCAL_INT32;
	goto allLoadPrmLoc32Start;
JIT_LOADPARAMLOCAL_F32_start:
	op = JIT_LOADPARAMLOCAL_F32;
	goto allLoadPrmLoc32Start;
JIT_LOADPARAMLOCAL_INTNATIVE_start: // Only on 32-bit?
	op = JIT_LOADPARAMLOCAL_INTNATIVE;
	goto allLoadPrmLoc32Start;
allLoadPrmLoc32Start:
	OPCODE_USE( op );
	{
		U32 ofs = GET_OP_32( 0 );
		U32 value = PARAMLOCAL_U32(ofs);
		PUSH_U32(value);
	}
JIT_LOADPARAMLOCAL_INT32_end:
JIT_LOADPARAMLOCAL_F32_end:
JIT_LOADPARAMLOCAL_INTNATIVE_end:
	GO_NEXT();

JIT_LOADPARAMLOCAL_INT64_start:
	op = JIT_LOADPARAMLOCAL_INT64;
	goto allLoadPrmLoc64Start;
JIT_LOADPARAMLOCAL_F64_start:
	op = JIT_LOADPARAMLOCAL_F64;
	goto allLoadPrmLoc64Start;
JIT_LOADPARAMLOCAL_O_start: // 64bit only.
	op = JIT_LOADPARAMLOCAL_O;
	goto allLoadPrmLoc64Start;
JIT_LOADPARAMLOCAL_PTR_start: // 64bit only.
	op = JIT_LOADPARAMLOCAL_PTR;
	goto allLoadPrmLoc64Start;
allLoadPrmLoc64Start:
	OPCODE_USE( op );
	{
		U32 ofs = GET_OP_32( 0 );
		U64 value = PARAMLOCAL_U64(ofs);
		PUSH_U64(value);
	}
JIT_LOADPARAMLOCAL_INT64_end:
JIT_LOADPARAMLOCAL_F64_end:
JIT_LOADPARAMLOCAL_O_end: // 64bit only.
JIT_LOADPARAMLOCAL_PTR_end: // 64bit only.
	GO_NEXT();

JIT_LOADPARAMLOCAL_VALUETYPE_start:
	OPCODE_USE(JIT_LOADPARAMLOCAL_VALUETYPE);
	{
		tMD_TypeDef *pTypeDef;
		U32 ofs;
		PTR pMem;

		ofs = GET_OP_32( 0 );
		pTypeDef = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );
		pMem = pParamsLocals + ofs;
		PUSH_VALUETYPE(pMem, pTypeDef->stackSize, pTypeDef->stackSize);
	}
JIT_LOADPARAMLOCAL_VALUETYPE_end:
	GO_NEXT();

JIT_LOADPARAMLOCAL_0_start:
	OPCODE_USE(JIT_LOADPARAMLOCAL_0);
	PUSH_U32(PARAMLOCAL_U32(0));
JIT_LOADPARAMLOCAL_0_end:
	GO_NEXT();

JIT_LOADPARAMLOCAL_1_start:
	OPCODE_USE(JIT_LOADPARAMLOCAL_1);
	PUSH_U32(PARAMLOCAL_U32(4));
JIT_LOADPARAMLOCAL_1_end:
	GO_NEXT();

JIT_LOADPARAMLOCAL_2_start:
	OPCODE_USE(JIT_LOADPARAMLOCAL_2);
	PUSH_U32(PARAMLOCAL_U32(8));
JIT_LOADPARAMLOCAL_2_end:
	GO_NEXT();

JIT_LOADPARAMLOCAL_3_start:
	OPCODE_USE(JIT_LOADPARAMLOCAL_3);
	PUSH_U32(PARAMLOCAL_U32(12));
JIT_LOADPARAMLOCAL_3_end:
	GO_NEXT();

JIT_LOADPARAMLOCAL_4_start:
	OPCODE_USE(JIT_LOADPARAMLOCAL_4);
	PUSH_U32(PARAMLOCAL_U32(16));
JIT_LOADPARAMLOCAL_4_end:
	GO_NEXT();

JIT_LOADPARAMLOCAL_5_start:
	OPCODE_USE(JIT_LOADPARAMLOCAL_5);
	PUSH_U32(PARAMLOCAL_U32(20));
JIT_LOADPARAMLOCAL_5_end:
	GO_NEXT();

JIT_LOADPARAMLOCAL_6_start:
	OPCODE_USE(JIT_LOADPARAMLOCAL_6);
	PUSH_U32(PARAMLOCAL_U32(24));
JIT_LOADPARAMLOCAL_6_end:
	GO_NEXT();

JIT_LOADPARAMLOCAL_7_start:
	OPCODE_USE(JIT_LOADPARAMLOCAL_7);
	PUSH_U32(PARAMLOCAL_U32(28));
JIT_LOADPARAMLOCAL_7_end:
	GO_NEXT();

JIT_LOAD_PARAMLOCAL_ADDR_start:
	OPCODE_USE(JIT_LOAD_PARAMLOCAL_ADDR);
	{
		U32 ofs = GET_OP_32( 0 );
		PTR pMem = pParamsLocals + ofs;
		PUSH_PTR(pMem);
	}
JIT_LOAD_PARAMLOCAL_ADDR_end:
	GO_NEXT();

JIT_STOREPARAMLOCAL_INT32_start:
	op = JIT_STOREPARAMLOCAL_INT32;
	goto allStorePrmLoc32Start;
JIT_STOREPARAMLOCAL_F32_start:
	op = JIT_STOREPARAMLOCAL_F32;
	goto allStorePrmLoc32Start;
JIT_STOREPARAMLOCAL_INTNATIVE_start: // Only on 32-bit?
	op = JIT_STOREPARAMLOCAL_INTNATIVE;
	goto allStorePrmLoc32Start;
allStorePrmLoc32Start:
	OPCODE_USE( op );
	{
		U32 ofs = GET_OP_32( 0 );
		U32 value = POP_U32();
		PARAMLOCAL_U32(ofs) = value;
	}
JIT_STOREPARAMLOCAL_INT32_end:
JIT_STOREPARAMLOCAL_F32_end:
JIT_STOREPARAMLOCAL_INTNATIVE_end:
	GO_NEXT();

JIT_STOREPARAMLOCAL_INT64_start:
	op = JIT_STOREPARAMLOCAL_INT64;
	goto allStorePrmLoc64Start;
JIT_STOREPARAMLOCAL_F64_start:
	op = JIT_STOREPARAMLOCAL_F64;
	goto allStorePrmLoc64Start;
JIT_STOREPARAMLOCAL_O_start: // 64bit only.
	op = JIT_STOREPARAMLOCAL_O;
	goto allStorePrmLoc64Start;
JIT_STOREPARAMLOCAL_PTR_start: // 64bit only.
	op = JIT_STOREPARAMLOCAL_PTR;
	goto allStorePrmLoc64Start;
allStorePrmLoc64Start:
	OPCODE_USE( op );
	{
		U32 ofs = GET_OP_32( 0 );
		U64 value = POP_U64();
		PARAMLOCAL_U64(ofs) = value;
	}
JIT_STOREPARAMLOCAL_INT64_end:
JIT_STOREPARAMLOCAL_F64_end:
JIT_STOREPARAMLOCAL_O_end: // 64bit only.
JIT_STOREPARAMLOCAL_PTR_end: // 64bit only.
	GO_NEXT();

JIT_STOREPARAMLOCAL_VALUETYPE_start:
	OPCODE_USE(JIT_STOREPARAMLOCAL_VALUETYPE);
	{
		tMD_TypeDef *pTypeDef;
		U32 ofs;
		PTR pMem;

		ofs = GET_OP_32( 0 );
		pTypeDef = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );
		pMem = pParamsLocals + ofs;
		POP_VALUETYPE(pMem, pTypeDef->stackSize, pTypeDef->stackSize);
	}
JIT_STOREPARAMLOCAL_VALUETYPE_end:
	GO_NEXT();

JIT_STOREPARAMLOCAL_0_start:
	OPCODE_USE(JIT_STOREPARAMLOCAL_0);
	PARAMLOCAL_U32(0) = POP_U32();
JIT_STOREPARAMLOCAL_0_end:
	GO_NEXT();

JIT_STOREPARAMLOCAL_1_start:
	OPCODE_USE(JIT_STOREPARAMLOCAL_1);
	PARAMLOCAL_U32(4) = POP_U32();
JIT_STOREPARAMLOCAL_1_end:
	GO_NEXT();

JIT_STOREPARAMLOCAL_2_start:
	OPCODE_USE(JIT_STOREPARAMLOCAL_2);
	PARAMLOCAL_U32(8) = POP_U32();
JIT_STOREPARAMLOCAL_2_end:
	GO_NEXT();

JIT_STOREPARAMLOCAL_3_start:
	OPCODE_USE(JIT_STOREPARAMLOCAL_3);
	PARAMLOCAL_U32(12) = POP_U32();
JIT_STOREPARAMLOCAL_3_end:
	GO_NEXT();

JIT_STOREPARAMLOCAL_4_start:
	OPCODE_USE(JIT_STOREPARAMLOCAL_4);
	PARAMLOCAL_U32(16) = POP_U32();
JIT_STOREPARAMLOCAL_4_end:
	GO_NEXT();

JIT_STOREPARAMLOCAL_5_start:
	OPCODE_USE(JIT_STOREPARAMLOCAL_5);
	PARAMLOCAL_U32(20) = POP_U32();
JIT_STOREPARAMLOCAL_5_end:
	GO_NEXT();

JIT_STOREPARAMLOCAL_6_start:
	OPCODE_USE(JIT_STOREPARAMLOCAL_6);
	PARAMLOCAL_U32(24) = POP_U32();
JIT_STOREPARAMLOCAL_6_end:
	GO_NEXT();

JIT_STOREPARAMLOCAL_7_start:
	OPCODE_USE(JIT_STOREPARAMLOCAL_7);
	PARAMLOCAL_U32(28) = POP_U32();
JIT_STOREPARAMLOCAL_7_end:
	GO_NEXT();

JIT_LOADINDIRECT_I8_start:
JIT_LOADINDIRECT_I16_start:
JIT_LOADINDIRECT_I32_start:
JIT_LOADINDIRECT_U8_start:
JIT_LOADINDIRECT_U16_start:
JIT_LOADINDIRECT_U32_start:
JIT_LOADINDIRECT_R32_start:
//JIT_LOADINDIRECT_REF_start: // 32bit only.
	OPCODE_USE(JIT_LOADINDIRECT_U32);
	{
		PTR pMem = POP_PTR();
		U32 value = *(U32*)pMem;
		PUSH_U32(value);
	}
JIT_LOADINDIRECT_I8_end:
JIT_LOADINDIRECT_I16_end:
JIT_LOADINDIRECT_I32_end:
JIT_LOADINDIRECT_U8_end:
JIT_LOADINDIRECT_U16_end:
JIT_LOADINDIRECT_U32_end:
JIT_LOADINDIRECT_R32_end:
//JIT_LOADINDIRECT_REF_end: // 32bit only.
	GO_NEXT();

JIT_LOADINDIRECT_R64_start:
JIT_LOADINDIRECT_I64_start:
JIT_LOADINDIRECT_REF_start: // 64bit only.
	OPCODE_USE(JIT_LOADINDIRECT_I64);
	{
		PTR pMem = POP_PTR();
		U64 value = *(U64*)pMem;
		PUSH_U64(value);
	}
JIT_LOADINDIRECT_R64_end:
JIT_LOADINDIRECT_I64_end:
JIT_LOADINDIRECT_REF_end: // 64bit only.
	GO_NEXT();

JIT_STOREINDIRECT_U8_start:
JIT_STOREINDIRECT_U16_start:
JIT_STOREINDIRECT_U32_start:
//JIT_STOREINDIRECT_REF_start: // 32bit only.
	OPCODE_USE(JIT_STOREINDIRECT_U32);
	{
		U32 value = POP_U32(); // The value to store
		PTR pMem = POP_PTR(); // The address to store to
		*(U32*)pMem = value;
	}
JIT_STOREINDIRECT_U8_end:
JIT_STOREINDIRECT_U16_end:
JIT_STOREINDIRECT_U32_end:
//JIT_STOREINDIRECT_REF_end: // 32bit only.
	GO_NEXT();

JIT_STOREINDIRECT_REF_start: // 64bit only.
	OPCODE_USE(JIT_STOREINDIRECT_REF);
	{
		U64 value = POP_U64(); // The value to store
		PTR pMem = POP_PTR(); // The address to store to
		*(U64*)pMem = value;
	}
JIT_STOREINDIRECT_REF_end: // 64bit only.
	GO_NEXT();

JIT_STORE_OBJECT_VALUETYPE_start:
	OPCODE_USE(JIT_STORE_OBJECT_VALUETYPE);
	{
		U32 size = GET_OP_32( 0 ); // The size, in bytes, of the value-type to store
		U32 memSize = ( size < 4 ) ? 4 : size;
		PTR pMem = pCurEvalStack - memSize - sizeof(void*);
		POP_VALUETYPE(*(void**)pMem, size, memSize);
		POP(4);
	}
JIT_STORE_OBJECT_VALUETYPE_end:
	GO_NEXT();

JIT_CALL_PINVOKE_start:
	OPCODE_USE(JIT_CALL_PINVOKE);
	{
		tJITCallPInvoke *pCallPInvoke;
		U32 res;

		int stepBack = 2; // the current opcode was 2x U32 value in JIT Ops table.

		pCallPInvoke = (tJITCallPInvoke*)(pCurOp - stepBack);
		res = PInvoke_Call(pCallPInvoke, pParamsLocals, pCurrentMethodState->pEvalStack, pThread);
		pCurrentMethodState->stackOfs = res;
	}
	goto JIT_RETURN_start;
JIT_CALL_PINVOKE_end:

JIT_CALL_NATIVE_start:
	OPCODE_USE(JIT_CALL_NATIVE);
	{
		tJITCallNative *pCallNative;
		PTR pThis;
		U32 thisOfs;
		tAsyncCall *pAsync;

		int stepBack = 2; // the current opcode was 2x U32 value in JIT Ops table.

		//pCallNative = (tJITCallNative*)&(pJIT->pOps[pCurrentMethodState->ipOffset - stepBack]);
		pCallNative = (tJITCallNative*)(pCurOp - stepBack);
		if (METHOD_ISSTATIC(pCallNative->pMethodDef)) {
			pThis = NULL;
			thisOfs = 0;
		} else {
			pThis = *(PTR*)pCurrentMethodState->pParamsLocals;
			thisOfs = sizeof(void*);
		}
		// Internal constructors MUST leave the newly created object in the return value
		// (ie on top of the evaluation stack)
		pAsync = pCallNative->fn(pThis, pCurrentMethodState->pParamsLocals + thisOfs, pCurrentMethodState->pEvalStack);
		if (pAsync != NULL) {
			// Save the method state
			SAVE_METHOD_STATE();
			// Change the IP pointer to point to the return instruction
			pCurrentMethodState->ipOffset = 3;
			// Handle special async codes
			if (pAsync == ASYNC_LOCK_EXIT) {
				return THREAD_STATUS_LOCK_EXIT;
			}
			// Set the async in the thread
			pThread->pAsync = pAsync;
			return THREAD_STATUS_ASYNC;
		}
	}
	// fall-through
JIT_CALL_NATIVE_end:

JIT_RETURN_start:
	OPCODE_USE(JIT_RETURN);
	log_f( 3, "Returned from %s() to %s()\n", pCurrentMethodState->pMethod->name, (pCurrentMethodState->pCaller) ? pCurrentMethodState->pCaller->pMethod->name : "<none>" );
	if (pCurrentMethodState->pCaller == NULL) {
		// End of thread!
		if (pCurrentMethodState->pMethod->pReturnType == types[TYPE_SYSTEM_INT32]) {
			// If function returned an int32, then make it the thread exit-value
			pThread->threadExitValue = (I32)POP_U32();
		}
		return THREAD_STATUS_EXIT;
	}

#ifdef ENABLE_STACKITEMS_TYPEINFO
	int stackItemType = STACKITEM_TYPE_POINTER; // default value for internal-call.
#endif // ENABLE_STACKITEMS_TYPEINFO

	// Make u32Value the number of bytes of the return value from the function
	if (pCurrentMethodState->pMethod->pReturnType != NULL) {
		u32Value = pCurrentMethodState->pMethod->pReturnType->stackSize;

#ifdef ENABLE_STACKITEMS_TYPEINFO

		// use the method return type to determine stackItemType.

	//	if ( pCurrentMethodState->pMethod->pReturnType->isValueType ) { // simple
	//		int stackItemType = STACKITEM_TYPE_VALUETYPE;
	//	}

		switch ( pCurrentMethodState->pMethod->pReturnType->stackType ) { // more precise
			case EVALSTACK_O:
			case EVALSTACK_PTR:
			stackItemType = STACKITEM_TYPE_POINTER;
			break;

			case EVALSTACK_VALUETYPE:
			stackItemType = STACKITEM_TYPE_VALUETYPE;
			break;

			default:
			stackItemType = STACKITEM_TYPE_VALUE;
		}

#endif // ENABLE_STACKITEMS_TYPEINFO

	} else if (pCurrentMethodState->isInternalNewObjCall) {
		u32Value = sizeof(void*);
	} else {
		u32Value = 0;
	}
	pMem = pCurrentMethodState->pEvalStack;
	{
		tMethodState *pOldMethodState = pCurrentMethodState;
		pThread->pCurrentMethodState = pCurrentMethodState->pCaller;
		LOAD_METHOD_STATE();
		// Copy return value to callers evaluation stack
		if (u32Value > 0) {
			memmove(pCurEvalStack, pMem, u32Value);
			pCurEvalStack += u32Value;

#ifdef ENABLE_STACKITEMS_TYPEINFO
PUSH_EVALSTACKITEM_TYPE( u32Value, -u32Value, stackItemType );
#endif // ENABLE_STACKITEMS_TYPEINFO

		}
		// Delete the current method state and go back to callers method state
		MethodState_Delete(pThread, &pOldMethodState);
	}
	if (pCurrentMethodState->pNextDelegate == NULL) {
		GO_NEXT();
	}
	// Fall-through if more delegate methods to invoke
JIT_RETURN_end:

JIT_INVOKE_DELEGATE_start:
	OPCODE_USE(JIT_INVOKE_DELEGATE);
	{
		tMD_MethodDef *pDelegateMethod, *pCallMethod;
		void *pDelegate;
		HEAP_PTR pDelegateThis;
		tMethodState *pCallMethodState;
		U32 ofs;

		if (pCurrentMethodState->pNextDelegate == NULL) {
			// First delegate, so get the Invoke() method defined within the delegate class
			pDelegateMethod = (tMD_MethodDef*)GET_OP_64( checkPointerTypes );
			// Take the params off the stack. This is the pointer to the tDelegate & params
			//pCurrentMethodState->stackOfs -= pDelegateMethod->parameterStackSize;
			pCurEvalStack -= pDelegateMethod->parameterStackSize;
			// Allocate memory for delegate params
			pCurrentMethodState->pDelegateParams = malloc(pDelegateMethod->parameterStackSize - sizeof(void*));
			memcpy(
				pCurrentMethodState->pDelegateParams,
				//pCurrentMethodState->pEvalStack + pCurrentMethodState->stackOfs + sizeof(void*),
				pCurEvalStack + sizeof(void*),
				pDelegateMethod->parameterStackSize - sizeof(void*));
			// Get the actual delegate heap pointer
			pDelegate = *(void**)pCurEvalStack;
		} else {
			pDelegateMethod = Delegate_GetMethod(pCurrentMethodState->pNextDelegate);
			if (pDelegateMethod->pReturnType != NULL) {
				pCurEvalStack -= pDelegateMethod->pReturnType->stackSize;
			}
			// Get the actual delegate heap pointer
			pDelegate = pCurrentMethodState->pNextDelegate;
		}
		if (pDelegate == NULL) {
			THROW(types[TYPE_SYSTEM_NULLREFERENCEEXCEPTION]);
		}
		// Get the real method to call; the target of the delegate.
		pCallMethod = Delegate_GetMethodAndStore(pDelegate, &pDelegateThis, &pCurrentMethodState->pNextDelegate);
		// Set up the call method state for the call.
		pCallMethodState = MethodState_Direct(pThread, pCallMethod, pCurrentMethodState, 0);
		if (pDelegateThis != NULL) {
			*(HEAP_PTR*)pCallMethodState->pParamsLocals = pDelegateThis;
			ofs = sizeof(void*);
		} else {
			ofs = 0;
		}
		memcpy(pCallMethodState->pParamsLocals + ofs,
			pCurrentMethodState->pDelegateParams,
			pCallMethod->parameterStackSize - ofs);
		CHANGE_METHOD_STATE(pCallMethodState);
	}
JIT_INVOKE_DELEGATE_end:
	GO_NEXT();

JIT_INVOKE_SYSTEM_REFLECTION_METHODBASE_start:
	OPCODE_USE(JIT_INVOKE_SYSTEM_REFLECTION_METHODBASE);
	{
		// Get the reference to MethodBase.Invoke
		tMD_MethodDef *pInvokeMethod = (tMD_MethodDef*)GET_OP_64( checkPointerTypes );

		// Take the MethodBase.Invoke params off the stack.
		pCurEvalStack -= pInvokeMethod->parameterStackSize;

		// Get a pointer to the MethodBase instance (e.g., a MethodInfo or ConstructorInfo),
		// and from that, determine which method we're going to invoke
		tMethodBase *pMethodBase = *(tMethodBase**)pCurEvalStack;
		tMD_MethodDef *pCallMethod = pMethodBase->methodDef;

		// Store the return type so that JIT_REFLECTION_DYNAMICALLY_BOX_RETURN_VALUE can
		// interpret the stack after the invocation
		pCurrentMethodState->pReflectionInvokeReturnType = pCallMethod->pReturnType;

		// Get the 'this' pointer for the call and the params array
		PTR invocationThis = (PTR)(*(tMethodBase**)(pCurEvalStack + sizeof(HEAP_PTR)));
		HEAP_PTR invocationParamsArray = *(HEAP_PTR*)(pCurEvalStack + sizeof(HEAP_PTR) + sizeof(PTR));		

		// Put the new 'this' on the stack
		PTR pPrevEvalStack = pCurEvalStack;
		PUSH_PTR(invocationThis);

		// Put any other params on the stack
		if (invocationParamsArray != NULL) {
			U32 invocationParamsArrayLength = SystemArray_GetLength(invocationParamsArray);
			PTR invocationParamsArrayElements = SystemArray_GetElements(invocationParamsArray);
			for (U32 paramIndex = 0; paramIndex < invocationParamsArrayLength; paramIndex++) {
				HEAP_PTR currentParam = (HEAP_PTR)(((U32*)(invocationParamsArrayElements))[paramIndex]);
				if (currentParam == NULL) {
					PUSH_O(NULL);
				} else {
					tMD_TypeDef *currentParamType = Heap_GetType(currentParam);

					if (Type_IsValueType(currentParamType)) {
						PUSH_VALUETYPE(currentParam, currentParamType->stackSize, currentParamType->stackSize);
					} else {
						PUSH_O(currentParam);
					}
				}
			}
		}
		pCurEvalStack = pPrevEvalStack;

		// Change interpreter state so we continue execution inside the method being invoked
		tMethodState *pCallMethodState = MethodState_Direct(pThread, pCallMethod, pCurrentMethodState, 0);
		memcpy(pCallMethodState->pParamsLocals, pCurEvalStack, pCallMethod->parameterStackSize);
		CHANGE_METHOD_STATE(pCallMethodState);
	}
JIT_INVOKE_SYSTEM_REFLECTION_METHODBASE_end:
	GO_NEXT();

JIT_REFLECTION_DYNAMICALLY_BOX_RETURN_VALUE_start:
	OPCODE_USE(JIT_REFLECTION_DYNAMICALLY_BOX_RETURN_VALUE);
	{
		tMD_TypeDef *pLastInvocationReturnType = pCurrentMethodState->pReflectionInvokeReturnType;
		if (pLastInvocationReturnType == NULL) {
			// It was a void method, so it won't have put anything on the stack. We need to put
			// a null value there as a return value, because MethodBase.Invoke isn't void.
			PUSH_O(NULL);
		} else if (Type_IsValueType(pLastInvocationReturnType)) {
			// For value types, remove the raw value data from the stack and replace it with a
			// boxed copy, because MethodBase.Invoke returns object.
			HEAP_PTR heapPtr = Heap_AllocType(pLastInvocationReturnType);
			POP_VALUETYPE(heapPtr, pLastInvocationReturnType->stackSize, pLastInvocationReturnType->stackSize);
			PUSH_O(heapPtr);
		}
	}

JIT_REFLECTION_DYNAMICALLY_BOX_RETURN_VALUE_end:
	GO_NEXT_CHECK();

JIT_DEREF_CALLVIRT_start:
	op = JIT_DEREF_CALLVIRT;
	goto allCallStart;
JIT_BOX_CALLVIRT_start:
	op = JIT_BOX_CALLVIRT;
	goto allCallStart;
JIT_CALL_PTR_start: // Note that JIT_CALL_PTR cannot be virtual
	op = JIT_CALL_PTR;
	goto allCallStart;
JIT_CALLVIRT_O_start:
	op = JIT_CALLVIRT_O;
	goto allCallStart;
JIT_CALL_O_start:
	op = JIT_CALL_O;
	goto allCallStart;
JIT_CALL_INTERFACE_start:
	op = JIT_CALL_INTERFACE;
allCallStart:
	OPCODE_USE(JIT_CALL_O);
	{
		tMD_MethodDef *pCallMethod;
		tMethodState *pCallMethodState;
		tMD_TypeDef *pBoxCallType;

		if (op == JIT_BOX_CALLVIRT) {
			pBoxCallType = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );
		}

		pCallMethod = (tMD_MethodDef*)GET_OP_64( checkPointerTypes );
		heapPtr = NULL;

		if (op == JIT_BOX_CALLVIRT) {
			// Need to de-ref and box the value-type before calling the function
			// TODO: Will this work on value-types that are not 4 bytes long?
			pMem = pCurEvalStack - pCallMethod->parameterStackSize;
			heapPtr = Heap_Box(pBoxCallType, *(PTR*)pMem);
			*(HEAP_PTR*)pMem = heapPtr;
		} else if (op == JIT_DEREF_CALLVIRT) {
			pMem = pCurEvalStack - pCallMethod->parameterStackSize;
			*(HEAP_PTR*)pMem = **(HEAP_PTR**)pMem;
		}

		// If it's a virtual call then find the real correct method to call
		if (op == JIT_CALLVIRT_O || op == JIT_BOX_CALLVIRT || op == JIT_DEREF_CALLVIRT) {
			tMD_TypeDef *pThisType;
			// Get the actual object that is becoming 'this'
			if (heapPtr == NULL) {
				heapPtr = *(HEAP_PTR*)(pCurEvalStack - pCallMethod->parameterStackSize);
			}
			if (heapPtr == NULL) {
				//Crash("NULL 'this' in Virtual call: %s", Sys_GetMethodDesc(pCallMethod));
				THROW(types[TYPE_SYSTEM_NULLREFERENCEEXCEPTION]);
			}
			pThisType = Heap_GetType(heapPtr);
			if (METHOD_ISVIRTUAL(pCallMethod)) {
				pCallMethod = pThisType->pVTable[pCallMethod->vTableOfs];
			}
		} else if (op == JIT_CALL_INTERFACE) {
			tMD_TypeDef *pInterface, *pThisType;
			U32 vIndex;
			I32 i;

			pInterface = pCallMethod->pParentType;
			// Get the actual object that is becoming 'this'
			heapPtr = *(HEAP_PTR*)(pCurEvalStack - pCallMethod->parameterStackSize);
			pThisType = Heap_GetType(heapPtr);
			// Find the interface mapping on the 'this' type.
			vIndex = 0xffffffff;
			// This must be searched backwards so if an interface is implemented more than
			// once in the type hierarchy, the most recent definition gets called
			for (i=(I32)pThisType->numInterfaces-1; i >= 0; i--) {
				if (pThisType->pInterfaceMaps[i].pInterface == pInterface) {
					// Found the right interface map
					if (pThisType->pInterfaceMaps[i].pVTableLookup != NULL) {
						vIndex = pThisType->pInterfaceMaps[i].pVTableLookup[pCallMethod->vTableOfs];
						break;
					}
					pCallMethod = pThisType->pInterfaceMaps[i].ppMethodVLookup[pCallMethod->vTableOfs];
					goto callMethodSet;
				}
			}
			Assert(vIndex != 0xffffffff);
			pCallMethod = pThisType->pVTable[vIndex];
		}
callMethodSet:
		log_f( 3, "Calling method: %s\n", Sys_GetMethodDesc(pCallMethod) );
		// Set up the new method state for the called method
		pCallMethodState = MethodState_Direct(pThread, pCallMethod, pCurrentMethodState, 0);
		// Set up the parameter stack for the method being called
		pTempPtr = pCurEvalStack;
		CreateParameters(pCallMethodState, pCallMethod, pCurrentMethodState, &pTempPtr, NULL);
		pCurEvalStack = pTempPtr;
		// Set up the local variables for the new method state
		CHANGE_METHOD_STATE(pCallMethodState);
	}
JIT_DEREF_CALLVIRT_end:
JIT_BOX_CALLVIRT_end:
JIT_CALL_PTR_end:
JIT_CALLVIRT_O_end:
JIT_CALL_O_end:
JIT_CALL_INTERFACE_end:
	GO_NEXT_CHECK();

JIT_BRANCH_start:
	OPCODE_USE(JIT_BRANCH);
	{
		U32 ofs = GET_OP_32( 0 );
		pCurOp = pOps + ofs;
	}
JIT_BRANCH_end:
	GO_NEXT_CHECK();

JIT_SWITCH_start:
	OPCODE_USE(JIT_SWITCH);
	{
		U32 ofs;
		// The number of jump targets
		U32 numTargets = GET_OP_32( 0 );
		// The jump target selected
		U32 target = POP_U32();
		if (target >= numTargets) {
			// This is not a valid jump target, so fall-through
			pCurOp += numTargets;
			goto JIT_SWITCH_end;
		}
		ofs = *(pCurOp + target);
		pCurOp = pOps + ofs;
	}
JIT_SWITCH_end:
	GO_NEXT_CHECK();

JIT_BRANCH_TRUE_start:
	OPCODE_USE(JIT_BRANCH_TRUE);
	{
		U32 value = POP_U32();
		U32 ofs = GET_OP_32( 0 );
		if (value != 0) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BRANCH_TRUE_end:
	GO_NEXT_CHECK();

JIT_BRANCH_FALSE_start:
	OPCODE_USE(JIT_BRANCH_FALSE);
	{
		U32 value = POP_U32();
		U32 ofs = GET_OP_32( 0 );
		if (value == 0) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BRANCH_FALSE_end:
	GO_NEXT_CHECK();

JIT_BRANCH64_TRUE_start:
	OPCODE_USE(JIT_BRANCH64_TRUE);
	{
		U64 value = POP_U64();
		U32 ofs = GET_OP_32( 0 );
		if (value != 0) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BRANCH64_TRUE_end:
	GO_NEXT_CHECK();

JIT_BRANCH64_FALSE_start:
	OPCODE_USE(JIT_BRANCH64_FALSE);
	{
		U64 value = POP_U64();
		U32 ofs = GET_OP_32( 0 );
		if (value == 0) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BRANCH64_FALSE_end:
	GO_NEXT_CHECK();

JIT_BEQ_I32I32_start:
	OPCODE_USE(JIT_BEQ_I32I32);
	{
		U32 v1, v2, ofs;
		POP_U32_U32(v1, v2);
		ofs = GET_OP_32( 0 );
		if ((I32)v1 == (I32)v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BEQ_I32I32_end:
	GO_NEXT_CHECK();

JIT_BEQ_I64I64_start:
	OPCODE_USE(JIT_BEQ_I64I64);
	{
		U64 v1, v2;
		U32 ofs;
		POP_U64_U64(v1, v2);
		ofs = GET_OP_32( 0 );
		if ((I64)v1 == (I64)v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BEQ_I64I64_end:
	GO_NEXT_CHECK();

JIT_BEQ_F32F32_start:
	OPCODE_USE(JIT_BEQ_F32F32);
	{
		float v1, v2;
		U32 ofs;
		POP_F32_F32(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 == v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BEQ_F32F32_end:
	GO_NEXT_CHECK();

JIT_BEQ_F64F64_start:
	OPCODE_USE(JIT_BEQ_F64F64);
	{
		double v1, v2;
		U32 ofs;
		POP_F64_F64(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 == v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BEQ_F64F64_end:
	GO_NEXT_CHECK();

JIT_BGE_I32I32_start:
	OPCODE_USE(JIT_BGE_I32I32);
	{
		U32 v1, v2, ofs;
		POP_U32_U32(v1, v2);
		ofs = GET_OP_32( 0 );
		if ((I32)v1 >= (I32)v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGE_I32I32_end:
	GO_NEXT_CHECK();

JIT_BGE_I64I64_start:
	OPCODE_USE(JIT_BGE_I64I64);
	{
		U64 v1, v2;
		U32 ofs;
		POP_U64_U64(v1, v2);
		ofs = GET_OP_32( 0 );
		if ((I64)v1 >= (I64)v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGE_I64I64_end:
	GO_NEXT_CHECK();

JIT_BGE_F32F32_start:
JIT_BGE_UN_F32F32_start:
	OPCODE_USE(JIT_BGE_F32F32);
	{
		float v1, v2;
		U32 ofs;
		POP_F32_F32(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 >= v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGE_F32F32_end:
JIT_BGE_UN_F32F32_end:
	GO_NEXT_CHECK();

JIT_BGE_F64F64_start:
JIT_BGE_UN_F64F64_start:
	OPCODE_USE(JIT_BGE_F64F64);
	{
		double v1, v2;
		U32 ofs;
		POP_F64_F64(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 >= v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGE_F64F64_end:
JIT_BGE_UN_F64F64_end:
	GO_NEXT_CHECK();

JIT_BGT_I32I32_start:
	OPCODE_USE(JIT_BGT_I32I32);
	{
		U32 v1, v2;
		U32 ofs;
		POP_U32_U32(v1, v2);
		ofs = GET_OP_32( 0 );
		if ((I32)v1 > (I32)v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGT_I32I32_end:
	GO_NEXT_CHECK();

JIT_BGT_I64I64_start:
	OPCODE_USE(JIT_BGT_I64I64);
	{
		U64 v1, v2;
		U32 ofs;
		POP_U64_U64(v1, v2);
		ofs = GET_OP_32( 0 );
		if ((I64)v1 > (I64)v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGT_I64I64_end:
	GO_NEXT_CHECK();

JIT_BGT_F32F32_start:
JIT_BGT_UN_F32F32_start:
	OPCODE_USE(JIT_BGT_F32F32);
	{
		float v1, v2;
		U32 ofs;
		POP_F32_F32(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 > v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGT_F32F32_end:
JIT_BGT_UN_F32F32_end:
	GO_NEXT_CHECK();

JIT_BGT_F64F64_start:
JIT_BGT_UN_F64F64_start:
	OPCODE_USE(JIT_BGT_F64F64);
	{
		double v1, v2;
		U32 ofs;
		POP_F64_F64(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 > v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGT_F64F64_end:
JIT_BGT_UN_F64F64_end:
	GO_NEXT_CHECK();

JIT_BLE_I32I32_start:
	OPCODE_USE(JIT_BLE_I32I32);
	{
		U32 v1, v2;
		U32 ofs;
		POP_U32_U32(v1, v2);
		ofs = GET_OP_32( 0 );
		if ((I32)v1 <= (I32)v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLE_I32I32_end:
	GO_NEXT_CHECK();

JIT_BLE_I64I64_start:
	OPCODE_USE(JIT_BLE_I64I64);
	{
		U64 v1, v2;
		U32 ofs;
		POP_U64_U64(v1, v2);
		ofs = GET_OP_32( 0 );
		if ((I64)v1 <= (I64)v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLE_I64I64_end:
	GO_NEXT_CHECK();

JIT_BLE_F32F32_start:
JIT_BLE_UN_F32F32_start:
	OPCODE_USE(JIT_BLE_F32F32);
	{
		float v1, v2;
		U32 ofs;
		POP_F32_F32(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 <= v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLE_F32F32_end:
JIT_BLE_UN_F32F32_end:
	GO_NEXT_CHECK();

JIT_BLE_F64F64_start:
JIT_BLE_UN_F64F64_start:
	OPCODE_USE(JIT_BLE_F64F64);
	{
		double v1, v2;
		U32 ofs;
		POP_F64_F64(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 <= v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLE_F64F64_end:
JIT_BLE_UN_F64F64_end:
	GO_NEXT_CHECK();

JIT_BLT_I32I32_start:
	OPCODE_USE(JIT_BLT_I32I32);
	{
		U32 v1, v2;
		U32 ofs;
		POP_U32_U32(v1, v2);
		ofs = GET_OP_32( 0 );
		if ((I32)v1 < (I32)v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLT_I32I32_end:
	GO_NEXT_CHECK();

JIT_BLT_I64I64_start:
	OPCODE_USE(JIT_BLT_I64I64);
	{
		U64 v1, v2;
		U32 ofs;
		POP_U64_U64(v1, v2);
		ofs = GET_OP_32( 0 );
		if ((I64)v1 < (I64)v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLT_I64I64_end:
	GO_NEXT_CHECK();

JIT_BLT_F32F32_start:
JIT_BLT_UN_F32F32_start:
	OPCODE_USE(JIT_BLT_F32F32);
	{
		float v1, v2;
		U32 ofs;
		POP_F32_F32(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 < v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLT_F32F32_end:
JIT_BLT_UN_F32F32_end:
	GO_NEXT_CHECK();

JIT_BLT_F64F64_start:
JIT_BLT_UN_F64F64_start:
	OPCODE_USE(JIT_BLT_F64F64);
	{
		double v1, v2;
		U32 ofs;
		POP_F64_F64(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 < v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLT_F64F64_end:
JIT_BLT_UN_F64F64_end:
	GO_NEXT_CHECK();

JIT_BNE_UN_I32I32_start:
	OPCODE_USE(JIT_BNE_UN_I32I32);
	{
		U32 v1, v2, ofs;
		POP_U32_U32(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 != v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BNE_UN_I32I32_end:
	GO_NEXT_CHECK();

JIT_BNE_UN_I64I64_start:
	OPCODE_USE(JIT_BNE_UN_I64I64);
	{
		U64 v1, v2;
		U32 ofs;
		POP_U64_U64(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 != v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BNE_UN_I64I64_end:
	GO_NEXT_CHECK();

JIT_BNE_UN_F32F32_start:
	OPCODE_USE(JIT_BNE_UN_F32F32);
	{
		float v1, v2;
		U32 ofs;
		POP_F32_F32(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 != v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BNE_UN_F32F32_end:
	GO_NEXT_CHECK();

JIT_BNE_UN_F64F64_start:
	OPCODE_USE(JIT_BNE_UN_F64F64);
	{
		double v1, v2;
		U32 ofs;
		POP_F64_F64(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 != v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BNE_UN_F64F64_end:
	GO_NEXT_CHECK();

JIT_BGE_UN_I32I32_start:
	OPCODE_USE(JIT_BGE_UN_I32I32);
	{
		U32 v1, v2, ofs;
		POP_U32_U32(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 >= v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGE_UN_I32I32_end:
	GO_NEXT_CHECK();

JIT_BGE_UN_I64I64_start:
	OPCODE_USE(JIT_BGE_UN_I64I64);
	{
		U64 v1, v2;
		U32 ofs;
		POP_U64_U64(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 >= v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGE_UN_I64I64_end:
	GO_NEXT_CHECK();

JIT_BGT_UN_I32I32_start:
	OPCODE_USE(JIT_BGT_UN_I32I32);
	{
		U32 v1, v2, ofs;
		POP_U32_U32(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 > v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGT_UN_I32I32_end:
	GO_NEXT_CHECK();

JIT_BGT_UN_I64I64_start:
	OPCODE_USE(JIT_BGT_UN_I64I64);
	{
		U64 v1, v2;
		U32 ofs;
		POP_U64_U64(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 > v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BGT_UN_I64I64_end:
	GO_NEXT_CHECK();

JIT_BLE_UN_I32I32_start:
	OPCODE_USE(JIT_BLE_UN_I32I32);
	{
		U32 v1, v2, ofs;
		POP_U32_U32(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 <= v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLE_UN_I32I32_end:
	GO_NEXT_CHECK();

JIT_BLE_UN_I64I64_start:
	OPCODE_USE(JIT_BLE_UN_I64I64);
	{
		U64 v1, v2;
		U32 ofs;
		POP_U64_U64(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 <= v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLE_UN_I64I64_end:
	GO_NEXT_CHECK();

JIT_BLT_UN_I32I32_start:
	OPCODE_USE(JIT_BLT_UN_I32I32);
	{
		U32 v1, v2, ofs;
		POP_U32_U32(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 < v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLT_UN_I32I32_end:
	GO_NEXT_CHECK();

JIT_BLT_UN_I64I64_start:
	OPCODE_USE(JIT_BLT_UN_I64I64);
	{
		U64 v1, v2;
		U32 ofs;
		POP_U64_U64(v1, v2);
		ofs = GET_OP_32( 0 );
		if (v1 < v2) {
			pCurOp = pOps + ofs;
		}
	}
JIT_BLT_UN_I64I64_end:
	GO_NEXT_CHECK();

JIT_CEQ_I32I32_start: // Handles I32 and O
	OPCODE_USE(JIT_CEQ_I32I32);
	BINARY_OP(U32, U32, U32, ==);
JIT_CEQ_I32I32_end:
	GO_NEXT();

JIT_CGT_I32I32_start:
	OPCODE_USE(JIT_CGT_I32I32);
	BINARY_OP(U32, I32, I32, >);
JIT_CGT_I32I32_end:
	GO_NEXT();

JIT_CGT_UN_I32I32_start: // Handles I32 and O
	OPCODE_USE(JIT_CGT_UN_I32I32);
	BINARY_OP(U32, U32, U32, >);
JIT_CGT_UN_I32I32_end:
	GO_NEXT();

JIT_CLT_I32I32_start:
	OPCODE_USE(JIT_CLT_I32I32);
	BINARY_OP(U32, I32, I32, <);
JIT_CLT_I32I32_end:
	GO_NEXT();

JIT_CLT_UN_I32I32_start:
	OPCODE_USE(JIT_CLT_UN_I32I32);
	BINARY_OP(U32, U32, U32, <);
JIT_CLT_UN_I32I32_end:
	GO_NEXT();

JIT_CEQ_I64I64_start:
	OPCODE_USE(JIT_CEQ_I64I64);
	BINARY_OP(U32, U64, U64, ==);
JIT_CEQ_I64I64_end:
	GO_NEXT();

JIT_CGT_I64I64_start:
	OPCODE_USE(JIT_CGT_I64I64);
	BINARY_OP(U32, I64, I64, >);
JIT_CGT_I64I64_end:
	GO_NEXT();

JIT_CGT_UN_I64I64_start:
	OPCODE_USE(JIT_CGT_UN_I64I64);
	BINARY_OP(U32, U64, U64, >);
JIT_CGT_UN_I64I64_end:
	GO_NEXT();

JIT_CLT_I64I64_start:
	OPCODE_USE(JIT_CLT_I64I64);
	BINARY_OP(U32, I64, I64, <);
JIT_CLT_I64I64_end:
	GO_NEXT();

JIT_CLT_UN_I64I64_start:
	OPCODE_USE(JIT_CLT_UN_I64I64);
	BINARY_OP(U32, U64, U64, <);
JIT_CLT_UN_I64I64_end:
	GO_NEXT();

JIT_CEQ_F32F32_start:
	OPCODE_USE(JIT_CEQ_F32F32);
	BINARY_OP(U32, float, float, ==);
JIT_CEQ_F32F32_end:
	GO_NEXT();

JIT_CEQ_F64F64_start:
	OPCODE_USE(JIT_CEQ_F64F64);
	BINARY_OP(U32, double, double, ==);
JIT_CEQ_F64F64_end:
	GO_NEXT();

JIT_CGT_F32F32_start:
	OPCODE_USE(JIT_CGT_F32F32);
	BINARY_OP(U32, float, float, >);
JIT_CGT_F32F32_end:
	GO_NEXT();

JIT_CGT_F64F64_start:
	OPCODE_USE(JIT_CGT_F64F64);
	BINARY_OP(U32, double, double, >);
JIT_CGT_F64F64_end:
	GO_NEXT();

JIT_CLT_F32F32_start:
	OPCODE_USE(JIT_CLT_F32F32);
	BINARY_OP(U32, float, float, <);
JIT_CLT_F32F32_end:
	GO_NEXT();

JIT_CLT_F64F64_start:
	OPCODE_USE(JIT_CLT_F64F64);
	BINARY_OP(U32, double, double, <);
JIT_CLT_F64F64_end:
	GO_NEXT();

JIT_ADD_OVF_I32I32_start:
	OPCODE_USE(JIT_ADD_OVF_I32I32);
	{
		U32 v1, v2;
		I64 res;
		POP_U32_U32(v1, v2);
		res = (I64)(I32)v1 + (I64)(I32)v2;
		if (res > (I64)0x7fffffff || res < (I64)0xffffffff80000000) {
			// Overflowed, so throw exception
			THROW(types[TYPE_SYSTEM_OVERFLOWEXCEPTION]);
		}
		PUSH_U32((I32)res);
	}
JIT_ADD_OVF_I32I32_end:
	GO_NEXT();

JIT_ADD_OVF_UN_I32I32_start:
	OPCODE_USE(JIT_ADD_OVF_UN_I32I32);
	{
		U32 v1, v2;
		U64 res;
		POP_U32_U32(v1, v2);
		res = (U64)v1 + (U64)v2;
		if (res > (U64)0xffffffff) {
			// Overflowed, so throw exception
			THROW(types[TYPE_SYSTEM_OVERFLOWEXCEPTION]);
		}
		PUSH_U32(res);
	}
JIT_ADD_OVF_UN_I32I32_end:
	GO_NEXT();

JIT_MUL_OVF_I32I32_start:
	OPCODE_USE(JIT_MUL_OVF_I32I32);
	{
		U32 v1, v2;
		I64 res;
		POP_U32_U32(v1, v2);
		res = (I64)(I32)v1 * (I64)(I32)v2;
		if (res > (I64)0x7fffffff || res < (I64)0xffffffff80000000) {
			// Overflowed, so throw exception
			THROW(types[TYPE_SYSTEM_OVERFLOWEXCEPTION]);
		}
		PUSH_U32((I32)res);
	}
JIT_MUL_OVF_I32I32_end:
	GO_NEXT();

JIT_MUL_OVF_UN_I32I32_start:
	OPCODE_USE(JIT_MUL_OVF_UN_I32I32);
	{
		U32 v1, v2;
		U64 res;
		POP_U32_U32(v1, v2);
		res = (U64)v1 * (U64)v2;
		if (res > (U64)0xffffffff) {
			// Overflowed, so throw exception
			THROW(types[TYPE_SYSTEM_OVERFLOWEXCEPTION]);
		}
		PUSH_U32(res);
	}
JIT_MUL_OVF_UN_I32I32_end:
	GO_NEXT();

JIT_SUB_OVF_I32I32_start:
	OPCODE_USE(JIT_SUB_OVF_I32I32);
	{
		U32 v1, v2;
		I64 res;
		POP_U32_U32(v1, v2);
		res = (I64)(I32)v1 - (I64)(I32)v2;
		if (res > (I64)0x7fffffff || res < (I64)0xffffffff80000000) {
			// Overflowed, so throw exception
			THROW(types[TYPE_SYSTEM_OVERFLOWEXCEPTION]);
		}
		PUSH_U32((I32)res);
	}
JIT_SUB_OVF_I32I32_end:
	GO_NEXT();

JIT_SUB_OVF_UN_I32I32_start:
	OPCODE_USE(JIT_SUB_OVF_UN_I32I32);
	{
		U32 v1, v2;
		U64 res;
		POP_U32_U32(v1, v2);
		res = (U64)v1 - (U64)v2;
		if (res > (U64)0xffffffff) {
			// Overflowed, so throw exception
			THROW(types[TYPE_SYSTEM_OVERFLOWEXCEPTION]);
		}
		PUSH_U32(res);
	}
JIT_SUB_OVF_UN_I32I32_end:
	GO_NEXT();

JIT_ADD_I32I32_start:
	OPCODE_USE(JIT_ADD_I32I32);
	BINARY_OP(I32, I32, I32, +);
JIT_ADD_I32I32_end:
	GO_NEXT();

JIT_ADD_I64I64_start:
	OPCODE_USE(JIT_ADD_I64I64);
	BINARY_OP(I64, I64, I64, +);
JIT_ADD_I64I64_end:
	GO_NEXT();

JIT_ADD_F32F32_start:
	OPCODE_USE(JIT_ADD_F32F32);
	BINARY_OP(float, float, float, +);
JIT_ADD_F32F32_end:
	GO_NEXT();

JIT_ADD_F64F64_start:
	OPCODE_USE(JIT_ADD_F64F64);
	BINARY_OP(double, double, double, +);
JIT_ADD_F64F64_end:
	GO_NEXT();

JIT_SUB_I32I32_start:
	OPCODE_USE(JIT_SUB_I32I32);
	BINARY_OP(I32, I32, I32, -);
JIT_SUB_I32I32_end:
	GO_NEXT();

JIT_SUB_I64I64_start:
	OPCODE_USE(JIT_SUB_I64I64);
	BINARY_OP(I64, I64, I64, -);
JIT_SUB_I64I64_end:
	GO_NEXT();

JIT_SUB_F32F32_start:
	OPCODE_USE(JIT_SUB_F32F32);
	BINARY_OP(double, double, double, -);
JIT_SUB_F32F32_end:
	GO_NEXT();

JIT_SUB_F64F64_start:
	OPCODE_USE(JIT_SUB_F64F64);
	BINARY_OP(double, double, double, -);
JIT_SUB_F64F64_end:
	GO_NEXT();

JIT_MUL_I32I32_start:
	OPCODE_USE(JIT_MUL_I32I32);
	BINARY_OP(I32, I32, I32, *);
JIT_MUL_I32I32_end:
	GO_NEXT();

JIT_MUL_I64I64_start:
	OPCODE_USE(JIT_MUL_I64I64);
	BINARY_OP(I64, I64, I64, *);
JIT_MUL_I64I64_end:
	GO_NEXT();

JIT_MUL_F32F32_start:
	OPCODE_USE(JIT_MUL_F32F32);
	BINARY_OP(float, float, float, *);
JIT_MUL_F32F32_end:
	GO_NEXT();

JIT_MUL_F64F64_start:
	OPCODE_USE(JIT_MUL_F64F64);
	BINARY_OP(double, double, double, *);
JIT_MUL_F64F64_end:
	GO_NEXT();

JIT_DIV_I32I32_start:
	OPCODE_USE(JIT_DIV_I32I32);
	BINARY_OP(I32, I32, I32, /);
JIT_DIV_I32I32_end:
	GO_NEXT();

JIT_DIV_I64I64_start:
	OPCODE_USE(JIT_DIV_I64I64);
	BINARY_OP(I64, I64, I64, /);
JIT_DIV_I64I64_end:
	GO_NEXT();

JIT_DIV_F32F32_start:
	OPCODE_USE(JIT_DIV_F32F32);
	BINARY_OP(float, float, float, /);
JIT_DIV_F32F32_end:
	GO_NEXT();

JIT_DIV_F64F64_start:
	OPCODE_USE(JIT_DIV_F64F64);
	BINARY_OP(double, double, double, /);
JIT_DIV_F64F64_end:
	GO_NEXT();

JIT_DIV_UN_I32I32_start:
	OPCODE_USE(JIT_DIV_UN_I32I32);
	BINARY_OP(U32, U32, U32, /);
JIT_DIV_UN_I32I32_end:
	GO_NEXT();

JIT_DIV_UN_I64I64_start:
	OPCODE_USE(JIT_DIV_UN_I64I64);
	BINARY_OP(U64, U64, U64, /);
JIT_DIV_UN_I64I64_end:
	GO_NEXT();

JIT_REM_I32I32_start:
	OPCODE_USE(JIT_REM_I32I32);
	BINARY_OP(I32, I32, I32, %);
JIT_REM_I32I32_end:
	GO_NEXT();

JIT_REM_I64I64_start:
	OPCODE_USE(JIT_REM_I64I64);
	BINARY_OP(I64, I64, I64, %);
JIT_REM_I64I64_end:
	GO_NEXT();

JIT_REM_UN_I32I32_start:
	OPCODE_USE(JIT_REM_UN_I32I32);
	BINARY_OP(U32, U32, U32, %);
JIT_REM_UN_I32I32_end:
	GO_NEXT();

JIT_REM_UN_I64I64_start:
	OPCODE_USE(JIT_REM_UN_I64I64);
	BINARY_OP(U64, U64, U64, %);
JIT_REM_UN_I64I64_end:
	GO_NEXT();

JIT_AND_I32I32_start:
	OPCODE_USE(JIT_AND_I32I32);
	BINARY_OP(U32, U32, U32, &);
JIT_AND_I32I32_end:
	GO_NEXT();

JIT_AND_I64I64_start:
	OPCODE_USE(JIT_AND_I64I64);
	BINARY_OP(U64, U64, U64, &);
JIT_AND_I64I64_end:
	GO_NEXT();

JIT_OR_I32I32_start:
	OPCODE_USE(JIT_OR_I32I32);
	BINARY_OP(U32, U32, U32, |);
JIT_OR_I32I32_end:
	GO_NEXT();

JIT_OR_I64I64_start:
	OPCODE_USE(JIT_OR_I64I64);
	BINARY_OP(U64, U64, U64, |);
JIT_OR_I64I64_end:
	GO_NEXT();

JIT_XOR_I32I32_start:
	OPCODE_USE(JIT_XOR_I32I32);
	BINARY_OP(U32, U32, U32, ^);
JIT_XOR_I32I32_end:
	GO_NEXT();

JIT_XOR_I64I64_start:
	OPCODE_USE(JIT_XOR_I64I64);
	BINARY_OP(U64, U64, U64, ^);
JIT_XOR_I64I64_end:
	GO_NEXT();

JIT_NEG_I32_start:
	OPCODE_USE(JIT_NEG_I32);
	UNARY_OP(I32, -);
JIT_NEG_I32_end:
	GO_NEXT();

JIT_NEG_I64_start:
	OPCODE_USE(JIT_NEG_I64);
	UNARY_OP(I64, -);
JIT_NEG_I64_end:
	GO_NEXT();

JIT_NEG_F32_start:
	OPCODE_USE(JIT_NEG_F32);
	UNARY_OP(float, -);
JIT_NEG_F32_end:
	GO_NEXT();

JIT_NEG_F64_start:
	OPCODE_USE(JIT_NEG_F64);
	UNARY_OP(double, -);
JIT_NEG_F64_end:
	GO_NEXT();

JIT_NOT_I32_start:
	OPCODE_USE(JIT_NOT_I32);
	UNARY_OP(U32, ~);
JIT_NOT_I32_end:
	GO_NEXT();

JIT_NOT_I64_start:
	OPCODE_USE(JIT_NOT_I64);
	UNARY_OP(U64, ~);
JIT_NOT_I64_end:
	GO_NEXT();

JIT_SHL_I32_start:
	OPCODE_USE(JIT_SHL_I32);
	BINARY_OP(U32, U32, U32, <<);
JIT_SHL_I32_end:
	GO_NEXT();

JIT_SHR_I32_start:
	OPCODE_USE(JIT_SHR_I32);
	BINARY_OP(I32, I32, U32, >>);
JIT_SHR_I32_end:
	GO_NEXT();

JIT_SHR_UN_I32_start:
	OPCODE_USE(JIT_SHR_UN_I32);
	BINARY_OP(U32, U32, U32, >>);
JIT_SHR_UN_I32_end:
	GO_NEXT();

JIT_SHL_I64_start:
	OPCODE_USE(JIT_SHL_I64);
	BINARY_OP(U64, U64, U32, <<);
JIT_SHL_I64_end:
	GO_NEXT();

JIT_SHR_I64_start:
	OPCODE_USE(JIT_SHR_I64);
	BINARY_OP(I64, I64, U32, >>);
JIT_SHR_I64_end:
	GO_NEXT();

JIT_SHR_UN_I64_start:
	OPCODE_USE(JIT_SHR_UN_I64);
	BINARY_OP(U64, U64, U32, >>);
JIT_SHR_UN_I64_end:
	GO_NEXT();

	// Conversion operations

JIT_CONV_U32_U32_start:
JIT_CONV_I32_U32_start:
	OPCODE_USE(JIT_CONV_I32_U32);
	{
		U32 mask = GET_OP_32( 0 );
		STACK_ADDR(U32) &= mask;
	}
JIT_CONV_U32_U32_end:
JIT_CONV_I32_U32_end:
	GO_NEXT();

JIT_CONV_U32_I32_start:
JIT_CONV_I32_I32_start:
	OPCODE_USE(JIT_CONV_I32_I32);
	{
		U32 shift = GET_OP_32( 0 );
		STACK_ADDR(I32) = (STACK_ADDR(I32) << shift) >> shift;
	}
JIT_CONV_U32_I32_end:
JIT_CONV_I32_I32_end:
	GO_NEXT();

JIT_CONV_I32_I64_start:
	OPCODE_USE(JIT_CONV_I32_I64);
	{
		I32 value = (I32)POP_U32();
		PUSH_U64((I64)value);
	}
JIT_CONV_I32_I64_end:
	GO_NEXT();

JIT_CONV_I32_U64_start:
JIT_CONV_U32_U64_start:
JIT_CONV_U32_I64_start:
	OPCODE_USE(JIT_CONV_U32_I64);
	{
		U32 value = POP_U32();
		PUSH_U64(value);
	}
JIT_CONV_I32_U64_end:
JIT_CONV_U32_U64_end:
JIT_CONV_U32_I64_end:
	GO_NEXT();

JIT_CONV_I32_R32_start:
	OPCODE_USE(JIT_CONV_I32_R32);
	{
		I32 value = (I32)POP_U32();
		PUSH_FLOAT(value);
	}
JIT_CONV_I32_R32_end:
	GO_NEXT();

JIT_CONV_I32_R64_start:
	OPCODE_USE(JIT_CONV_I32_R64);
	{
		I32 value = (I32)POP_U32();
		PUSH_DOUBLE(value);
	}
JIT_CONV_I32_R64_end:
	GO_NEXT();

JIT_CONV_U32_R32_start:
	OPCODE_USE(JIT_CONV_U32_R32);
	{
		U32 value = POP_U32();
		PUSH_FLOAT(value);
	}
JIT_CONV_U32_R32_end:
	GO_NEXT();

JIT_CONV_U32_R64_start:
	OPCODE_USE(JIT_CONV_U32_R64);
	{
		U32 value = POP_U32();
		PUSH_DOUBLE(value);
	}
JIT_CONV_U32_R64_end:
	GO_NEXT();

JIT_CONV_I64_U32_start:
JIT_CONV_U64_U32_start:
	OPCODE_USE(JIT_CONV_I64_U32);
	{
		U32 mask = GET_OP_32( 0 );
		U64 value = POP_U64();
		PUSH_U32(value & mask);
	}
JIT_CONV_I64_U32_end:
JIT_CONV_U64_U32_end:
	GO_NEXT();

JIT_CONV_I64_I32_start:
JIT_CONV_U64_I32_start:
	OPCODE_USE(JIT_CONV_I64_U32);
	{
		U32 shift = GET_OP_32( 0 );
		I32 value = (I32)POP_U64();
		value = (value << shift) >> shift;
		PUSH_U32(value);
	}
JIT_CONV_I64_I32_end:
JIT_CONV_U64_I32_end:
	GO_NEXT();

JIT_CONV_I64_R32_start:
	OPCODE_USE(JIT_CONV_I64_R32);
	{
		I64 value = (I64)POP_U64();
		PUSH_FLOAT(value);
	}
JIT_CONV_I64_R32_end:
	GO_NEXT();

JIT_CONV_I64_R64_start:
	OPCODE_USE(JIT_CONV_I64_R64);
	{
		I64 value = (I64)POP_U64();
		PUSH_DOUBLE(value);
	}
JIT_CONV_I64_R64_end:
	GO_NEXT();

JIT_CONV_U64_R32_start:
	OPCODE_USE(JIT_CONV_U64_R32);
	{
		U64 value = POP_U64();
		PUSH_FLOAT(value);
	}
JIT_CONV_U64_R32_end:
	GO_NEXT();

JIT_CONV_U64_R64_start:
	OPCODE_USE(JIT_CONV_U64_R64);
	{
		U64 value = POP_U64();
		PUSH_DOUBLE(value);
	}
JIT_CONV_U64_R64_end:
	GO_NEXT();

JIT_CONV_R32_I32_start:
	OPCODE_USE(JIT_CONV_R32_I32);
	{
		U32 shift = GET_OP_32( 0 );
		I32 result;
		float value = POP_FLOAT();
		result = (I32)value;
		result = (result << shift) >> shift;
		PUSH_U32(result);
	}
JIT_CONV_R32_I32_end:
	GO_NEXT();

JIT_CONV_R32_U32_start:
	OPCODE_USE(JIT_CONV_R32_U32);
	{
		U32 mask = GET_OP_32( 0 );
		float value = POP_FLOAT();
		PUSH_U32(((U32)value) & mask);
	}
JIT_CONV_R32_U32_end:
	GO_NEXT();

JIT_CONV_R32_I64_start:
	OPCODE_USE(JIT_CONV_R32_I64);
	{
		float value = POP_FLOAT();
		PUSH_U64((I64)value);
	}
JIT_CONV_R32_I64_end:
	GO_NEXT();

JIT_CONV_R32_U64_start:
	OPCODE_USE(JIT_CONV_R32_U64);
	{
		float value = POP_FLOAT();
		PUSH_U64(value);
	}
JIT_CONV_R32_U64_end:
	GO_NEXT();

JIT_CONV_R32_R64_start:
	OPCODE_USE(JIT_CONV_R32_R64);
	{
		float value = POP_FLOAT();
		PUSH_DOUBLE(value);
	}
JIT_CONV_R32_R64_end:
	GO_NEXT();

JIT_CONV_R64_I32_start:
	OPCODE_USE(JIT_CONV_R64_I32);
	{
		U32 shift = GET_OP_32( 0 );
		I32 result;
		double value = POP_DOUBLE();
		result = (I32)value;
		result = (result << shift) >> shift;
		PUSH_U32(result);
	}
JIT_CONV_R64_I32_end:
	GO_NEXT();

JIT_CONV_R64_U32_start:
	OPCODE_USE(JIT_CONV_R64_U32);
	{
		U32 mask = GET_OP_32( 0 );
		double value = POP_DOUBLE();
		PUSH_U32(((U32)value) & mask);
	}
JIT_CONV_R64_U32_end:
	GO_NEXT();

JIT_CONV_R64_I64_start:
	OPCODE_USE(JIT_CONV_R64_I64);
	{
		double value = POP_DOUBLE();
		PUSH_U64((I64)value);
	}
JIT_CONV_R64_I64_end:
	GO_NEXT();

JIT_CONV_R64_U64_start:
	OPCODE_USE(JIT_CONV_R64_U64);
	{
		double value = POP_DOUBLE();
		PUSH_U64(value);
	}
JIT_CONV_R64_U64_end:
	GO_NEXT();

JIT_CONV_R64_R32_start:
	OPCODE_USE(JIT_CONV_R64_R32);
	{
		float value = (float)POP_DOUBLE();
		PUSH_FLOAT(value);
	}
JIT_CONV_R64_R32_end:
	GO_NEXT();

JIT_LOADFUNCTION_start:
	OPCODE_USE(JIT_LOADFUNCTION);
	{
		// This is actually a pointer not a U64.
		U64 value = GET_OP_64( 0 );
		PUSH_U64(value); // 64bit
	}
JIT_LOADFUNCTION_end:
	GO_NEXT();

JIT_LOADOBJECT_start:
	OPCODE_USE(JIT_LOADOBJECT);
	{
		tMD_TypeDef *pTypeDef;
		PTR pMem;

		pMem = POP_PTR(); // address of value-type
		pTypeDef = (tMD_TypeDef*)GET_OP_64( checkPointerTypes ); // type of the value-type
		//if (pTypeDef->stackSize != pTypeDef->arrayElementSize) {

		// For bytes and int16s we need some special code to ensure that the stack
		// does not contain rubbish in the bits unused in this type.
		// But there is no harm in running this for all types, and it's smaller and probably faster
		*(U32*)pCurEvalStack = 0;

		//}
		PUSH_VALUETYPE(pMem, pTypeDef->arrayElementSize, pTypeDef->stackSize);
	}
JIT_LOADOBJECT_end:
	GO_NEXT();

JIT_LOAD_STRING_start:
	OPCODE_USE(JIT_LOAD_STRING);
	{
		U32 value = GET_OP_32( 0 );
		PTR heapPtr = SystemString_FromUserStrings(pCurrentMethodState->pMetaData, value);
		PUSH_O(heapPtr);
	}
JIT_LOAD_STRING_end:
	GO_NEXT();

JIT_NEWOBJECT_start:
	OPCODE_USE(JIT_NEWOBJECT);
	{
		tMD_MethodDef *pConstructorDef;
		HEAP_PTR obj;
		tMethodState *pCallMethodState;
		U32 isInternalConstructor;
		PTR pTempPtr;

		pConstructorDef = (tMD_MethodDef*)GET_OP_64( checkPointerTypes );
		isInternalConstructor = (pConstructorDef->implFlags & METHODIMPLATTRIBUTES_INTERNALCALL) != 0;

		if (!isInternalConstructor) {
			// All internal constructors MUST allocate their own 'this' objects
			obj = Heap_AllocType(pConstructorDef->pParentType);
		} else {
			// Need to set this to something non-NULL so that CreateParameters() works properly
			obj = (HEAP_PTR)-1;
		}

		// Set up the new method state for the called method
		pCallMethodState = MethodState_Direct(pThread, pConstructorDef, pCurrentMethodState, isInternalConstructor);
		// Fill in the parameters
		pTempPtr = pCurEvalStack;
		CreateParameters(pCallMethodState, pConstructorDef, pCurrentMethodState, &pTempPtr, obj);
		pCurEvalStack = pTempPtr;
		if (!isInternalConstructor) {
			// Push the object here, so it's on the stack when the constructor returns
			PUSH_O(obj);
		}
		// Set up the local variables for the new method state (for the obj constructor)
		CHANGE_METHOD_STATE(pCallMethodState);
		// Run any pending Finalizers
		RUN_FINALIZER();
	}
JIT_NEWOBJECT_end:
	GO_NEXT_CHECK();

JIT_NEWOBJECT_VALUETYPE_start:
	OPCODE_USE(JIT_NEWOBJECT_VALUETYPE);
	{
		tMD_MethodDef *pConstructorDef;
		tMethodState *pCallMethodState;
		U32 isInternalConstructor;
		PTR pTempPtr, pMem;

		pConstructorDef = (tMD_MethodDef*)GET_OP_64( checkPointerTypes );
		isInternalConstructor = (pConstructorDef->implFlags & METHODIMPLATTRIBUTES_INTERNALCALL) != 0;

		// Allocate space on the eval-stack for the new value-type here
		pMem = pCurEvalStack - (pConstructorDef->parameterStackSize - sizeof(PTR));

		// Set up the new method state for the called method
		pCallMethodState = MethodState_Direct(pThread, pConstructorDef, pCurrentMethodState, isInternalConstructor);
		// Fill in the parameters
		pTempPtr = pCurEvalStack;
		CreateParameters(pCallMethodState, pConstructorDef, pCurrentMethodState, &pTempPtr, pMem);
		pCurEvalStack = pTempPtr;
		// Set the stack state so it's correct for the constructor return
		pCurEvalStack += pConstructorDef->pParentType->stackSize;

		// Set up the local variables for the new method state
		CHANGE_METHOD_STATE(pCallMethodState);
		// Run any pending Finalizers
		RUN_FINALIZER();
	}
JIT_NEWOBJECT_VALUETYPE_end:
	GO_NEXT_CHECK();

JIT_IS_INSTANCE_start:
	op = JIT_IS_INSTANCE;
	goto jitCastClass;
JIT_CAST_CLASS_start:
	op = JIT_CAST_CLASS;
jitCastClass:
	OPCODE_USE(JIT_CAST_CLASS);
	{
		tMD_TypeDef *pToType, *pTestType;
		HEAP_PTR heapPtr;

		pToType = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );
		heapPtr = POP_O();
		if (heapPtr == NULL) {
			PUSH_O(NULL);
			goto JIT_IS_INSTANCE_end;
		}
		pTestType = Heap_GetType(heapPtr);
		if (TYPE_ISARRAY(pTestType) && TYPE_ISARRAY(pToType)) {
			// Arrays are handled specially - check if the element type is compatible
			if (Type_IsAssignableFrom(pToType->pArrayElementType, pTestType->pArrayElementType)) {
				PUSH_O(heapPtr);
				goto JIT_IS_INSTANCE_end;
			}
		} else {
			if (Type_IsAssignableFrom(pToType, pTestType) ||
				(pToType->pGenericDefinition == types[TYPE_SYSTEM_NULLABLE] &&
				pToType->ppClassTypeArgs[0] == pTestType)) {
				// If derived class, interface, or nullable type compatible.
				PUSH_O(heapPtr);
				goto JIT_IS_INSTANCE_end;
			}
		}
		if (op == JIT_IS_INSTANCE) {
			PUSH_O(NULL);
		} else {
			THROW(types[TYPE_SYSTEM_INVALIDCASTEXCEPTION]);
		}
	}
JIT_IS_INSTANCE_end:
JIT_CAST_CLASS_end:
	GO_NEXT();

JIT_NEW_VECTOR_start: // Array with 1 dimension, zero-based
	OPCODE_USE(JIT_NEW_VECTOR);
	{
		tMD_TypeDef *pArrayTypeDef;
		U32 numElements;
		HEAP_PTR heapPtr;

		pArrayTypeDef = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );
		numElements = POP_U32();
		heapPtr = SystemArray_NewVector(pArrayTypeDef, numElements);
		PUSH_O(heapPtr);
		// Run any pending Finalizers
		RUN_FINALIZER();
	}
JIT_NEW_VECTOR_end:
	GO_NEXT();

JIT_LOAD_VECTOR_LEN_start: // Load the length of a vector array
	OPCODE_USE(JIT_LOAD_VECTOR_LEN);
	{
		PTR heapPtr = POP_O();
		U32 value = SystemArray_GetLength(heapPtr);
		PUSH_U32(value);
	}
JIT_LOAD_VECTOR_LEN_end:
	GO_NEXT();

JIT_LOAD_ELEMENT_I8_start:
	OPCODE_USE(JIT_LOAD_ELEMENT_I8);
	{
		U32 value, idx = POP_U32(); // Array index
		HEAP_PTR heapPtr = POP_O();
		SystemArray_LoadElement(heapPtr, idx, (PTR)&value);
		PUSH_U32((I8)value);
	}
JIT_LOAD_ELEMENT_I8_end:
	GO_NEXT();

JIT_LOAD_ELEMENT_U8_start:
	OPCODE_USE(JIT_LOAD_ELEMENT_U8);
	{
		U32 value, idx = POP_U32(); // Array index
		HEAP_PTR heapPtr = POP_O();
		SystemArray_LoadElement(heapPtr, idx, (PTR)&value);
		PUSH_U32((U8)value);
	}
JIT_LOAD_ELEMENT_U8_end:
	GO_NEXT();

JIT_LOAD_ELEMENT_I16_start:
	OPCODE_USE(JIT_LOAD_ELEMENT_I16);
	{
		U32 value, idx = POP_U32(); // Array index
		HEAP_PTR heapPtr = POP_O();
		SystemArray_LoadElement(heapPtr, idx, (PTR)&value);
		PUSH_U32((I16)value);
	}
JIT_LOAD_ELEMENT_I16_end:
	GO_NEXT();

JIT_LOAD_ELEMENT_U16_start:
	OPCODE_USE(JIT_LOAD_ELEMENT_U16);
	{
		U32 value, idx = POP_U32(); // Array index
		HEAP_PTR heapPtr = POP_O();
		SystemArray_LoadElement(heapPtr, idx, (PTR)&value);
		PUSH_U32((U16)value);
	}
JIT_LOAD_ELEMENT_U16_end:
	GO_NEXT();

JIT_LOAD_ELEMENT_I32_start:
JIT_LOAD_ELEMENT_U32_start:
JIT_LOAD_ELEMENT_R32_start:
	OPCODE_USE(JIT_LOAD_ELEMENT_I32);
	{
		U32 value, idx = POP_U32(); // Array index
		HEAP_PTR heapPtr = POP_O();
		SystemArray_LoadElement(heapPtr, idx, (PTR)&value);
		PUSH_U32(value);
	}
JIT_LOAD_ELEMENT_I32_end:
JIT_LOAD_ELEMENT_U32_end:
JIT_LOAD_ELEMENT_R32_end:
	GO_NEXT();

JIT_LOAD_ELEMENT_I64_start:
JIT_LOAD_ELEMENT_U64_start:
JIT_LOAD_ELEMENT_R64_start:
	OPCODE_USE(JIT_LOAD_ELEMENT_I64);
	{
		U32 idx = POP_U32(); // array index
		HEAP_PTR heapPtr = POP_O();
		U64 value;
		SystemArray_LoadElement(heapPtr, idx, (PTR)&value);
		PUSH_U64(value);
	}
JIT_LOAD_ELEMENT_I64_end:
JIT_LOAD_ELEMENT_U64_end:
JIT_LOAD_ELEMENT_R64_end:
	GO_NEXT();

JIT_LOAD_ELEMENT_start:
	OPCODE_USE(JIT_LOAD_ELEMENT);
	{
		U32 idx = POP_U32(); // Array index
		HEAP_PTR heapPtr = POP_O(); // array object
		U32 size = GET_OP_32( 0 ); // size of type on stack
		*(U32*)pCurEvalStack = 0; // This is required to zero out the stack for types that are stored in <4 bytes in arrays
		SystemArray_LoadElement(heapPtr, idx, pCurEvalStack);
		pCurEvalStack += size;
	}
JIT_LOAD_ELEMENT_end:
	GO_NEXT();

JIT_LOAD_ELEMENT_ADDR_start:
	OPCODE_USE(JIT_LOAD_ELEMENT_ADDR);
	{
		U32 idx = POP_U32(); // Array index
		PTR heapPtr = POP_O();
		PTR pMem = SystemArray_LoadElementAddress(heapPtr, idx);
		PUSH_PTR(pMem);
	}
JIT_LOAD_ELEMENT_ADDR_end:
	GO_NEXT();

JIT_STORE_ELEMENT_32_start:
	OPCODE_USE(JIT_STORE_ELEMENT_32);
	{
		U32 value = POP_U32(); // Value
		U32 idx = POP_U32(); // Array index
		PTR heapPtr = POP_O();
		SystemArray_StoreElement(heapPtr, idx, (PTR)&value);
	}
JIT_STORE_ELEMENT_32_end:
	GO_NEXT();

JIT_STORE_ELEMENT_64_start:
	OPCODE_USE(JIT_STORE_ELEMENT_64);
	{
		U64 value = POP_U64(); // Value
		U32 idx = POP_U32(); // Array index
		PTR heapPtr = POP_O();
		SystemArray_StoreElement(heapPtr, idx, (PTR)&value);
	}
JIT_STORE_ELEMENT_64_end:
	GO_NEXT();

JIT_STORE_ELEMENT_start:
	OPCODE_USE(JIT_STORE_ELEMENT);
	{
		HEAP_PTR heapPtr;
		PTR pMem;
		U32 idx, size = GET_OP_32( 0 ); // Size in bytes of value on stack
		POP(size);
		pMem = pCurEvalStack;
		idx = POP_U32(); // Array index
		heapPtr = POP_O(); // Array on heap
		SystemArray_StoreElement(heapPtr, idx, pMem);
	}
JIT_STORE_ELEMENT_end:
	GO_NEXT();

JIT_STOREFIELD_INT32_start:
	op = JIT_STOREFIELD_INT32;
	goto allStoreField32Start;
JIT_STOREFIELD_F32_start:
	op = JIT_STOREFIELD_F32;
	goto allStoreField32Start;
JIT_STOREFIELD_INTNATIVE_start: // intnative is 32bit
	op = JIT_STOREFIELD_INTNATIVE;
	goto allStoreField32Start;
allStoreField32Start:
	OPCODE_USE( op );
	{
		tMD_FieldDef *pFieldDef;
		PTR pMem;
		U32 value;
		HEAP_PTR heapPtr;

		pFieldDef = (tMD_FieldDef*)GET_OP_64( checkPointerTypes );
		value = POP_U32();
		heapPtr = POP_O();
		pMem = heapPtr + pFieldDef->memOffset;
		*(U32*)pMem = value;
	}
JIT_STOREFIELD_INT32_end:
JIT_STOREFIELD_F32_end:
JIT_STOREFIELD_INTNATIVE_end:
	GO_NEXT();

JIT_STOREFIELD_INT64_start:
	op = JIT_STOREFIELD_INT64;
	goto allStoreField64Start;
JIT_STOREFIELD_F64_start:
	op = JIT_STOREFIELD_F64;
	goto allStoreField64Start;
JIT_STOREFIELD_O_start: // 64bit only.
	op = JIT_STOREFIELD_O;
	goto allStoreField64Start;
JIT_STOREFIELD_PTR_start: // 64bit only.
	op = JIT_STOREFIELD_PTR;
	goto allStoreField64Start;
allStoreField64Start:
	OPCODE_USE( op );
	{
		tMD_FieldDef *pFieldDef;
		PTR pMem;
		U64 value;
		HEAP_PTR heapPtr;

		pFieldDef = (tMD_FieldDef*)GET_OP_64( checkPointerTypes );
		value = POP_U64();
		heapPtr = POP_O();
		pMem = heapPtr + pFieldDef->memOffset;
		*(U64*)pMem = value;
	}
JIT_STOREFIELD_INT64_end:
JIT_STOREFIELD_F64_end:
JIT_STOREFIELD_O_end: // 64bit only.
JIT_STOREFIELD_PTR_end: // 64bit only.
	GO_NEXT();

JIT_STOREFIELD_VALUETYPE_start:
	OPCODE_USE(JIT_STOREFIELD_VALUETYPE);
	{
		tMD_FieldDef *pFieldDef;
		PTR pMem;

		pFieldDef = (tMD_FieldDef*)GET_OP_64( checkPointerTypes );
		pCurEvalStack -= pFieldDef->memSize;
		pMem = pCurEvalStack;
		heapPtr = POP_O();
		memcpy(heapPtr + pFieldDef->memOffset, pMem, pFieldDef->memSize);
	}
JIT_STOREFIELD_VALUETYPE_end:
	GO_NEXT();

JIT_LOADFIELD_start:
	OPCODE_USE(JIT_LOADFIELD);
	// TODO: Optimize into LOADFIELD of different types O, INT32, INT64, F, etc...)
	{
		tMD_FieldDef *pFieldDef;

		pFieldDef = (tMD_FieldDef*)GET_OP_64( checkPointerTypes );
		heapPtr = POP_O();
		pMem = heapPtr + pFieldDef->memOffset;
		// It may not be a value-type, but this'll work anyway
		PUSH_VALUETYPE(pMem, pFieldDef->memSize, pFieldDef->memSize);
	}
JIT_LOADFIELD_end:
	GO_NEXT();

JIT_LOADFIELD_4_start:
	OPCODE_USE(JIT_LOADFIELD_4);
	{
		U32 ofs = GET_OP_32( 0 );
		PTR heapPtr = POP_O();
		PUSH_U32(*(U32*)(heapPtr + ofs));
	}
JIT_LOADFIELD_4_end:
	GO_NEXT();

JIT_LOADFIELD_VALUETYPE_start:
	OPCODE_USE(JIT_LOADFIELD_VALUETYPE);
	{
		tMD_FieldDef *pFieldDef;

		u32Value = GET_OP_32( 0 ); // Get the size of the value-type on the eval stack
		pFieldDef = (tMD_FieldDef*)GET_OP_64( checkPointerTypes );

		// [Steve edit] The following line used to be:
		//     pCurrentMethodState->stackOfs -= u32Value;
		// ... but this seems to result in calculating the wrong pMem value and getting garbage results.
		// My guess is that at some point they refactored from using 'pEvalStack' to 'pCurEvalStack', but
		// didn't update this method (because nothing in corlib reads fields from structs).
		// I think the following line moves the stack pointer along correctly instead:
		pCurEvalStack -= u32Value;

		//pMem = pEvalStack + pCurrentMethodState->stackOfs + pFieldDef->memOffset;
		pMem = pCurEvalStack + pFieldDef->memOffset;
		// It may not be a value-type, but this'll work anyway
		PUSH_VALUETYPE(pMem, pFieldDef->memSize, pFieldDef->memSize);
	}
JIT_LOADFIELD_VALUETYPE_end:
	GO_NEXT();

JIT_LOAD_FIELD_ADDR_start:
	OPCODE_USE(JIT_LOAD_FIELD_ADDR);
	{
		U32 ofs = GET_OP_32( 0 );
		HEAP_PTR heapPtr = POP_O();
		PTR pMem = heapPtr + ofs;
		PUSH_PTR(pMem);
	}
JIT_LOAD_FIELD_ADDR_end:
	GO_NEXT();

JIT_STORESTATICFIELD_INT32_start:
JIT_STORESTATICFIELD_F32_start:
JIT_STORESTATICFIELD_INTNATIVE_start: // intnative is 32bit
	OPCODE_USE(JIT_STORESTATICFIELD_INT32);
	{
		tMD_FieldDef *pFieldDef;
		PTR pMem;
		U32 value;

		pFieldDef = (tMD_FieldDef*)GET_OP_64( checkPointerTypes );
		value = POP_U32();
		pMem = pFieldDef->pMemory;
		*(U32*)pMem = value;
	}
JIT_STORESTATICFIELD_INT32_end:
JIT_STORESTATICFIELD_F32_end:
JIT_STORESTATICFIELD_INTNATIVE_end:
	GO_NEXT();

JIT_STORESTATICFIELD_INT64_start:
JIT_STORESTATICFIELD_F64_start:
JIT_STORESTATICFIELD_O_start: // 64bit only.
JIT_STORESTATICFIELD_PTR_start: // 64bit only.
	OPCODE_USE(JIT_STORESTATICFIELD_INT64);
	{
		tMD_FieldDef *pFieldDef;
		PTR pMem;
		U64 value;

		pFieldDef = (tMD_FieldDef*)GET_OP_64( checkPointerTypes );
		value = POP_U64();
		//pMem = pFieldDef->pParentType->pStaticFields + pFieldDef->memOffset;
		pMem = pFieldDef->pMemory;
		*(U64*)pMem = value;
	}
JIT_STORESTATICFIELD_INT64_end:
JIT_STORESTATICFIELD_F64_end:
JIT_STORESTATICFIELD_O_end: // 64bit only.
JIT_STORESTATICFIELD_PTR_end: // 64bit only.
	GO_NEXT();

JIT_STORESTATICFIELD_VALUETYPE_start:
	OPCODE_USE(JIT_STORESTATICFIELD_VALUETYPE);
	{
		tMD_FieldDef *pFieldDef;
		PTR pMem;

		pFieldDef = (tMD_FieldDef*)GET_OP_64( checkPointerTypes );
		pMem = pFieldDef->pMemory;
		POP_VALUETYPE(pMem, pFieldDef->memSize, pFieldDef->memSize);
	}
JIT_STORESTATICFIELD_VALUETYPE_end:
	GO_NEXT();

JIT_LOADSTATICFIELDADDRESS_CHECKTYPEINIT_start:
	op = JIT_LOADSTATICFIELDADDRESS_CHECKTYPEINIT;
	goto loadStaticFieldStart;
JIT_LOADSTATICFIELD_CHECKTYPEINIT_VALUETYPE_start:
	op = JIT_LOADSTATICFIELD_CHECKTYPEINIT_VALUETYPE;
	goto loadStaticFieldStart;
JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT32_start:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_F32_start:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_INTNATIVE_start: // intnative is 32bit
	op = JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT32;
	goto loadStaticFieldStart;
JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT64_start:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_F64_start:
	op = JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT64;
	goto loadStaticFieldStart;
JIT_LOADSTATICFIELD_CHECKTYPEINIT_O_start:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_PTR_start:
	op = JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT64; // 64bit
loadStaticFieldStart:
	OPCODE_USE(JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT32);
	{
		tMD_FieldDef *pFieldDef;
		tMD_TypeDef *pParentType;

		pFieldDef = (tMD_FieldDef*)GET_OP_64( checkPointerTypes );
		pParentType = pFieldDef->pParentType;
		// Check that any type (static) constructor has been called
		if (pParentType->isTypeInitialised == 0) {
			// Set the state to initialised
			pParentType->isTypeInitialised = 1;
			// Initialise the type (if there is a static constructor)
			if (pParentType->pStaticConstructor != NULL) {
				tMethodState *pCallMethodState;

				int stepBack = 4; // 64bit : opCode = 2, pFieldDef-ptr = 2

				// Call static constructor
				// Need to re-run this instruction when we return from static constructor call
				//pCurrentMethodState->ipOffset -= stepBack;
				pCurOp -= stepBack;
				pCallMethodState = MethodState_Direct(pThread, pParentType->pStaticConstructor, pCurrentMethodState, 0);
				// There can be no parameters, so don't need to set them up
				CHANGE_METHOD_STATE(pCallMethodState);
				GO_NEXT_CHECK();
			}
		}

		if (op == JIT_LOADSTATICFIELDADDRESS_CHECKTYPEINIT) {
			U64 value; // 64bit address
			value = (U64)(pFieldDef->pMemory);
			PUSH_U64(value);
		} else if (op == JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT32 ) {
			U32 value;
			value = *(U32*)(pFieldDef->pMemory);
			PUSH_U32(value);
		} else if (op == JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT64) {
			U64 value;
			value = *(U64*)(pFieldDef->pMemory);
			PUSH_U64(value);
		} else if (op == JIT_LOADSTATICFIELD_CHECKTYPEINIT_VALUETYPE) {
			PUSH_VALUETYPE(pFieldDef->pMemory, pFieldDef->memSize, pFieldDef->memSize);
		} else {
			Crash( "JIT_LOADSTATICFIELD unknown op: %d", op );
		}
	}
JIT_LOADSTATICFIELDADDRESS_CHECKTYPEINIT_end:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_VALUETYPE_end:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT32_end:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT64_end:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_INTNATIVE_end:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_F32_end:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_F64_end:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_O_end:
JIT_LOADSTATICFIELD_CHECKTYPEINIT_PTR_end:
	GO_NEXT();

JIT_INIT_VALUETYPE_start:
	OPCODE_USE(JIT_INIT_VALUETYPE);
	{
		tMD_TypeDef *pTypeDef;

		pTypeDef = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );
		pMem = POP_PTR();
		memset(pMem, 0, pTypeDef->instanceMemSize);
	}
JIT_INIT_VALUETYPE_end:
	GO_NEXT();

JIT_INIT_OBJECT_start:
	OPCODE_USE(JIT_INIT_OBJECT);
	{
		PTR pMem = POP_PTR();
		*(void**)pMem = NULL;
	}
JIT_INIT_OBJECT_end:
	GO_NEXT();

JIT_BOX_INT32_start:
JIT_BOX_F32_start:
JIT_BOX_INTNATIVE_start:
	OPCODE_USE(JIT_BOX_INT32);
	{
		tMD_TypeDef *pTypeDef;

		pTypeDef = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );
		heapPtr = Heap_AllocType(pTypeDef);
		u32Value = POP_U32();
		*(U32*)heapPtr = u32Value;
		PUSH_O(heapPtr);
	}
JIT_BOX_INT32_end:
JIT_BOX_F32_end:
JIT_BOX_INTNATIVE_end:
	GO_NEXT();

JIT_BOX_INT64_start:
JIT_BOX_F64_start:
OPCODE_USE(JIT_BOX_INT64);
	{
		tMD_TypeDef *pTypeDef = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );
		heapPtr = Heap_AllocType(pTypeDef);
		*(U64*)heapPtr = POP_U64();
		PUSH_O(heapPtr);
	}
JIT_BOX_INT64_end:
JIT_BOX_F64_end:
	GO_NEXT();

JIT_BOX_VALUETYPE_start:
	OPCODE_USE(JIT_BOX_VALUETYPE);
	{
		tMD_TypeDef *pTypeDef;

		pTypeDef = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );
		heapPtr = Heap_AllocType(pTypeDef);
		POP_VALUETYPE(heapPtr, pTypeDef->stackSize, pTypeDef->stackSize);
		PUSH_O(heapPtr);
	}
JIT_BOX_VALUETYPE_end:
	GO_NEXT();

JIT_BOX_O_start:
	pCurOp += 2; // 64bit
	// Fall-through
JIT_UNBOX2OBJECT_start: // TODO: This is not correct - it should check the type, just like CAST_CLASS
	OPCODE_USE(JIT_UNBOX2OBJECT);
	// Nothing to do
JIT_BOX_O_end:
JIT_UNBOX2OBJECT_end:
	GO_NEXT();

JIT_BOX_NULLABLE_start:
	OPCODE_USE(JIT_BOX_NULLABLE);
	{
		// Get the underlying type of the nullable type
		tMD_TypeDef *pType = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );

		// Take the nullable type off the stack. The +4 is because the of the HasValue field (Bool, size = 4 bytes)
		pCurEvalStack -= pType->stackSize + 4;
		// If .HasValue
		if (*(U32*)pCurEvalStack) {
			// Box the underlying type
			HEAP_PTR boxed;
			boxed = Heap_Box(pType, pCurEvalStack + 4);
			PUSH_O(boxed);
		} else {
			// Put a NULL pointer on the stack
			PUSH_O(NULL);
		}
	}
JIT_BOX_NULLABLE_end:
	GO_NEXT();

JIT_UNBOX2VALUETYPE_start:
	OPCODE_USE(JIT_UNBOX2VALUETYPE);
	{
		tMD_TypeDef *pTypeDef;
		HEAP_PTR heapPtr;

		heapPtr = POP_O();
		pTypeDef = Heap_GetType(heapPtr);
		PUSH_VALUETYPE(heapPtr, pTypeDef->stackSize, pTypeDef->stackSize);
	}
JIT_UNBOX2VALUETYPE_end:
	GO_NEXT();

JIT_UNBOX_NULLABLE_start:
	OPCODE_USE(JIT_UNBOX_NULLABLE);
	{
		tMD_TypeDef *pTypeDef = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );
		HEAP_PTR heapPtr;
		heapPtr = POP_O();
		if (heapPtr == NULL) {
			// Push .HasValue (= false)
			PUSH_U32(0);
			// And increase the stack pointer by the size of the underlying type
			// (the contents don't matter)
			pCurEvalStack += pTypeDef->stackSize;
		} else {
			// Push .HasValue (= true)
			PUSH_U32(1);
			// Push the contents of .Value
			PUSH_VALUETYPE(heapPtr, pTypeDef->stackSize, pTypeDef->stackSize);
		}
	}
JIT_UNBOX_NULLABLE_end:
	GO_NEXT();

JIT_LOADTOKEN_TYPE_start:
	OPCODE_USE(JIT_LOADTOKEN_TYPE);
	{
		tMD_TypeDef *pTypeDef;

		pTypeDef = (tMD_TypeDef*)GET_OP_64( checkPointerTypes );
		// Push new valuetype onto evaluation stack
		PUSH_PTR((PTR)pTypeDef);
	}
JIT_LOADTOKEN_TYPE_end:
	GO_NEXT();

JIT_LOADTOKEN_FIELD_start:
	OPCODE_USE(JIT_LOADTOKEN_FIELD);
	{
		tMD_FieldDef *pFieldDef;

		pFieldDef = (tMD_FieldDef*)GET_OP_64( checkPointerTypes );
		// Push new valuetype onto evaluation stack - only works on static fields.
		PUSH_PTR(pFieldDef->pMemory);
	}
JIT_LOADTOKEN_FIELD_end:
	GO_NEXT();

JIT_RETHROW_start:
	op = JIT_RETHROW;
	goto throwStart;
JIT_THROW_start:
	op = JIT_THROW;
throwStart:
	OPCODE_USE(JIT_THROW);
	{
		U32 i;
		tExceptionHeader *pCatch;
		tMethodState *pCatchMethodState;
		tMD_TypeDef *pExType;

		// Get the exception object
		if (op == JIT_RETHROW) {
			heapPtr = pThread->pCurrentExceptionObject;
		} else {
			heapPtr = POP_O();
throwHeapPtr:
			pThread->pCurrentExceptionObject = heapPtr;
		}
		SAVE_METHOD_STATE();
		pExType = Heap_GetType(heapPtr);
		// Find any catch exception clauses; look in the complete call stack
		pCatch = NULL;
		pCatchMethodState = pCurrentMethodState;
		for(;;) {
			for (i=0; i<pCatchMethodState->pMethod->pJITted->numExceptionHandlers; i++) {
				tExceptionHeader *pEx = &pCatchMethodState->pMethod->pJITted->pExceptionHeaders[i];
				if (pEx->flags == COR_ILEXCEPTION_CLAUSE_EXCEPTION &&
					pCatchMethodState->ipOffset - 1 >= pEx->tryStart &&
					pCatchMethodState->ipOffset - 1 < pEx->tryEnd &&
					Type_IsDerivedFromOrSame(pEx->pCatchTypeDef, pExType)) {
					
					// Found the correct catch clause to jump to
					pCatch = pEx;
					break;
				}
			}
			if (pCatch != NULL) {
				// Found a suitable exception handler
				break;
			}
			pCatchMethodState = pCatchMethodState->pCaller;
			if (pCatchMethodState == NULL) {
				Crash("Unhandled exception in %s.%s(): %s.%s",
					pCurrentMethodState->pMethod->pParentType->name,
					pCurrentMethodState->pMethod->name, pExType->nameSpace, pExType->name);
			}
		}
		// Unwind the stack down to the exception handler's stack frame (MethodState)
		// Run all finally clauses during unwinding
		pThread->pCatchMethodState = pCatchMethodState;
		pThread->pCatchExceptionHandler = pCatch;
		// Have to use the pThread->pCatchMethodState, as we could be getting here from END_FINALLY
		while (pCurrentMethodState != pThread->pCatchMethodState) {
			tMethodState *pPrevState;

finallyUnwindStack:
			for (i=pThread->nextFinallyUnwindStack; i<pCurrentMethodState->pMethod->pJITted->numExceptionHandlers; i++) {
				tExceptionHeader *pEx;

				pEx = &pCurrentMethodState->pMethod->pJITted->pExceptionHeaders[i];
				if (pEx->flags == COR_ILEXCEPTION_CLAUSE_FINALLY &&
					pCurrentMethodState->ipOffset - 1 >= pEx->tryStart &&
					pCurrentMethodState->ipOffset - 1 < pEx->tryEnd) {

					// Found a finally handler
					POP_ALL();
					CHANGE_METHOD_STATE(pCurrentMethodState);
					pCurrentMethodState->ipOffset = pEx->handlerStart;
					// Keep track of which finally clause should be executed next
					pThread->nextFinallyUnwindStack = i + 1;
					goto throwEnd;
				}
			}

			pPrevState = pCurrentMethodState->pCaller;
			MethodState_Delete(pThread, &pCurrentMethodState);
			pCurrentMethodState = pPrevState;
			// Reset the stack unwind tracker
			pThread->nextFinallyUnwindStack = 0;
		}
		// Set the IP to the catch handler
		pCurrentMethodState->ipOffset = pThread->pCatchExceptionHandler->handlerStart;
		// Set the current method state
		LOAD_METHOD_STATE();
		// Push onto this stack-frame's evaluation stack the opject thrown
		POP_ALL();
		PUSH_O(pThread->pCurrentExceptionObject);
	}
throwEnd:
JIT_THROW_end:
JIT_RETHROW_end:
	GO_NEXT_CHECK();

JIT_LEAVE_start:
	OPCODE_USE(JIT_LEAVE);
	{
		U32 i;
		tExceptionHeader *pFinally;

		// Find any finally exception clauses
		pFinally = NULL;
		for (i=0; i<pJIT->numExceptionHandlers; i++) {
			if (pJIT->pExceptionHeaders[i].flags == COR_ILEXCEPTION_CLAUSE_FINALLY &&
				pCurrentMethodState->ipOffset - 1 >= pJIT->pExceptionHeaders[i].tryStart &&
				pCurrentMethodState->ipOffset - 1 < pJIT->pExceptionHeaders[i].tryEnd) {
				// Found the correct finally clause to jump to
				pFinally = &pJIT->pExceptionHeaders[i];
				break;
			}
		}
		POP_ALL();
		ofs = GET_OP_32( 0 );
		if (pFinally != NULL) {
			// Jump to 'finally' section
			pCurOp = pOps + pFinally->handlerStart;
			pCurrentMethodState->pOpEndFinally = pOps + ofs;
		} else {
			// just branch
			pCurOp = pOps + ofs;
		}
	}
JIT_LEAVE_end:
	GO_NEXT_CHECK();

JIT_END_FINALLY_start:
	OPCODE_USE(JIT_END_FINALLY);
	if (pThread->nextFinallyUnwindStack > 0) {
		// unwinding stack, so jump back to unwind code
		goto finallyUnwindStack;
	} else {
		// Just empty the evaluation stack and continue on to the next opcode
		// (finally blocks are always after catch blocks, so execution can just continue)
		POP_ALL();
		// And jump to the correct instruction, as specified in the leave instruction
		pCurOp = pCurrentMethodState->pOpEndFinally;
	}
JIT_END_FINALLY_end:
	GO_NEXT_CHECK();

done:
	SAVE_METHOD_STATE();

	return THREAD_STATUS_RUNNING;
}

void JIT_Execute_Init() {
	// Initialise the JIT code addresses
	JIT_Execute(NULL, 0);
}

