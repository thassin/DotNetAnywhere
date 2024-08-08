
// TommiHassinen 2022

#include "JIT_OpCodes.h"

#include <stdio.h>

typedef struct tJITOpCodeName_ tJITOpCodeName;
struct tJITOpCodeName_ {
	int opCode;
	char name[100];
};

tJITOpCodeName __names[] = {
	{ JIT_NOP, "JIT_NOP" },
	{ JIT_RETURN, "JIT_RETURN" },
	{ JIT_LOAD_I32, "JIT_LOAD_I32" },
	{ JIT_BRANCH, "JIT_BRANCH" },
	{ JIT_LOAD_STRING, "JIT_LOAD_STRING" },
	{ JIT_CALLVIRT_O, "JIT_CALLVIRT_O" },
	{ JIT_CALL_NATIVE, "JIT_CALL_NATIVE" },
	{ JIT_CALL_O, "JIT_CALL_O" },
	{ JIT_NEWOBJECT, "JIT_NEWOBJECT" },
	{ JIT_LOAD_PARAMLOCAL_ADDR, "JIT_LOAD_PARAMLOCAL_ADDR" },
	{ JIT_CALL_PTR, "JIT_CALL_PTR" },
	{ JIT_BOX_CALLVIRT, "JIT_BOX_CALLVIRT" },
	{ JIT_INIT_VALUETYPE, "JIT_INIT_VALUETYPE" },
	{ JIT_NEW_VECTOR, "JIT_NEW_VECTOR" },
	{ JIT_NEWOBJECT_VALUETYPE, "JIT_NEWOBJECT_VALUETYPE" },
	{ JIT_IS_INSTANCE, "JIT_IS_INSTANCE" },
	{ JIT_LOAD_NULL, "JIT_LOAD_NULL" },
	{ JIT_UNBOX2VALUETYPE, "JIT_UNBOX2VALUETYPE" },
	{ JIT_UNBOX2OBJECT, "JIT_UNBOX2OBJECT" },
	{ JIT_LOAD_FIELD_ADDR, "JIT_LOAD_FIELD_ADDR" },
	{ JIT_DUP_GENERAL, "JIT_DUP_GENERAL" },
	{ JIT_POP, "JIT_POP" },
	{ JIT_STORE_OBJECT_VALUETYPE, "JIT_STORE_OBJECT_VALUETYPE" },
	{ JIT_DEREF_CALLVIRT, "JIT_DEREF_CALLVIRT" },
	{ JIT_STORE_ELEMENT, "JIT_STORE_ELEMENT" },
	{ JIT_LEAVE, "JIT_LEAVE" },
	{ JIT_END_FINALLY, "JIT_END_FINALLY" },
	{ JIT_THROW, "JIT_THROW" },
	{ JIT_RETHROW, "JIT_RETHROW" },
	{ JIT_LOADOBJECT, "JIT_LOADOBJECT" },
	{ JIT_LOAD_VECTOR_LEN, "JIT_LOAD_VECTOR_LEN" },
	{ JIT_SWITCH, "JIT_SWITCH" },
	{ JIT_LOAD_ELEMENT_ADDR, "JIT_LOAD_ELEMENT_ADDR" },
	{ JIT_CALL_INTERFACE, "JIT_CALL_INTERFACE" },
	{ JIT_CAST_CLASS, "JIT_CAST_CLASS" },
	{ JIT_LOAD_ELEMENT, "JIT_LOAD_ELEMENT" },
	{ JIT_LOADFIELD_VALUETYPE, "JIT_LOADFIELD_VALUETYPE" },
	{ JIT_LOADFIELD, "JIT_LOADFIELD" },
	{ JIT_LOADFUNCTION, "JIT_LOADFUNCTION" },
	{ JIT_INVOKE_DELEGATE, "JIT_INVOKE_DELEGATE" },
	{ JIT_CALL_PINVOKE, "JIT_CALL_PINVOKE" },
	{ JIT_LOAD_I64, "JIT_LOAD_I64" },
	{ JIT_INIT_OBJECT, "JIT_INIT_OBJECT" },
	{ JIT_DUP_4, "JIT_DUP_4" },
	{ JIT_DUP_8, "JIT_DUP_8" },
	{ JIT_LOADSTATICFIELDADDRESS_CHECKTYPEINIT, "JIT_LOADSTATICFIELDADDRESS_CHECKTYPEINIT" },
	{ JIT_POP_4, "JIT_POP_4" },
	{ JIT_LOAD_F32, "JIT_LOAD_F32" },

	{ JIT_LOADPARAMLOCAL_INT64, "JIT_LOADPARAMLOCAL_INT64" },
	{ JIT_LOADPARAMLOCAL_INT32, "JIT_LOADPARAMLOCAL_INT32" },
	{ JIT_LOADPARAMLOCAL_INTNATIVE, "JIT_LOADPARAMLOCAL_INTNATIVE" },
//	{ JIT_LOADPARAMLOCAL_F, "JIT_LOADPARAMLOCAL_F" },
	{ JIT_LOADPARAMLOCAL_F32, "JIT_LOADPARAMLOCAL_F32" },
	{ JIT_LOADPARAMLOCAL_F64, "JIT_LOADPARAMLOCAL_F64" },
	{ JIT_LOADPARAMLOCAL_PTR, "JIT_LOADPARAMLOCAL_PTR" },
	{ JIT_LOADPARAMLOCAL_O, "JIT_LOADPARAMLOCAL_O" },
//	{ JIT_LOADPARAMLOCAL_TRANSPTR, "JIT_LOADPARAMLOCAL_TRANSPTR" },
	{ JIT_LOADPARAMLOCAL_VALUETYPE, "JIT_LOADPARAMLOCAL_VALUETYPE" },

	{ JIT_STOREPARAMLOCAL_INT64, "JIT_STOREPARAMLOCAL_INT64" },
	{ JIT_STOREPARAMLOCAL_INT32, "JIT_STOREPARAMLOCAL_INT32" },
	{ JIT_STOREPARAMLOCAL_INTNATIVE, "JIT_STOREPARAMLOCAL_INTNATIVE" },
//	{ JIT_STOREPARAMLOCAL_F, "JIT_STOREPARAMLOCAL_F" },
	{ JIT_STOREPARAMLOCAL_F32, "JIT_STOREPARAMLOCAL_F32" },
	{ JIT_STOREPARAMLOCAL_F64, "JIT_STOREPARAMLOCAL_F64" },
	{ JIT_STOREPARAMLOCAL_PTR, "JIT_STOREPARAMLOCAL_PTR" },
	{ JIT_STOREPARAMLOCAL_O, "JIT_STOREPARAMLOCAL_O" },
//	{ JIT_STOREPARAMLOCAL_TRANSPTR, "JIT_STOREPARAMLOCAL_TRANSPTR" },
	{ JIT_STOREPARAMLOCAL_VALUETYPE, "JIT_STOREPARAMLOCAL_VALUETYPE" },

	{ JIT_STOREFIELD_INT64, "JIT_STOREFIELD_INT64" },
	{ JIT_STOREFIELD_INT32, "JIT_STOREFIELD_INT32" },
	{ JIT_STOREFIELD_INTNATIVE, "JIT_STOREFIELD_INTNATIVE" },
//	{ JIT_STOREFIELD_F, "JIT_STOREFIELD_F" },
	{ JIT_STOREFIELD_F32, "JIT_STOREFIELD_F32" },
	{ JIT_STOREFIELD_F64, "JIT_STOREFIELD_F64" },
	{ JIT_STOREFIELD_PTR, "JIT_STOREFIELD_PTR" },
	{ JIT_STOREFIELD_O, "JIT_STOREFIELD_O" },
//	{ JIT_STOREFIELD_TRANSPTR, "JIT_STOREFIELD_TRANSPTR" },
	{ JIT_STOREFIELD_VALUETYPE, "JIT_STOREFIELD_VALUETYPE" },

	{ JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT64, "JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT64" },
	{ JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT32, "JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT32" },
	{ JIT_LOADSTATICFIELD_CHECKTYPEINIT_INTNATIVE, "JIT_LOADSTATICFIELD_CHECKTYPEINIT_INTNATIVE" },
//	{ JIT_LOADSTATICFIELD_CHECKTYPEINIT_F, "JIT_LOADSTATICFIELD_CHECKTYPEINIT_F" },
	{ JIT_LOADSTATICFIELD_CHECKTYPEINIT_F32, "JIT_LOADSTATICFIELD_CHECKTYPEINIT_F32" },
	{ JIT_LOADSTATICFIELD_CHECKTYPEINIT_F64, "JIT_LOADSTATICFIELD_CHECKTYPEINIT_F64" },
	{ JIT_LOADSTATICFIELD_CHECKTYPEINIT_PTR, "JIT_LOADSTATICFIELD_CHECKTYPEINIT_PTR" },
	{ JIT_LOADSTATICFIELD_CHECKTYPEINIT_O, "JIT_LOADSTATICFIELD_CHECKTYPEINIT_O" },
//	{ JIT_LOADSTATICFIELD_CHECKTYPEINIT_TRANSPTR, "JIT_LOADSTATICFIELD_CHECKTYPEINIT_TRANSPTR" },
	{ JIT_LOADSTATICFIELD_CHECKTYPEINIT_VALUETYPE, "JIT_LOADSTATICFIELD_CHECKTYPEINIT_VALUETYPE" },

	{ JIT_LOADSTATICFIELD_INT64, "JIT_LOADSTATICFIELD_INT64" },
	{ JIT_LOADSTATICFIELD_INT32, "JIT_LOADSTATICFIELD_INT32" },
	{ JIT_LOADSTATICFIELD_INTNATIVE, "JIT_LOADSTATICFIELD_INTNATIVE" },
//	{ JIT_LOADSTATICFIELD_F, "JIT_LOADSTATICFIELD_F" },
	{ JIT_LOADSTATICFIELD_F32, "JIT_LOADSTATICFIELD_F32" },
	{ JIT_LOADSTATICFIELD_F64, "JIT_LOADSTATICFIELD_F64" },
	{ JIT_LOADSTATICFIELD_PTR, "JIT_LOADSTATICFIELD_PTR" },
	{ JIT_LOADSTATICFIELD_O, "JIT_LOADSTATICFIELD_O" },
//	{ JIT_LOADSTATICFIELD_TRANSPTR, "JIT_LOADSTATICFIELD_TRANSPTR" },
	{ JIT_LOADSTATICFIELD_VALUETYPE, "JIT_LOADSTATICFIELD_VALUETYPE" },

	{ JIT_STORESTATICFIELD_INT64, "JIT_STORESTATICFIELD_INT64" },
	{ JIT_STORESTATICFIELD_INT32, "JIT_STORESTATICFIELD_INT32" },
	{ JIT_STORESTATICFIELD_INTNATIVE, "JIT_STORESTATICFIELD_INTNATIVE" },
//	{ JIT_STORESTATICFIELD_F, "JIT_STORESTATICFIELD_F" },
	{ JIT_STORESTATICFIELD_F32, "JIT_STORESTATICFIELD_F32" },
	{ JIT_STORESTATICFIELD_F64, "JIT_STORESTATICFIELD_F64" },
	{ JIT_STORESTATICFIELD_PTR, "JIT_STORESTATICFIELD_PTR" },
	{ JIT_STORESTATICFIELD_O, "JIT_STORESTATICFIELD_O" },
//	{ JIT_STORESTATICFIELD_TRANSPTR, "JIT_STORESTATICFIELD_TRANSPTR" },
	{ JIT_STORESTATICFIELD_VALUETYPE, "JIT_STORESTATICFIELD_VALUETYPE" },

	{ JIT_BOX_INT64, "JIT_BOX_INT64" },
	{ JIT_BOX_INT32, "JIT_BOX_INT32" },
	{ JIT_BOX_INTNATIVE, "JIT_BOX_INTNATIVE" },
//	{ JIT_BOX_F, "JIT_BOX_F" },
	{ JIT_BOX_F32, "JIT_BOX_F32" },
	{ JIT_BOX_F64, "JIT_BOX_F64" },
	{ JIT_BOX_PTR, "JIT_BOX_PTR" },
	{ JIT_BOX_O, "JIT_BOX_O" },
//	{ JIT_BOX_TRANSPTR, "JIT_BOX_TRANSPTR" },
	{ JIT_BOX_VALUETYPE, "JIT_BOX_VALUETYPE" },

	{ JIT_CEQ_I32I32, "JIT_CEQ_I32I32" },
	{ JIT_CGT_I32I32, "JIT_CGT_I32I32" },
	{ JIT_CGT_UN_I32I32, "JIT_CGT_UN_I32I32" },
	{ JIT_CLT_I32I32, "JIT_CLT_I32I32" },
	{ JIT_CLT_UN_I32I32, "JIT_CLT_UN_I32I32" },

	{ JIT_CEQ_I64I64, "JIT_CEQ_I64I64" },
	{ JIT_CGT_I64I64, "JIT_CGT_I64I64" },
	{ JIT_CGT_UN_I64I64, "JIT_CGT_UN_I64I64" },
	{ JIT_CLT_I64I64, "JIT_CLT_I64I64" },
	{ JIT_CLT_UN_I64I64, "JIT_CLT_UN_I64I64" },

	{ JIT_ADD_OVF_I32I32, "JIT_ADD_OVF_I32I32" },
	{ JIT_ADD_OVF_UN_I32I32, "JIT_ADD_OVF_UN_I32I32" },
	{ JIT_MUL_OVF_I32I32, "JIT_MUL_OVF_I32I32" },
	{ JIT_MUL_OVF_UN_I32I32, "JIT_MUL_OVF_UN_I32I32" },
	{ JIT_SUB_OVF_I32I32, "JIT_SUB_OVF_I32I32" },
	{ JIT_SUB_OVF_UN_I32I32, "JIT_SUB_OVF_UN_I32I32" },
	{ JIT_ADD_I32I32, "JIT_ADD_I32I32" },
	{ JIT_SUB_I32I32, "JIT_SUB_I32I32" },
	{ JIT_MUL_I32I32, "JIT_MUL_I32I32" },
	{ JIT_DIV_I32I32, "JIT_DIV_I32I32" },
	{ JIT_DIV_UN_I32I32, "JIT_DIV_UN_I32I32" },
	{ JIT_REM_I32I32, "JIT_REM_I32I32" },
	{ JIT_REM_UN_I32I32, "JIT_REM_UN_I32I32" },
	{ JIT_AND_I32I32, "JIT_AND_I32I32" },
	{ JIT_OR_I32I32, "JIT_OR_I32I32" },
	{ JIT_XOR_I32I32, "JIT_XOR_I32I32" },

	{ JIT_NEG_I32, "JIT_NEG_I32" },
	{ JIT_NOT_I32, "JIT_NOT_I32" },
	{ JIT_NEG_I64, "JIT_NEG_I64" },
	{ JIT_NOT_I64, "JIT_NOT_I64" },

	{ JIT_BOX_NULLABLE, "JIT_BOX_NULLABLE" },
	{ JIT_LOAD_F64, "JIT_LOAD_F64" },

	{ JIT_BEQ_I32I32, "JIT_BEQ_I32I32" },
	{ JIT_BGE_I32I32, "JIT_BGE_I32I32" },
	{ JIT_BGT_I32I32, "JIT_BGT_I32I32" },
	{ JIT_BLE_I32I32, "JIT_BLE_I32I32" },
	{ JIT_BLT_I32I32, "JIT_BLT_I32I32" },
	{ JIT_BNE_UN_I32I32, "JIT_BNE_UN_I32I32" },
	{ JIT_BGE_UN_I32I32, "JIT_BGE_UN_I32I32" },
	{ JIT_BGT_UN_I32I32, "JIT_BGT_UN_I32I32" },
	{ JIT_BLE_UN_I32I32, "JIT_BLE_UN_I32I32" },
	{ JIT_BLT_UN_I32I32, "JIT_BLT_UN_I32I32" },

	{ JIT_BEQ_I64I64, "JIT_BEQ_I64I64" },
	{ JIT_BGE_I64I64, "JIT_BGE_I64I64" },
	{ JIT_BGT_I64I64, "JIT_BGT_I64I64" },
	{ JIT_BLE_I64I64, "JIT_BLE_I64I64" },
	{ JIT_BLT_I64I64, "JIT_BLT_I64I64" },
	{ JIT_BNE_UN_I64I64, "JIT_BNE_UN_I64I64" },
	{ JIT_BGE_UN_I64I64, "JIT_BGE_UN_I64I64" },
	{ JIT_BGT_UN_I64I64, "JIT_BGT_UN_I64I64" },
	{ JIT_BLE_UN_I64I64, "JIT_BLE_UN_I64I64" },
	{ JIT_BLT_UN_I64I64, "JIT_BLT_UN_I64I64" },

	{ JIT_SHL_I32, "JIT_SHL_I32" },
	{ JIT_SHR_I32, "JIT_SHR_I32" },
	{ JIT_SHR_UN_I32, "JIT_SHR_UN_I32" },
	{ JIT_SHL_I64, "JIT_SHL_I64" },
	{ JIT_SHR_I64, "JIT_SHR_I64" },
	{ JIT_SHR_UN_I64, "JIT_SHR_UN_I64" },

	{ JIT_BRANCH_FALSE, "JIT_BRANCH_FALSE" },
	{ JIT_BRANCH_TRUE, "JIT_BRANCH_TRUE" },

	{ JIT_LOADTOKEN_BASE, "JIT_LOADTOKEN_BASE" },
	{ JIT_LOADTOKEN_TYPE, "JIT_LOADTOKEN_TYPE" },
	{ JIT_LOADTOKEN_METHOD, "JIT_LOADTOKEN_METHOD" },
	{ JIT_LOADTOKEN_FIELD, "JIT_LOADTOKEN_FIELD" },

	{ JIT_LOADINDIRECT_I8, "JIT_LOADINDIRECT_I8" },
	{ JIT_LOADINDIRECT_U8, "JIT_LOADINDIRECT_U8" },
	{ JIT_LOADINDIRECT_I16, "JIT_LOADINDIRECT_I16" },
	{ JIT_LOADINDIRECT_U16, "JIT_LOADINDIRECT_U16" },
	{ JIT_LOADINDIRECT_I32, "JIT_LOADINDIRECT_I32" },
	{ JIT_LOADINDIRECT_U32, "JIT_LOADINDIRECT_U32" },
	{ JIT_LOADINDIRECT_I64, "JIT_LOADINDIRECT_I64" },
	{ JIT_LOADINDIRECT_I, "JIT_LOADINDIRECT_I" },
	{ JIT_LOADINDIRECT_R32, "JIT_LOADINDIRECT_R32" },
	{ JIT_LOADINDIRECT_R64, "JIT_LOADINDIRECT_R64" },
	{ JIT_LOADINDIRECT_REF, "JIT_LOADINDIRECT_REF" },

	{ JIT_STOREINDIRECT_REF, "JIT_STOREINDIRECT_REF" },
	{ JIT_STOREINDIRECT_U8, "JIT_STOREINDIRECT_U8" },
	{ JIT_STOREINDIRECT_U16, "JIT_STOREINDIRECT_U16" },
	{ JIT_STOREINDIRECT_U32, "JIT_STOREINDIRECT_U32" },
	{ JIT_STOREINDIRECT_U64, "JIT_STOREINDIRECT_U64" },
	{ JIT_STOREINDIRECT_R32, "JIT_STOREINDIRECT_R32" },
	{ JIT_STOREINDIRECT_R64, "JIT_STOREINDIRECT_R64" },

//	{ JIT_CONV_SIGNED32, "" },
//	{ JIT_CONV_UNSIGNED32, "" },
//	{ JIT_CONV_INT_I64, "" },

//	{ JIT_CONV_I1, "" },
//	{ JIT_CONV_I2, "" },
//	{ JIT_CONV_I4, "" },
//	{ JIT_CONV_I8, "" },
//	{ JIT_CONV_R4, "" },
//	{ JIT_CONV_R8, "" },
//	{ JIT_CONV_U4, "" },
//	{ JIT_CONV_U8, "" },
//	{ JIT_CONV_U2, "" },
//	{ JIT_CONV_U1, "" },
//	{ JIT_CONV_I_NATIVE, "" },
//	{ JIT_CONV_U_NATIVE, "" },

//	{ JIT_CONV_OVF_I1, "" },
//	{ JIT_CONV_OVF_U1, "" },
//	{ JIT_CONV_OVF_I2, "" },
//	{ JIT_CONV_OVF_U2, "" },
//	{ JIT_CONV_OVF_I4, "" },
//	{ JIT_CONV_OVF_U4, "" },
//	{ JIT_CONV_OVF_I8, "" },
//	{ JIT_CONV_OVF_U8, "" },

	{ JIT_UNBOX_NULLABLE, "JIT_UNBOX_NULLABLE" },

	{ JIT_STORE_ELEMENT_32, "JIT_STORE_ELEMENT_32" },
	{ JIT_STORE_ELEMENT_64, "JIT_STORE_ELEMENT_64" },

	{ JIT_LOAD_ELEMENT_I8, "JIT_LOAD_ELEMENT_I8" },
	{ JIT_LOAD_ELEMENT_U8, "JIT_LOAD_ELEMENT_U8" },
	{ JIT_LOAD_ELEMENT_I16, "JIT_LOAD_ELEMENT_I16" },
	{ JIT_LOAD_ELEMENT_U16, "JIT_LOAD_ELEMENT_U16" },
	{ JIT_LOAD_ELEMENT_I32, "JIT_LOAD_ELEMENT_I32" },
	{ JIT_LOAD_ELEMENT_U32, "JIT_LOAD_ELEMENT_U32" },
	{ JIT_LOAD_ELEMENT_I64, "JIT_LOAD_ELEMENT_I64" },
	{ JIT_LOAD_ELEMENT_U64, "JIT_LOAD_ELEMENT_U64" },
	{ JIT_LOAD_ELEMENT_R32, "JIT_LOAD_ELEMENT_R32" },
	{ JIT_LOAD_ELEMENT_R64, "JIT_LOAD_ELEMENT_R64" },

	{ JIT_ADD_OVF_I64I64, "JIT_ADD_OVF_I64I64" },
	{ JIT_ADD_OVF_UN_I64I64, "JIT_ADD_OVF_UN_I64I64" },
	{ JIT_MUL_OVF_I64I64, "JIT_MUL_OVF_I64I64" },
	{ JIT_MUL_OVF_UN_I64I64, "JIT_MUL_OVF_UN_I64I64" },
	{ JIT_SUB_OVF_I64I64, "JIT_SUB_OVF_I64I64" },
	{ JIT_SUB_OVF_UN_I64I64, "JIT_SUB_OVF_UN_I64I64" },
	{ JIT_ADD_I64I64, "JIT_ADD_I64I64" },
	{ JIT_SUB_I64I64, "JIT_SUB_I64I64" },
	{ JIT_MUL_I64I64, "JIT_MUL_I64I64" },
	{ JIT_DIV_I64I64, "JIT_DIV_I64I64" },
	{ JIT_DIV_UN_I64I64, "JIT_DIV_UN_I64I64" },
	{ JIT_REM_I64I64, "JIT_REM_I64I64" },
	{ JIT_REM_UN_I64I64, "JIT_REM_UN_I64I64" },
	{ JIT_AND_I64I64, "JIT_AND_I64I64" },
	{ JIT_OR_I64I64, "JIT_OR_I64I64" },
	{ JIT_XOR_I64I64, "JIT_XOR_I64I64" },

	{ JIT_CEQ_F32F32, "JIT_CEQ_F32F32" },
	{ JIT_CGT_F32F32, "JIT_CGT_F32F32" },
	{ JIT_CGT_UN_F32F32, "JIT_CGT_UN_F32F32" },
	{ JIT_CLT_F32F32, "JIT_CLT_F32F32" },
	{ JIT_CLT_UN_F32F32, "JIT_CLT_UN_F32F32" },

	{ JIT_BEQ_F32F32, "JIT_BEQ_F32F32" },
	{ JIT_BGE_F32F32, "JIT_BGE_F32F32" },
	{ JIT_BGT_F32F32, "JIT_BGT_F32F32" },
	{ JIT_BLE_F32F32, "JIT_BLE_F32F32" },
	{ JIT_BLT_F32F32, "JIT_BLT_F32F32" },
	{ JIT_BNE_UN_F32F32, "JIT_BNE_UN_F32F32" },
	{ JIT_BGE_UN_F32F32, "JIT_BGE_UN_F32F32" },
	{ JIT_BGT_UN_F32F32, "JIT_BGT_UN_F32F32" },
	{ JIT_BLE_UN_F32F32, "JIT_BLE_UN_F32F32" },
	{ JIT_BLT_UN_F32F32, "JIT_BLT_UN_F32F32" },

	{ JIT_ADD_F32F32, "JIT_ADD_F32F32" },
	{ JIT_SUB_F32F32, "JIT_SUB_F32F32" },
	{ JIT_MUL_F32F32, "JIT_MUL_F32F32" },
	{ JIT_DIV_F32F32, "JIT_DIV_F32F32" },
	{ JIT_DIV_UN_F32F32, "JIT_DIV_UN_F32F32" },
	{ JIT_REM_F32F32, "JIT_REM_F32F32" },
	{ JIT_REM_UN_F32F32, "JIT_REM_UN_F32F32" },

	{ JIT_CEQ_F64F64, "JIT_CEQ_F64F64" },
	{ JIT_CGT_F64F64, "JIT_CGT_F64F64" },
	{ JIT_CGT_UN_F64F64, "JIT_CGT_UN_F64F64" },
	{ JIT_CLT_F64F64, "JIT_CLT_F64F64" },
	{ JIT_CLT_UN_F64F64, "JIT_CLT_UN_F64F64" },

	{ JIT_BEQ_F64F64, "JIT_BEQ_F64F64" },
	{ JIT_BGE_F64F64, "JIT_BGE_F64F64" },
	{ JIT_BGT_F64F64, "JIT_BGT_F64F64" },
	{ JIT_BLE_F64F64, "JIT_BLE_F64F64" },
	{ JIT_BLT_F64F64, "JIT_BLT_F64F64" },
	{ JIT_BNE_UN_F64F64, "JIT_BNE_UN_F64F64" },
	{ JIT_BGE_UN_F64F64, "JIT_BGE_UN_F64F64" },
	{ JIT_BGT_UN_F64F64, "JIT_BGT_UN_F64F64" },
	{ JIT_BLE_UN_F64F64, "JIT_BLE_UN_F64F64" },
	{ JIT_BLT_UN_F64F64, "JIT_BLT_UN_F64F64" },

	{ JIT_ADD_F64F64, "JIT_ADD_F64F64" },
	{ JIT_SUB_F64F64, "JIT_SUB_F64F64" },
	{ JIT_MUL_F64F64, "JIT_MUL_F64F64" },
	{ JIT_DIV_F64F64, "JIT_DIV_F64F64" },
	{ JIT_DIV_UN_F64F64, "JIT_DIV_UN_F64F64" },
	{ JIT_REM_F64F64, "JIT_REM_F64F64" },
	{ JIT_REM_UN_F64F64, "JIT_REM_UN_F64F64" },

	{ JIT_LOADPARAMLOCAL_0, "JIT_LOADPARAMLOCAL_0" },
	{ JIT_LOADPARAMLOCAL_1, "JIT_LOADPARAMLOCAL_1" },
	{ JIT_LOADPARAMLOCAL_2, "JIT_LOADPARAMLOCAL_2" },
	{ JIT_LOADPARAMLOCAL_3, "JIT_LOADPARAMLOCAL_3" },
	{ JIT_LOADPARAMLOCAL_4, "JIT_LOADPARAMLOCAL_4" },
	{ JIT_LOADPARAMLOCAL_5, "JIT_LOADPARAMLOCAL_5" },
	{ JIT_LOADPARAMLOCAL_6, "JIT_LOADPARAMLOCAL_6" },
	{ JIT_LOADPARAMLOCAL_7, "JIT_LOADPARAMLOCAL_7" },

	{ JIT_STOREPARAMLOCAL_0, "JIT_STOREPARAMLOCAL_0" },
	{ JIT_STOREPARAMLOCAL_1, "JIT_STOREPARAMLOCAL_1" },
	{ JIT_STOREPARAMLOCAL_2, "JIT_STOREPARAMLOCAL_2" },
	{ JIT_STOREPARAMLOCAL_3, "JIT_STOREPARAMLOCAL_3" },
	{ JIT_STOREPARAMLOCAL_4, "JIT_STOREPARAMLOCAL_4" },
	{ JIT_STOREPARAMLOCAL_5, "JIT_STOREPARAMLOCAL_5" },
	{ JIT_STOREPARAMLOCAL_6, "JIT_STOREPARAMLOCAL_6" },
	{ JIT_STOREPARAMLOCAL_7, "JIT_STOREPARAMLOCAL_7" },

	{ JIT_LOAD_I4_M1, "JIT_LOAD_I4_M1" },
	{ JIT_LOAD_I4_0, "JIT_LOAD_I4_0" },
	{ JIT_LOAD_I4_1, "JIT_LOAD_I4_1" },
	{ JIT_LOAD_I4_2, "JIT_LOAD_I4_2" },

	{ JIT_LOADFIELD_4, "JIT_LOADFIELD_4" },

	{ JIT_CONV_OFFSET_I32, "JIT_CONV_OFFSET_I32" },
	{ JIT_CONV_OFFSET_U32, "JIT_CONV_OFFSET_U32" },
	{ JIT_CONV_OFFSET_I64, "JIT_CONV_OFFSET_I64" },
	{ JIT_CONV_OFFSET_U64, "JIT_CONV_OFFSET_U64" },
	{ JIT_CONV_OFFSET_R32, "JIT_CONV_OFFSET_R32" },
	{ JIT_CONV_OFFSET_R64, "JIT_CONV_OFFSET_R64" },

	{ JIT_CONV_FROM_I32, "JIT_CONV_FROM_I32" },
	{ JIT_CONV_I32_I32, "JIT_CONV_I32_I32" },
	{ JIT_CONV_I32_U32, "JIT_CONV_I32_U32" },
	{ JIT_CONV_I32_I64, "JIT_CONV_I32_I64" },
	{ JIT_CONV_I32_U64, "JIT_CONV_I32_U64" },
	{ JIT_CONV_I32_R32, "JIT_CONV_I32_R32" },
	{ JIT_CONV_I32_R64, "JIT_CONV_I32_R64" },

	{ JIT_CONV_FROM_U32, "JIT_CONV_FROM_U32" },
	{ JIT_CONV_U32_I32, "JIT_CONV_U32_I32" },
	{ JIT_CONV_U32_U32, "JIT_CONV_U32_U32" },
	{ JIT_CONV_U32_I64, "JIT_CONV_U32_I64" },
	{ JIT_CONV_U32_U64, "JIT_CONV_U32_U64" },
	{ JIT_CONV_U32_R32, "JIT_CONV_U32_R32" },
	{ JIT_CONV_U32_R64, "JIT_CONV_U32_R64" },

	{ JIT_CONV_FROM_I64, "JIT_CONV_FROM_I64" },
	{ JIT_CONV_I64_I32, "JIT_CONV_I64_I32" },
	{ JIT_CONV_I64_U32, "JIT_CONV_I64_U32" },
	{ JIT_CONV_I64_I64, "JIT_CONV_I64_I64" },
	{ JIT_CONV_I64_U64, "JIT_CONV_I64_U64" },
	{ JIT_CONV_I64_R32, "JIT_CONV_I64_R32" },
	{ JIT_CONV_I64_R64, "JIT_CONV_I64_R64" },

	{ JIT_CONV_FROM_U64, "JIT_CONV_FROM_U64" },
	{ JIT_CONV_U64_I32, "JIT_CONV_U64_I32" },
	{ JIT_CONV_U64_U32, "JIT_CONV_U64_U32" },
	{ JIT_CONV_U64_I64, "JIT_CONV_U64_I64" },
	{ JIT_CONV_U64_U64, "JIT_CONV_U64_U64" },
	{ JIT_CONV_U64_R32, "JIT_CONV_U64_R32" },
	{ JIT_CONV_U64_R64, "JIT_CONV_U64_R64" },

	{ JIT_CONV_FROM_R32, "JIT_CONV_FROM_R32" },
	{ JIT_CONV_R32_I32, "JIT_CONV_R32_I32" },
	{ JIT_CONV_R32_U32, "JIT_CONV_R32_U32" },
	{ JIT_CONV_R32_I64, "JIT_CONV_R32_I64" },
	{ JIT_CONV_R32_U64, "JIT_CONV_R32_U64" },
	{ JIT_CONV_R32_R32, "JIT_CONV_R32_R32" },
	{ JIT_CONV_R32_R64, "JIT_CONV_R32_R64" },

	{ JIT_CONV_FROM_R64, "JIT_CONV_FROM_R64" },
	{ JIT_CONV_R64_I32, "JIT_CONV_R64_I32" },
	{ JIT_CONV_R64_U32, "JIT_CONV_R64_U32" },
	{ JIT_CONV_R64_I64, "JIT_CONV_R64_I64" },
	{ JIT_CONV_R64_U64, "JIT_CONV_R64_U64" },
	{ JIT_CONV_R64_R32, "JIT_CONV_R64_R32" },
	{ JIT_CONV_R64_R64, "JIT_CONV_R64_R64" },

	{ JIT_INVOKE_SYSTEM_REFLECTION_METHODBASE, "JIT_INVOKE_SYSTEM_REFLECTION_METHODBASE" },
	{ JIT_REFLECTION_DYNAMICALLY_BOX_RETURN_VALUE, "JIT_REFLECTION_DYNAMICALLY_BOX_RETURN_VALUE" },

	{ -1, "" } // an end mark.
};

static char __unknown[32];

const char * JIT_GetOpCodeName( int opCode ) {

	int i = 0;
	while( __names[i].opCode != -1 ) {
		if ( __names[i].opCode == opCode ) {
			return __names[i].name;
		}
		i++;
	}

	sprintf( __unknown, "unknown_%#x", opCode );
	return __unknown;
}

