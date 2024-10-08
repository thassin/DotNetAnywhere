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

#include "PInvoke.h"
#include "MetaData.h"
#include "MetaDataTables.h"
#include "JIT.h"
#include "Type.h"
#include "System.String.h"
#include "EvalStack.h"

typedef struct tLoadedLib_ tLoadedLib;
struct tLoadedLib_ {
	// The name of the library - this is the name as specified in the .NET assembly
	STRING name;
	// The library
	void *pLib;

	tLoadedLib *pNext;
};

static tLoadedLib *pLoadedLibs = NULL;

static tLoadedLib* GetLib(STRING name) {
	// See if it's already loaded
	tLoadedLib *pLib = pLoadedLibs;
	char libName[256];
	void *pNativeLib;

	while (pLib != NULL) {
		if (strcmp(name, pLib->name) == 0) {
			return pLib;
		}
	}
	sprintf(libName, "%s%s", LIB_PREFIX, name);
	if (strlen(libName) >= 4) {
		if (strcmp(".dll", libName + strlen(libName) - 4) == 0) {
			// Cut off the ".dll" suffix if it's there
			libName[strlen(libName) - 4] = 0;
		}
	}
	// Not loaded, so load it
	sprintf(strchr(libName, 0), ".%s", LIB_SUFFIX);
#if _WIN32
	pNativeLib = LoadLibraryA(libName);
#else
	pNativeLib = dlopen(libName, RTLD_LAZY); //DL_LAZY);
#endif
	if (pNativeLib == NULL) {
		// Failed to load library
		printf("Failed to load library: %s\n", libName);
#ifndef _WIN32
		{
			char *pError;
			pError = dlerror();
			if (pError) {
				printf("dlopen() Error: '%s'", pError);
			}
		}
#endif
		return NULL;
	}
	pLib = TMALLOCFOREVER(tLoadedLib);
	pLib->pNext = pLoadedLibs;
	pLoadedLibs = pLib;
	pLib->name = name;
	pLib->pLib = pNativeLib;
	return pLib;
}

fnPInvoke PInvoke_GetFunction(tMetaData *pMetaData, tMD_ImplMap *pImplMap) {
	tLoadedLib *pLib;
	STRING libName;
	void *pProc;

	libName = MetaData_GetModuleRefName(pMetaData, pImplMap->importScope);

#ifdef _EMSCRIPTEN
	return (fnPInvoke)invokeJsFunc;
#else // _EMSCRIPTEN

	pLib = GetLib(libName);
	if (pLib == NULL) {
		// Library not found, so we can't find the function
		return NULL;
	}

#ifdef _WIN32
	pProc = GetProcAddress(pLib->pLib, pImplMap->importName);
#else // _WIN32
	pProc = dlsym(pLib->pLib, pImplMap->importName);
#endif // _WIN32

#endif // _EMSCRIPTEN

	return pProc;
}

static void* ConvertStringToANSI(HEAP_PTR pHeapEntry) {
	U32 strLen, i;
	STRING2 str = SystemString_GetString(pHeapEntry, &strLen);
	unsigned char *pAnsi = (unsigned char*)malloc(strLen + 1);
	for (i = 0; i < strLen; i++) {
		pAnsi[i] = (unsigned char)str[i];
	}
	pAnsi[i] = 0;
	return pAnsi;
}

// This function is needed to maintain string immutability, and to add a null-terminator
static void* ConvertStringToUnicode(HEAP_PTR pHeapEntry) {
	U32 strLen;
	STRING2 str = SystemString_GetString(pHeapEntry, &strLen);
	unsigned short *pUnicode = (unsigned short*)malloc((strLen + 1) << 1);
	memcpy(pUnicode, str, strLen << 1);
	pUnicode[strLen] = 0;
	return pUnicode;
}

#include "PInvoke_TypeDef.h"

typedef U64 (STDCALL *_uCuuuuu)(U32 _0, U32 _1, U32 _2, U32 _3, U32 _4);
typedef U64 (STDCALL *_uCuuuuuu)(U32 _0, U32 _1, U32 _2, U32 _3, U32 _4, U32 _5);
typedef U64 (STDCALL *_uCuuuuuuu)(U32 _0, U32 _1, U32 _2, U32 _3, U32 _4, U32 _5, U32 _6);
typedef U64 (STDCALL *_uCuuuuuuuu)(U32 _0, U32 _1, U32 _2, U32 _3, U32 _4, U32 _5, U32 _6, U32 _7);
typedef U64 (STDCALL *_uCuuuuuuuuu)(U32 _0, U32 _1, U32 _2, U32 _3, U32 _4, U32 _5, U32 _6, U32 _7, U32 _8);
typedef U64 (STDCALL *_uCuuuuuuuuuu)(U32 _0, U32 _1, U32 _2, U32 _3, U32 _4, U32 _5, U32 _6, U32 _7, U32 _8, U32 _9);

#define CALL0(returnType) (returnType)
#define CALL1(returnType, t0) ((returnType) | ((t0)<<2))
#define CALL2(returnType, t0, t1) ((returnType) | ((t0)<<2) | ((t1)<<4))
#define CALL3(returnType, t0, t1, t2) ((returnType) | ((t0)<<2) | ((t1)<<4) | ((t2)<<6))
#define CALL4(returnType, t0, t1, t2, t3) ((returnType) | ((t0)<<2) | ((t1)<<4) | ((t2)<<6) | ((t3)<<8))
#define CALL5(returnType, t0, t1, t2, t3, t4) ((returnType) | ((t0)<<2) | ((t1)<<4) | ((t2)<<6) | ((t3)<<8) | ((t4)<<10))
#define CALL6(returnType, t0, t1, t2, t3, t4, t5) ((returnType) | ((t0)<<2) | ((t1)<<4) | ((t2)<<6) | ((t3)<<8) | ((t4)<<10) | ((t5)<<12))
#define CALL7(returnType, t0, t1, t2, t3, t4, t5, t6) ((returnType) | ((t0)<<2) | ((t1)<<4) | ((t2)<<6) | ((t3)<<8) | ((t4)<<10) | ((t5)<<12) | ((t6)<<14))
#define CALL8(returnType, t0, t1, t2, t3, t4, t5, t6, t7) ((returnType) | ((t0)<<2) | ((t1)<<4) | ((t2)<<6) | ((t3)<<8) | ((t4)<<10) | ((t5)<<12) | ((t6)<<14) | ((t7)<<16))
#define CALL9(returnType, t0, t1, t2, t3, t4, t5, t6, t7, t8) ((returnType) | ((t0)<<2) | ((t1)<<4) | ((t2)<<6) | ((t3)<<8) | ((t4)<<10) | ((t5)<<12) | ((t6)<<14) | ((t7)<<16) | ((t8)<<18))
#define CALL10(returnType, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9) ((returnType) | ((t0)<<2) | ((t1)<<4) | ((t2)<<6) | ((t3)<<8) | ((t4)<<10) | ((t5)<<12) | ((t6)<<14) | ((t7)<<16) | ((t8)<<18) | ((t9)<<20))

#define TP_INT32 1
#define TP_FP32 2
#define TP_FP64 3

//#define SET_ARG_TYPE(paramNum, type) funcParams |= (type << ((paramNum+1) << 1))
#define SET_ARG_TYPE(paramNum, type) funcParams |= (type << ((paramNum+1) * 2))

#define MAX_ARGS 16
U32 PInvoke_Call(tJITCallPInvoke *pCall, PTR pParams, PTR pReturnValue, tThread *pCallingThread) {
	U32 _args[MAX_ARGS];
	double _argsd[MAX_ARGS];
	void* _pTempMem[MAX_ARGS];
	U32 numParams, param, paramTypeNum;
	tMD_MethodDef *pMethod = pCall->pMethod;
	tMD_TypeDef *pReturnType = pMethod->pReturnType;
	tMD_ImplMap *pImplMap = pCall->pImplMap;
#ifdef _EMSCRIPTEN
	fnPInvoke pFn = pCall->fn;
#else // _EMSCRIPTEN
	void *pFn = pCall->fn;
#endif // _EMSCRIPTEN
	U32 _argOfs = 0, _argdOfs = 0, paramOfs = 0;
	U32 _tempMemOfs = 0;
	U32 i;
	U64 funcParams = TP_INT32;
	U32 uRet;
	float fRet;
	double dRet;

	// [Steve edit] Before we issue the call into JS code, we need to set the calling .NET thread's state
	// to 'suspended' so that, if the JS code makes other calls into .NET, the DNA runtime doesn't try to
	// resume this original thread automaticaly (its default behaviour in Thread.c is that, at the end of
	// each thread's execution, it tries to resume any other nonbackground thread). If we don't do this,
	// then you wouldn't be able to call back into .NET code while inside a pInvoke call because the calling
	// thread would go into an infinite loop.
	U32 originalCallingThreadState = pCallingThread->state;
	pCallingThread->state |= THREADSTATE_SUSPENDED;

	if (pReturnType != NULL) {
		if (pReturnType == types[TYPE_SYSTEM_SINGLE]) {
			funcParams = TP_FP32;
		} else if (pReturnType == types[TYPE_SYSTEM_DOUBLE]) {
			funcParams = TP_FP64;
		}
	}

	int argShift = 0;

#ifdef _EMSCRIPTEN

	argShift = 2;

	// Prepend the 'libName' and 'funcName' strings to the set of arguments
	// NOTE: These aren't currently used in js-interop.js, but they would be if I found a way
	// to pass an arbitrary set of args without declaring the C func type in advance
	_args[0] = (U32)MetaData_GetModuleRefName(pCall->pMethod->pMetaData, pCall->pImplMap->importScope);
	_args[1] = (U32)pCall->pMethod->name;
	_argOfs += 2;
	SET_ARG_TYPE(0, TP_INT32);
	SET_ARG_TYPE(1, TP_INT32);

#endif // _EMSCRIPTEN

	numParams = pMethod->numberOfParameters;
	for (param = 0, paramTypeNum = 0; param < numParams; param++, paramTypeNum++) {
		tParameter *pParam = &(pMethod->pParams[param]);
		tMD_TypeDef *pParamType = pParam->pTypeDef;
		U32 paramType = TP_INT32;

		if (pParamType->stackType == EVALSTACK_INT32) {
			_args[_argOfs] = *(U32*)(pParams + paramOfs);
			_argOfs++;
			paramOfs += 4;
		} else if (pParamType == types[TYPE_SYSTEM_STRING]) {
			// Allocate a temp bit of memory for the string that's been converted.
			void *pString;
			if (IMPLMAP_ISCHARSET_ANSI(pImplMap) || IMPLMAP_ISCHARSET_AUTO(pImplMap) || IMPLMAP_ISCHARSET_NOTSPEC(pImplMap)) {
				pString = ConvertStringToANSI(*(HEAP_PTR*)(pParams + paramOfs));
			} else if (IMPLMAP_ISCHARSET_UNICODE(pImplMap)) {
				pString = ConvertStringToUnicode(*(HEAP_PTR*)(pParams + paramOfs));
			} else {
				Crash("PInvoke_Call() Cannot handle string marshalling of given type");
			}
			_pTempMem[_tempMemOfs] = pString;
			_tempMemOfs++;
			_args[_argOfs] = (U32)pString;
			_argOfs++;
			paramOfs += 4;
		} else if (pParamType == types[TYPE_SYSTEM_INTPTR]) {
			// Only works for 32-bit
			_args[_argOfs] = *(U32*)(pParams + paramOfs);
			_argOfs++;
			paramOfs += 4;
		} else if (pParamType == types[TYPE_SYSTEM_SINGLE]) {
			_argsd[_argdOfs] = *(float*)(pParams + paramOfs);
			_argdOfs++;
			paramOfs += 4;
			paramType = TP_FP32;
		} else if (pParamType == types[TYPE_SYSTEM_DOUBLE]) {
			_argsd[_argdOfs] = *(double*)(pParams + paramOfs);
			_argdOfs++;
			paramOfs += 8;
			paramType = TP_FP64;
		} else {
			Crash("PInvoke_Call() Cannot handle parameter of type: %s", pParamType->name);
		}
		SET_ARG_TYPE(paramTypeNum + argShift, paramType);
	}

#ifdef _EMSCRIPTEN

	// [Steve edit] I'm hard-coding the pinvoke function pointer type here, as a workaround for
	// Emscripten's function pointer limitations.
	// See the longer comment in JIT.h for details.
	if (funcParams != 255) {
		Crash("PInvoke_Call() currently only supports calls of type 255; you tried to make a call of type %i.\n", funcParams);
	}
	int intRet = pFn((STRING)_args[0], (STRING)_args[1], (STRING)_args[2]);
	uRet = (U32)intRet;

#else // _EMSCRIPTEN

	switch (funcParams) {

#include "PInvoke_CaseCode.h"

		case CALL5(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
			uRet = ((_uCuuuuu)(pFn))(_args[0], _args[1], _args[2], _args[3], _args[4]);
			break;

		case CALL6(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
			uRet = ((_uCuuuuuu)(pFn))(_args[0], _args[1], _args[2], _args[3], _args[4], _args[5]);
			break;

		case CALL7(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
			uRet = ((_uCuuuuuuu)(pFn))(_args[0], _args[1], _args[2], _args[3], _args[4], _args[5], _args[6]);
			break;

		case CALL8(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
			uRet = ((_uCuuuuuuuu)(pFn))(_args[0], _args[1], _args[2], _args[3], _args[4], _args[5], _args[6], _args[7]);
			break;

		case CALL9(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
			uRet = ((_uCuuuuuuuuu)(pFn))(_args[0], _args[1], _args[2], _args[3], _args[4], _args[5], _args[6], _args[7], _args[8]);
			break;

		case CALL10(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
			uRet = ((_uCuuuuuuuuuu)(pFn))(_args[0], _args[1], _args[2], _args[3], _args[4], _args[5], _args[6], _args[7], _args[8], _args[9]);
			break;

		default:
			Crash("PInvoke_Call() Cannot handle the function parameters: %#x", funcParams);
	}

#endif // _EMSCRIPTEN

	for (i = 0; i < _tempMemOfs; i++) {
		free(_pTempMem[i]);
	}

	// [Steve edit] Restore previous thread state
	pCallingThread->state = originalCallingThreadState;

	if (pReturnType == NULL) {
		return 0;
	}
	if (pReturnType->stackType == EVALSTACK_INT32) {
		*(U32*)pReturnValue = (U32)uRet;
		return 4;
	}
	if (pReturnType == types[TYPE_SYSTEM_STRING]) {
		if (IMPLMAP_ISCHARSET_ANSI(pImplMap) || IMPLMAP_ISCHARSET_AUTO(pImplMap) || IMPLMAP_ISCHARSET_NOTSPEC(pImplMap)) {
			*(HEAP_PTR*)pReturnValue = SystemString_FromCharPtrASCII((U8*)(U32)uRet);
		} else if (IMPLMAP_ISCHARSET_UNICODE(pImplMap)) {
			*(HEAP_PTR*)pReturnValue = SystemString_FromCharPtrUTF16((U16*)(U32)uRet);
		} else {
			Crash("PInvoke_Call() Cannot handle return string in specified format");
		}
		return sizeof(void*);
	}
	if (pReturnType == types[TYPE_SYSTEM_INTPTR]) {
		*(void**)pReturnValue = (void*)(U32)uRet;
		return sizeof(void*);
	}
	if (pReturnType == types[TYPE_SYSTEM_SINGLE]) {
		*(float*)pReturnValue = fRet;
		return 4;
	}
	if (pReturnType == types[TYPE_SYSTEM_DOUBLE]) {
		*(double*)pReturnValue = dRet;
		return 8;
	}

	Crash("PInvoke_Call() Cannot handle return type: %s", pReturnType->name);
	FAKE_RETURN;
}

