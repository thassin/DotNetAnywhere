// generated using generate_PInv_files_64bit.php
case CALL0(TP_INT32):
	uRet = ((_uC)(pFn))();
	break;
case CALL0(TP_INT64):
	xRet = ((_xC)(pFn))();
	break;
case CALL0(TP_FP32):
	fRet = ((_fC)(pFn))();
	break;
case CALL0(TP_FP64):
	dRet = ((_dC)(pFn))();
	break;
case CALL1(TP_INT32, TP_INT32):
	uRet = ((_uCu)(pFn))((U32)_args[0]);
	break;
case CALL1(TP_INT32, TP_INT64):
	uRet = ((_uCx)(pFn))(_args[0]);
	break;
case CALL1(TP_INT32, TP_FP32):
	uRet = ((_uCf)(pFn))((float)_argsd[0]);
	break;
case CALL1(TP_INT32, TP_FP64):
	uRet = ((_uCd)(pFn))(_argsd[0]);
	break;
case CALL1(TP_INT64, TP_INT32):
	xRet = ((_xCu)(pFn))((U32)_args[0]);
	break;
case CALL1(TP_INT64, TP_INT64):
	xRet = ((_xCx)(pFn))(_args[0]);
	break;
case CALL1(TP_INT64, TP_FP32):
	xRet = ((_xCf)(pFn))((float)_argsd[0]);
	break;
case CALL1(TP_INT64, TP_FP64):
	xRet = ((_xCd)(pFn))(_argsd[0]);
	break;
case CALL1(TP_FP32, TP_INT32):
	fRet = ((_fCu)(pFn))((U32)_args[0]);
	break;
case CALL1(TP_FP32, TP_INT64):
	fRet = ((_fCx)(pFn))(_args[0]);
	break;
case CALL1(TP_FP32, TP_FP32):
	fRet = ((_fCf)(pFn))((float)_argsd[0]);
	break;
case CALL1(TP_FP32, TP_FP64):
	fRet = ((_fCd)(pFn))(_argsd[0]);
	break;
case CALL1(TP_FP64, TP_INT32):
	dRet = ((_dCu)(pFn))((U32)_args[0]);
	break;
case CALL1(TP_FP64, TP_INT64):
	dRet = ((_dCx)(pFn))(_args[0]);
	break;
case CALL1(TP_FP64, TP_FP32):
	dRet = ((_dCf)(pFn))((float)_argsd[0]);
	break;
case CALL1(TP_FP64, TP_FP64):
	dRet = ((_dCd)(pFn))(_argsd[0]);
	break;
case CALL2(TP_INT32, TP_INT32, TP_INT32):
	uRet = ((_uCuu)(pFn))((U32)_args[0], (U32)_args[1]);
	break;
case CALL2(TP_INT32, TP_INT32, TP_INT64):
	uRet = ((_uCux)(pFn))((U32)_args[0], _args[1]);
	break;
case CALL2(TP_INT32, TP_INT32, TP_FP32):
	uRet = ((_uCuf)(pFn))((U32)_args[0], (float)_argsd[0]);
	break;
case CALL2(TP_INT32, TP_INT32, TP_FP64):
	uRet = ((_uCud)(pFn))((U32)_args[0], _argsd[0]);
	break;
case CALL2(TP_INT32, TP_INT64, TP_INT32):
	uRet = ((_uCxu)(pFn))(_args[0], (U32)_args[1]);
	break;
case CALL2(TP_INT32, TP_INT64, TP_INT64):
	uRet = ((_uCxx)(pFn))(_args[0], _args[1]);
	break;
case CALL2(TP_INT32, TP_INT64, TP_FP32):
	uRet = ((_uCxf)(pFn))(_args[0], (float)_argsd[0]);
	break;
case CALL2(TP_INT32, TP_INT64, TP_FP64):
	uRet = ((_uCxd)(pFn))(_args[0], _argsd[0]);
	break;
case CALL2(TP_INT32, TP_FP32, TP_INT32):
	uRet = ((_uCfu)(pFn))((float)_argsd[0], (U32)_args[0]);
	break;
case CALL2(TP_INT32, TP_FP32, TP_INT64):
	uRet = ((_uCfx)(pFn))((float)_argsd[0], _args[0]);
	break;
case CALL2(TP_INT32, TP_FP32, TP_FP32):
	uRet = ((_uCff)(pFn))((float)_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_INT32, TP_FP32, TP_FP64):
	uRet = ((_uCfd)(pFn))((float)_argsd[0], _argsd[1]);
	break;
case CALL2(TP_INT32, TP_FP64, TP_INT32):
	uRet = ((_uCdu)(pFn))(_argsd[0], (U32)_args[0]);
	break;
case CALL2(TP_INT32, TP_FP64, TP_INT64):
	uRet = ((_uCdx)(pFn))(_argsd[0], _args[0]);
	break;
case CALL2(TP_INT32, TP_FP64, TP_FP32):
	uRet = ((_uCdf)(pFn))(_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_INT32, TP_FP64, TP_FP64):
	uRet = ((_uCdd)(pFn))(_argsd[0], _argsd[1]);
	break;
case CALL2(TP_INT64, TP_INT32, TP_INT32):
	xRet = ((_xCuu)(pFn))((U32)_args[0], (U32)_args[1]);
	break;
case CALL2(TP_INT64, TP_INT32, TP_INT64):
	xRet = ((_xCux)(pFn))((U32)_args[0], _args[1]);
	break;
case CALL2(TP_INT64, TP_INT32, TP_FP32):
	xRet = ((_xCuf)(pFn))((U32)_args[0], (float)_argsd[0]);
	break;
case CALL2(TP_INT64, TP_INT32, TP_FP64):
	xRet = ((_xCud)(pFn))((U32)_args[0], _argsd[0]);
	break;
case CALL2(TP_INT64, TP_INT64, TP_INT32):
	xRet = ((_xCxu)(pFn))(_args[0], (U32)_args[1]);
	break;
case CALL2(TP_INT64, TP_INT64, TP_INT64):
	xRet = ((_xCxx)(pFn))(_args[0], _args[1]);
	break;
case CALL2(TP_INT64, TP_INT64, TP_FP32):
	xRet = ((_xCxf)(pFn))(_args[0], (float)_argsd[0]);
	break;
case CALL2(TP_INT64, TP_INT64, TP_FP64):
	xRet = ((_xCxd)(pFn))(_args[0], _argsd[0]);
	break;
case CALL2(TP_INT64, TP_FP32, TP_INT32):
	xRet = ((_xCfu)(pFn))((float)_argsd[0], (U32)_args[0]);
	break;
case CALL2(TP_INT64, TP_FP32, TP_INT64):
	xRet = ((_xCfx)(pFn))((float)_argsd[0], _args[0]);
	break;
case CALL2(TP_INT64, TP_FP32, TP_FP32):
	xRet = ((_xCff)(pFn))((float)_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_INT64, TP_FP32, TP_FP64):
	xRet = ((_xCfd)(pFn))((float)_argsd[0], _argsd[1]);
	break;
case CALL2(TP_INT64, TP_FP64, TP_INT32):
	xRet = ((_xCdu)(pFn))(_argsd[0], (U32)_args[0]);
	break;
case CALL2(TP_INT64, TP_FP64, TP_INT64):
	xRet = ((_xCdx)(pFn))(_argsd[0], _args[0]);
	break;
case CALL2(TP_INT64, TP_FP64, TP_FP32):
	xRet = ((_xCdf)(pFn))(_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_INT64, TP_FP64, TP_FP64):
	xRet = ((_xCdd)(pFn))(_argsd[0], _argsd[1]);
	break;
case CALL2(TP_FP32, TP_INT32, TP_INT32):
	fRet = ((_fCuu)(pFn))((U32)_args[0], (U32)_args[1]);
	break;
case CALL2(TP_FP32, TP_INT32, TP_INT64):
	fRet = ((_fCux)(pFn))((U32)_args[0], _args[1]);
	break;
case CALL2(TP_FP32, TP_INT32, TP_FP32):
	fRet = ((_fCuf)(pFn))((U32)_args[0], (float)_argsd[0]);
	break;
case CALL2(TP_FP32, TP_INT32, TP_FP64):
	fRet = ((_fCud)(pFn))((U32)_args[0], _argsd[0]);
	break;
case CALL2(TP_FP32, TP_INT64, TP_INT32):
	fRet = ((_fCxu)(pFn))(_args[0], (U32)_args[1]);
	break;
case CALL2(TP_FP32, TP_INT64, TP_INT64):
	fRet = ((_fCxx)(pFn))(_args[0], _args[1]);
	break;
case CALL2(TP_FP32, TP_INT64, TP_FP32):
	fRet = ((_fCxf)(pFn))(_args[0], (float)_argsd[0]);
	break;
case CALL2(TP_FP32, TP_INT64, TP_FP64):
	fRet = ((_fCxd)(pFn))(_args[0], _argsd[0]);
	break;
case CALL2(TP_FP32, TP_FP32, TP_INT32):
	fRet = ((_fCfu)(pFn))((float)_argsd[0], (U32)_args[0]);
	break;
case CALL2(TP_FP32, TP_FP32, TP_INT64):
	fRet = ((_fCfx)(pFn))((float)_argsd[0], _args[0]);
	break;
case CALL2(TP_FP32, TP_FP32, TP_FP32):
	fRet = ((_fCff)(pFn))((float)_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_FP32, TP_FP32, TP_FP64):
	fRet = ((_fCfd)(pFn))((float)_argsd[0], _argsd[1]);
	break;
case CALL2(TP_FP32, TP_FP64, TP_INT32):
	fRet = ((_fCdu)(pFn))(_argsd[0], (U32)_args[0]);
	break;
case CALL2(TP_FP32, TP_FP64, TP_INT64):
	fRet = ((_fCdx)(pFn))(_argsd[0], _args[0]);
	break;
case CALL2(TP_FP32, TP_FP64, TP_FP32):
	fRet = ((_fCdf)(pFn))(_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_FP32, TP_FP64, TP_FP64):
	fRet = ((_fCdd)(pFn))(_argsd[0], _argsd[1]);
	break;
case CALL2(TP_FP64, TP_INT32, TP_INT32):
	dRet = ((_dCuu)(pFn))((U32)_args[0], (U32)_args[1]);
	break;
case CALL2(TP_FP64, TP_INT32, TP_INT64):
	dRet = ((_dCux)(pFn))((U32)_args[0], _args[1]);
	break;
case CALL2(TP_FP64, TP_INT32, TP_FP32):
	dRet = ((_dCuf)(pFn))((U32)_args[0], (float)_argsd[0]);
	break;
case CALL2(TP_FP64, TP_INT32, TP_FP64):
	dRet = ((_dCud)(pFn))((U32)_args[0], _argsd[0]);
	break;
case CALL2(TP_FP64, TP_INT64, TP_INT32):
	dRet = ((_dCxu)(pFn))(_args[0], (U32)_args[1]);
	break;
case CALL2(TP_FP64, TP_INT64, TP_INT64):
	dRet = ((_dCxx)(pFn))(_args[0], _args[1]);
	break;
case CALL2(TP_FP64, TP_INT64, TP_FP32):
	dRet = ((_dCxf)(pFn))(_args[0], (float)_argsd[0]);
	break;
case CALL2(TP_FP64, TP_INT64, TP_FP64):
	dRet = ((_dCxd)(pFn))(_args[0], _argsd[0]);
	break;
case CALL2(TP_FP64, TP_FP32, TP_INT32):
	dRet = ((_dCfu)(pFn))((float)_argsd[0], (U32)_args[0]);
	break;
case CALL2(TP_FP64, TP_FP32, TP_INT64):
	dRet = ((_dCfx)(pFn))((float)_argsd[0], _args[0]);
	break;
case CALL2(TP_FP64, TP_FP32, TP_FP32):
	dRet = ((_dCff)(pFn))((float)_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_FP64, TP_FP32, TP_FP64):
	dRet = ((_dCfd)(pFn))((float)_argsd[0], _argsd[1]);
	break;
case CALL2(TP_FP64, TP_FP64, TP_INT32):
	dRet = ((_dCdu)(pFn))(_argsd[0], (U32)_args[0]);
	break;
case CALL2(TP_FP64, TP_FP64, TP_INT64):
	dRet = ((_dCdx)(pFn))(_argsd[0], _args[0]);
	break;
case CALL2(TP_FP64, TP_FP64, TP_FP32):
	dRet = ((_dCdf)(pFn))(_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_FP64, TP_FP64, TP_FP64):
	dRet = ((_dCdd)(pFn))(_argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_INT32, TP_INT32):
	uRet = ((_uCuuu)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_INT32, TP_INT64):
	uRet = ((_uCuux)(pFn))((U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_INT32, TP_FP32):
	uRet = ((_uCuuf)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_INT32, TP_FP64):
	uRet = ((_uCuud)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_INT64, TP_INT32):
	uRet = ((_uCuxu)(pFn))((U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_INT64, TP_INT64):
	uRet = ((_uCuxx)(pFn))((U32)_args[0], _args[1], _args[2]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_INT64, TP_FP32):
	uRet = ((_uCuxf)(pFn))((U32)_args[0], _args[1], (float)_argsd[0]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_INT64, TP_FP64):
	uRet = ((_uCuxd)(pFn))((U32)_args[0], _args[1], _argsd[0]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP32, TP_INT32):
	uRet = ((_uCufu)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP32, TP_INT64):
	uRet = ((_uCufx)(pFn))((U32)_args[0], (float)_argsd[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP32, TP_FP32):
	uRet = ((_uCuff)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP32, TP_FP64):
	uRet = ((_uCufd)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP64, TP_INT32):
	uRet = ((_uCudu)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP64, TP_INT64):
	uRet = ((_uCudx)(pFn))((U32)_args[0], _argsd[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP64, TP_FP32):
	uRet = ((_uCudf)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP64, TP_FP64):
	uRet = ((_uCudd)(pFn))((U32)_args[0], _argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_INT32, TP_INT32):
	uRet = ((_uCxuu)(pFn))(_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_INT32, TP_INT64):
	uRet = ((_uCxux)(pFn))(_args[0], (U32)_args[1], _args[2]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_INT32, TP_FP32):
	uRet = ((_uCxuf)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_INT32, TP_FP64):
	uRet = ((_uCxud)(pFn))(_args[0], (U32)_args[1], _argsd[0]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_INT64, TP_INT32):
	uRet = ((_uCxxu)(pFn))(_args[0], _args[1], (U32)_args[2]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_INT64, TP_INT64):
	uRet = ((_uCxxx)(pFn))(_args[0], _args[1], _args[2]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_INT64, TP_FP32):
	uRet = ((_uCxxf)(pFn))(_args[0], _args[1], (float)_argsd[0]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_INT64, TP_FP64):
	uRet = ((_uCxxd)(pFn))(_args[0], _args[1], _argsd[0]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_FP32, TP_INT32):
	uRet = ((_uCxfu)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_FP32, TP_INT64):
	uRet = ((_uCxfx)(pFn))(_args[0], (float)_argsd[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_FP32, TP_FP32):
	uRet = ((_uCxff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_FP32, TP_FP64):
	uRet = ((_uCxfd)(pFn))(_args[0], (float)_argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_FP64, TP_INT32):
	uRet = ((_uCxdu)(pFn))(_args[0], _argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_FP64, TP_INT64):
	uRet = ((_uCxdx)(pFn))(_args[0], _argsd[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_FP64, TP_FP32):
	uRet = ((_uCxdf)(pFn))(_args[0], _argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT64, TP_FP64, TP_FP64):
	uRet = ((_uCxdd)(pFn))(_args[0], _argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_INT32, TP_INT32):
	uRet = ((_uCfuu)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_INT32, TP_INT64):
	uRet = ((_uCfux)(pFn))((float)_argsd[0], (U32)_args[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_INT32, TP_FP32):
	uRet = ((_uCfuf)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_INT32, TP_FP64):
	uRet = ((_uCfud)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_INT64, TP_INT32):
	uRet = ((_uCfxu)(pFn))((float)_argsd[0], _args[0], (U32)_args[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_INT64, TP_INT64):
	uRet = ((_uCfxx)(pFn))((float)_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_INT64, TP_FP32):
	uRet = ((_uCfxf)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_INT64, TP_FP64):
	uRet = ((_uCfxd)(pFn))((float)_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP32, TP_INT32):
	uRet = ((_uCffu)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP32, TP_INT64):
	uRet = ((_uCffx)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP32, TP_FP32):
	uRet = ((_uCfff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP32, TP_FP64):
	uRet = ((_uCffd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP64, TP_INT32):
	uRet = ((_uCfdu)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP64, TP_INT64):
	uRet = ((_uCfdx)(pFn))((float)_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP64, TP_FP32):
	uRet = ((_uCfdf)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP64, TP_FP64):
	uRet = ((_uCfdd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_INT32, TP_INT32):
	uRet = ((_uCduu)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_INT32, TP_INT64):
	uRet = ((_uCdux)(pFn))(_argsd[0], (U32)_args[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_INT32, TP_FP32):
	uRet = ((_uCduf)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_INT32, TP_FP64):
	uRet = ((_uCdud)(pFn))(_argsd[0], (U32)_args[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_INT64, TP_INT32):
	uRet = ((_uCdxu)(pFn))(_argsd[0], _args[0], (U32)_args[1]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_INT64, TP_INT64):
	uRet = ((_uCdxx)(pFn))(_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_INT64, TP_FP32):
	uRet = ((_uCdxf)(pFn))(_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_INT64, TP_FP64):
	uRet = ((_uCdxd)(pFn))(_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP32, TP_INT32):
	uRet = ((_uCdfu)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP32, TP_INT64):
	uRet = ((_uCdfx)(pFn))(_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP32, TP_FP32):
	uRet = ((_uCdff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP32, TP_FP64):
	uRet = ((_uCdfd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP64, TP_INT32):
	uRet = ((_uCddu)(pFn))(_argsd[0], _argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP64, TP_INT64):
	uRet = ((_uCddx)(pFn))(_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP64, TP_FP32):
	uRet = ((_uCddf)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP64, TP_FP64):
	uRet = ((_uCddd)(pFn))(_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_INT32, TP_INT32):
	xRet = ((_xCuuu)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_INT32, TP_INT64):
	xRet = ((_xCuux)(pFn))((U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_INT32, TP_FP32):
	xRet = ((_xCuuf)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_INT32, TP_FP64):
	xRet = ((_xCuud)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_INT64, TP_INT32):
	xRet = ((_xCuxu)(pFn))((U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_INT64, TP_INT64):
	xRet = ((_xCuxx)(pFn))((U32)_args[0], _args[1], _args[2]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_INT64, TP_FP32):
	xRet = ((_xCuxf)(pFn))((U32)_args[0], _args[1], (float)_argsd[0]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_INT64, TP_FP64):
	xRet = ((_xCuxd)(pFn))((U32)_args[0], _args[1], _argsd[0]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_FP32, TP_INT32):
	xRet = ((_xCufu)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_FP32, TP_INT64):
	xRet = ((_xCufx)(pFn))((U32)_args[0], (float)_argsd[0], _args[1]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_FP32, TP_FP32):
	xRet = ((_xCuff)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_FP32, TP_FP64):
	xRet = ((_xCufd)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_FP64, TP_INT32):
	xRet = ((_xCudu)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_FP64, TP_INT64):
	xRet = ((_xCudx)(pFn))((U32)_args[0], _argsd[0], _args[1]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_FP64, TP_FP32):
	xRet = ((_xCudf)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT64, TP_INT32, TP_FP64, TP_FP64):
	xRet = ((_xCudd)(pFn))((U32)_args[0], _argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_INT32, TP_INT32):
	xRet = ((_xCxuu)(pFn))(_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_INT32, TP_INT64):
	xRet = ((_xCxux)(pFn))(_args[0], (U32)_args[1], _args[2]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_INT32, TP_FP32):
	xRet = ((_xCxuf)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_INT32, TP_FP64):
	xRet = ((_xCxud)(pFn))(_args[0], (U32)_args[1], _argsd[0]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_INT64, TP_INT32):
	xRet = ((_xCxxu)(pFn))(_args[0], _args[1], (U32)_args[2]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_INT64, TP_INT64):
	xRet = ((_xCxxx)(pFn))(_args[0], _args[1], _args[2]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_INT64, TP_FP32):
	xRet = ((_xCxxf)(pFn))(_args[0], _args[1], (float)_argsd[0]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_INT64, TP_FP64):
	xRet = ((_xCxxd)(pFn))(_args[0], _args[1], _argsd[0]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_FP32, TP_INT32):
	xRet = ((_xCxfu)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_FP32, TP_INT64):
	xRet = ((_xCxfx)(pFn))(_args[0], (float)_argsd[0], _args[1]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_FP32, TP_FP32):
	xRet = ((_xCxff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_FP32, TP_FP64):
	xRet = ((_xCxfd)(pFn))(_args[0], (float)_argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_FP64, TP_INT32):
	xRet = ((_xCxdu)(pFn))(_args[0], _argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_FP64, TP_INT64):
	xRet = ((_xCxdx)(pFn))(_args[0], _argsd[0], _args[1]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_FP64, TP_FP32):
	xRet = ((_xCxdf)(pFn))(_args[0], _argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT64, TP_INT64, TP_FP64, TP_FP64):
	xRet = ((_xCxdd)(pFn))(_args[0], _argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_INT32, TP_INT32):
	xRet = ((_xCfuu)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_INT32, TP_INT64):
	xRet = ((_xCfux)(pFn))((float)_argsd[0], (U32)_args[0], _args[1]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_INT32, TP_FP32):
	xRet = ((_xCfuf)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_INT32, TP_FP64):
	xRet = ((_xCfud)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_INT64, TP_INT32):
	xRet = ((_xCfxu)(pFn))((float)_argsd[0], _args[0], (U32)_args[1]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_INT64, TP_INT64):
	xRet = ((_xCfxx)(pFn))((float)_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_INT64, TP_FP32):
	xRet = ((_xCfxf)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_INT64, TP_FP64):
	xRet = ((_xCfxd)(pFn))((float)_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_FP32, TP_INT32):
	xRet = ((_xCffu)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_FP32, TP_INT64):
	xRet = ((_xCffx)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_FP32, TP_FP32):
	xRet = ((_xCfff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_FP32, TP_FP64):
	xRet = ((_xCffd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_FP64, TP_INT32):
	xRet = ((_xCfdu)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_FP64, TP_INT64):
	xRet = ((_xCfdx)(pFn))((float)_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_FP64, TP_FP32):
	xRet = ((_xCfdf)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT64, TP_FP32, TP_FP64, TP_FP64):
	xRet = ((_xCfdd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_INT32, TP_INT32):
	xRet = ((_xCduu)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_INT32, TP_INT64):
	xRet = ((_xCdux)(pFn))(_argsd[0], (U32)_args[0], _args[1]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_INT32, TP_FP32):
	xRet = ((_xCduf)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_INT32, TP_FP64):
	xRet = ((_xCdud)(pFn))(_argsd[0], (U32)_args[0], _argsd[1]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_INT64, TP_INT32):
	xRet = ((_xCdxu)(pFn))(_argsd[0], _args[0], (U32)_args[1]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_INT64, TP_INT64):
	xRet = ((_xCdxx)(pFn))(_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_INT64, TP_FP32):
	xRet = ((_xCdxf)(pFn))(_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_INT64, TP_FP64):
	xRet = ((_xCdxd)(pFn))(_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_FP32, TP_INT32):
	xRet = ((_xCdfu)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_FP32, TP_INT64):
	xRet = ((_xCdfx)(pFn))(_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_FP32, TP_FP32):
	xRet = ((_xCdff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_FP32, TP_FP64):
	xRet = ((_xCdfd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_FP64, TP_INT32):
	xRet = ((_xCddu)(pFn))(_argsd[0], _argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_FP64, TP_INT64):
	xRet = ((_xCddx)(pFn))(_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_FP64, TP_FP32):
	xRet = ((_xCddf)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT64, TP_FP64, TP_FP64, TP_FP64):
	xRet = ((_xCddd)(pFn))(_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_INT32, TP_INT32):
	fRet = ((_fCuuu)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_INT32, TP_INT64):
	fRet = ((_fCuux)(pFn))((U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_INT32, TP_FP32):
	fRet = ((_fCuuf)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_INT32, TP_FP64):
	fRet = ((_fCuud)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_INT64, TP_INT32):
	fRet = ((_fCuxu)(pFn))((U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_INT64, TP_INT64):
	fRet = ((_fCuxx)(pFn))((U32)_args[0], _args[1], _args[2]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_INT64, TP_FP32):
	fRet = ((_fCuxf)(pFn))((U32)_args[0], _args[1], (float)_argsd[0]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_INT64, TP_FP64):
	fRet = ((_fCuxd)(pFn))((U32)_args[0], _args[1], _argsd[0]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP32, TP_INT32):
	fRet = ((_fCufu)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP32, TP_INT64):
	fRet = ((_fCufx)(pFn))((U32)_args[0], (float)_argsd[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP32, TP_FP32):
	fRet = ((_fCuff)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP32, TP_FP64):
	fRet = ((_fCufd)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP64, TP_INT32):
	fRet = ((_fCudu)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP64, TP_INT64):
	fRet = ((_fCudx)(pFn))((U32)_args[0], _argsd[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP64, TP_FP32):
	fRet = ((_fCudf)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP64, TP_FP64):
	fRet = ((_fCudd)(pFn))((U32)_args[0], _argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_INT32, TP_INT32):
	fRet = ((_fCxuu)(pFn))(_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_INT32, TP_INT64):
	fRet = ((_fCxux)(pFn))(_args[0], (U32)_args[1], _args[2]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_INT32, TP_FP32):
	fRet = ((_fCxuf)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_INT32, TP_FP64):
	fRet = ((_fCxud)(pFn))(_args[0], (U32)_args[1], _argsd[0]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_INT64, TP_INT32):
	fRet = ((_fCxxu)(pFn))(_args[0], _args[1], (U32)_args[2]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_INT64, TP_INT64):
	fRet = ((_fCxxx)(pFn))(_args[0], _args[1], _args[2]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_INT64, TP_FP32):
	fRet = ((_fCxxf)(pFn))(_args[0], _args[1], (float)_argsd[0]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_INT64, TP_FP64):
	fRet = ((_fCxxd)(pFn))(_args[0], _args[1], _argsd[0]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_FP32, TP_INT32):
	fRet = ((_fCxfu)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_FP32, TP_INT64):
	fRet = ((_fCxfx)(pFn))(_args[0], (float)_argsd[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_FP32, TP_FP32):
	fRet = ((_fCxff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_FP32, TP_FP64):
	fRet = ((_fCxfd)(pFn))(_args[0], (float)_argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_FP64, TP_INT32):
	fRet = ((_fCxdu)(pFn))(_args[0], _argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_FP64, TP_INT64):
	fRet = ((_fCxdx)(pFn))(_args[0], _argsd[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_FP64, TP_FP32):
	fRet = ((_fCxdf)(pFn))(_args[0], _argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_INT64, TP_FP64, TP_FP64):
	fRet = ((_fCxdd)(pFn))(_args[0], _argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_INT32, TP_INT32):
	fRet = ((_fCfuu)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_INT32, TP_INT64):
	fRet = ((_fCfux)(pFn))((float)_argsd[0], (U32)_args[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_INT32, TP_FP32):
	fRet = ((_fCfuf)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_INT32, TP_FP64):
	fRet = ((_fCfud)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_INT64, TP_INT32):
	fRet = ((_fCfxu)(pFn))((float)_argsd[0], _args[0], (U32)_args[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_INT64, TP_INT64):
	fRet = ((_fCfxx)(pFn))((float)_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_INT64, TP_FP32):
	fRet = ((_fCfxf)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_INT64, TP_FP64):
	fRet = ((_fCfxd)(pFn))((float)_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP32, TP_INT32):
	fRet = ((_fCffu)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP32, TP_INT64):
	fRet = ((_fCffx)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP32, TP_FP32):
	fRet = ((_fCfff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP32, TP_FP64):
	fRet = ((_fCffd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP64, TP_INT32):
	fRet = ((_fCfdu)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP64, TP_INT64):
	fRet = ((_fCfdx)(pFn))((float)_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP64, TP_FP32):
	fRet = ((_fCfdf)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP64, TP_FP64):
	fRet = ((_fCfdd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_INT32, TP_INT32):
	fRet = ((_fCduu)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_INT32, TP_INT64):
	fRet = ((_fCdux)(pFn))(_argsd[0], (U32)_args[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_INT32, TP_FP32):
	fRet = ((_fCduf)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_INT32, TP_FP64):
	fRet = ((_fCdud)(pFn))(_argsd[0], (U32)_args[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_INT64, TP_INT32):
	fRet = ((_fCdxu)(pFn))(_argsd[0], _args[0], (U32)_args[1]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_INT64, TP_INT64):
	fRet = ((_fCdxx)(pFn))(_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_INT64, TP_FP32):
	fRet = ((_fCdxf)(pFn))(_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_INT64, TP_FP64):
	fRet = ((_fCdxd)(pFn))(_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP32, TP_INT32):
	fRet = ((_fCdfu)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP32, TP_INT64):
	fRet = ((_fCdfx)(pFn))(_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP32, TP_FP32):
	fRet = ((_fCdff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP32, TP_FP64):
	fRet = ((_fCdfd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP64, TP_INT32):
	fRet = ((_fCddu)(pFn))(_argsd[0], _argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP64, TP_INT64):
	fRet = ((_fCddx)(pFn))(_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP64, TP_FP32):
	fRet = ((_fCddf)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP64, TP_FP64):
	fRet = ((_fCddd)(pFn))(_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_INT32, TP_INT32):
	dRet = ((_dCuuu)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_INT32, TP_INT64):
	dRet = ((_dCuux)(pFn))((U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_INT32, TP_FP32):
	dRet = ((_dCuuf)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_INT32, TP_FP64):
	dRet = ((_dCuud)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_INT64, TP_INT32):
	dRet = ((_dCuxu)(pFn))((U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_INT64, TP_INT64):
	dRet = ((_dCuxx)(pFn))((U32)_args[0], _args[1], _args[2]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_INT64, TP_FP32):
	dRet = ((_dCuxf)(pFn))((U32)_args[0], _args[1], (float)_argsd[0]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_INT64, TP_FP64):
	dRet = ((_dCuxd)(pFn))((U32)_args[0], _args[1], _argsd[0]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP32, TP_INT32):
	dRet = ((_dCufu)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP32, TP_INT64):
	dRet = ((_dCufx)(pFn))((U32)_args[0], (float)_argsd[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP32, TP_FP32):
	dRet = ((_dCuff)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP32, TP_FP64):
	dRet = ((_dCufd)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP64, TP_INT32):
	dRet = ((_dCudu)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP64, TP_INT64):
	dRet = ((_dCudx)(pFn))((U32)_args[0], _argsd[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP64, TP_FP32):
	dRet = ((_dCudf)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP64, TP_FP64):
	dRet = ((_dCudd)(pFn))((U32)_args[0], _argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_INT32, TP_INT32):
	dRet = ((_dCxuu)(pFn))(_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_INT32, TP_INT64):
	dRet = ((_dCxux)(pFn))(_args[0], (U32)_args[1], _args[2]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_INT32, TP_FP32):
	dRet = ((_dCxuf)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_INT32, TP_FP64):
	dRet = ((_dCxud)(pFn))(_args[0], (U32)_args[1], _argsd[0]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_INT64, TP_INT32):
	dRet = ((_dCxxu)(pFn))(_args[0], _args[1], (U32)_args[2]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_INT64, TP_INT64):
	dRet = ((_dCxxx)(pFn))(_args[0], _args[1], _args[2]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_INT64, TP_FP32):
	dRet = ((_dCxxf)(pFn))(_args[0], _args[1], (float)_argsd[0]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_INT64, TP_FP64):
	dRet = ((_dCxxd)(pFn))(_args[0], _args[1], _argsd[0]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_FP32, TP_INT32):
	dRet = ((_dCxfu)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_FP32, TP_INT64):
	dRet = ((_dCxfx)(pFn))(_args[0], (float)_argsd[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_FP32, TP_FP32):
	dRet = ((_dCxff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_FP32, TP_FP64):
	dRet = ((_dCxfd)(pFn))(_args[0], (float)_argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_FP64, TP_INT32):
	dRet = ((_dCxdu)(pFn))(_args[0], _argsd[0], (U32)_args[1]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_FP64, TP_INT64):
	dRet = ((_dCxdx)(pFn))(_args[0], _argsd[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_FP64, TP_FP32):
	dRet = ((_dCxdf)(pFn))(_args[0], _argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_INT64, TP_FP64, TP_FP64):
	dRet = ((_dCxdd)(pFn))(_args[0], _argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_INT32, TP_INT32):
	dRet = ((_dCfuu)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_INT32, TP_INT64):
	dRet = ((_dCfux)(pFn))((float)_argsd[0], (U32)_args[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_INT32, TP_FP32):
	dRet = ((_dCfuf)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_INT32, TP_FP64):
	dRet = ((_dCfud)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_INT64, TP_INT32):
	dRet = ((_dCfxu)(pFn))((float)_argsd[0], _args[0], (U32)_args[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_INT64, TP_INT64):
	dRet = ((_dCfxx)(pFn))((float)_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_INT64, TP_FP32):
	dRet = ((_dCfxf)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_INT64, TP_FP64):
	dRet = ((_dCfxd)(pFn))((float)_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP32, TP_INT32):
	dRet = ((_dCffu)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP32, TP_INT64):
	dRet = ((_dCffx)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP32, TP_FP32):
	dRet = ((_dCfff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP32, TP_FP64):
	dRet = ((_dCffd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP64, TP_INT32):
	dRet = ((_dCfdu)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP64, TP_INT64):
	dRet = ((_dCfdx)(pFn))((float)_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP64, TP_FP32):
	dRet = ((_dCfdf)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP64, TP_FP64):
	dRet = ((_dCfdd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_INT32, TP_INT32):
	dRet = ((_dCduu)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_INT32, TP_INT64):
	dRet = ((_dCdux)(pFn))(_argsd[0], (U32)_args[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_INT32, TP_FP32):
	dRet = ((_dCduf)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_INT32, TP_FP64):
	dRet = ((_dCdud)(pFn))(_argsd[0], (U32)_args[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_INT64, TP_INT32):
	dRet = ((_dCdxu)(pFn))(_argsd[0], _args[0], (U32)_args[1]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_INT64, TP_INT64):
	dRet = ((_dCdxx)(pFn))(_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_INT64, TP_FP32):
	dRet = ((_dCdxf)(pFn))(_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_INT64, TP_FP64):
	dRet = ((_dCdxd)(pFn))(_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP32, TP_INT32):
	dRet = ((_dCdfu)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP32, TP_INT64):
	dRet = ((_dCdfx)(pFn))(_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP32, TP_FP32):
	dRet = ((_dCdff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP32, TP_FP64):
	dRet = ((_dCdfd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP64, TP_INT32):
	dRet = ((_dCddu)(pFn))(_argsd[0], _argsd[1], (U32)_args[0]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP64, TP_INT64):
	dRet = ((_dCddx)(pFn))(_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP64, TP_FP32):
	dRet = ((_dCddf)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP64, TP_FP64):
	dRet = ((_dCddd)(pFn))(_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
	uRet = ((_uCuuuu)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT64):
	uRet = ((_uCuuux)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_FP32):
	uRet = ((_uCuuuf)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_FP64):
	uRet = ((_uCuuud)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_INT64, TP_INT32):
	uRet = ((_uCuuxu)(pFn))((U32)_args[0], (U32)_args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_INT64, TP_INT64):
	uRet = ((_uCuuxx)(pFn))((U32)_args[0], (U32)_args[1], _args[2], _args[3]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_INT64, TP_FP32):
	uRet = ((_uCuuxf)(pFn))((U32)_args[0], (U32)_args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_INT64, TP_FP64):
	uRet = ((_uCuuxd)(pFn))((U32)_args[0], (U32)_args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP32, TP_INT32):
	uRet = ((_uCuufu)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP32, TP_INT64):
	uRet = ((_uCuufx)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP32, TP_FP32):
	uRet = ((_uCuuff)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP32, TP_FP64):
	uRet = ((_uCuufd)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP64, TP_INT32):
	uRet = ((_uCuudu)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP64, TP_INT64):
	uRet = ((_uCuudx)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP64, TP_FP32):
	uRet = ((_uCuudf)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP64, TP_FP64):
	uRet = ((_uCuudd)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_INT32, TP_INT32):
	uRet = ((_uCuxuu)(pFn))((U32)_args[0], _args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_INT32, TP_INT64):
	uRet = ((_uCuxux)(pFn))((U32)_args[0], _args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_INT32, TP_FP32):
	uRet = ((_uCuxuf)(pFn))((U32)_args[0], _args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_INT32, TP_FP64):
	uRet = ((_uCuxud)(pFn))((U32)_args[0], _args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_INT64, TP_INT32):
	uRet = ((_uCuxxu)(pFn))((U32)_args[0], _args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_INT64, TP_INT64):
	uRet = ((_uCuxxx)(pFn))((U32)_args[0], _args[1], _args[2], _args[3]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_INT64, TP_FP32):
	uRet = ((_uCuxxf)(pFn))((U32)_args[0], _args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_INT64, TP_FP64):
	uRet = ((_uCuxxd)(pFn))((U32)_args[0], _args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_FP32, TP_INT32):
	uRet = ((_uCuxfu)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_FP32, TP_INT64):
	uRet = ((_uCuxfx)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_FP32, TP_FP32):
	uRet = ((_uCuxff)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_FP32, TP_FP64):
	uRet = ((_uCuxfd)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_FP64, TP_INT32):
	uRet = ((_uCuxdu)(pFn))((U32)_args[0], _args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_FP64, TP_INT64):
	uRet = ((_uCuxdx)(pFn))((U32)_args[0], _args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_FP64, TP_FP32):
	uRet = ((_uCuxdf)(pFn))((U32)_args[0], _args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT64, TP_FP64, TP_FP64):
	uRet = ((_uCuxdd)(pFn))((U32)_args[0], _args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_INT32, TP_INT32):
	uRet = ((_uCufuu)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_INT32, TP_INT64):
	uRet = ((_uCufux)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_INT32, TP_FP32):
	uRet = ((_uCufuf)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_INT32, TP_FP64):
	uRet = ((_uCufud)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_INT64, TP_INT32):
	uRet = ((_uCufxu)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_INT64, TP_INT64):
	uRet = ((_uCufxx)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_INT64, TP_FP32):
	uRet = ((_uCufxf)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_INT64, TP_FP64):
	uRet = ((_uCufxd)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP32, TP_INT32):
	uRet = ((_uCuffu)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP32, TP_INT64):
	uRet = ((_uCuffx)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP32, TP_FP32):
	uRet = ((_uCufff)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP32, TP_FP64):
	uRet = ((_uCuffd)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP64, TP_INT32):
	uRet = ((_uCufdu)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP64, TP_INT64):
	uRet = ((_uCufdx)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP64, TP_FP32):
	uRet = ((_uCufdf)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP64, TP_FP64):
	uRet = ((_uCufdd)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_INT32, TP_INT32):
	uRet = ((_uCuduu)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_INT32, TP_INT64):
	uRet = ((_uCudux)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_INT32, TP_FP32):
	uRet = ((_uCuduf)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_INT32, TP_FP64):
	uRet = ((_uCudud)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_INT64, TP_INT32):
	uRet = ((_uCudxu)(pFn))((U32)_args[0], _argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_INT64, TP_INT64):
	uRet = ((_uCudxx)(pFn))((U32)_args[0], _argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_INT64, TP_FP32):
	uRet = ((_uCudxf)(pFn))((U32)_args[0], _argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_INT64, TP_FP64):
	uRet = ((_uCudxd)(pFn))((U32)_args[0], _argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP32, TP_INT32):
	uRet = ((_uCudfu)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP32, TP_INT64):
	uRet = ((_uCudfx)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP32, TP_FP32):
	uRet = ((_uCudff)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP32, TP_FP64):
	uRet = ((_uCudfd)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP64, TP_INT32):
	uRet = ((_uCuddu)(pFn))((U32)_args[0], _argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP64, TP_INT64):
	uRet = ((_uCuddx)(pFn))((U32)_args[0], _argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP64, TP_FP32):
	uRet = ((_uCuddf)(pFn))((U32)_args[0], _argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP64, TP_FP64):
	uRet = ((_uCuddd)(pFn))((U32)_args[0], _argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_INT32, TP_INT32):
	uRet = ((_uCxuuu)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_INT32, TP_INT64):
	uRet = ((_uCxuux)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_INT32, TP_FP32):
	uRet = ((_uCxuuf)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_INT32, TP_FP64):
	uRet = ((_uCxuud)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_INT64, TP_INT32):
	uRet = ((_uCxuxu)(pFn))(_args[0], (U32)_args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_INT64, TP_INT64):
	uRet = ((_uCxuxx)(pFn))(_args[0], (U32)_args[1], _args[2], _args[3]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_INT64, TP_FP32):
	uRet = ((_uCxuxf)(pFn))(_args[0], (U32)_args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_INT64, TP_FP64):
	uRet = ((_uCxuxd)(pFn))(_args[0], (U32)_args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_FP32, TP_INT32):
	uRet = ((_uCxufu)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_FP32, TP_INT64):
	uRet = ((_uCxufx)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_FP32, TP_FP32):
	uRet = ((_uCxuff)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_FP32, TP_FP64):
	uRet = ((_uCxufd)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_FP64, TP_INT32):
	uRet = ((_uCxudu)(pFn))(_args[0], (U32)_args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_FP64, TP_INT64):
	uRet = ((_uCxudx)(pFn))(_args[0], (U32)_args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_FP64, TP_FP32):
	uRet = ((_uCxudf)(pFn))(_args[0], (U32)_args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT32, TP_FP64, TP_FP64):
	uRet = ((_uCxudd)(pFn))(_args[0], (U32)_args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_INT32, TP_INT32):
	uRet = ((_uCxxuu)(pFn))(_args[0], _args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_INT32, TP_INT64):
	uRet = ((_uCxxux)(pFn))(_args[0], _args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_INT32, TP_FP32):
	uRet = ((_uCxxuf)(pFn))(_args[0], _args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_INT32, TP_FP64):
	uRet = ((_uCxxud)(pFn))(_args[0], _args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_INT64, TP_INT32):
	uRet = ((_uCxxxu)(pFn))(_args[0], _args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_INT64, TP_INT64):
	uRet = ((_uCxxxx)(pFn))(_args[0], _args[1], _args[2], _args[3]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_INT64, TP_FP32):
	uRet = ((_uCxxxf)(pFn))(_args[0], _args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_INT64, TP_FP64):
	uRet = ((_uCxxxd)(pFn))(_args[0], _args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_FP32, TP_INT32):
	uRet = ((_uCxxfu)(pFn))(_args[0], _args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_FP32, TP_INT64):
	uRet = ((_uCxxfx)(pFn))(_args[0], _args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_FP32, TP_FP32):
	uRet = ((_uCxxff)(pFn))(_args[0], _args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_FP32, TP_FP64):
	uRet = ((_uCxxfd)(pFn))(_args[0], _args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_FP64, TP_INT32):
	uRet = ((_uCxxdu)(pFn))(_args[0], _args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_FP64, TP_INT64):
	uRet = ((_uCxxdx)(pFn))(_args[0], _args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_FP64, TP_FP32):
	uRet = ((_uCxxdf)(pFn))(_args[0], _args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_INT64, TP_FP64, TP_FP64):
	uRet = ((_uCxxdd)(pFn))(_args[0], _args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_INT32, TP_INT32):
	uRet = ((_uCxfuu)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_INT32, TP_INT64):
	uRet = ((_uCxfux)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_INT32, TP_FP32):
	uRet = ((_uCxfuf)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_INT32, TP_FP64):
	uRet = ((_uCxfud)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_INT64, TP_INT32):
	uRet = ((_uCxfxu)(pFn))(_args[0], (float)_argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_INT64, TP_INT64):
	uRet = ((_uCxfxx)(pFn))(_args[0], (float)_argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_INT64, TP_FP32):
	uRet = ((_uCxfxf)(pFn))(_args[0], (float)_argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_INT64, TP_FP64):
	uRet = ((_uCxfxd)(pFn))(_args[0], (float)_argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_FP32, TP_INT32):
	uRet = ((_uCxffu)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_FP32, TP_INT64):
	uRet = ((_uCxffx)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_FP32, TP_FP32):
	uRet = ((_uCxfff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_FP32, TP_FP64):
	uRet = ((_uCxffd)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_FP64, TP_INT32):
	uRet = ((_uCxfdu)(pFn))(_args[0], (float)_argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_FP64, TP_INT64):
	uRet = ((_uCxfdx)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_FP64, TP_FP32):
	uRet = ((_uCxfdf)(pFn))(_args[0], (float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP32, TP_FP64, TP_FP64):
	uRet = ((_uCxfdd)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_INT32, TP_INT32):
	uRet = ((_uCxduu)(pFn))(_args[0], _argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_INT32, TP_INT64):
	uRet = ((_uCxdux)(pFn))(_args[0], _argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_INT32, TP_FP32):
	uRet = ((_uCxduf)(pFn))(_args[0], _argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_INT32, TP_FP64):
	uRet = ((_uCxdud)(pFn))(_args[0], _argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_INT64, TP_INT32):
	uRet = ((_uCxdxu)(pFn))(_args[0], _argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_INT64, TP_INT64):
	uRet = ((_uCxdxx)(pFn))(_args[0], _argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_INT64, TP_FP32):
	uRet = ((_uCxdxf)(pFn))(_args[0], _argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_INT64, TP_FP64):
	uRet = ((_uCxdxd)(pFn))(_args[0], _argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_FP32, TP_INT32):
	uRet = ((_uCxdfu)(pFn))(_args[0], _argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_FP32, TP_INT64):
	uRet = ((_uCxdfx)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_FP32, TP_FP32):
	uRet = ((_uCxdff)(pFn))(_args[0], _argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_FP32, TP_FP64):
	uRet = ((_uCxdfd)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_FP64, TP_INT32):
	uRet = ((_uCxddu)(pFn))(_args[0], _argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_FP64, TP_INT64):
	uRet = ((_uCxddx)(pFn))(_args[0], _argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_FP64, TP_FP32):
	uRet = ((_uCxddf)(pFn))(_args[0], _argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT64, TP_FP64, TP_FP64, TP_FP64):
	uRet = ((_uCxddd)(pFn))(_args[0], _argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_INT32, TP_INT32):
	uRet = ((_uCfuuu)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_INT32, TP_INT64):
	uRet = ((_uCfuux)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_INT32, TP_FP32):
	uRet = ((_uCfuuf)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_INT32, TP_FP64):
	uRet = ((_uCfuud)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_INT64, TP_INT32):
	uRet = ((_uCfuxu)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_INT64, TP_INT64):
	uRet = ((_uCfuxx)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_INT64, TP_FP32):
	uRet = ((_uCfuxf)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_INT64, TP_FP64):
	uRet = ((_uCfuxd)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP32, TP_INT32):
	uRet = ((_uCfufu)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP32, TP_INT64):
	uRet = ((_uCfufx)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP32, TP_FP32):
	uRet = ((_uCfuff)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP32, TP_FP64):
	uRet = ((_uCfufd)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP64, TP_INT32):
	uRet = ((_uCfudu)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP64, TP_INT64):
	uRet = ((_uCfudx)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP64, TP_FP32):
	uRet = ((_uCfudf)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP64, TP_FP64):
	uRet = ((_uCfudd)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_INT32, TP_INT32):
	uRet = ((_uCfxuu)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_INT32, TP_INT64):
	uRet = ((_uCfxux)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_INT32, TP_FP32):
	uRet = ((_uCfxuf)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_INT32, TP_FP64):
	uRet = ((_uCfxud)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_INT64, TP_INT32):
	uRet = ((_uCfxxu)(pFn))((float)_argsd[0], _args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_INT64, TP_INT64):
	uRet = ((_uCfxxx)(pFn))((float)_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_INT64, TP_FP32):
	uRet = ((_uCfxxf)(pFn))((float)_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_INT64, TP_FP64):
	uRet = ((_uCfxxd)(pFn))((float)_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_FP32, TP_INT32):
	uRet = ((_uCfxfu)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_FP32, TP_INT64):
	uRet = ((_uCfxfx)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_FP32, TP_FP32):
	uRet = ((_uCfxff)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_FP32, TP_FP64):
	uRet = ((_uCfxfd)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_FP64, TP_INT32):
	uRet = ((_uCfxdu)(pFn))((float)_argsd[0], _args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_FP64, TP_INT64):
	uRet = ((_uCfxdx)(pFn))((float)_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_FP64, TP_FP32):
	uRet = ((_uCfxdf)(pFn))((float)_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT64, TP_FP64, TP_FP64):
	uRet = ((_uCfxdd)(pFn))((float)_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_INT32, TP_INT32):
	uRet = ((_uCffuu)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_INT32, TP_INT64):
	uRet = ((_uCffux)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_INT32, TP_FP32):
	uRet = ((_uCffuf)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_INT32, TP_FP64):
	uRet = ((_uCffud)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_INT64, TP_INT32):
	uRet = ((_uCffxu)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_INT64, TP_INT64):
	uRet = ((_uCffxx)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_INT64, TP_FP32):
	uRet = ((_uCffxf)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_INT64, TP_FP64):
	uRet = ((_uCffxd)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP32, TP_INT32):
	uRet = ((_uCfffu)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP32, TP_INT64):
	uRet = ((_uCfffx)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP32, TP_FP32):
	uRet = ((_uCffff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP32, TP_FP64):
	uRet = ((_uCfffd)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP64, TP_INT32):
	uRet = ((_uCffdu)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP64, TP_INT64):
	uRet = ((_uCffdx)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP64, TP_FP32):
	uRet = ((_uCffdf)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP64, TP_FP64):
	uRet = ((_uCffdd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_INT32, TP_INT32):
	uRet = ((_uCfduu)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_INT32, TP_INT64):
	uRet = ((_uCfdux)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_INT32, TP_FP32):
	uRet = ((_uCfduf)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_INT32, TP_FP64):
	uRet = ((_uCfdud)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_INT64, TP_INT32):
	uRet = ((_uCfdxu)(pFn))((float)_argsd[0], _argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_INT64, TP_INT64):
	uRet = ((_uCfdxx)(pFn))((float)_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_INT64, TP_FP32):
	uRet = ((_uCfdxf)(pFn))((float)_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_INT64, TP_FP64):
	uRet = ((_uCfdxd)(pFn))((float)_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP32, TP_INT32):
	uRet = ((_uCfdfu)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP32, TP_INT64):
	uRet = ((_uCfdfx)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP32, TP_FP32):
	uRet = ((_uCfdff)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP32, TP_FP64):
	uRet = ((_uCfdfd)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP64, TP_INT32):
	uRet = ((_uCfddu)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP64, TP_INT64):
	uRet = ((_uCfddx)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP64, TP_FP32):
	uRet = ((_uCfddf)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP64, TP_FP64):
	uRet = ((_uCfddd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_INT32, TP_INT32):
	uRet = ((_uCduuu)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_INT32, TP_INT64):
	uRet = ((_uCduux)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_INT32, TP_FP32):
	uRet = ((_uCduuf)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_INT32, TP_FP64):
	uRet = ((_uCduud)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_INT64, TP_INT32):
	uRet = ((_uCduxu)(pFn))(_argsd[0], (U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_INT64, TP_INT64):
	uRet = ((_uCduxx)(pFn))(_argsd[0], (U32)_args[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_INT64, TP_FP32):
	uRet = ((_uCduxf)(pFn))(_argsd[0], (U32)_args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_INT64, TP_FP64):
	uRet = ((_uCduxd)(pFn))(_argsd[0], (U32)_args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP32, TP_INT32):
	uRet = ((_uCdufu)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP32, TP_INT64):
	uRet = ((_uCdufx)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP32, TP_FP32):
	uRet = ((_uCduff)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP32, TP_FP64):
	uRet = ((_uCdufd)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP64, TP_INT32):
	uRet = ((_uCdudu)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP64, TP_INT64):
	uRet = ((_uCdudx)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP64, TP_FP32):
	uRet = ((_uCdudf)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP64, TP_FP64):
	uRet = ((_uCdudd)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_INT32, TP_INT32):
	uRet = ((_uCdxuu)(pFn))(_argsd[0], _args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_INT32, TP_INT64):
	uRet = ((_uCdxux)(pFn))(_argsd[0], _args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_INT32, TP_FP32):
	uRet = ((_uCdxuf)(pFn))(_argsd[0], _args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_INT32, TP_FP64):
	uRet = ((_uCdxud)(pFn))(_argsd[0], _args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_INT64, TP_INT32):
	uRet = ((_uCdxxu)(pFn))(_argsd[0], _args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_INT64, TP_INT64):
	uRet = ((_uCdxxx)(pFn))(_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_INT64, TP_FP32):
	uRet = ((_uCdxxf)(pFn))(_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_INT64, TP_FP64):
	uRet = ((_uCdxxd)(pFn))(_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_FP32, TP_INT32):
	uRet = ((_uCdxfu)(pFn))(_argsd[0], _args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_FP32, TP_INT64):
	uRet = ((_uCdxfx)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_FP32, TP_FP32):
	uRet = ((_uCdxff)(pFn))(_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_FP32, TP_FP64):
	uRet = ((_uCdxfd)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_FP64, TP_INT32):
	uRet = ((_uCdxdu)(pFn))(_argsd[0], _args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_FP64, TP_INT64):
	uRet = ((_uCdxdx)(pFn))(_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_FP64, TP_FP32):
	uRet = ((_uCdxdf)(pFn))(_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT64, TP_FP64, TP_FP64):
	uRet = ((_uCdxdd)(pFn))(_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_INT32, TP_INT32):
	uRet = ((_uCdfuu)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_INT32, TP_INT64):
	uRet = ((_uCdfux)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_INT32, TP_FP32):
	uRet = ((_uCdfuf)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_INT32, TP_FP64):
	uRet = ((_uCdfud)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_INT64, TP_INT32):
	uRet = ((_uCdfxu)(pFn))(_argsd[0], (float)_argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_INT64, TP_INT64):
	uRet = ((_uCdfxx)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_INT64, TP_FP32):
	uRet = ((_uCdfxf)(pFn))(_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_INT64, TP_FP64):
	uRet = ((_uCdfxd)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP32, TP_INT32):
	uRet = ((_uCdffu)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP32, TP_INT64):
	uRet = ((_uCdffx)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP32, TP_FP32):
	uRet = ((_uCdfff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP32, TP_FP64):
	uRet = ((_uCdffd)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP64, TP_INT32):
	uRet = ((_uCdfdu)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP64, TP_INT64):
	uRet = ((_uCdfdx)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP64, TP_FP32):
	uRet = ((_uCdfdf)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP64, TP_FP64):
	uRet = ((_uCdfdd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_INT32, TP_INT32):
	uRet = ((_uCdduu)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_INT32, TP_INT64):
	uRet = ((_uCddux)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_INT32, TP_FP32):
	uRet = ((_uCdduf)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_INT32, TP_FP64):
	uRet = ((_uCddud)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_INT64, TP_INT32):
	uRet = ((_uCddxu)(pFn))(_argsd[0], _argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_INT64, TP_INT64):
	uRet = ((_uCddxx)(pFn))(_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_INT64, TP_FP32):
	uRet = ((_uCddxf)(pFn))(_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_INT64, TP_FP64):
	uRet = ((_uCddxd)(pFn))(_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP32, TP_INT32):
	uRet = ((_uCddfu)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP32, TP_INT64):
	uRet = ((_uCddfx)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP32, TP_FP32):
	uRet = ((_uCddff)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP32, TP_FP64):
	uRet = ((_uCddfd)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP64, TP_INT32):
	uRet = ((_uCdddu)(pFn))(_argsd[0], _argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP64, TP_INT64):
	uRet = ((_uCdddx)(pFn))(_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP64, TP_FP32):
	uRet = ((_uCdddf)(pFn))(_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP64, TP_FP64):
	uRet = ((_uCdddd)(pFn))(_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
	xRet = ((_xCuuuu)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_INT32, TP_INT64):
	xRet = ((_xCuuux)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_INT32, TP_FP32):
	xRet = ((_xCuuuf)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_INT32, TP_FP64):
	xRet = ((_xCuuud)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_INT64, TP_INT32):
	xRet = ((_xCuuxu)(pFn))((U32)_args[0], (U32)_args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_INT64, TP_INT64):
	xRet = ((_xCuuxx)(pFn))((U32)_args[0], (U32)_args[1], _args[2], _args[3]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_INT64, TP_FP32):
	xRet = ((_xCuuxf)(pFn))((U32)_args[0], (U32)_args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_INT64, TP_FP64):
	xRet = ((_xCuuxd)(pFn))((U32)_args[0], (U32)_args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_FP32, TP_INT32):
	xRet = ((_xCuufu)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_FP32, TP_INT64):
	xRet = ((_xCuufx)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_FP32, TP_FP32):
	xRet = ((_xCuuff)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_FP32, TP_FP64):
	xRet = ((_xCuufd)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_FP64, TP_INT32):
	xRet = ((_xCuudu)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_FP64, TP_INT64):
	xRet = ((_xCuudx)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_FP64, TP_FP32):
	xRet = ((_xCuudf)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT32, TP_FP64, TP_FP64):
	xRet = ((_xCuudd)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_INT32, TP_INT32):
	xRet = ((_xCuxuu)(pFn))((U32)_args[0], _args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_INT32, TP_INT64):
	xRet = ((_xCuxux)(pFn))((U32)_args[0], _args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_INT32, TP_FP32):
	xRet = ((_xCuxuf)(pFn))((U32)_args[0], _args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_INT32, TP_FP64):
	xRet = ((_xCuxud)(pFn))((U32)_args[0], _args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_INT64, TP_INT32):
	xRet = ((_xCuxxu)(pFn))((U32)_args[0], _args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_INT64, TP_INT64):
	xRet = ((_xCuxxx)(pFn))((U32)_args[0], _args[1], _args[2], _args[3]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_INT64, TP_FP32):
	xRet = ((_xCuxxf)(pFn))((U32)_args[0], _args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_INT64, TP_FP64):
	xRet = ((_xCuxxd)(pFn))((U32)_args[0], _args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_FP32, TP_INT32):
	xRet = ((_xCuxfu)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_FP32, TP_INT64):
	xRet = ((_xCuxfx)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_FP32, TP_FP32):
	xRet = ((_xCuxff)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_FP32, TP_FP64):
	xRet = ((_xCuxfd)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_FP64, TP_INT32):
	xRet = ((_xCuxdu)(pFn))((U32)_args[0], _args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_FP64, TP_INT64):
	xRet = ((_xCuxdx)(pFn))((U32)_args[0], _args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_FP64, TP_FP32):
	xRet = ((_xCuxdf)(pFn))((U32)_args[0], _args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_INT64, TP_FP64, TP_FP64):
	xRet = ((_xCuxdd)(pFn))((U32)_args[0], _args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_INT32, TP_INT32):
	xRet = ((_xCufuu)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_INT32, TP_INT64):
	xRet = ((_xCufux)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_INT32, TP_FP32):
	xRet = ((_xCufuf)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_INT32, TP_FP64):
	xRet = ((_xCufud)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_INT64, TP_INT32):
	xRet = ((_xCufxu)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_INT64, TP_INT64):
	xRet = ((_xCufxx)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_INT64, TP_FP32):
	xRet = ((_xCufxf)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_INT64, TP_FP64):
	xRet = ((_xCufxd)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_FP32, TP_INT32):
	xRet = ((_xCuffu)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_FP32, TP_INT64):
	xRet = ((_xCuffx)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_FP32, TP_FP32):
	xRet = ((_xCufff)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_FP32, TP_FP64):
	xRet = ((_xCuffd)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_FP64, TP_INT32):
	xRet = ((_xCufdu)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_FP64, TP_INT64):
	xRet = ((_xCufdx)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_FP64, TP_FP32):
	xRet = ((_xCufdf)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP32, TP_FP64, TP_FP64):
	xRet = ((_xCufdd)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_INT32, TP_INT32):
	xRet = ((_xCuduu)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_INT32, TP_INT64):
	xRet = ((_xCudux)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_INT32, TP_FP32):
	xRet = ((_xCuduf)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_INT32, TP_FP64):
	xRet = ((_xCudud)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_INT64, TP_INT32):
	xRet = ((_xCudxu)(pFn))((U32)_args[0], _argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_INT64, TP_INT64):
	xRet = ((_xCudxx)(pFn))((U32)_args[0], _argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_INT64, TP_FP32):
	xRet = ((_xCudxf)(pFn))((U32)_args[0], _argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_INT64, TP_FP64):
	xRet = ((_xCudxd)(pFn))((U32)_args[0], _argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_FP32, TP_INT32):
	xRet = ((_xCudfu)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_FP32, TP_INT64):
	xRet = ((_xCudfx)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_FP32, TP_FP32):
	xRet = ((_xCudff)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_FP32, TP_FP64):
	xRet = ((_xCudfd)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_FP64, TP_INT32):
	xRet = ((_xCuddu)(pFn))((U32)_args[0], _argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_FP64, TP_INT64):
	xRet = ((_xCuddx)(pFn))((U32)_args[0], _argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_FP64, TP_FP32):
	xRet = ((_xCuddf)(pFn))((U32)_args[0], _argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT32, TP_FP64, TP_FP64, TP_FP64):
	xRet = ((_xCuddd)(pFn))((U32)_args[0], _argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_INT32, TP_INT32):
	xRet = ((_xCxuuu)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_INT32, TP_INT64):
	xRet = ((_xCxuux)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_INT32, TP_FP32):
	xRet = ((_xCxuuf)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_INT32, TP_FP64):
	xRet = ((_xCxuud)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_INT64, TP_INT32):
	xRet = ((_xCxuxu)(pFn))(_args[0], (U32)_args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_INT64, TP_INT64):
	xRet = ((_xCxuxx)(pFn))(_args[0], (U32)_args[1], _args[2], _args[3]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_INT64, TP_FP32):
	xRet = ((_xCxuxf)(pFn))(_args[0], (U32)_args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_INT64, TP_FP64):
	xRet = ((_xCxuxd)(pFn))(_args[0], (U32)_args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_FP32, TP_INT32):
	xRet = ((_xCxufu)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_FP32, TP_INT64):
	xRet = ((_xCxufx)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_FP32, TP_FP32):
	xRet = ((_xCxuff)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_FP32, TP_FP64):
	xRet = ((_xCxufd)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_FP64, TP_INT32):
	xRet = ((_xCxudu)(pFn))(_args[0], (U32)_args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_FP64, TP_INT64):
	xRet = ((_xCxudx)(pFn))(_args[0], (U32)_args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_FP64, TP_FP32):
	xRet = ((_xCxudf)(pFn))(_args[0], (U32)_args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT32, TP_FP64, TP_FP64):
	xRet = ((_xCxudd)(pFn))(_args[0], (U32)_args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_INT32, TP_INT32):
	xRet = ((_xCxxuu)(pFn))(_args[0], _args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_INT32, TP_INT64):
	xRet = ((_xCxxux)(pFn))(_args[0], _args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_INT32, TP_FP32):
	xRet = ((_xCxxuf)(pFn))(_args[0], _args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_INT32, TP_FP64):
	xRet = ((_xCxxud)(pFn))(_args[0], _args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_INT64, TP_INT32):
	xRet = ((_xCxxxu)(pFn))(_args[0], _args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_INT64, TP_INT64):
	xRet = ((_xCxxxx)(pFn))(_args[0], _args[1], _args[2], _args[3]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_INT64, TP_FP32):
	xRet = ((_xCxxxf)(pFn))(_args[0], _args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_INT64, TP_FP64):
	xRet = ((_xCxxxd)(pFn))(_args[0], _args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_FP32, TP_INT32):
	xRet = ((_xCxxfu)(pFn))(_args[0], _args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_FP32, TP_INT64):
	xRet = ((_xCxxfx)(pFn))(_args[0], _args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_FP32, TP_FP32):
	xRet = ((_xCxxff)(pFn))(_args[0], _args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_FP32, TP_FP64):
	xRet = ((_xCxxfd)(pFn))(_args[0], _args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_FP64, TP_INT32):
	xRet = ((_xCxxdu)(pFn))(_args[0], _args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_FP64, TP_INT64):
	xRet = ((_xCxxdx)(pFn))(_args[0], _args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_FP64, TP_FP32):
	xRet = ((_xCxxdf)(pFn))(_args[0], _args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_INT64, TP_FP64, TP_FP64):
	xRet = ((_xCxxdd)(pFn))(_args[0], _args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_INT32, TP_INT32):
	xRet = ((_xCxfuu)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_INT32, TP_INT64):
	xRet = ((_xCxfux)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_INT32, TP_FP32):
	xRet = ((_xCxfuf)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_INT32, TP_FP64):
	xRet = ((_xCxfud)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_INT64, TP_INT32):
	xRet = ((_xCxfxu)(pFn))(_args[0], (float)_argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_INT64, TP_INT64):
	xRet = ((_xCxfxx)(pFn))(_args[0], (float)_argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_INT64, TP_FP32):
	xRet = ((_xCxfxf)(pFn))(_args[0], (float)_argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_INT64, TP_FP64):
	xRet = ((_xCxfxd)(pFn))(_args[0], (float)_argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_FP32, TP_INT32):
	xRet = ((_xCxffu)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_FP32, TP_INT64):
	xRet = ((_xCxffx)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_FP32, TP_FP32):
	xRet = ((_xCxfff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_FP32, TP_FP64):
	xRet = ((_xCxffd)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_FP64, TP_INT32):
	xRet = ((_xCxfdu)(pFn))(_args[0], (float)_argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_FP64, TP_INT64):
	xRet = ((_xCxfdx)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_FP64, TP_FP32):
	xRet = ((_xCxfdf)(pFn))(_args[0], (float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP32, TP_FP64, TP_FP64):
	xRet = ((_xCxfdd)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_INT32, TP_INT32):
	xRet = ((_xCxduu)(pFn))(_args[0], _argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_INT32, TP_INT64):
	xRet = ((_xCxdux)(pFn))(_args[0], _argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_INT32, TP_FP32):
	xRet = ((_xCxduf)(pFn))(_args[0], _argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_INT32, TP_FP64):
	xRet = ((_xCxdud)(pFn))(_args[0], _argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_INT64, TP_INT32):
	xRet = ((_xCxdxu)(pFn))(_args[0], _argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_INT64, TP_INT64):
	xRet = ((_xCxdxx)(pFn))(_args[0], _argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_INT64, TP_FP32):
	xRet = ((_xCxdxf)(pFn))(_args[0], _argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_INT64, TP_FP64):
	xRet = ((_xCxdxd)(pFn))(_args[0], _argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_FP32, TP_INT32):
	xRet = ((_xCxdfu)(pFn))(_args[0], _argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_FP32, TP_INT64):
	xRet = ((_xCxdfx)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_FP32, TP_FP32):
	xRet = ((_xCxdff)(pFn))(_args[0], _argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_FP32, TP_FP64):
	xRet = ((_xCxdfd)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_FP64, TP_INT32):
	xRet = ((_xCxddu)(pFn))(_args[0], _argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_FP64, TP_INT64):
	xRet = ((_xCxddx)(pFn))(_args[0], _argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_FP64, TP_FP32):
	xRet = ((_xCxddf)(pFn))(_args[0], _argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_INT64, TP_FP64, TP_FP64, TP_FP64):
	xRet = ((_xCxddd)(pFn))(_args[0], _argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_INT32, TP_INT32):
	xRet = ((_xCfuuu)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_INT32, TP_INT64):
	xRet = ((_xCfuux)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_INT32, TP_FP32):
	xRet = ((_xCfuuf)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_INT32, TP_FP64):
	xRet = ((_xCfuud)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_INT64, TP_INT32):
	xRet = ((_xCfuxu)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_INT64, TP_INT64):
	xRet = ((_xCfuxx)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_INT64, TP_FP32):
	xRet = ((_xCfuxf)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_INT64, TP_FP64):
	xRet = ((_xCfuxd)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_FP32, TP_INT32):
	xRet = ((_xCfufu)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_FP32, TP_INT64):
	xRet = ((_xCfufx)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_FP32, TP_FP32):
	xRet = ((_xCfuff)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_FP32, TP_FP64):
	xRet = ((_xCfufd)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_FP64, TP_INT32):
	xRet = ((_xCfudu)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_FP64, TP_INT64):
	xRet = ((_xCfudx)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_FP64, TP_FP32):
	xRet = ((_xCfudf)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT32, TP_FP64, TP_FP64):
	xRet = ((_xCfudd)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_INT32, TP_INT32):
	xRet = ((_xCfxuu)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_INT32, TP_INT64):
	xRet = ((_xCfxux)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_INT32, TP_FP32):
	xRet = ((_xCfxuf)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_INT32, TP_FP64):
	xRet = ((_xCfxud)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_INT64, TP_INT32):
	xRet = ((_xCfxxu)(pFn))((float)_argsd[0], _args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_INT64, TP_INT64):
	xRet = ((_xCfxxx)(pFn))((float)_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_INT64, TP_FP32):
	xRet = ((_xCfxxf)(pFn))((float)_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_INT64, TP_FP64):
	xRet = ((_xCfxxd)(pFn))((float)_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_FP32, TP_INT32):
	xRet = ((_xCfxfu)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_FP32, TP_INT64):
	xRet = ((_xCfxfx)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_FP32, TP_FP32):
	xRet = ((_xCfxff)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_FP32, TP_FP64):
	xRet = ((_xCfxfd)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_FP64, TP_INT32):
	xRet = ((_xCfxdu)(pFn))((float)_argsd[0], _args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_FP64, TP_INT64):
	xRet = ((_xCfxdx)(pFn))((float)_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_FP64, TP_FP32):
	xRet = ((_xCfxdf)(pFn))((float)_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_INT64, TP_FP64, TP_FP64):
	xRet = ((_xCfxdd)(pFn))((float)_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_INT32, TP_INT32):
	xRet = ((_xCffuu)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_INT32, TP_INT64):
	xRet = ((_xCffux)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_INT32, TP_FP32):
	xRet = ((_xCffuf)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_INT32, TP_FP64):
	xRet = ((_xCffud)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_INT64, TP_INT32):
	xRet = ((_xCffxu)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_INT64, TP_INT64):
	xRet = ((_xCffxx)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_INT64, TP_FP32):
	xRet = ((_xCffxf)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_INT64, TP_FP64):
	xRet = ((_xCffxd)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_FP32, TP_INT32):
	xRet = ((_xCfffu)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_FP32, TP_INT64):
	xRet = ((_xCfffx)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_FP32, TP_FP32):
	xRet = ((_xCffff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_FP32, TP_FP64):
	xRet = ((_xCfffd)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_FP64, TP_INT32):
	xRet = ((_xCffdu)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_FP64, TP_INT64):
	xRet = ((_xCffdx)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_FP64, TP_FP32):
	xRet = ((_xCffdf)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP32, TP_FP64, TP_FP64):
	xRet = ((_xCffdd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_INT32, TP_INT32):
	xRet = ((_xCfduu)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_INT32, TP_INT64):
	xRet = ((_xCfdux)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_INT32, TP_FP32):
	xRet = ((_xCfduf)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_INT32, TP_FP64):
	xRet = ((_xCfdud)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_INT64, TP_INT32):
	xRet = ((_xCfdxu)(pFn))((float)_argsd[0], _argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_INT64, TP_INT64):
	xRet = ((_xCfdxx)(pFn))((float)_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_INT64, TP_FP32):
	xRet = ((_xCfdxf)(pFn))((float)_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_INT64, TP_FP64):
	xRet = ((_xCfdxd)(pFn))((float)_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_FP32, TP_INT32):
	xRet = ((_xCfdfu)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_FP32, TP_INT64):
	xRet = ((_xCfdfx)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_FP32, TP_FP32):
	xRet = ((_xCfdff)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_FP32, TP_FP64):
	xRet = ((_xCfdfd)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_FP64, TP_INT32):
	xRet = ((_xCfddu)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_FP64, TP_INT64):
	xRet = ((_xCfddx)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_FP64, TP_FP32):
	xRet = ((_xCfddf)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP32, TP_FP64, TP_FP64, TP_FP64):
	xRet = ((_xCfddd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_INT32, TP_INT32):
	xRet = ((_xCduuu)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_INT32, TP_INT64):
	xRet = ((_xCduux)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_INT32, TP_FP32):
	xRet = ((_xCduuf)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_INT32, TP_FP64):
	xRet = ((_xCduud)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_INT64, TP_INT32):
	xRet = ((_xCduxu)(pFn))(_argsd[0], (U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_INT64, TP_INT64):
	xRet = ((_xCduxx)(pFn))(_argsd[0], (U32)_args[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_INT64, TP_FP32):
	xRet = ((_xCduxf)(pFn))(_argsd[0], (U32)_args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_INT64, TP_FP64):
	xRet = ((_xCduxd)(pFn))(_argsd[0], (U32)_args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_FP32, TP_INT32):
	xRet = ((_xCdufu)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_FP32, TP_INT64):
	xRet = ((_xCdufx)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_FP32, TP_FP32):
	xRet = ((_xCduff)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_FP32, TP_FP64):
	xRet = ((_xCdufd)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_FP64, TP_INT32):
	xRet = ((_xCdudu)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_FP64, TP_INT64):
	xRet = ((_xCdudx)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_FP64, TP_FP32):
	xRet = ((_xCdudf)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT32, TP_FP64, TP_FP64):
	xRet = ((_xCdudd)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_INT32, TP_INT32):
	xRet = ((_xCdxuu)(pFn))(_argsd[0], _args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_INT32, TP_INT64):
	xRet = ((_xCdxux)(pFn))(_argsd[0], _args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_INT32, TP_FP32):
	xRet = ((_xCdxuf)(pFn))(_argsd[0], _args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_INT32, TP_FP64):
	xRet = ((_xCdxud)(pFn))(_argsd[0], _args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_INT64, TP_INT32):
	xRet = ((_xCdxxu)(pFn))(_argsd[0], _args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_INT64, TP_INT64):
	xRet = ((_xCdxxx)(pFn))(_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_INT64, TP_FP32):
	xRet = ((_xCdxxf)(pFn))(_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_INT64, TP_FP64):
	xRet = ((_xCdxxd)(pFn))(_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_FP32, TP_INT32):
	xRet = ((_xCdxfu)(pFn))(_argsd[0], _args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_FP32, TP_INT64):
	xRet = ((_xCdxfx)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_FP32, TP_FP32):
	xRet = ((_xCdxff)(pFn))(_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_FP32, TP_FP64):
	xRet = ((_xCdxfd)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_FP64, TP_INT32):
	xRet = ((_xCdxdu)(pFn))(_argsd[0], _args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_FP64, TP_INT64):
	xRet = ((_xCdxdx)(pFn))(_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_FP64, TP_FP32):
	xRet = ((_xCdxdf)(pFn))(_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_INT64, TP_FP64, TP_FP64):
	xRet = ((_xCdxdd)(pFn))(_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_INT32, TP_INT32):
	xRet = ((_xCdfuu)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_INT32, TP_INT64):
	xRet = ((_xCdfux)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_INT32, TP_FP32):
	xRet = ((_xCdfuf)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_INT32, TP_FP64):
	xRet = ((_xCdfud)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_INT64, TP_INT32):
	xRet = ((_xCdfxu)(pFn))(_argsd[0], (float)_argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_INT64, TP_INT64):
	xRet = ((_xCdfxx)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_INT64, TP_FP32):
	xRet = ((_xCdfxf)(pFn))(_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_INT64, TP_FP64):
	xRet = ((_xCdfxd)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_FP32, TP_INT32):
	xRet = ((_xCdffu)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_FP32, TP_INT64):
	xRet = ((_xCdffx)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_FP32, TP_FP32):
	xRet = ((_xCdfff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_FP32, TP_FP64):
	xRet = ((_xCdffd)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_FP64, TP_INT32):
	xRet = ((_xCdfdu)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_FP64, TP_INT64):
	xRet = ((_xCdfdx)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_FP64, TP_FP32):
	xRet = ((_xCdfdf)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP32, TP_FP64, TP_FP64):
	xRet = ((_xCdfdd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_INT32, TP_INT32):
	xRet = ((_xCdduu)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_INT32, TP_INT64):
	xRet = ((_xCddux)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_INT32, TP_FP32):
	xRet = ((_xCdduf)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_INT32, TP_FP64):
	xRet = ((_xCddud)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_INT64, TP_INT32):
	xRet = ((_xCddxu)(pFn))(_argsd[0], _argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_INT64, TP_INT64):
	xRet = ((_xCddxx)(pFn))(_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_INT64, TP_FP32):
	xRet = ((_xCddxf)(pFn))(_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_INT64, TP_FP64):
	xRet = ((_xCddxd)(pFn))(_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_FP32, TP_INT32):
	xRet = ((_xCddfu)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_FP32, TP_INT64):
	xRet = ((_xCddfx)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_FP32, TP_FP32):
	xRet = ((_xCddff)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_FP32, TP_FP64):
	xRet = ((_xCddfd)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_FP64, TP_INT32):
	xRet = ((_xCdddu)(pFn))(_argsd[0], _argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_FP64, TP_INT64):
	xRet = ((_xCdddx)(pFn))(_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_FP64, TP_FP32):
	xRet = ((_xCdddf)(pFn))(_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT64, TP_FP64, TP_FP64, TP_FP64, TP_FP64):
	xRet = ((_xCdddd)(pFn))(_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
	fRet = ((_fCuuuu)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_INT32, TP_INT64):
	fRet = ((_fCuuux)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_INT32, TP_FP32):
	fRet = ((_fCuuuf)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_INT32, TP_FP64):
	fRet = ((_fCuuud)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_INT64, TP_INT32):
	fRet = ((_fCuuxu)(pFn))((U32)_args[0], (U32)_args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_INT64, TP_INT64):
	fRet = ((_fCuuxx)(pFn))((U32)_args[0], (U32)_args[1], _args[2], _args[3]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_INT64, TP_FP32):
	fRet = ((_fCuuxf)(pFn))((U32)_args[0], (U32)_args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_INT64, TP_FP64):
	fRet = ((_fCuuxd)(pFn))((U32)_args[0], (U32)_args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP32, TP_INT32):
	fRet = ((_fCuufu)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP32, TP_INT64):
	fRet = ((_fCuufx)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP32, TP_FP32):
	fRet = ((_fCuuff)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP32, TP_FP64):
	fRet = ((_fCuufd)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP64, TP_INT32):
	fRet = ((_fCuudu)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP64, TP_INT64):
	fRet = ((_fCuudx)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP64, TP_FP32):
	fRet = ((_fCuudf)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP64, TP_FP64):
	fRet = ((_fCuudd)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_INT32, TP_INT32):
	fRet = ((_fCuxuu)(pFn))((U32)_args[0], _args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_INT32, TP_INT64):
	fRet = ((_fCuxux)(pFn))((U32)_args[0], _args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_INT32, TP_FP32):
	fRet = ((_fCuxuf)(pFn))((U32)_args[0], _args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_INT32, TP_FP64):
	fRet = ((_fCuxud)(pFn))((U32)_args[0], _args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_INT64, TP_INT32):
	fRet = ((_fCuxxu)(pFn))((U32)_args[0], _args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_INT64, TP_INT64):
	fRet = ((_fCuxxx)(pFn))((U32)_args[0], _args[1], _args[2], _args[3]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_INT64, TP_FP32):
	fRet = ((_fCuxxf)(pFn))((U32)_args[0], _args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_INT64, TP_FP64):
	fRet = ((_fCuxxd)(pFn))((U32)_args[0], _args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_FP32, TP_INT32):
	fRet = ((_fCuxfu)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_FP32, TP_INT64):
	fRet = ((_fCuxfx)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_FP32, TP_FP32):
	fRet = ((_fCuxff)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_FP32, TP_FP64):
	fRet = ((_fCuxfd)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_FP64, TP_INT32):
	fRet = ((_fCuxdu)(pFn))((U32)_args[0], _args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_FP64, TP_INT64):
	fRet = ((_fCuxdx)(pFn))((U32)_args[0], _args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_FP64, TP_FP32):
	fRet = ((_fCuxdf)(pFn))((U32)_args[0], _args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT64, TP_FP64, TP_FP64):
	fRet = ((_fCuxdd)(pFn))((U32)_args[0], _args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_INT32, TP_INT32):
	fRet = ((_fCufuu)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_INT32, TP_INT64):
	fRet = ((_fCufux)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_INT32, TP_FP32):
	fRet = ((_fCufuf)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_INT32, TP_FP64):
	fRet = ((_fCufud)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_INT64, TP_INT32):
	fRet = ((_fCufxu)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_INT64, TP_INT64):
	fRet = ((_fCufxx)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_INT64, TP_FP32):
	fRet = ((_fCufxf)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_INT64, TP_FP64):
	fRet = ((_fCufxd)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP32, TP_INT32):
	fRet = ((_fCuffu)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP32, TP_INT64):
	fRet = ((_fCuffx)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP32, TP_FP32):
	fRet = ((_fCufff)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP32, TP_FP64):
	fRet = ((_fCuffd)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP64, TP_INT32):
	fRet = ((_fCufdu)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP64, TP_INT64):
	fRet = ((_fCufdx)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP64, TP_FP32):
	fRet = ((_fCufdf)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP64, TP_FP64):
	fRet = ((_fCufdd)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_INT32, TP_INT32):
	fRet = ((_fCuduu)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_INT32, TP_INT64):
	fRet = ((_fCudux)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_INT32, TP_FP32):
	fRet = ((_fCuduf)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_INT32, TP_FP64):
	fRet = ((_fCudud)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_INT64, TP_INT32):
	fRet = ((_fCudxu)(pFn))((U32)_args[0], _argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_INT64, TP_INT64):
	fRet = ((_fCudxx)(pFn))((U32)_args[0], _argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_INT64, TP_FP32):
	fRet = ((_fCudxf)(pFn))((U32)_args[0], _argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_INT64, TP_FP64):
	fRet = ((_fCudxd)(pFn))((U32)_args[0], _argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP32, TP_INT32):
	fRet = ((_fCudfu)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP32, TP_INT64):
	fRet = ((_fCudfx)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP32, TP_FP32):
	fRet = ((_fCudff)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP32, TP_FP64):
	fRet = ((_fCudfd)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP64, TP_INT32):
	fRet = ((_fCuddu)(pFn))((U32)_args[0], _argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP64, TP_INT64):
	fRet = ((_fCuddx)(pFn))((U32)_args[0], _argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP64, TP_FP32):
	fRet = ((_fCuddf)(pFn))((U32)_args[0], _argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP64, TP_FP64):
	fRet = ((_fCuddd)(pFn))((U32)_args[0], _argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_INT32, TP_INT32):
	fRet = ((_fCxuuu)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_INT32, TP_INT64):
	fRet = ((_fCxuux)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_INT32, TP_FP32):
	fRet = ((_fCxuuf)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_INT32, TP_FP64):
	fRet = ((_fCxuud)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_INT64, TP_INT32):
	fRet = ((_fCxuxu)(pFn))(_args[0], (U32)_args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_INT64, TP_INT64):
	fRet = ((_fCxuxx)(pFn))(_args[0], (U32)_args[1], _args[2], _args[3]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_INT64, TP_FP32):
	fRet = ((_fCxuxf)(pFn))(_args[0], (U32)_args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_INT64, TP_FP64):
	fRet = ((_fCxuxd)(pFn))(_args[0], (U32)_args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_FP32, TP_INT32):
	fRet = ((_fCxufu)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_FP32, TP_INT64):
	fRet = ((_fCxufx)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_FP32, TP_FP32):
	fRet = ((_fCxuff)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_FP32, TP_FP64):
	fRet = ((_fCxufd)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_FP64, TP_INT32):
	fRet = ((_fCxudu)(pFn))(_args[0], (U32)_args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_FP64, TP_INT64):
	fRet = ((_fCxudx)(pFn))(_args[0], (U32)_args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_FP64, TP_FP32):
	fRet = ((_fCxudf)(pFn))(_args[0], (U32)_args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT32, TP_FP64, TP_FP64):
	fRet = ((_fCxudd)(pFn))(_args[0], (U32)_args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_INT32, TP_INT32):
	fRet = ((_fCxxuu)(pFn))(_args[0], _args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_INT32, TP_INT64):
	fRet = ((_fCxxux)(pFn))(_args[0], _args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_INT32, TP_FP32):
	fRet = ((_fCxxuf)(pFn))(_args[0], _args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_INT32, TP_FP64):
	fRet = ((_fCxxud)(pFn))(_args[0], _args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_INT64, TP_INT32):
	fRet = ((_fCxxxu)(pFn))(_args[0], _args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_INT64, TP_INT64):
	fRet = ((_fCxxxx)(pFn))(_args[0], _args[1], _args[2], _args[3]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_INT64, TP_FP32):
	fRet = ((_fCxxxf)(pFn))(_args[0], _args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_INT64, TP_FP64):
	fRet = ((_fCxxxd)(pFn))(_args[0], _args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_FP32, TP_INT32):
	fRet = ((_fCxxfu)(pFn))(_args[0], _args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_FP32, TP_INT64):
	fRet = ((_fCxxfx)(pFn))(_args[0], _args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_FP32, TP_FP32):
	fRet = ((_fCxxff)(pFn))(_args[0], _args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_FP32, TP_FP64):
	fRet = ((_fCxxfd)(pFn))(_args[0], _args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_FP64, TP_INT32):
	fRet = ((_fCxxdu)(pFn))(_args[0], _args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_FP64, TP_INT64):
	fRet = ((_fCxxdx)(pFn))(_args[0], _args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_FP64, TP_FP32):
	fRet = ((_fCxxdf)(pFn))(_args[0], _args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_INT64, TP_FP64, TP_FP64):
	fRet = ((_fCxxdd)(pFn))(_args[0], _args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_INT32, TP_INT32):
	fRet = ((_fCxfuu)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_INT32, TP_INT64):
	fRet = ((_fCxfux)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_INT32, TP_FP32):
	fRet = ((_fCxfuf)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_INT32, TP_FP64):
	fRet = ((_fCxfud)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_INT64, TP_INT32):
	fRet = ((_fCxfxu)(pFn))(_args[0], (float)_argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_INT64, TP_INT64):
	fRet = ((_fCxfxx)(pFn))(_args[0], (float)_argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_INT64, TP_FP32):
	fRet = ((_fCxfxf)(pFn))(_args[0], (float)_argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_INT64, TP_FP64):
	fRet = ((_fCxfxd)(pFn))(_args[0], (float)_argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_FP32, TP_INT32):
	fRet = ((_fCxffu)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_FP32, TP_INT64):
	fRet = ((_fCxffx)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_FP32, TP_FP32):
	fRet = ((_fCxfff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_FP32, TP_FP64):
	fRet = ((_fCxffd)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_FP64, TP_INT32):
	fRet = ((_fCxfdu)(pFn))(_args[0], (float)_argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_FP64, TP_INT64):
	fRet = ((_fCxfdx)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_FP64, TP_FP32):
	fRet = ((_fCxfdf)(pFn))(_args[0], (float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP32, TP_FP64, TP_FP64):
	fRet = ((_fCxfdd)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_INT32, TP_INT32):
	fRet = ((_fCxduu)(pFn))(_args[0], _argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_INT32, TP_INT64):
	fRet = ((_fCxdux)(pFn))(_args[0], _argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_INT32, TP_FP32):
	fRet = ((_fCxduf)(pFn))(_args[0], _argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_INT32, TP_FP64):
	fRet = ((_fCxdud)(pFn))(_args[0], _argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_INT64, TP_INT32):
	fRet = ((_fCxdxu)(pFn))(_args[0], _argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_INT64, TP_INT64):
	fRet = ((_fCxdxx)(pFn))(_args[0], _argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_INT64, TP_FP32):
	fRet = ((_fCxdxf)(pFn))(_args[0], _argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_INT64, TP_FP64):
	fRet = ((_fCxdxd)(pFn))(_args[0], _argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_FP32, TP_INT32):
	fRet = ((_fCxdfu)(pFn))(_args[0], _argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_FP32, TP_INT64):
	fRet = ((_fCxdfx)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_FP32, TP_FP32):
	fRet = ((_fCxdff)(pFn))(_args[0], _argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_FP32, TP_FP64):
	fRet = ((_fCxdfd)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_FP64, TP_INT32):
	fRet = ((_fCxddu)(pFn))(_args[0], _argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_FP64, TP_INT64):
	fRet = ((_fCxddx)(pFn))(_args[0], _argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_FP64, TP_FP32):
	fRet = ((_fCxddf)(pFn))(_args[0], _argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT64, TP_FP64, TP_FP64, TP_FP64):
	fRet = ((_fCxddd)(pFn))(_args[0], _argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_INT32, TP_INT32):
	fRet = ((_fCfuuu)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_INT32, TP_INT64):
	fRet = ((_fCfuux)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_INT32, TP_FP32):
	fRet = ((_fCfuuf)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_INT32, TP_FP64):
	fRet = ((_fCfuud)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_INT64, TP_INT32):
	fRet = ((_fCfuxu)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_INT64, TP_INT64):
	fRet = ((_fCfuxx)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_INT64, TP_FP32):
	fRet = ((_fCfuxf)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_INT64, TP_FP64):
	fRet = ((_fCfuxd)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP32, TP_INT32):
	fRet = ((_fCfufu)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP32, TP_INT64):
	fRet = ((_fCfufx)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP32, TP_FP32):
	fRet = ((_fCfuff)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP32, TP_FP64):
	fRet = ((_fCfufd)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP64, TP_INT32):
	fRet = ((_fCfudu)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP64, TP_INT64):
	fRet = ((_fCfudx)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP64, TP_FP32):
	fRet = ((_fCfudf)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP64, TP_FP64):
	fRet = ((_fCfudd)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_INT32, TP_INT32):
	fRet = ((_fCfxuu)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_INT32, TP_INT64):
	fRet = ((_fCfxux)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_INT32, TP_FP32):
	fRet = ((_fCfxuf)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_INT32, TP_FP64):
	fRet = ((_fCfxud)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_INT64, TP_INT32):
	fRet = ((_fCfxxu)(pFn))((float)_argsd[0], _args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_INT64, TP_INT64):
	fRet = ((_fCfxxx)(pFn))((float)_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_INT64, TP_FP32):
	fRet = ((_fCfxxf)(pFn))((float)_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_INT64, TP_FP64):
	fRet = ((_fCfxxd)(pFn))((float)_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_FP32, TP_INT32):
	fRet = ((_fCfxfu)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_FP32, TP_INT64):
	fRet = ((_fCfxfx)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_FP32, TP_FP32):
	fRet = ((_fCfxff)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_FP32, TP_FP64):
	fRet = ((_fCfxfd)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_FP64, TP_INT32):
	fRet = ((_fCfxdu)(pFn))((float)_argsd[0], _args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_FP64, TP_INT64):
	fRet = ((_fCfxdx)(pFn))((float)_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_FP64, TP_FP32):
	fRet = ((_fCfxdf)(pFn))((float)_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT64, TP_FP64, TP_FP64):
	fRet = ((_fCfxdd)(pFn))((float)_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_INT32, TP_INT32):
	fRet = ((_fCffuu)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_INT32, TP_INT64):
	fRet = ((_fCffux)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_INT32, TP_FP32):
	fRet = ((_fCffuf)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_INT32, TP_FP64):
	fRet = ((_fCffud)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_INT64, TP_INT32):
	fRet = ((_fCffxu)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_INT64, TP_INT64):
	fRet = ((_fCffxx)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_INT64, TP_FP32):
	fRet = ((_fCffxf)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_INT64, TP_FP64):
	fRet = ((_fCffxd)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP32, TP_INT32):
	fRet = ((_fCfffu)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP32, TP_INT64):
	fRet = ((_fCfffx)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP32, TP_FP32):
	fRet = ((_fCffff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP32, TP_FP64):
	fRet = ((_fCfffd)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP64, TP_INT32):
	fRet = ((_fCffdu)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP64, TP_INT64):
	fRet = ((_fCffdx)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP64, TP_FP32):
	fRet = ((_fCffdf)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP64, TP_FP64):
	fRet = ((_fCffdd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_INT32, TP_INT32):
	fRet = ((_fCfduu)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_INT32, TP_INT64):
	fRet = ((_fCfdux)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_INT32, TP_FP32):
	fRet = ((_fCfduf)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_INT32, TP_FP64):
	fRet = ((_fCfdud)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_INT64, TP_INT32):
	fRet = ((_fCfdxu)(pFn))((float)_argsd[0], _argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_INT64, TP_INT64):
	fRet = ((_fCfdxx)(pFn))((float)_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_INT64, TP_FP32):
	fRet = ((_fCfdxf)(pFn))((float)_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_INT64, TP_FP64):
	fRet = ((_fCfdxd)(pFn))((float)_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP32, TP_INT32):
	fRet = ((_fCfdfu)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP32, TP_INT64):
	fRet = ((_fCfdfx)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP32, TP_FP32):
	fRet = ((_fCfdff)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP32, TP_FP64):
	fRet = ((_fCfdfd)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP64, TP_INT32):
	fRet = ((_fCfddu)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP64, TP_INT64):
	fRet = ((_fCfddx)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP64, TP_FP32):
	fRet = ((_fCfddf)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP64, TP_FP64):
	fRet = ((_fCfddd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_INT32, TP_INT32):
	fRet = ((_fCduuu)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_INT32, TP_INT64):
	fRet = ((_fCduux)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_INT32, TP_FP32):
	fRet = ((_fCduuf)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_INT32, TP_FP64):
	fRet = ((_fCduud)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_INT64, TP_INT32):
	fRet = ((_fCduxu)(pFn))(_argsd[0], (U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_INT64, TP_INT64):
	fRet = ((_fCduxx)(pFn))(_argsd[0], (U32)_args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_INT64, TP_FP32):
	fRet = ((_fCduxf)(pFn))(_argsd[0], (U32)_args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_INT64, TP_FP64):
	fRet = ((_fCduxd)(pFn))(_argsd[0], (U32)_args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP32, TP_INT32):
	fRet = ((_fCdufu)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP32, TP_INT64):
	fRet = ((_fCdufx)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP32, TP_FP32):
	fRet = ((_fCduff)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP32, TP_FP64):
	fRet = ((_fCdufd)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP64, TP_INT32):
	fRet = ((_fCdudu)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP64, TP_INT64):
	fRet = ((_fCdudx)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP64, TP_FP32):
	fRet = ((_fCdudf)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP64, TP_FP64):
	fRet = ((_fCdudd)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_INT32, TP_INT32):
	fRet = ((_fCdxuu)(pFn))(_argsd[0], _args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_INT32, TP_INT64):
	fRet = ((_fCdxux)(pFn))(_argsd[0], _args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_INT32, TP_FP32):
	fRet = ((_fCdxuf)(pFn))(_argsd[0], _args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_INT32, TP_FP64):
	fRet = ((_fCdxud)(pFn))(_argsd[0], _args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_INT64, TP_INT32):
	fRet = ((_fCdxxu)(pFn))(_argsd[0], _args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_INT64, TP_INT64):
	fRet = ((_fCdxxx)(pFn))(_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_INT64, TP_FP32):
	fRet = ((_fCdxxf)(pFn))(_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_INT64, TP_FP64):
	fRet = ((_fCdxxd)(pFn))(_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_FP32, TP_INT32):
	fRet = ((_fCdxfu)(pFn))(_argsd[0], _args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_FP32, TP_INT64):
	fRet = ((_fCdxfx)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_FP32, TP_FP32):
	fRet = ((_fCdxff)(pFn))(_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_FP32, TP_FP64):
	fRet = ((_fCdxfd)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_FP64, TP_INT32):
	fRet = ((_fCdxdu)(pFn))(_argsd[0], _args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_FP64, TP_INT64):
	fRet = ((_fCdxdx)(pFn))(_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_FP64, TP_FP32):
	fRet = ((_fCdxdf)(pFn))(_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT64, TP_FP64, TP_FP64):
	fRet = ((_fCdxdd)(pFn))(_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_INT32, TP_INT32):
	fRet = ((_fCdfuu)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_INT32, TP_INT64):
	fRet = ((_fCdfux)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_INT32, TP_FP32):
	fRet = ((_fCdfuf)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_INT32, TP_FP64):
	fRet = ((_fCdfud)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_INT64, TP_INT32):
	fRet = ((_fCdfxu)(pFn))(_argsd[0], (float)_argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_INT64, TP_INT64):
	fRet = ((_fCdfxx)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_INT64, TP_FP32):
	fRet = ((_fCdfxf)(pFn))(_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_INT64, TP_FP64):
	fRet = ((_fCdfxd)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP32, TP_INT32):
	fRet = ((_fCdffu)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP32, TP_INT64):
	fRet = ((_fCdffx)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP32, TP_FP32):
	fRet = ((_fCdfff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP32, TP_FP64):
	fRet = ((_fCdffd)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP64, TP_INT32):
	fRet = ((_fCdfdu)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP64, TP_INT64):
	fRet = ((_fCdfdx)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP64, TP_FP32):
	fRet = ((_fCdfdf)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP64, TP_FP64):
	fRet = ((_fCdfdd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_INT32, TP_INT32):
	fRet = ((_fCdduu)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_INT32, TP_INT64):
	fRet = ((_fCddux)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_INT32, TP_FP32):
	fRet = ((_fCdduf)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_INT32, TP_FP64):
	fRet = ((_fCddud)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_INT64, TP_INT32):
	fRet = ((_fCddxu)(pFn))(_argsd[0], _argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_INT64, TP_INT64):
	fRet = ((_fCddxx)(pFn))(_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_INT64, TP_FP32):
	fRet = ((_fCddxf)(pFn))(_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_INT64, TP_FP64):
	fRet = ((_fCddxd)(pFn))(_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP32, TP_INT32):
	fRet = ((_fCddfu)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP32, TP_INT64):
	fRet = ((_fCddfx)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP32, TP_FP32):
	fRet = ((_fCddff)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP32, TP_FP64):
	fRet = ((_fCddfd)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP64, TP_INT32):
	fRet = ((_fCdddu)(pFn))(_argsd[0], _argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP64, TP_INT64):
	fRet = ((_fCdddx)(pFn))(_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP64, TP_FP32):
	fRet = ((_fCdddf)(pFn))(_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP64, TP_FP64):
	fRet = ((_fCdddd)(pFn))(_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
	dRet = ((_dCuuuu)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_INT32, TP_INT64):
	dRet = ((_dCuuux)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_INT32, TP_FP32):
	dRet = ((_dCuuuf)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_INT32, TP_FP64):
	dRet = ((_dCuuud)(pFn))((U32)_args[0], (U32)_args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_INT64, TP_INT32):
	dRet = ((_dCuuxu)(pFn))((U32)_args[0], (U32)_args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_INT64, TP_INT64):
	dRet = ((_dCuuxx)(pFn))((U32)_args[0], (U32)_args[1], _args[2], _args[3]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_INT64, TP_FP32):
	dRet = ((_dCuuxf)(pFn))((U32)_args[0], (U32)_args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_INT64, TP_FP64):
	dRet = ((_dCuuxd)(pFn))((U32)_args[0], (U32)_args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP32, TP_INT32):
	dRet = ((_dCuufu)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP32, TP_INT64):
	dRet = ((_dCuufx)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP32, TP_FP32):
	dRet = ((_dCuuff)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP32, TP_FP64):
	dRet = ((_dCuufd)(pFn))((U32)_args[0], (U32)_args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP64, TP_INT32):
	dRet = ((_dCuudu)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP64, TP_INT64):
	dRet = ((_dCuudx)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP64, TP_FP32):
	dRet = ((_dCuudf)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP64, TP_FP64):
	dRet = ((_dCuudd)(pFn))((U32)_args[0], (U32)_args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_INT32, TP_INT32):
	dRet = ((_dCuxuu)(pFn))((U32)_args[0], _args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_INT32, TP_INT64):
	dRet = ((_dCuxux)(pFn))((U32)_args[0], _args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_INT32, TP_FP32):
	dRet = ((_dCuxuf)(pFn))((U32)_args[0], _args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_INT32, TP_FP64):
	dRet = ((_dCuxud)(pFn))((U32)_args[0], _args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_INT64, TP_INT32):
	dRet = ((_dCuxxu)(pFn))((U32)_args[0], _args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_INT64, TP_INT64):
	dRet = ((_dCuxxx)(pFn))((U32)_args[0], _args[1], _args[2], _args[3]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_INT64, TP_FP32):
	dRet = ((_dCuxxf)(pFn))((U32)_args[0], _args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_INT64, TP_FP64):
	dRet = ((_dCuxxd)(pFn))((U32)_args[0], _args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_FP32, TP_INT32):
	dRet = ((_dCuxfu)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_FP32, TP_INT64):
	dRet = ((_dCuxfx)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_FP32, TP_FP32):
	dRet = ((_dCuxff)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_FP32, TP_FP64):
	dRet = ((_dCuxfd)(pFn))((U32)_args[0], _args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_FP64, TP_INT32):
	dRet = ((_dCuxdu)(pFn))((U32)_args[0], _args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_FP64, TP_INT64):
	dRet = ((_dCuxdx)(pFn))((U32)_args[0], _args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_FP64, TP_FP32):
	dRet = ((_dCuxdf)(pFn))((U32)_args[0], _args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT64, TP_FP64, TP_FP64):
	dRet = ((_dCuxdd)(pFn))((U32)_args[0], _args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_INT32, TP_INT32):
	dRet = ((_dCufuu)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_INT32, TP_INT64):
	dRet = ((_dCufux)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_INT32, TP_FP32):
	dRet = ((_dCufuf)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_INT32, TP_FP64):
	dRet = ((_dCufud)(pFn))((U32)_args[0], (float)_argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_INT64, TP_INT32):
	dRet = ((_dCufxu)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_INT64, TP_INT64):
	dRet = ((_dCufxx)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_INT64, TP_FP32):
	dRet = ((_dCufxf)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_INT64, TP_FP64):
	dRet = ((_dCufxd)(pFn))((U32)_args[0], (float)_argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP32, TP_INT32):
	dRet = ((_dCuffu)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP32, TP_INT64):
	dRet = ((_dCuffx)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP32, TP_FP32):
	dRet = ((_dCufff)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP32, TP_FP64):
	dRet = ((_dCuffd)(pFn))((U32)_args[0], (float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP64, TP_INT32):
	dRet = ((_dCufdu)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP64, TP_INT64):
	dRet = ((_dCufdx)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP64, TP_FP32):
	dRet = ((_dCufdf)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP64, TP_FP64):
	dRet = ((_dCufdd)(pFn))((U32)_args[0], (float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_INT32, TP_INT32):
	dRet = ((_dCuduu)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_INT32, TP_INT64):
	dRet = ((_dCudux)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_INT32, TP_FP32):
	dRet = ((_dCuduf)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_INT32, TP_FP64):
	dRet = ((_dCudud)(pFn))((U32)_args[0], _argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_INT64, TP_INT32):
	dRet = ((_dCudxu)(pFn))((U32)_args[0], _argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_INT64, TP_INT64):
	dRet = ((_dCudxx)(pFn))((U32)_args[0], _argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_INT64, TP_FP32):
	dRet = ((_dCudxf)(pFn))((U32)_args[0], _argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_INT64, TP_FP64):
	dRet = ((_dCudxd)(pFn))((U32)_args[0], _argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP32, TP_INT32):
	dRet = ((_dCudfu)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP32, TP_INT64):
	dRet = ((_dCudfx)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP32, TP_FP32):
	dRet = ((_dCudff)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP32, TP_FP64):
	dRet = ((_dCudfd)(pFn))((U32)_args[0], _argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP64, TP_INT32):
	dRet = ((_dCuddu)(pFn))((U32)_args[0], _argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP64, TP_INT64):
	dRet = ((_dCuddx)(pFn))((U32)_args[0], _argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP64, TP_FP32):
	dRet = ((_dCuddf)(pFn))((U32)_args[0], _argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP64, TP_FP64):
	dRet = ((_dCuddd)(pFn))((U32)_args[0], _argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_INT32, TP_INT32):
	dRet = ((_dCxuuu)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_INT32, TP_INT64):
	dRet = ((_dCxuux)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_INT32, TP_FP32):
	dRet = ((_dCxuuf)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_INT32, TP_FP64):
	dRet = ((_dCxuud)(pFn))(_args[0], (U32)_args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_INT64, TP_INT32):
	dRet = ((_dCxuxu)(pFn))(_args[0], (U32)_args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_INT64, TP_INT64):
	dRet = ((_dCxuxx)(pFn))(_args[0], (U32)_args[1], _args[2], _args[3]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_INT64, TP_FP32):
	dRet = ((_dCxuxf)(pFn))(_args[0], (U32)_args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_INT64, TP_FP64):
	dRet = ((_dCxuxd)(pFn))(_args[0], (U32)_args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_FP32, TP_INT32):
	dRet = ((_dCxufu)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_FP32, TP_INT64):
	dRet = ((_dCxufx)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_FP32, TP_FP32):
	dRet = ((_dCxuff)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_FP32, TP_FP64):
	dRet = ((_dCxufd)(pFn))(_args[0], (U32)_args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_FP64, TP_INT32):
	dRet = ((_dCxudu)(pFn))(_args[0], (U32)_args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_FP64, TP_INT64):
	dRet = ((_dCxudx)(pFn))(_args[0], (U32)_args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_FP64, TP_FP32):
	dRet = ((_dCxudf)(pFn))(_args[0], (U32)_args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT32, TP_FP64, TP_FP64):
	dRet = ((_dCxudd)(pFn))(_args[0], (U32)_args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_INT32, TP_INT32):
	dRet = ((_dCxxuu)(pFn))(_args[0], _args[1], (U32)_args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_INT32, TP_INT64):
	dRet = ((_dCxxux)(pFn))(_args[0], _args[1], (U32)_args[2], _args[3]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_INT32, TP_FP32):
	dRet = ((_dCxxuf)(pFn))(_args[0], _args[1], (U32)_args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_INT32, TP_FP64):
	dRet = ((_dCxxud)(pFn))(_args[0], _args[1], (U32)_args[2], _argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_INT64, TP_INT32):
	dRet = ((_dCxxxu)(pFn))(_args[0], _args[1], _args[2], (U32)_args[3]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_INT64, TP_INT64):
	dRet = ((_dCxxxx)(pFn))(_args[0], _args[1], _args[2], _args[3]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_INT64, TP_FP32):
	dRet = ((_dCxxxf)(pFn))(_args[0], _args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_INT64, TP_FP64):
	dRet = ((_dCxxxd)(pFn))(_args[0], _args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_FP32, TP_INT32):
	dRet = ((_dCxxfu)(pFn))(_args[0], _args[1], (float)_argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_FP32, TP_INT64):
	dRet = ((_dCxxfx)(pFn))(_args[0], _args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_FP32, TP_FP32):
	dRet = ((_dCxxff)(pFn))(_args[0], _args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_FP32, TP_FP64):
	dRet = ((_dCxxfd)(pFn))(_args[0], _args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_FP64, TP_INT32):
	dRet = ((_dCxxdu)(pFn))(_args[0], _args[1], _argsd[0], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_FP64, TP_INT64):
	dRet = ((_dCxxdx)(pFn))(_args[0], _args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_FP64, TP_FP32):
	dRet = ((_dCxxdf)(pFn))(_args[0], _args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_INT64, TP_FP64, TP_FP64):
	dRet = ((_dCxxdd)(pFn))(_args[0], _args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_INT32, TP_INT32):
	dRet = ((_dCxfuu)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_INT32, TP_INT64):
	dRet = ((_dCxfux)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_INT32, TP_FP32):
	dRet = ((_dCxfuf)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_INT32, TP_FP64):
	dRet = ((_dCxfud)(pFn))(_args[0], (float)_argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_INT64, TP_INT32):
	dRet = ((_dCxfxu)(pFn))(_args[0], (float)_argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_INT64, TP_INT64):
	dRet = ((_dCxfxx)(pFn))(_args[0], (float)_argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_INT64, TP_FP32):
	dRet = ((_dCxfxf)(pFn))(_args[0], (float)_argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_INT64, TP_FP64):
	dRet = ((_dCxfxd)(pFn))(_args[0], (float)_argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_FP32, TP_INT32):
	dRet = ((_dCxffu)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_FP32, TP_INT64):
	dRet = ((_dCxffx)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_FP32, TP_FP32):
	dRet = ((_dCxfff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_FP32, TP_FP64):
	dRet = ((_dCxffd)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_FP64, TP_INT32):
	dRet = ((_dCxfdu)(pFn))(_args[0], (float)_argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_FP64, TP_INT64):
	dRet = ((_dCxfdx)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_FP64, TP_FP32):
	dRet = ((_dCxfdf)(pFn))(_args[0], (float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP32, TP_FP64, TP_FP64):
	dRet = ((_dCxfdd)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_INT32, TP_INT32):
	dRet = ((_dCxduu)(pFn))(_args[0], _argsd[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_INT32, TP_INT64):
	dRet = ((_dCxdux)(pFn))(_args[0], _argsd[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_INT32, TP_FP32):
	dRet = ((_dCxduf)(pFn))(_args[0], _argsd[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_INT32, TP_FP64):
	dRet = ((_dCxdud)(pFn))(_args[0], _argsd[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_INT64, TP_INT32):
	dRet = ((_dCxdxu)(pFn))(_args[0], _argsd[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_INT64, TP_INT64):
	dRet = ((_dCxdxx)(pFn))(_args[0], _argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_INT64, TP_FP32):
	dRet = ((_dCxdxf)(pFn))(_args[0], _argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_INT64, TP_FP64):
	dRet = ((_dCxdxd)(pFn))(_args[0], _argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_FP32, TP_INT32):
	dRet = ((_dCxdfu)(pFn))(_args[0], _argsd[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_FP32, TP_INT64):
	dRet = ((_dCxdfx)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_FP32, TP_FP32):
	dRet = ((_dCxdff)(pFn))(_args[0], _argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_FP32, TP_FP64):
	dRet = ((_dCxdfd)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_FP64, TP_INT32):
	dRet = ((_dCxddu)(pFn))(_args[0], _argsd[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_FP64, TP_INT64):
	dRet = ((_dCxddx)(pFn))(_args[0], _argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_FP64, TP_FP32):
	dRet = ((_dCxddf)(pFn))(_args[0], _argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT64, TP_FP64, TP_FP64, TP_FP64):
	dRet = ((_dCxddd)(pFn))(_args[0], _argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_INT32, TP_INT32):
	dRet = ((_dCfuuu)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_INT32, TP_INT64):
	dRet = ((_dCfuux)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_INT32, TP_FP32):
	dRet = ((_dCfuuf)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_INT32, TP_FP64):
	dRet = ((_dCfuud)(pFn))((float)_argsd[0], (U32)_args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_INT64, TP_INT32):
	dRet = ((_dCfuxu)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_INT64, TP_INT64):
	dRet = ((_dCfuxx)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_INT64, TP_FP32):
	dRet = ((_dCfuxf)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_INT64, TP_FP64):
	dRet = ((_dCfuxd)(pFn))((float)_argsd[0], (U32)_args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP32, TP_INT32):
	dRet = ((_dCfufu)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP32, TP_INT64):
	dRet = ((_dCfufx)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP32, TP_FP32):
	dRet = ((_dCfuff)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP32, TP_FP64):
	dRet = ((_dCfufd)(pFn))((float)_argsd[0], (U32)_args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP64, TP_INT32):
	dRet = ((_dCfudu)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP64, TP_INT64):
	dRet = ((_dCfudx)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP64, TP_FP32):
	dRet = ((_dCfudf)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP64, TP_FP64):
	dRet = ((_dCfudd)(pFn))((float)_argsd[0], (U32)_args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_INT32, TP_INT32):
	dRet = ((_dCfxuu)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_INT32, TP_INT64):
	dRet = ((_dCfxux)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_INT32, TP_FP32):
	dRet = ((_dCfxuf)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_INT32, TP_FP64):
	dRet = ((_dCfxud)(pFn))((float)_argsd[0], _args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_INT64, TP_INT32):
	dRet = ((_dCfxxu)(pFn))((float)_argsd[0], _args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_INT64, TP_INT64):
	dRet = ((_dCfxxx)(pFn))((float)_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_INT64, TP_FP32):
	dRet = ((_dCfxxf)(pFn))((float)_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_INT64, TP_FP64):
	dRet = ((_dCfxxd)(pFn))((float)_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_FP32, TP_INT32):
	dRet = ((_dCfxfu)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_FP32, TP_INT64):
	dRet = ((_dCfxfx)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_FP32, TP_FP32):
	dRet = ((_dCfxff)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_FP32, TP_FP64):
	dRet = ((_dCfxfd)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_FP64, TP_INT32):
	dRet = ((_dCfxdu)(pFn))((float)_argsd[0], _args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_FP64, TP_INT64):
	dRet = ((_dCfxdx)(pFn))((float)_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_FP64, TP_FP32):
	dRet = ((_dCfxdf)(pFn))((float)_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT64, TP_FP64, TP_FP64):
	dRet = ((_dCfxdd)(pFn))((float)_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_INT32, TP_INT32):
	dRet = ((_dCffuu)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_INT32, TP_INT64):
	dRet = ((_dCffux)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_INT32, TP_FP32):
	dRet = ((_dCffuf)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_INT32, TP_FP64):
	dRet = ((_dCffud)(pFn))((float)_argsd[0], (float)_argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_INT64, TP_INT32):
	dRet = ((_dCffxu)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_INT64, TP_INT64):
	dRet = ((_dCffxx)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_INT64, TP_FP32):
	dRet = ((_dCffxf)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_INT64, TP_FP64):
	dRet = ((_dCffxd)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP32, TP_INT32):
	dRet = ((_dCfffu)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP32, TP_INT64):
	dRet = ((_dCfffx)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP32, TP_FP32):
	dRet = ((_dCffff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP32, TP_FP64):
	dRet = ((_dCfffd)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP64, TP_INT32):
	dRet = ((_dCffdu)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP64, TP_INT64):
	dRet = ((_dCffdx)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP64, TP_FP32):
	dRet = ((_dCffdf)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP64, TP_FP64):
	dRet = ((_dCffdd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_INT32, TP_INT32):
	dRet = ((_dCfduu)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_INT32, TP_INT64):
	dRet = ((_dCfdux)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_INT32, TP_FP32):
	dRet = ((_dCfduf)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_INT32, TP_FP64):
	dRet = ((_dCfdud)(pFn))((float)_argsd[0], _argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_INT64, TP_INT32):
	dRet = ((_dCfdxu)(pFn))((float)_argsd[0], _argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_INT64, TP_INT64):
	dRet = ((_dCfdxx)(pFn))((float)_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_INT64, TP_FP32):
	dRet = ((_dCfdxf)(pFn))((float)_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_INT64, TP_FP64):
	dRet = ((_dCfdxd)(pFn))((float)_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP32, TP_INT32):
	dRet = ((_dCfdfu)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP32, TP_INT64):
	dRet = ((_dCfdfx)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP32, TP_FP32):
	dRet = ((_dCfdff)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP32, TP_FP64):
	dRet = ((_dCfdfd)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP64, TP_INT32):
	dRet = ((_dCfddu)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP64, TP_INT64):
	dRet = ((_dCfddx)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP64, TP_FP32):
	dRet = ((_dCfddf)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP64, TP_FP64):
	dRet = ((_dCfddd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_INT32, TP_INT32):
	dRet = ((_dCduuu)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_INT32, TP_INT64):
	dRet = ((_dCduux)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_INT32, TP_FP32):
	dRet = ((_dCduuf)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_INT32, TP_FP64):
	dRet = ((_dCduud)(pFn))(_argsd[0], (U32)_args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_INT64, TP_INT32):
	dRet = ((_dCduxu)(pFn))(_argsd[0], (U32)_args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_INT64, TP_INT64):
	dRet = ((_dCduxx)(pFn))(_argsd[0], (U32)_args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_INT64, TP_FP32):
	dRet = ((_dCduxf)(pFn))(_argsd[0], (U32)_args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_INT64, TP_FP64):
	dRet = ((_dCduxd)(pFn))(_argsd[0], (U32)_args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP32, TP_INT32):
	dRet = ((_dCdufu)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP32, TP_INT64):
	dRet = ((_dCdufx)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP32, TP_FP32):
	dRet = ((_dCduff)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP32, TP_FP64):
	dRet = ((_dCdufd)(pFn))(_argsd[0], (U32)_args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP64, TP_INT32):
	dRet = ((_dCdudu)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP64, TP_INT64):
	dRet = ((_dCdudx)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP64, TP_FP32):
	dRet = ((_dCdudf)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP64, TP_FP64):
	dRet = ((_dCdudd)(pFn))(_argsd[0], (U32)_args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_INT32, TP_INT32):
	dRet = ((_dCdxuu)(pFn))(_argsd[0], _args[0], (U32)_args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_INT32, TP_INT64):
	dRet = ((_dCdxux)(pFn))(_argsd[0], _args[0], (U32)_args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_INT32, TP_FP32):
	dRet = ((_dCdxuf)(pFn))(_argsd[0], _args[0], (U32)_args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_INT32, TP_FP64):
	dRet = ((_dCdxud)(pFn))(_argsd[0], _args[0], (U32)_args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_INT64, TP_INT32):
	dRet = ((_dCdxxu)(pFn))(_argsd[0], _args[0], _args[1], (U32)_args[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_INT64, TP_INT64):
	dRet = ((_dCdxxx)(pFn))(_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_INT64, TP_FP32):
	dRet = ((_dCdxxf)(pFn))(_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_INT64, TP_FP64):
	dRet = ((_dCdxxd)(pFn))(_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_FP32, TP_INT32):
	dRet = ((_dCdxfu)(pFn))(_argsd[0], _args[0], (float)_argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_FP32, TP_INT64):
	dRet = ((_dCdxfx)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_FP32, TP_FP32):
	dRet = ((_dCdxff)(pFn))(_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_FP32, TP_FP64):
	dRet = ((_dCdxfd)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_FP64, TP_INT32):
	dRet = ((_dCdxdu)(pFn))(_argsd[0], _args[0], _argsd[1], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_FP64, TP_INT64):
	dRet = ((_dCdxdx)(pFn))(_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_FP64, TP_FP32):
	dRet = ((_dCdxdf)(pFn))(_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT64, TP_FP64, TP_FP64):
	dRet = ((_dCdxdd)(pFn))(_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_INT32, TP_INT32):
	dRet = ((_dCdfuu)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_INT32, TP_INT64):
	dRet = ((_dCdfux)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_INT32, TP_FP32):
	dRet = ((_dCdfuf)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_INT32, TP_FP64):
	dRet = ((_dCdfud)(pFn))(_argsd[0], (float)_argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_INT64, TP_INT32):
	dRet = ((_dCdfxu)(pFn))(_argsd[0], (float)_argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_INT64, TP_INT64):
	dRet = ((_dCdfxx)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_INT64, TP_FP32):
	dRet = ((_dCdfxf)(pFn))(_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_INT64, TP_FP64):
	dRet = ((_dCdfxd)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP32, TP_INT32):
	dRet = ((_dCdffu)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP32, TP_INT64):
	dRet = ((_dCdffx)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP32, TP_FP32):
	dRet = ((_dCdfff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP32, TP_FP64):
	dRet = ((_dCdffd)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP64, TP_INT32):
	dRet = ((_dCdfdu)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP64, TP_INT64):
	dRet = ((_dCdfdx)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP64, TP_FP32):
	dRet = ((_dCdfdf)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP64, TP_FP64):
	dRet = ((_dCdfdd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_INT32, TP_INT32):
	dRet = ((_dCdduu)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_INT32, TP_INT64):
	dRet = ((_dCddux)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_INT32, TP_FP32):
	dRet = ((_dCdduf)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_INT32, TP_FP64):
	dRet = ((_dCddud)(pFn))(_argsd[0], _argsd[1], (U32)_args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_INT64, TP_INT32):
	dRet = ((_dCddxu)(pFn))(_argsd[0], _argsd[1], _args[0], (U32)_args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_INT64, TP_INT64):
	dRet = ((_dCddxx)(pFn))(_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_INT64, TP_FP32):
	dRet = ((_dCddxf)(pFn))(_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_INT64, TP_FP64):
	dRet = ((_dCddxd)(pFn))(_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP32, TP_INT32):
	dRet = ((_dCddfu)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP32, TP_INT64):
	dRet = ((_dCddfx)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP32, TP_FP32):
	dRet = ((_dCddff)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP32, TP_FP64):
	dRet = ((_dCddfd)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP64, TP_INT32):
	dRet = ((_dCdddu)(pFn))(_argsd[0], _argsd[1], _argsd[2], (U32)_args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP64, TP_INT64):
	dRet = ((_dCdddx)(pFn))(_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP64, TP_FP32):
	dRet = ((_dCdddf)(pFn))(_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP64, TP_FP64):
	dRet = ((_dCdddd)(pFn))(_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
