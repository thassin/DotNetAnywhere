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

#if !defined (__JIT_H)
#define __JIT_H

typedef struct tJITted_ tJITted;
typedef struct tExceptionHeader_ tExceptionHeader;

#ifdef _EMSCRIPTEN

// [Steve] This overly-specific-looking int-returning 3-STRING-arg signature is because it's difficult
// to support arbitrary signatures given Emscripten's limitations around needing to know the original
// type of a function pointer when invoking it: https://kripken.github.io/emscripten-site/docs/porting/guidelines/function_pointer_issues.html
// My workaround is just to hard-code this as the only possible PInvoke method signature and then skip
// the code in PInvoke.c that tries to dynamically select a function pointer type.
//
// With more work I'm sure it would be possible to figure out a mechanism for getting the original
// Pinvoke.c logic to work. It might even just be as simple as changing the return type of fnPInvoke from int
// to U64, since it looks like that's hardcoded as the return type in Pinvoke.c. But I don't need to deal
// with that now.
typedef int(*fnPInvoke)(STRING libName, STRING funcName, STRING arg0);

#endif // _EMSCRIPTEN

#include "Types.h"

// jitops typeinfo is an U8 flag value.
// each 32-bit Ops value has it's own 8-bit type value.

#define JITOPS_TYPE_VAL_32		( 1 << 0 )	// 1
#define JITOPS_TYPE_VAL_64		( 1 << 1 )	// 2
#define JITOPS_TYPE_OP_32		( 1 << 2 )	// 4
#define JITOPS_TYPE_PTR_32		( 1 << 4 )	// 16
#define JITOPS_TYPE_BRANCH		( 1 << 5 )	// 32
#define JITOPS_TYPE_64_2ND		( 1 << 6 )	// 64

// stackitem typeinfo is an U8 value, in which:
// *) highest 2 bits encode the value type/kind, and
// *) lowest 6 bits encode a "reversed-offset" of a value.

// so, we assume that the stack data is allocated as 32-bit blocks,
// and for each 32-bit stack-data block we assign an 8-bit type value.

// the offset values are 0,1,2,... so they can be used to find out
// what is the size of the current stack item. if the item is too
// big, so that a maximum value of offset (63) is exceeded, the
// maximum value is used as the offset value.

// some examples:
// stackitem size=4	offset values: 0
// stackitem size=8	offset values: 1,0
// stackitem size=40	offset values: 9,8,7,6,5,4,3,2,1,0
// stackitem size=400	offset values: 63,63,63,...,63,62,61,...3,2,1,0

#define STACKITEM_TYPE_VALUE		1	// for int,long,float,double values.
#define STACKITEM_TYPE_POINTER		2	// for pointers (O and PTR).
#define STACKITEM_TYPE_VALUETYPE	3	// for valuetypes.

#define STACKITEM_SIZE_MASK		0x3f

struct tJITted_ {
	// The JITted opcodes
	U32 *pOps;
#ifdef ENABLE_JITOPS_TYPEINFO
	// Types of JITted opcodes/data (for debug purposes only).
	U8 *pOpTypes;
#endif // ENABLE_JITOPS_TYPEINFO
	// The corresponding sequence points in the original CIL
	U32 *pOpSequencePoints;
	// The maximum size of the evaluation stack
	U32 maxStack;
	// The required size of the locals stack
	U32 localsStackSize;
	// Number of exception handler headers
	U32 numExceptionHandlers;
	// Pointer to the exception handler headers (NULL if none)
	tExceptionHeader *pExceptionHeaders;
	// If we have debug metadata for this method, points to it
	tDebugMetaDataEntry *pDebugMetadataEntry;
#ifdef GEN_COMBINED_OPCODES
	// The number of bytes used by this JITted method - to include ALL bytes:
	// The size of the opcodes, plus the size of the combined opcodes.
	U32 opsMemSize;
	// Store all memory used to store combined opcodes, so they can be free()d later
	tCombinedOpcodesMem *pCombinedOpcodesMem;
#endif
};

#include "MetaDataTables.h"
#include "Thread.h"

#define COR_ILEXCEPTION_CLAUSE_EXCEPTION 0
#define COR_ILEXCEPTION_CLAUSE_FINALLY 2

struct tExceptionHeader_ {

// NOTICE this struct must remain constant in size and layout, because memcpy() is used
// for filling this, see JIT_Prepare() at JIT.c line 1767 for example.

	U32 flags;
	U32 tryStart;
	U32 tryEnd;
	U32 handlerStart;
	U32 handlerEnd;
	union {
		// Class token for type-based exception handler
		IDX_TABLE classToken;
		// Filter code offset for filter-based exception handler (not supported)
		U32 filterOffset;
		// The TypeDef of the catch type
		tMD_TypeDef *pCatchTypeDef;
	} u;
};

typedef struct tJITCallNative_ tJITCallNative;
struct tJITCallNative_ {
	U32 opCode;
	// The method meta-data
	tMD_MethodDef *pMethodDef;
	// the native pointer to the function
	fnInternalCall fn;
	// The RET instruction. This is needed when the native function has blocking IO or sleep
	U32 retOpCode;
};

typedef struct tJITCallPInvoke_ tJITCallPInvoke;
struct tJITCallPInvoke_ {
	U32 opCode;
	// The native function to call
#ifdef _EMSCRIPTEN
	fnPInvoke fn;
#else // _EMSCRIPTEN
	void* fn;
#endif // _EMSCRIPTEN
	// The method that is being called
	tMD_MethodDef *pMethod;
	// The ImplMap of the function that's being called
	tMD_ImplMap *pImplMap;
};

typedef struct tJITCodeInfo_ {
	// The beginning and end of the actual native code to run the JIT opcode.
	void *pStart;
	void *pEnd;
	U32 isDynamic;
} tJITCodeInfo;

#include "JIT_OpCodes.h"

extern tJITCodeInfo jitCodeInfo[JIT_OPCODE_MAXNUM];
extern tJITCodeInfo jitCodeGoNext;

void JIT_Execute_Init();

//void JIT_Prepare(tMD_MethodDef *pMethodDef);
void JIT_Prepare(tMD_MethodDef *pMethodDef, U32 genCombinedOpcodes);

U32 JIT_Execute(tThread *pThread, U32 numInst);

#ifdef DIAG_OPCODE_TIMES
#include "JIT_OpCodes.h"
extern U64 opcodeTimes[JIT_OPCODE_MAXNUM];
#endif // DIAG_OPCODE_TIMES

#ifdef DIAG_OPCODE_USE
#include "JIT_OpCodes.h"
extern U32 opcodeNumUses[JIT_OPCODE_MAXNUM];
#endif // DIAG_OPCODE_USE

const char * JIT_GetOpCodeName( int opCode );

#endif // __JIT_H
