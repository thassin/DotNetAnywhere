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

#include "MetaData.h"

#include "Types.h"
#include "Type.h"
#include "RVA.h"

#include <stddef.h>

unsigned int MetaData_DecodeSigEntry(SIG *pSig) {
	return MetaData_DecodeSigEntryExt(pSig, 1);
}

unsigned int MetaData_DecodeSigEntryExt(SIG *pSig, int coerceFFToZero) {
	unsigned char a,b,c,d;
	a = *(*pSig)++;
	if ((a & 0x80) == 0) {
		// 1-byte entry
		return a;
	}
	// Special case
	if (a == 0xff) {
		return coerceFFToZero == 1 ? 0 : 0xffffffff;
	}

	b = *(*pSig)++;
	if ((a & 0xc0) == 0x80) {
		// 2-byte entry
		return ((int)(a & 0x3f)) << 8 | b;
	}
	// 4-byte entry
	c = *(*pSig)++;
	d = *(*pSig)++;
	return ((int)(a & 0x1f)) << 24 | ((int)b) << 16 | ((int)c) << 8 | d;
}

IDX_TABLE MetaData_DecodeSigEntryToken(SIG *pSig) {
	static U8 tableID[4] = {MD_TABLE_TYPEDEF, MD_TABLE_TYPEREF, MD_TABLE_TYPESPEC, 0};

	U32 entry = MetaData_DecodeSigEntry(pSig);
	return MAKE_TABLE_INDEX(tableID[entry & 0x3], entry >> 2);
}

tMetaData* MetaData() {
	tMetaData *pRet = TMALLOC(tMetaData);
	memset(pRet, 0, sizeof(tMetaData));
	return pRet;
}

void MetaData_LoadStrings(tMetaData *pThis, void *pStream, unsigned int streamLen) {
	pThis->strings.pStart = (unsigned char*)pStream;

	log_f(1, "Loaded strings\n");
}

unsigned int MetaData_DecodeHeapEntryLength(unsigned char **ppHeapEntry) {
	return MetaData_DecodeSigEntry((SIG*)ppHeapEntry);
}

void MetaData_LoadBlobs(tMetaData *pThis, void *pStream, unsigned int streamLen) {
	pThis->blobs.pStart = (unsigned char*)pStream;

	log_f(1, "Loaded blobs\n");

}

void MetaData_LoadUserStrings(tMetaData *pThis, void *pStream, unsigned int streamLen) {
	pThis->userStrings.pStart = (unsigned char*)pStream;

	log_f(1, "Loaded User Strings\n");

}

void MetaData_LoadGUIDs(tMetaData *pThis, void *pStream, unsigned int streamLen) {
	pThis->GUIDs.numGUIDs = streamLen / 16;

	// This is stored -16 because numbering starts from 1. This means that a simple indexing calculation
	// can be used, as if it started from 0
	pThis->GUIDs.pGUID1 = (unsigned char*)pStream;

	log_f(1, "Read %d GUIDs\n", pThis->GUIDs.numGUIDs);
}

/*
Format of definition strings:
Always 2 characters to togther. 1st character defines source, 2nd defines destination.
Sources:
	c: 8-bit value
	s: 16-bit short
	i: 32-bit int
	S: Index into string heap
	G: Index into GUID heap
	B: Index into BLOB heap
	0: Coded index: TypeDefOrRef
	1: Coded index: HasConstant
	2: Coded index: HasCustomAttribute
	3: Coded index: HasFieldMarshall
	4: Coded index: HasDeclSecurity
	5: Coded index: MemberRefParent
	6: Coded index: HasSemantics
	7: Coded index: MethodDefOrRef
	8: Coded index: MemberForwarded
	9: Coded index: Implementation
	:: Coded index: CustomAttributeType
	;: Coded index: ResolutionScope
	<: Coded index: TypeOrMethodDef
	\x00 - \x2c: Simple indexes into the respective table
	^: RVA: Convert to pointer
	x: Nothing, use 0
	m: This metadata pointer
	l: (lower case L) Boolean, is this the last entry in this table?
	I: The original table index for this table item
Destination:
	x: nowhere, ignore
	*: 32-bit index into relevant heap;
		Or coded index - MSB = which table, other 3 bytes = table index
		Or 32-bit int
		Or pointer (also RVA)
	s: 16-bit value
	c: 8-bit value
*/
static char* tableDefs[] = {
	// 0x00
	"sxS*G*GxGx",
	// 0x01
	"x*;*S*S*",
	// 0x02
	"x*m*i*S*S*0*\x04*\x06*xclcxcxcx*x*x*x*x*x*x*x*x*x*x*I*x*x*x*x*x*x*x*x*x*x*x*x*",
	// 0x03
	NULL,
	// 0x04
	"x*m*ssxsS*B*x*x*x*x*I*x*",
	// 0x05
	NULL,
	// 0x06
	"x*m*^*ssssS*B*\x08*x*x*x*x*x*x*I*x*x*x*"
#ifdef GEN_COMBINED_OPCODES
	"x*x*x*x*x*x*"
#endif
#ifdef DIAG_METHOD_CALLS
	"x*x*x*"
#endif
	,
	// 0x07
	NULL,
	// 0x08
	"ssssS*",
	// 0x09
	"\x02*0*",
	// 0x0A
	"x*5*S*B*",
	// 0x0B
	"ccccxs1*B*",
	// 0x0C
	"2*:*B*",
	// 0x0D
	NULL,
	// 0x0E
	"ssxs4*B*",
	// 0x0F
	"ssxsi*\x02*",
	// 0x10
	NULL,
	// 0x11
	"B*",
	// 0x12
	"\x02*\x14*",
	// 0x13
	NULL,
	// 0x14
	"ssxsS*0*",
	// 0x15
	"\x02*\x17*",
	// 0x16
	NULL,
	// 0x17
	"ssxsS*B*",
	// 0x18
	"ssxs\06*6*",
	// 0x19
	"\x02*7*7*",
	// 0x1A
	"S*",
	// 0x1B
	"x*m*B*",
	// 0x1C
	"ssxs8*S*\x1a*",
	// 0x1D
	"^*\x04*",
	// 0x1E
	NULL,
	// 0x1F
	NULL,
	// 0x20
	"i*ssssssssi*B*S*S*",
	// 0x21
	NULL,
	// 0x22
	NULL,
	// 0x23
	"ssssssssi*B*S*S*B*",
	// 0x24
	NULL,
	// 0x25
	NULL,
	// 0x26
	NULL,
	// 0x27
	NULL,
	// 0x28
	NULL,
	// 0x29
	"\x02*\x02*",
	// 0x2A
	"ssss<*S*",
	// 0x2B
	"x*m*7*B*",
	// 0x2C
	"\x2a*0*",
};

// Coded indexes use this lookup table.
// Note that the extra 'z' characters are important!
// (Because of how the lookup works each string must be a power of 2 in length)
static unsigned char* codedTags[] = {
	// TypeDefOrRef
	"\x02\x01\x1Bz",
	// HasConstant
	"\x04\x08\x17z",
	// HasCustomAttribute
	"\x06\x04\x01\x02\x08\x09\x0A\x00\x0E\x17\x14\x11\x1A\x1B\x20\x23\x26\x27\x28zzzzzzzzzzzzz",
	// HasFieldMarshall
	"\x04\x08",
	// HasDeclSecurity
	"\x02\x06\x20z",
	// MemberRefParent
	"z\x01\x1A\x06\x1Bzzz",
	// HasSemantics
	"\x14\x17",
	// MethodDefOrRef
	"\x06\x0A",
	// MemberForwarded
	"\x04\x06",
	// Implementation
	"\x26\x23\x27z",
	// CustomAttributeType
	"zz\x06\x0Azzzz",
	// ResolutionScope
	"\x00\x1A\x23\x01",
	// TypeOrMethodDef
	"\x02\x06",
};

static unsigned char codedTagBits[] = {
	2, 2, 5, 1, 2, 3, 1, 1, 1, 2, 3, 2, 1
};

static unsigned char tableRowSize[MAX_TABLES];

void MetaData_Init() {
	U32 i;
	for (i=0; i<MAX_TABLES; i++) {
		tableRowSize[i] = 0;
	}
}

static unsigned int GetU16(unsigned char *pSource) {
	unsigned int a,b;

	a = pSource[0];
	b = pSource[1];
	return a | (b << 8);
}

static unsigned int GetU32(unsigned char *pSource) {
	unsigned int a,b,c,d;

	a = pSource[0];
	b = pSource[1];
	c = pSource[2];
	d = pSource[3];
	return a | (b << 8) | (c << 16) | (d << 24);
}

// TommiHassinen 20221012 about 64-bit changes:
// => the original 32bit metadata tables are dense (since those were designed that way).
// => but introducing 64bit values there will cause considerable amount of padding(s) to structs.
// => here we pre-calculate offsets for each of the struct fields, and use these offsets to write values.
// => as a consequence, we are also free to change the ordering of fields in MetaDataTables.h structs.

// https://stackoverflow.com/questions/9788679/how-to-get-the-relative-address-of-a-field-in-a-structure-dump-c 

#define FIELDINFO_END 0, -1

static int table_0_fieldInfo[] = {
	offsetof( struct tMD_Module_, name ), 1,
	offsetof( struct tMD_Module_, mvID ), 1,
	FIELDINFO_END
};

static int table_1_fieldInfo[] = {
	offsetof( struct tMD_TypeRef_, pTypeDef ), 1,
	offsetof( struct tMD_TypeRef_, resolutionScope ), 0,
	offsetof( struct tMD_TypeRef_, name ), 1,
	offsetof( struct tMD_TypeRef_, nameSpace ), 1,
	FIELDINFO_END
};

static int table_2_fieldInfo[] = {
	offsetof( struct tMD_TypeDef_, pTypeDef ), 1,
	offsetof( struct tMD_TypeDef_, pMetaData ), 1,
	offsetof( struct tMD_TypeDef_, flags ), 0,
	offsetof( struct tMD_TypeDef_, name ), 1,
	offsetof( struct tMD_TypeDef_, nameSpace ), 1,
	offsetof( struct tMD_TypeDef_, extends ), 0,
	offsetof( struct tMD_TypeDef_, fieldList ), 0,
	offsetof( struct tMD_TypeDef_, methodList ), 0,
	offsetof( struct tMD_TypeDef_, isFilled ), 0,
	offsetof( struct tMD_TypeDef_, isLast ), 0,
	offsetof( struct tMD_TypeDef_, isValueType ), 0,
	offsetof( struct tMD_TypeDef_, stackType ), 0,
	offsetof( struct tMD_TypeDef_, instanceMemSize ), 0,
	offsetof( struct tMD_TypeDef_, pParent ), 1,
	offsetof( struct tMD_TypeDef_, pVTable ), 1,
	offsetof( struct tMD_TypeDef_, numVirtualMethods ), 0,
	offsetof( struct tMD_TypeDef_, pStaticFields ), 1,
	offsetof( struct tMD_TypeDef_, isTypeInitialised ), 0, // NOTICE this is a 32bit field which covers 4x 8bit fields.
	offsetof( struct tMD_TypeDef_, pStaticConstructor ), 1,
	offsetof( struct tMD_TypeDef_, arrayElementSize ), 0,
	offsetof( struct tMD_TypeDef_, stackSize ), 0,
	offsetof( struct tMD_TypeDef_, numInterfaces ), 0,
	offsetof( struct tMD_TypeDef_, pInterfaceMaps ), 1,
	offsetof( struct tMD_TypeDef_, tableIndex ), 0,
	offsetof( struct tMD_TypeDef_, pGenericInstances ), 1,
	offsetof( struct tMD_TypeDef_, pGenericDefinition ), 1,
	offsetof( struct tMD_TypeDef_, ppClassTypeArgs ), 1,
	offsetof( struct tMD_TypeDef_, pArrayElementType ), 1,
	offsetof( struct tMD_TypeDef_, numFields ), 0,
	offsetof( struct tMD_TypeDef_, ppFields ), 1,
	offsetof( struct tMD_TypeDef_, staticFieldSize ), 0,
	offsetof( struct tMD_TypeDef_, numMethods ), 0,
	offsetof( struct tMD_TypeDef_, ppMethods ), 1,
	offsetof( struct tMD_TypeDef_, pNestedIn ), 1,
	offsetof( struct tMD_TypeDef_, pFinalizer ), 1,
	offsetof( struct tMD_TypeDef_, typeObject ), 1,
	FIELDINFO_END
};

static int table_4_fieldInfo[] = {
	offsetof( struct tMD_FieldDef_, pFieldDef ), 1,
	offsetof( struct tMD_FieldDef_, pMetaData ), 1,
	offsetof( struct tMD_FieldDef_, flags ), 0,
	offsetof( struct tMD_FieldDef_, padding0 ), 0,
	offsetof( struct tMD_FieldDef_, name ), 1,
	offsetof( struct tMD_FieldDef_, signature ), 1,
	offsetof( struct tMD_FieldDef_, pType ), 1,
	offsetof( struct tMD_FieldDef_, pParentType ), 1,
	offsetof( struct tMD_FieldDef_, memOffset ), 0,
	offsetof( struct tMD_FieldDef_, memSize ), 0,
	offsetof( struct tMD_FieldDef_, tableIndex ), 0,
	offsetof( struct tMD_FieldDef_, pMemory ), 1,
	FIELDINFO_END
};

static int table_6_fieldInfo[] = {
	offsetof( struct tMD_MethodDef_, pMethodDef ), 1,
	offsetof( struct tMD_MethodDef_, pMetaData ), 1,
	offsetof( struct tMD_MethodDef_, pCIL ), 1,
	offsetof( struct tMD_MethodDef_, implFlags ), 0,
	offsetof( struct tMD_MethodDef_, flags ), 0,
	offsetof( struct tMD_MethodDef_, name ), 1,
	offsetof( struct tMD_MethodDef_, signature ), 1,
	offsetof( struct tMD_MethodDef_, paramList ), 0,
	offsetof( struct tMD_MethodDef_, pJITted ), 1,
	offsetof( struct tMD_MethodDef_, isFilled ), 0, // NOTICE this is a 32bit field which covers 2x 8bit + 16bit fields.
	offsetof( struct tMD_MethodDef_, pParams ), 1,
	offsetof( struct tMD_MethodDef_, parameterStackSize ), 0,
	offsetof( struct tMD_MethodDef_, pReturnType ), 1,
	offsetof( struct tMD_MethodDef_, pParentType ), 1,
	offsetof( struct tMD_MethodDef_, tableIndex ), 0,
	offsetof( struct tMD_MethodDef_, vTableOfs ), 0,
	offsetof( struct tMD_MethodDef_, ppMethodTypeArgs ), 1,
	offsetof( struct tMD_MethodDef_, pGenericMethodInstances ), 1,
	FIELDINFO_END
};

static int table_8_fieldInfo[] = {
	offsetof( struct tMD_Param_, flags ), 0,
	offsetof( struct tMD_Param_, sequence ), 0,
	offsetof( struct tMD_Param_, name ), 1,
	FIELDINFO_END
};

static int table_9_fieldInfo[] = {
	offsetof( struct tMD_InterfaceImpl_, class_ ), 0,
	offsetof( struct tMD_InterfaceImpl_, interface_ ), 0,
	FIELDINFO_END
};

static int table_10_fieldInfo[] = {
	offsetof( struct tMD_MemberRef_, u ), 1,
	offsetof( struct tMD_MemberRef_, class_ ), 0,
	offsetof( struct tMD_MemberRef_, name ), 1,
	offsetof( struct tMD_MemberRef_, signature ), 1,
	FIELDINFO_END
};

static int table_11_fieldInfo[] = {
	offsetof( struct tMD_Constant_, type ), 0,
	offsetof( struct tMD_Constant_, padding0 ), 0,
	offsetof( struct tMD_Constant_, padding1 ), 0,
	offsetof( struct tMD_Constant_, parent ), 0,
	offsetof( struct tMD_Constant_, value ), 1,
	FIELDINFO_END
};

static int table_12_fieldInfo[] = {
	offsetof( struct tMD_CustomAttribute_, parent ), 0,
	offsetof( struct tMD_CustomAttribute_, type ), 0,
	offsetof( struct tMD_CustomAttribute_, value ), 1,
	FIELDINFO_END
};

static int table_14_fieldInfo[] = {
	offsetof( struct tMD_DeclSecurity_, action ), 0,
	offsetof( struct tMD_DeclSecurity_, padding0 ), 0,
	offsetof( struct tMD_DeclSecurity_, parent ), 0,
	offsetof( struct tMD_DeclSecurity_, permissionSet ), 1,
	FIELDINFO_END
};

static int table_15_fieldInfo[] = {
	offsetof( struct tMD_ClassLayout_, packingSize ), 0,
	offsetof( struct tMD_ClassLayout_, padding0 ), 0,
	offsetof( struct tMD_ClassLayout_, classSize ), 0,
	offsetof( struct tMD_ClassLayout_, parent ), 0,
	FIELDINFO_END
};

static int table_17_fieldInfo[] = {
	offsetof( struct tMD_StandAloneSig_, signature ), 1,
	FIELDINFO_END
};

static int table_18_fieldInfo[] = {
	offsetof( struct tMD_EventMap_, parent ), 0,
	offsetof( struct tMD_EventMap_, eventList ), 0,
	FIELDINFO_END
};

static int table_20_fieldInfo[] = {
	offsetof( struct tMD_Event_, eventFlags ), 0,
	offsetof( struct tMD_Event_, padding0 ), 0,
	offsetof( struct tMD_Event_, name ), 1,
	offsetof( struct tMD_Event_, eventType ), 0,
	FIELDINFO_END
};

static int table_21_fieldInfo[] = {
	offsetof( struct tMD_PropertyMap_, parent ), 0,
	offsetof( struct tMD_PropertyMap_, propertyList ), 0,
	FIELDINFO_END
};

static int table_23_fieldInfo[] = {
	offsetof( struct tMD_Property_, flags ), 0,
	offsetof( struct tMD_Property_, padding0 ), 0,
	offsetof( struct tMD_Property_, name ), 1,
	offsetof( struct tMD_Property_, typeSig ), 1,
	FIELDINFO_END
};

static int table_24_fieldInfo[] = {
	offsetof( struct tMD_MethodSemantics_, semantics ), 0,
	offsetof( struct tMD_MethodSemantics_, padding0 ), 0,
	offsetof( struct tMD_MethodSemantics_, method ), 0,
	offsetof( struct tMD_MethodSemantics_, association ), 0,
	FIELDINFO_END
};

static int table_25_fieldInfo[] = {
	offsetof( struct tMD_MethodImpl_, class_ ), 0,
	offsetof( struct tMD_MethodImpl_, methodBody ), 0,
	offsetof( struct tMD_MethodImpl_, methodDeclaration ), 0,
	FIELDINFO_END
};

static int table_26_fieldInfo[] = {
	offsetof( struct tMD_ModuleRef_, name ), 1,
	FIELDINFO_END
};

static int table_27_fieldInfo[] = {
	offsetof( struct tMD_TypeSpec_, pTypeDef ), 1,
	offsetof( struct tMD_TypeSpec_, pMetaData ), 1,
	offsetof( struct tMD_TypeSpec_, signature ), 1,
	FIELDINFO_END
};

static int table_28_fieldInfo[] = {
	offsetof( struct tMD_ImplMap_, mappingFlags ), 0,
	offsetof( struct tMD_ImplMap_, padding ), 0,
	offsetof( struct tMD_ImplMap_, memberForwarded ), 0,
	offsetof( struct tMD_ImplMap_, importName ), 1,
	offsetof( struct tMD_ImplMap_, importScope ), 0,
	FIELDINFO_END
};

static int table_29_fieldInfo[] = {
	offsetof( struct tMD_FieldRVA_, rva ), 1,
	offsetof( struct tMD_FieldRVA_, field ), 0,
	FIELDINFO_END
};

static int table_32_fieldInfo[] = {
	offsetof( struct tMD_Assembly_, hashAlgID ), 0,
	offsetof( struct tMD_Assembly_, majorVersion ), 0,
	offsetof( struct tMD_Assembly_, minorVersion ), 0,
	offsetof( struct tMD_Assembly_, buildNumber ), 0,
	offsetof( struct tMD_Assembly_, revisionNumber ), 0,
	offsetof( struct tMD_Assembly_, flags ), 0,
	offsetof( struct tMD_Assembly_, publicKey ), 1,
	offsetof( struct tMD_Assembly_, name ), 1,
	offsetof( struct tMD_Assembly_, culture ), 1,
	FIELDINFO_END
};

static int table_35_fieldInfo[] = {
	offsetof( struct tMD_AssemblyRef_, majorVersion ), 0,
	offsetof( struct tMD_AssemblyRef_, minorVersion ), 0,
	offsetof( struct tMD_AssemblyRef_, buildNumber ), 0,
	offsetof( struct tMD_AssemblyRef_, revisionNumber ), 0,

	offsetof( struct tMD_AssemblyRef_, flags ), 0,
	offsetof( struct tMD_AssemblyRef_, publicKeyOrToken ), 1,
	offsetof( struct tMD_AssemblyRef_, name ), 1,
	offsetof( struct tMD_AssemblyRef_, culture ), 1,
	offsetof( struct tMD_AssemblyRef_, hashValue ), 1,
	FIELDINFO_END
};
static int table_41_fieldInfo[] = {
	offsetof( struct tMD_NestedClass_, nestedClass ), 0,
	offsetof( struct tMD_NestedClass_, enclosingClass ), 0,
	FIELDINFO_END
};

static int table_42_fieldInfo[] = {
	offsetof( struct tMD_GenericParam_, number ), 0,
	offsetof( struct tMD_GenericParam_, flags ), 0,
	offsetof( struct tMD_GenericParam_, owner ), 0,
	offsetof( struct tMD_GenericParam_, name ), 1,
	FIELDINFO_END
};

static int table_43_fieldInfo[] = {
	offsetof( struct tMD_MethodSpec_, pMethodDef ), 1,
	offsetof( struct tMD_MethodSpec_, pMetaData ), 1,
	offsetof( struct tMD_MethodSpec_, method ), 0,
	offsetof( struct tMD_MethodSpec_, instantiation ), 1,
	FIELDINFO_END
};

static int table_44_fieldInfo[] = {
	offsetof( struct tMD_GenericParamConstraint_, pGenericParam ), 1,
	offsetof( struct tMD_GenericParamConstraint_, constraint ), 0,
	FIELDINFO_END
};

// Loads a single table, returns pointer to table in memory.
static void* LoadSingleTable(tMetaData *pThis, tRVA *pRVA, int tableID, void **ppTable) {
	int numRows = pThis->tables.numRows[tableID];
	int rowLen = 0; // Number of bytes taken by each row in memory.
	int i, row;
	char *pDef = tableDefs[tableID];
	int defLen = (int)strlen(pDef);
	void *pRet;
	unsigned char *pSource = *ppTable;
	unsigned char *pDest;
	U64 v = 0; // is possibly a pointer!

// TommiHassinen 20221012 about 64-bit changes:
// => here we fill structures defined in MetaDataTables.h
// => originally only 8,16 and 32 bit values were used, but pointer values must be 64bit here.
// => checks added for structure sizes, item counts written, etc...

	// Determine the destination row size, if not already known.
	if (tableRowSize[tableID] == 0) {

rowLen = 0;
switch ( tableID ) {
	case 0:		rowLen = sizeof( tMD_Module ); break;
	case 1:		rowLen = sizeof( tMD_TypeRef ); break;
	case 2:		rowLen = sizeof( tMD_TypeDef ); break;
	case 4:		rowLen = sizeof( tMD_FieldDef ); break;
	case 6:		rowLen = sizeof( tMD_MethodDef ); break;
	case 8:		rowLen = sizeof( tMD_Param ); break;
	case 9:		rowLen = sizeof( tMD_InterfaceImpl ); break;
	case 10:	rowLen = sizeof( tMD_MemberRef ); break;
	case 11:	rowLen = sizeof( tMD_Constant ); break;
	case 12:	rowLen = sizeof( tMD_CustomAttribute ); break;
	case 14:	rowLen = sizeof( tMD_DeclSecurity ); break;
	case 15:	rowLen = sizeof( tMD_ClassLayout ); break;
	case 17:	rowLen = sizeof( tMD_StandAloneSig ); break;
	case 18:	rowLen = sizeof( tMD_EventMap ); break;
	case 20:	rowLen = sizeof( tMD_Event ); break;
	case 21:	rowLen = sizeof( tMD_PropertyMap ); break;
	case 23:	rowLen = sizeof( tMD_Property ); break;
	case 24:	rowLen = sizeof( tMD_MethodSemantics ); break;
	case 25:	rowLen = sizeof( tMD_MethodImpl ); break;
	case 26:	rowLen = sizeof( tMD_ModuleRef ); break;
	case 27:	rowLen = sizeof( tMD_TypeSpec ); break;
	case 28:	rowLen = sizeof( tMD_ImplMap ); break;
	case 29:	rowLen = sizeof( tMD_FieldRVA ); break;
	case 32:	rowLen = sizeof( tMD_Assembly ); break;
	case 35:	rowLen = sizeof( tMD_AssemblyRef ); break;
	case 41:	rowLen = sizeof( tMD_NestedClass ); break;
	case 42:	rowLen = sizeof( tMD_GenericParam ); break;
	case 43:	rowLen = sizeof( tMD_MethodSpec ); break;
	case 44:	rowLen = sizeof( tMD_GenericParamConstraint ); break;
}

int expectedSize = -1;
switch ( tableID ) {
	case 0:		expectedSize = 16; break;
	case 1:		expectedSize = 32; break;
//	case 2:		expectedSize = 232; break; // before 20240723
	case 2:		expectedSize = 240; break; // 20240723 "staticFieldSize_refTypeFields" added.
	case 4:		expectedSize = 80; break;
	case 6:		expectedSize = 128; break;
	case 8:		expectedSize = 16; break;
	case 9:		expectedSize = 8; break;
	case 10:	expectedSize = 32; break;
	case 11:	expectedSize = 16; break;
	case 12:	expectedSize = 16; break;
	case 14:	expectedSize = 16; break;
	case 15:	expectedSize = 12; break;
	case 17:	expectedSize = 8; break;
	case 18:	expectedSize = 8; break;
	case 20:	expectedSize = 24; break;
	case 21:	expectedSize = 8; break;
	case 23:	expectedSize = 24; break;
	case 24:	expectedSize = 12; break;
	case 25:	expectedSize = 12; break;
	case 26:	expectedSize = 8; break;
	case 27:	expectedSize = 24; break;
	case 28:	expectedSize = 24; break;
	case 29:	expectedSize = 16; break;
	case 32:	expectedSize = 40; break;
	case 35:	expectedSize = 48; break;
	case 41:	expectedSize = 8; break;
	case 42:	expectedSize = 16; break;
	case 43:	expectedSize = 32; break;
	case 44:	expectedSize = 16; break;
}

if ( rowLen != expectedSize ) {
    Crash( "for tableID=%d rowLen=%d is not as expected: %d\n", tableID, rowLen, expectedSize );
}

		tableRowSize[tableID] = rowLen;
	} else {
		rowLen = tableRowSize[tableID];
	}

int *fieldInfo = NULL;
switch ( tableID ) {
	case 0:		fieldInfo = table_0_fieldInfo; break;
	case 1:		fieldInfo = table_1_fieldInfo; break;
	case 2:		fieldInfo = table_2_fieldInfo; break;
	case 4:		fieldInfo = table_4_fieldInfo; break;
	case 6:		fieldInfo = table_6_fieldInfo; break;
	case 8:		fieldInfo = table_8_fieldInfo; break;
	case 9:		fieldInfo = table_9_fieldInfo; break;
	case 10:	fieldInfo = table_10_fieldInfo; break;
	case 11:	fieldInfo = table_11_fieldInfo; break;
	case 12:	fieldInfo = table_12_fieldInfo; break;
	case 14:	fieldInfo = table_14_fieldInfo; break;
	case 15:	fieldInfo = table_15_fieldInfo; break;
	case 17:	fieldInfo = table_17_fieldInfo; break;
	case 18:	fieldInfo = table_18_fieldInfo; break;
	case 20:	fieldInfo = table_20_fieldInfo; break;
	case 21:	fieldInfo = table_21_fieldInfo; break;
	case 23:	fieldInfo = table_23_fieldInfo; break;
	case 24:	fieldInfo = table_24_fieldInfo; break;
	case 25:	fieldInfo = table_25_fieldInfo; break;
	case 26:	fieldInfo = table_26_fieldInfo; break;
	case 27:	fieldInfo = table_27_fieldInfo; break;
	case 28:	fieldInfo = table_28_fieldInfo; break;
	case 29:	fieldInfo = table_29_fieldInfo; break;
	case 32:	fieldInfo = table_32_fieldInfo; break;
	case 35:	fieldInfo = table_35_fieldInfo; break;
	case 41:	fieldInfo = table_41_fieldInfo; break;
	case 42:	fieldInfo = table_42_fieldInfo; break;
	case 43:	fieldInfo = table_43_fieldInfo; break;
	case 44:	fieldInfo = table_43_fieldInfo; break;
}

if ( fieldInfo == NULL ) {
    Crash( "for tableID=%d fieldInfo is NULL\n", tableID );
}

	// Allocate memory for destination table
	pDest = pRet = malloc(numRows * rowLen);

	// Load table
	for (row=0; row<numRows; row++) {

int fieldIndex = 0;
int rowItemBytes = 0;

		for (i=0; i<defLen; i += 2) {

int is64bit_by_value_source = 0;

			unsigned char d = pDef[i];
			if (d < MAX_TABLES) {
				if (pThis->tables.numRows[d] < 0x10000) {
					// Use 16-bit offset
					v = GetU16(pSource);
					pSource += 2;
				} else {
					// Use 32-bit offset
					v = GetU32(pSource);
					pSource += 4;
				}
				v |= d << 24;
			} else {
				switch (d) {
					case 'c': // 8-bit value
						v = *(U8*)pSource;
						pSource++;
						break;
					case 's': // 16-bit short
						v = GetU16(pSource);
						pSource += 2;
						break;
					case 'i': // 32-bit int
						v = GetU32(pSource);
						pSource += 4;
						break;
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case ':':
					case ';':
					case '<':
						{
							int ofs = pDef[i] - '0';
							char* pCoding = codedTags[ofs];
							int tagBits = codedTagBits[ofs];
							unsigned char tag = *pSource & ((1 << tagBits) - 1);
							int idxIntoTableID = pCoding[tag]; // The actual table index that we're looking for
							if (idxIntoTableID < 0 || idxIntoTableID > MAX_TABLES) {
								Crash("Error: Bad table index: 0x%02x\n", idxIntoTableID);
							}
							if (pThis->tables.codedIndex32Bit[ofs]) {
								// Use 32-bit number
								v = GetU32(pSource) >> tagBits;
								pSource += 4;
							} else {
								// Use 16-bit number
								v = GetU16(pSource) >> tagBits;
								pSource += 2;
							}
							v |= idxIntoTableID << 24;
						}
						break;
					case 'S': // index into string heap
						if (pThis->index32BitString) {
							v = GetU32(pSource);
							pSource += 4;
						} else {
							v = GetU16(pSource);
							pSource += 2;
						}
						v = (U64)(pThis->strings.pStart + v);
is64bit_by_value_source = 1;
						break;
					case 'G': // index into GUID heap
						if (pThis->index32BitGUID) {
							v = GetU32(pSource);
							pSource += 4;
						} else {
							v = GetU16(pSource);
							pSource += 2;
						}
						v = (U64)(pThis->GUIDs.pGUID1 + ((v-1) * 16));
is64bit_by_value_source = 1;
						break;
					case 'B': // index into BLOB heap
						if (pThis->index32BitBlob) {
							v = GetU32(pSource);
							pSource += 4;
						} else {
							v = GetU16(pSource);
							pSource += 2;
						}
						v = (U64)(pThis->blobs.pStart + v);
is64bit_by_value_source = 1;
						break;
					case '^': // RVA to convert to pointer
						v = GetU32(pSource);
						pSource += 4;
						v = (U64)RVA_FindData(pRVA, v);
is64bit_by_value_source = 1;
						break;
					case 'm': // Pointer to this metadata
						v = (U64)pThis;
is64bit_by_value_source = 1;
						break;
					case 'l': // Is this the last table entry?
						v = (row == numRows - 1);
						break;
					case 'I': // Original table index
						v = MAKE_TABLE_INDEX(tableID, row + 1);
						break;
					case 'x': // Nothing, use 0
						v = 0; // NOTICE this might be a value to either 32bit or 64bit destination.
						break;
					default:
						Crash("Cannot handle MetaData source definition character '%c' (0x%02X)\n", d, d);
				}
			}

			int tmpFI = -1; // value -1 indicates that no value has been written.

			long destOffset = 0;
			int is64bit_by_fieldInfo = 0;

			unsigned char *pDestTmp = NULL;

			switch (pDef[i+1]) {
				case '*':
					tmpFI = fieldIndex++;
					destOffset = (long) fieldInfo[2 * tmpFI + 0];
					is64bit_by_fieldInfo = fieldInfo[2 * tmpFI + 1];
					pDestTmp = pDest + destOffset;
					if ( is64bit_by_fieldInfo ) {
						*(U64*)pDestTmp = v;
						rowItemBytes += 8;
					} else {
						*(U32*)pDestTmp = (U32)v;
						rowItemBytes += 4;
					}
					break;
				case 's':
					tmpFI = fieldIndex++;
					destOffset = (long) fieldInfo[2 * tmpFI + 0];
					is64bit_by_fieldInfo = fieldInfo[2 * tmpFI + 1];
					pDestTmp = pDest + destOffset;
					*(U16*)pDestTmp = (U16)v;
					rowItemBytes += 2;
					break;
				case 'c':
					tmpFI = fieldIndex++;
					destOffset = (long) fieldInfo[2 * tmpFI + 0];
					is64bit_by_fieldInfo = fieldInfo[2 * tmpFI + 1];
					pDestTmp = pDest + destOffset;
					*(U8*)pDestTmp = (U8)v;
					destOffset++;
					rowItemBytes++;
					break;
				case 'x':
					// Do nothing
					break;
				default:
					Crash("Cannot handle MetaData destination definition character '%c'\n", pDef[i+1]);
			}

			if ( tmpFI != -1 ) { // a field was written, make some checks.
				if ( is64bit_by_fieldInfo < 0 ) Crash("Not enough fieldOffsets for tableID=%d (negative value received).\n", tableID);
				if ( is64bit_by_value_source != 0 && is64bit_by_fieldInfo == 0 ) Crash("For tableID=%d is64bit is conflicting for field %d.\n", tableID, tmpFI);
			}

// this logging helps in defining the "is64bit" rules above.
// => the value type is poorly defined in all "typeIN='x' typeOUT='*'" cases.
// => see the the struct definitions in MetaDataTables.h to force the values as 64bit as needed.

//int is64bit = is64bit_by_value_source | is64bit_by_fieldInfo;
//log_f( 3, "rowItem:  i=%d  typeIN='%c'  typeOUT='%c'  is64bit=%d\n", i, pDef[i], pDef[i+1], is64bit );

		}

	if ( tableID == 2 ) {
		tMD_TypeDef *ptr = pDest;
		ptr->staticFieldSize_refTypeFields = 0; // field "staticFieldSize_refTypeFields" is not read.

		//log_f( 3, "TYPEDEF %s.%s isFilled=%d :: instanceMemSize=%d stackSize=%d arrayElementSize=%d staticFieldSize=%d\n", ptr->nameSpace, ptr->name, ptr->isFilled, ptr->instanceMemSize, ptr->stackSize, ptr->arrayElementSize, ptr->staticFieldSize );
	}

pDest += rowLen;

int paddingBytes = 0;
if ( tableID == 1 ) paddingBytes = 4;
//if ( tableID == 2 ) paddingBytes = 28; // before 20240723
if ( tableID == 2 ) paddingBytes = 36; // 20240723 "staticFieldSize_refTypeFields" added.
if ( tableID == 4 ) paddingBytes = 8;
if ( tableID == 6 ) paddingBytes = 16;
if ( tableID == 8 ) paddingBytes = 4;
if ( tableID == 10 ) paddingBytes = 4;
if ( tableID == 20 ) paddingBytes = 8;
if ( tableID == 23 ) paddingBytes = 4;
if ( tableID == 28 ) paddingBytes = 4;
if ( tableID == 29 ) paddingBytes = 4;
if ( tableID == 35 ) paddingBytes = 4;
if ( tableID == 43 ) paddingBytes = 4;

if ( rowItemBytes + paddingBytes != rowLen ) {
	Crash("Writing MetaData row on tableID=%d failed: rowItemBytes=%d paddingBytes=%d rowLen=%d\n", tableID, rowItemBytes, paddingBytes, rowLen);
}

	}

	log_f(1, "Loaded MetaData table 0x%02X; %d rows\n", tableID, numRows);

	// Update the parameter to the position after this table
	*ppTable = pSource;
	// Return new table information
	return pRet;
}

void MetaData_LoadTables(tMetaData *pThis, tRVA *pRVA, void *pStream, unsigned int streamLen) {
	U64 valid, j;
	unsigned char c;
	int i, k, numTables;
	void *pTable;

	c = *(unsigned char*)&((char*)pStream)[6];
	pThis->index32BitString = (c & 1) > 0;
	pThis->index32BitGUID = (c & 2) > 0;
	pThis->index32BitBlob = (c & 4) > 0;

	valid = *(U64*)&((char*)pStream)[8];

	// Count how many tables there are, and read in all the number of rows of each table.
	numTables = 0;
	for (i=0, j=1; i<MAX_TABLES; i++, j <<= 1) {
		if (valid & j) {
			pThis->tables.numRows[i] = *(unsigned int*)&((char*)pStream)[24 + numTables * 4];
			numTables++;
		} else {
			pThis->tables.numRows[i] = 0;
			pThis->tables.data[i] = NULL;
		}
	}

	// Determine if each coded index lookup type needs to use 16 or 32 bit indexes
	for (i=0; i<13; i++) {
		char* pCoding = codedTags[i];
		int tagBits = codedTagBits[i];
		// Discover max table size
		unsigned int maxTableLen = 0;
		for (k=0; k < (1<<tagBits); k++) {
			unsigned char t = pCoding[k];
			if (t != 'z') {
				if (pThis->tables.numRows[t] > maxTableLen) {
					maxTableLen = pThis->tables.numRows[t];
				}
			}
		}
		if (maxTableLen < (unsigned)(1 << (16 - tagBits))) {
			// Use 16-bit number
			pThis->tables.codedIndex32Bit[i] = 0;
		} else {
			// Use 32-bit number
			pThis->tables.codedIndex32Bit[i] = 1;
		}
	}

	pTable = &((char*)pStream)[24 + numTables * 4];

	for (i=0; i<MAX_TABLES; i++) {
		if (pThis->tables.numRows[i] > 0) {
			if (i*4 >= sizeof(tableDefs) || tableDefs[i] == NULL) {
				Crash("No table definition for MetaData table 0x%02x\n", i);
			}
			pThis->tables.data[i] = LoadSingleTable(pThis, pRVA, i, &pTable);
		}
	}
}

PTR MetaData_GetBlob(BLOB_ blob, U32 *pBlobLength) {
	unsigned int len = MetaData_DecodeHeapEntryLength(&blob);
	if (pBlobLength != NULL) {
		*pBlobLength = len;
	}
	return blob;
}

// Returns length in bytes, not characters
STRING2 MetaData_GetUserString(tMetaData *pThis, IDX_USERSTRINGS index, unsigned int *pStringLength) {
	unsigned char *pString = pThis->userStrings.pStart + (index & 0x00ffffff);
	unsigned int len = MetaData_DecodeHeapEntryLength(&pString);
	if (pStringLength != NULL) {
		// -1 because of extra terminating character in the heap
		*pStringLength = len - 1;
	}
	return (STRING2)pString;
}

void* MetaData_GetTableRow(tMetaData *pThis, IDX_TABLE index) {
	char *pData;
	
	if (TABLE_OFS(index) == 0) {
		return NULL;
	}
	pData = (char*)pThis->tables.data[TABLE_ID(index)];
	// Table indexes start at one, hence the -1 here.
	return pData + (TABLE_OFS(index) - 1) * tableRowSize[TABLE_ID(index)];
}

void MetaData_GetConstant(tMetaData *pThis, IDX_TABLE idx, PTR pResultMem) {
	tMD_Constant *pConst = NULL;

	switch (TABLE_ID(idx)) {
	case MD_TABLE_FIELDDEF:
		{
			tMD_FieldDef *pField = (tMD_FieldDef*)MetaData_GetTableRow(pThis, idx);
			pConst = (tMD_Constant*)pField->pMemory;
		}
		break;
	default:
		Crash("MetaData_GetConstant() Cannot handle idx: %#x", idx);
	}

	switch (pConst->type) {
	case ELEMENT_TYPE_I4:
		//*(U32*)pReturnMem = MetaData_DecodeSigEntry(
		memcpy(pResultMem, pConst->value+1, 4);
		return;
	default:
		Crash("MetaData_GetConstant() Cannot handle value type: 0x%02x", pConst->type);
	}
}

void MetaData_GetHeapRoots(tHeapRoots *pHeapRoots, tMetaData *pMetaData) {
	U32 i, top;
	// Go through all types, getting their static variables.

	top = pMetaData->tables.numRows[MD_TABLE_TYPEDEF];
	for (i=1; i<=top; i++) {
		tMD_TypeDef *pTypeDef;

		pTypeDef = (tMD_TypeDef*)MetaData_GetTableRow(pMetaData, MAKE_TABLE_INDEX(MD_TABLE_TYPEDEF, i));
		if (pTypeDef->isGenericDefinition) {
			Generic_GetHeapRoots(pHeapRoots, pTypeDef);
		} else {
			if (pTypeDef->staticFieldSize_refTypeFields > 0) {
				Heap_SetRoots(pHeapRoots, pTypeDef->pStaticFields, NULL, pTypeDef->staticFieldSize_refTypeFields, 21);
			}
		}
	}
}
