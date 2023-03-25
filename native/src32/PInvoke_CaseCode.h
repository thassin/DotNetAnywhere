// generated using generate_PInv_files_32bit.php
case CALL0(TP_INT32):
	uRet = ((_uC)(pFn))();
	break;
case CALL0(TP_FP32):
	fRet = ((_fC)(pFn))();
	break;
case CALL0(TP_FP64):
	dRet = ((_dC)(pFn))();
	break;
case CALL1(TP_INT32, TP_INT32):
	uRet = ((_uCu)(pFn))(_args[0]);
	break;
case CALL1(TP_INT32, TP_FP32):
	uRet = ((_uCf)(pFn))((float)_argsd[0]);
	break;
case CALL1(TP_INT32, TP_FP64):
	uRet = ((_uCd)(pFn))(_argsd[0]);
	break;
case CALL1(TP_FP32, TP_INT32):
	fRet = ((_fCu)(pFn))(_args[0]);
	break;
case CALL1(TP_FP32, TP_FP32):
	fRet = ((_fCf)(pFn))((float)_argsd[0]);
	break;
case CALL1(TP_FP32, TP_FP64):
	fRet = ((_fCd)(pFn))(_argsd[0]);
	break;
case CALL1(TP_FP64, TP_INT32):
	dRet = ((_dCu)(pFn))(_args[0]);
	break;
case CALL1(TP_FP64, TP_FP32):
	dRet = ((_dCf)(pFn))((float)_argsd[0]);
	break;
case CALL1(TP_FP64, TP_FP64):
	dRet = ((_dCd)(pFn))(_argsd[0]);
	break;
case CALL2(TP_INT32, TP_INT32, TP_INT32):
	uRet = ((_uCuu)(pFn))(_args[0], _args[1]);
	break;
case CALL2(TP_INT32, TP_INT32, TP_FP32):
	uRet = ((_uCuf)(pFn))(_args[0], (float)_argsd[0]);
	break;
case CALL2(TP_INT32, TP_INT32, TP_FP64):
	uRet = ((_uCud)(pFn))(_args[0], _argsd[0]);
	break;
case CALL2(TP_INT32, TP_FP32, TP_INT32):
	uRet = ((_uCfu)(pFn))((float)_argsd[0], _args[0]);
	break;
case CALL2(TP_INT32, TP_FP32, TP_FP32):
	uRet = ((_uCff)(pFn))((float)_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_INT32, TP_FP32, TP_FP64):
	uRet = ((_uCfd)(pFn))((float)_argsd[0], _argsd[1]);
	break;
case CALL2(TP_INT32, TP_FP64, TP_INT32):
	uRet = ((_uCdu)(pFn))(_argsd[0], _args[0]);
	break;
case CALL2(TP_INT32, TP_FP64, TP_FP32):
	uRet = ((_uCdf)(pFn))(_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_INT32, TP_FP64, TP_FP64):
	uRet = ((_uCdd)(pFn))(_argsd[0], _argsd[1]);
	break;
case CALL2(TP_FP32, TP_INT32, TP_INT32):
	fRet = ((_fCuu)(pFn))(_args[0], _args[1]);
	break;
case CALL2(TP_FP32, TP_INT32, TP_FP32):
	fRet = ((_fCuf)(pFn))(_args[0], (float)_argsd[0]);
	break;
case CALL2(TP_FP32, TP_INT32, TP_FP64):
	fRet = ((_fCud)(pFn))(_args[0], _argsd[0]);
	break;
case CALL2(TP_FP32, TP_FP32, TP_INT32):
	fRet = ((_fCfu)(pFn))((float)_argsd[0], _args[0]);
	break;
case CALL2(TP_FP32, TP_FP32, TP_FP32):
	fRet = ((_fCff)(pFn))((float)_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_FP32, TP_FP32, TP_FP64):
	fRet = ((_fCfd)(pFn))((float)_argsd[0], _argsd[1]);
	break;
case CALL2(TP_FP32, TP_FP64, TP_INT32):
	fRet = ((_fCdu)(pFn))(_argsd[0], _args[0]);
	break;
case CALL2(TP_FP32, TP_FP64, TP_FP32):
	fRet = ((_fCdf)(pFn))(_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_FP32, TP_FP64, TP_FP64):
	fRet = ((_fCdd)(pFn))(_argsd[0], _argsd[1]);
	break;
case CALL2(TP_FP64, TP_INT32, TP_INT32):
	dRet = ((_dCuu)(pFn))(_args[0], _args[1]);
	break;
case CALL2(TP_FP64, TP_INT32, TP_FP32):
	dRet = ((_dCuf)(pFn))(_args[0], (float)_argsd[0]);
	break;
case CALL2(TP_FP64, TP_INT32, TP_FP64):
	dRet = ((_dCud)(pFn))(_args[0], _argsd[0]);
	break;
case CALL2(TP_FP64, TP_FP32, TP_INT32):
	dRet = ((_dCfu)(pFn))((float)_argsd[0], _args[0]);
	break;
case CALL2(TP_FP64, TP_FP32, TP_FP32):
	dRet = ((_dCff)(pFn))((float)_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_FP64, TP_FP32, TP_FP64):
	dRet = ((_dCfd)(pFn))((float)_argsd[0], _argsd[1]);
	break;
case CALL2(TP_FP64, TP_FP64, TP_INT32):
	dRet = ((_dCdu)(pFn))(_argsd[0], _args[0]);
	break;
case CALL2(TP_FP64, TP_FP64, TP_FP32):
	dRet = ((_dCdf)(pFn))(_argsd[0], (float)_argsd[1]);
	break;
case CALL2(TP_FP64, TP_FP64, TP_FP64):
	dRet = ((_dCdd)(pFn))(_argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_INT32, TP_INT32):
	uRet = ((_uCuuu)(pFn))(_args[0], _args[1], _args[2]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_INT32, TP_FP32):
	uRet = ((_uCuuf)(pFn))(_args[0], _args[1], (float)_argsd[0]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_INT32, TP_FP64):
	uRet = ((_uCuud)(pFn))(_args[0], _args[1], _argsd[0]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP32, TP_INT32):
	uRet = ((_uCufu)(pFn))(_args[0], (float)_argsd[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP32, TP_FP32):
	uRet = ((_uCuff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP32, TP_FP64):
	uRet = ((_uCufd)(pFn))(_args[0], (float)_argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP64, TP_INT32):
	uRet = ((_uCudu)(pFn))(_args[0], _argsd[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP64, TP_FP32):
	uRet = ((_uCudf)(pFn))(_args[0], _argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_INT32, TP_FP64, TP_FP64):
	uRet = ((_uCudd)(pFn))(_args[0], _argsd[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_INT32, TP_INT32):
	uRet = ((_uCfuu)(pFn))((float)_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_INT32, TP_FP32):
	uRet = ((_uCfuf)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_INT32, TP_FP64):
	uRet = ((_uCfud)(pFn))((float)_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP32, TP_INT32):
	uRet = ((_uCffu)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP32, TP_FP32):
	uRet = ((_uCfff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP32, TP_FP64):
	uRet = ((_uCffd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP64, TP_INT32):
	uRet = ((_uCfdu)(pFn))((float)_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP64, TP_FP32):
	uRet = ((_uCfdf)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP32, TP_FP64, TP_FP64):
	uRet = ((_uCfdd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_INT32, TP_INT32):
	uRet = ((_uCduu)(pFn))(_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_INT32, TP_FP32):
	uRet = ((_uCduf)(pFn))(_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_INT32, TP_FP64):
	uRet = ((_uCdud)(pFn))(_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP32, TP_INT32):
	uRet = ((_uCdfu)(pFn))(_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP32, TP_FP32):
	uRet = ((_uCdff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP32, TP_FP64):
	uRet = ((_uCdfd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP64, TP_INT32):
	uRet = ((_uCddu)(pFn))(_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP64, TP_FP32):
	uRet = ((_uCddf)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_INT32, TP_FP64, TP_FP64, TP_FP64):
	uRet = ((_uCddd)(pFn))(_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_INT32, TP_INT32):
	fRet = ((_fCuuu)(pFn))(_args[0], _args[1], _args[2]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_INT32, TP_FP32):
	fRet = ((_fCuuf)(pFn))(_args[0], _args[1], (float)_argsd[0]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_INT32, TP_FP64):
	fRet = ((_fCuud)(pFn))(_args[0], _args[1], _argsd[0]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP32, TP_INT32):
	fRet = ((_fCufu)(pFn))(_args[0], (float)_argsd[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP32, TP_FP32):
	fRet = ((_fCuff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP32, TP_FP64):
	fRet = ((_fCufd)(pFn))(_args[0], (float)_argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP64, TP_INT32):
	fRet = ((_fCudu)(pFn))(_args[0], _argsd[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP64, TP_FP32):
	fRet = ((_fCudf)(pFn))(_args[0], _argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_INT32, TP_FP64, TP_FP64):
	fRet = ((_fCudd)(pFn))(_args[0], _argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_INT32, TP_INT32):
	fRet = ((_fCfuu)(pFn))((float)_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_INT32, TP_FP32):
	fRet = ((_fCfuf)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_INT32, TP_FP64):
	fRet = ((_fCfud)(pFn))((float)_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP32, TP_INT32):
	fRet = ((_fCffu)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP32, TP_FP32):
	fRet = ((_fCfff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP32, TP_FP64):
	fRet = ((_fCffd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP64, TP_INT32):
	fRet = ((_fCfdu)(pFn))((float)_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP64, TP_FP32):
	fRet = ((_fCfdf)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP32, TP_FP64, TP_FP64):
	fRet = ((_fCfdd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_INT32, TP_INT32):
	fRet = ((_fCduu)(pFn))(_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_INT32, TP_FP32):
	fRet = ((_fCduf)(pFn))(_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_INT32, TP_FP64):
	fRet = ((_fCdud)(pFn))(_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP32, TP_INT32):
	fRet = ((_fCdfu)(pFn))(_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP32, TP_FP32):
	fRet = ((_fCdff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP32, TP_FP64):
	fRet = ((_fCdfd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP64, TP_INT32):
	fRet = ((_fCddu)(pFn))(_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP64, TP_FP32):
	fRet = ((_fCddf)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP32, TP_FP64, TP_FP64, TP_FP64):
	fRet = ((_fCddd)(pFn))(_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_INT32, TP_INT32):
	dRet = ((_dCuuu)(pFn))(_args[0], _args[1], _args[2]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_INT32, TP_FP32):
	dRet = ((_dCuuf)(pFn))(_args[0], _args[1], (float)_argsd[0]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_INT32, TP_FP64):
	dRet = ((_dCuud)(pFn))(_args[0], _args[1], _argsd[0]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP32, TP_INT32):
	dRet = ((_dCufu)(pFn))(_args[0], (float)_argsd[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP32, TP_FP32):
	dRet = ((_dCuff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP32, TP_FP64):
	dRet = ((_dCufd)(pFn))(_args[0], (float)_argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP64, TP_INT32):
	dRet = ((_dCudu)(pFn))(_args[0], _argsd[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP64, TP_FP32):
	dRet = ((_dCudf)(pFn))(_args[0], _argsd[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_INT32, TP_FP64, TP_FP64):
	dRet = ((_dCudd)(pFn))(_args[0], _argsd[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_INT32, TP_INT32):
	dRet = ((_dCfuu)(pFn))((float)_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_INT32, TP_FP32):
	dRet = ((_dCfuf)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_INT32, TP_FP64):
	dRet = ((_dCfud)(pFn))((float)_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP32, TP_INT32):
	dRet = ((_dCffu)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP32, TP_FP32):
	dRet = ((_dCfff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP32, TP_FP64):
	dRet = ((_dCffd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP64, TP_INT32):
	dRet = ((_dCfdu)(pFn))((float)_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP64, TP_FP32):
	dRet = ((_dCfdf)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP32, TP_FP64, TP_FP64):
	dRet = ((_dCfdd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_INT32, TP_INT32):
	dRet = ((_dCduu)(pFn))(_argsd[0], _args[0], _args[1]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_INT32, TP_FP32):
	dRet = ((_dCduf)(pFn))(_argsd[0], _args[0], (float)_argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_INT32, TP_FP64):
	dRet = ((_dCdud)(pFn))(_argsd[0], _args[0], _argsd[1]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP32, TP_INT32):
	dRet = ((_dCdfu)(pFn))(_argsd[0], (float)_argsd[1], _args[0]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP32, TP_FP32):
	dRet = ((_dCdff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP32, TP_FP64):
	dRet = ((_dCdfd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP64, TP_INT32):
	dRet = ((_dCddu)(pFn))(_argsd[0], _argsd[1], _args[0]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP64, TP_FP32):
	dRet = ((_dCddf)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL3(TP_FP64, TP_FP64, TP_FP64, TP_FP64):
	dRet = ((_dCddd)(pFn))(_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
	uRet = ((_uCuuuu)(pFn))(_args[0], _args[1], _args[2], _args[3]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_FP32):
	uRet = ((_uCuuuf)(pFn))(_args[0], _args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_INT32, TP_FP64):
	uRet = ((_uCuuud)(pFn))(_args[0], _args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP32, TP_INT32):
	uRet = ((_uCuufu)(pFn))(_args[0], _args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP32, TP_FP32):
	uRet = ((_uCuuff)(pFn))(_args[0], _args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP32, TP_FP64):
	uRet = ((_uCuufd)(pFn))(_args[0], _args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP64, TP_INT32):
	uRet = ((_uCuudu)(pFn))(_args[0], _args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP64, TP_FP32):
	uRet = ((_uCuudf)(pFn))(_args[0], _args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_INT32, TP_FP64, TP_FP64):
	uRet = ((_uCuudd)(pFn))(_args[0], _args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_INT32, TP_INT32):
	uRet = ((_uCufuu)(pFn))(_args[0], (float)_argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_INT32, TP_FP32):
	uRet = ((_uCufuf)(pFn))(_args[0], (float)_argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_INT32, TP_FP64):
	uRet = ((_uCufud)(pFn))(_args[0], (float)_argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP32, TP_INT32):
	uRet = ((_uCuffu)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP32, TP_FP32):
	uRet = ((_uCufff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP32, TP_FP64):
	uRet = ((_uCuffd)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP64, TP_INT32):
	uRet = ((_uCufdu)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP64, TP_FP32):
	uRet = ((_uCufdf)(pFn))(_args[0], (float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP32, TP_FP64, TP_FP64):
	uRet = ((_uCufdd)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_INT32, TP_INT32):
	uRet = ((_uCuduu)(pFn))(_args[0], _argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_INT32, TP_FP32):
	uRet = ((_uCuduf)(pFn))(_args[0], _argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_INT32, TP_FP64):
	uRet = ((_uCudud)(pFn))(_args[0], _argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP32, TP_INT32):
	uRet = ((_uCudfu)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP32, TP_FP32):
	uRet = ((_uCudff)(pFn))(_args[0], _argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP32, TP_FP64):
	uRet = ((_uCudfd)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP64, TP_INT32):
	uRet = ((_uCuddu)(pFn))(_args[0], _argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP64, TP_FP32):
	uRet = ((_uCuddf)(pFn))(_args[0], _argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_INT32, TP_FP64, TP_FP64, TP_FP64):
	uRet = ((_uCuddd)(pFn))(_args[0], _argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_INT32, TP_INT32):
	uRet = ((_uCfuuu)(pFn))((float)_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_INT32, TP_FP32):
	uRet = ((_uCfuuf)(pFn))((float)_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_INT32, TP_FP64):
	uRet = ((_uCfuud)(pFn))((float)_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP32, TP_INT32):
	uRet = ((_uCfufu)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP32, TP_FP32):
	uRet = ((_uCfuff)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP32, TP_FP64):
	uRet = ((_uCfufd)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP64, TP_INT32):
	uRet = ((_uCfudu)(pFn))((float)_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP64, TP_FP32):
	uRet = ((_uCfudf)(pFn))((float)_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_INT32, TP_FP64, TP_FP64):
	uRet = ((_uCfudd)(pFn))((float)_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_INT32, TP_INT32):
	uRet = ((_uCffuu)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_INT32, TP_FP32):
	uRet = ((_uCffuf)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_INT32, TP_FP64):
	uRet = ((_uCffud)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP32, TP_INT32):
	uRet = ((_uCfffu)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP32, TP_FP32):
	uRet = ((_uCffff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP32, TP_FP64):
	uRet = ((_uCfffd)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP64, TP_INT32):
	uRet = ((_uCffdu)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP64, TP_FP32):
	uRet = ((_uCffdf)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP32, TP_FP64, TP_FP64):
	uRet = ((_uCffdd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_INT32, TP_INT32):
	uRet = ((_uCfduu)(pFn))((float)_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_INT32, TP_FP32):
	uRet = ((_uCfduf)(pFn))((float)_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_INT32, TP_FP64):
	uRet = ((_uCfdud)(pFn))((float)_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP32, TP_INT32):
	uRet = ((_uCfdfu)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP32, TP_FP32):
	uRet = ((_uCfdff)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP32, TP_FP64):
	uRet = ((_uCfdfd)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP64, TP_INT32):
	uRet = ((_uCfddu)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP64, TP_FP32):
	uRet = ((_uCfddf)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP32, TP_FP64, TP_FP64, TP_FP64):
	uRet = ((_uCfddd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_INT32, TP_INT32):
	uRet = ((_uCduuu)(pFn))(_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_INT32, TP_FP32):
	uRet = ((_uCduuf)(pFn))(_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_INT32, TP_FP64):
	uRet = ((_uCduud)(pFn))(_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP32, TP_INT32):
	uRet = ((_uCdufu)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP32, TP_FP32):
	uRet = ((_uCduff)(pFn))(_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP32, TP_FP64):
	uRet = ((_uCdufd)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP64, TP_INT32):
	uRet = ((_uCdudu)(pFn))(_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP64, TP_FP32):
	uRet = ((_uCdudf)(pFn))(_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_INT32, TP_FP64, TP_FP64):
	uRet = ((_uCdudd)(pFn))(_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_INT32, TP_INT32):
	uRet = ((_uCdfuu)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_INT32, TP_FP32):
	uRet = ((_uCdfuf)(pFn))(_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_INT32, TP_FP64):
	uRet = ((_uCdfud)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP32, TP_INT32):
	uRet = ((_uCdffu)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP32, TP_FP32):
	uRet = ((_uCdfff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP32, TP_FP64):
	uRet = ((_uCdffd)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP64, TP_INT32):
	uRet = ((_uCdfdu)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP64, TP_FP32):
	uRet = ((_uCdfdf)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP32, TP_FP64, TP_FP64):
	uRet = ((_uCdfdd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_INT32, TP_INT32):
	uRet = ((_uCdduu)(pFn))(_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_INT32, TP_FP32):
	uRet = ((_uCdduf)(pFn))(_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_INT32, TP_FP64):
	uRet = ((_uCddud)(pFn))(_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP32, TP_INT32):
	uRet = ((_uCddfu)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP32, TP_FP32):
	uRet = ((_uCddff)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP32, TP_FP64):
	uRet = ((_uCddfd)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP64, TP_INT32):
	uRet = ((_uCdddu)(pFn))(_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP64, TP_FP32):
	uRet = ((_uCdddf)(pFn))(_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_INT32, TP_FP64, TP_FP64, TP_FP64, TP_FP64):
	uRet = ((_uCdddd)(pFn))(_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
	fRet = ((_fCuuuu)(pFn))(_args[0], _args[1], _args[2], _args[3]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_INT32, TP_FP32):
	fRet = ((_fCuuuf)(pFn))(_args[0], _args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_INT32, TP_FP64):
	fRet = ((_fCuuud)(pFn))(_args[0], _args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP32, TP_INT32):
	fRet = ((_fCuufu)(pFn))(_args[0], _args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP32, TP_FP32):
	fRet = ((_fCuuff)(pFn))(_args[0], _args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP32, TP_FP64):
	fRet = ((_fCuufd)(pFn))(_args[0], _args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP64, TP_INT32):
	fRet = ((_fCuudu)(pFn))(_args[0], _args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP64, TP_FP32):
	fRet = ((_fCuudf)(pFn))(_args[0], _args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_INT32, TP_FP64, TP_FP64):
	fRet = ((_fCuudd)(pFn))(_args[0], _args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_INT32, TP_INT32):
	fRet = ((_fCufuu)(pFn))(_args[0], (float)_argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_INT32, TP_FP32):
	fRet = ((_fCufuf)(pFn))(_args[0], (float)_argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_INT32, TP_FP64):
	fRet = ((_fCufud)(pFn))(_args[0], (float)_argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP32, TP_INT32):
	fRet = ((_fCuffu)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP32, TP_FP32):
	fRet = ((_fCufff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP32, TP_FP64):
	fRet = ((_fCuffd)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP64, TP_INT32):
	fRet = ((_fCufdu)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP64, TP_FP32):
	fRet = ((_fCufdf)(pFn))(_args[0], (float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP32, TP_FP64, TP_FP64):
	fRet = ((_fCufdd)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_INT32, TP_INT32):
	fRet = ((_fCuduu)(pFn))(_args[0], _argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_INT32, TP_FP32):
	fRet = ((_fCuduf)(pFn))(_args[0], _argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_INT32, TP_FP64):
	fRet = ((_fCudud)(pFn))(_args[0], _argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP32, TP_INT32):
	fRet = ((_fCudfu)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP32, TP_FP32):
	fRet = ((_fCudff)(pFn))(_args[0], _argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP32, TP_FP64):
	fRet = ((_fCudfd)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP64, TP_INT32):
	fRet = ((_fCuddu)(pFn))(_args[0], _argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP64, TP_FP32):
	fRet = ((_fCuddf)(pFn))(_args[0], _argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_INT32, TP_FP64, TP_FP64, TP_FP64):
	fRet = ((_fCuddd)(pFn))(_args[0], _argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_INT32, TP_INT32):
	fRet = ((_fCfuuu)(pFn))((float)_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_INT32, TP_FP32):
	fRet = ((_fCfuuf)(pFn))((float)_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_INT32, TP_FP64):
	fRet = ((_fCfuud)(pFn))((float)_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP32, TP_INT32):
	fRet = ((_fCfufu)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP32, TP_FP32):
	fRet = ((_fCfuff)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP32, TP_FP64):
	fRet = ((_fCfufd)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP64, TP_INT32):
	fRet = ((_fCfudu)(pFn))((float)_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP64, TP_FP32):
	fRet = ((_fCfudf)(pFn))((float)_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_INT32, TP_FP64, TP_FP64):
	fRet = ((_fCfudd)(pFn))((float)_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_INT32, TP_INT32):
	fRet = ((_fCffuu)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_INT32, TP_FP32):
	fRet = ((_fCffuf)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_INT32, TP_FP64):
	fRet = ((_fCffud)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP32, TP_INT32):
	fRet = ((_fCfffu)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP32, TP_FP32):
	fRet = ((_fCffff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP32, TP_FP64):
	fRet = ((_fCfffd)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP64, TP_INT32):
	fRet = ((_fCffdu)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP64, TP_FP32):
	fRet = ((_fCffdf)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP32, TP_FP64, TP_FP64):
	fRet = ((_fCffdd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_INT32, TP_INT32):
	fRet = ((_fCfduu)(pFn))((float)_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_INT32, TP_FP32):
	fRet = ((_fCfduf)(pFn))((float)_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_INT32, TP_FP64):
	fRet = ((_fCfdud)(pFn))((float)_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP32, TP_INT32):
	fRet = ((_fCfdfu)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP32, TP_FP32):
	fRet = ((_fCfdff)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP32, TP_FP64):
	fRet = ((_fCfdfd)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP64, TP_INT32):
	fRet = ((_fCfddu)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP64, TP_FP32):
	fRet = ((_fCfddf)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP32, TP_FP64, TP_FP64, TP_FP64):
	fRet = ((_fCfddd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_INT32, TP_INT32):
	fRet = ((_fCduuu)(pFn))(_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_INT32, TP_FP32):
	fRet = ((_fCduuf)(pFn))(_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_INT32, TP_FP64):
	fRet = ((_fCduud)(pFn))(_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP32, TP_INT32):
	fRet = ((_fCdufu)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP32, TP_FP32):
	fRet = ((_fCduff)(pFn))(_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP32, TP_FP64):
	fRet = ((_fCdufd)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP64, TP_INT32):
	fRet = ((_fCdudu)(pFn))(_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP64, TP_FP32):
	fRet = ((_fCdudf)(pFn))(_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_INT32, TP_FP64, TP_FP64):
	fRet = ((_fCdudd)(pFn))(_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_INT32, TP_INT32):
	fRet = ((_fCdfuu)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_INT32, TP_FP32):
	fRet = ((_fCdfuf)(pFn))(_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_INT32, TP_FP64):
	fRet = ((_fCdfud)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP32, TP_INT32):
	fRet = ((_fCdffu)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP32, TP_FP32):
	fRet = ((_fCdfff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP32, TP_FP64):
	fRet = ((_fCdffd)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP64, TP_INT32):
	fRet = ((_fCdfdu)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP64, TP_FP32):
	fRet = ((_fCdfdf)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP32, TP_FP64, TP_FP64):
	fRet = ((_fCdfdd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_INT32, TP_INT32):
	fRet = ((_fCdduu)(pFn))(_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_INT32, TP_FP32):
	fRet = ((_fCdduf)(pFn))(_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_INT32, TP_FP64):
	fRet = ((_fCddud)(pFn))(_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP32, TP_INT32):
	fRet = ((_fCddfu)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP32, TP_FP32):
	fRet = ((_fCddff)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP32, TP_FP64):
	fRet = ((_fCddfd)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP64, TP_INT32):
	fRet = ((_fCdddu)(pFn))(_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP64, TP_FP32):
	fRet = ((_fCdddf)(pFn))(_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP32, TP_FP64, TP_FP64, TP_FP64, TP_FP64):
	fRet = ((_fCdddd)(pFn))(_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_INT32, TP_INT32):
	dRet = ((_dCuuuu)(pFn))(_args[0], _args[1], _args[2], _args[3]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_INT32, TP_FP32):
	dRet = ((_dCuuuf)(pFn))(_args[0], _args[1], _args[2], (float)_argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_INT32, TP_FP64):
	dRet = ((_dCuuud)(pFn))(_args[0], _args[1], _args[2], _argsd[0]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP32, TP_INT32):
	dRet = ((_dCuufu)(pFn))(_args[0], _args[1], (float)_argsd[0], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP32, TP_FP32):
	dRet = ((_dCuuff)(pFn))(_args[0], _args[1], (float)_argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP32, TP_FP64):
	dRet = ((_dCuufd)(pFn))(_args[0], _args[1], (float)_argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP64, TP_INT32):
	dRet = ((_dCuudu)(pFn))(_args[0], _args[1], _argsd[0], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP64, TP_FP32):
	dRet = ((_dCuudf)(pFn))(_args[0], _args[1], _argsd[0], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_INT32, TP_FP64, TP_FP64):
	dRet = ((_dCuudd)(pFn))(_args[0], _args[1], _argsd[0], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_INT32, TP_INT32):
	dRet = ((_dCufuu)(pFn))(_args[0], (float)_argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_INT32, TP_FP32):
	dRet = ((_dCufuf)(pFn))(_args[0], (float)_argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_INT32, TP_FP64):
	dRet = ((_dCufud)(pFn))(_args[0], (float)_argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP32, TP_INT32):
	dRet = ((_dCuffu)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP32, TP_FP32):
	dRet = ((_dCufff)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP32, TP_FP64):
	dRet = ((_dCuffd)(pFn))(_args[0], (float)_argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP64, TP_INT32):
	dRet = ((_dCufdu)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP64, TP_FP32):
	dRet = ((_dCufdf)(pFn))(_args[0], (float)_argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP32, TP_FP64, TP_FP64):
	dRet = ((_dCufdd)(pFn))(_args[0], (float)_argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_INT32, TP_INT32):
	dRet = ((_dCuduu)(pFn))(_args[0], _argsd[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_INT32, TP_FP32):
	dRet = ((_dCuduf)(pFn))(_args[0], _argsd[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_INT32, TP_FP64):
	dRet = ((_dCudud)(pFn))(_args[0], _argsd[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP32, TP_INT32):
	dRet = ((_dCudfu)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP32, TP_FP32):
	dRet = ((_dCudff)(pFn))(_args[0], _argsd[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP32, TP_FP64):
	dRet = ((_dCudfd)(pFn))(_args[0], _argsd[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP64, TP_INT32):
	dRet = ((_dCuddu)(pFn))(_args[0], _argsd[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP64, TP_FP32):
	dRet = ((_dCuddf)(pFn))(_args[0], _argsd[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_INT32, TP_FP64, TP_FP64, TP_FP64):
	dRet = ((_dCuddd)(pFn))(_args[0], _argsd[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_INT32, TP_INT32):
	dRet = ((_dCfuuu)(pFn))((float)_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_INT32, TP_FP32):
	dRet = ((_dCfuuf)(pFn))((float)_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_INT32, TP_FP64):
	dRet = ((_dCfuud)(pFn))((float)_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP32, TP_INT32):
	dRet = ((_dCfufu)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP32, TP_FP32):
	dRet = ((_dCfuff)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP32, TP_FP64):
	dRet = ((_dCfufd)(pFn))((float)_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP64, TP_INT32):
	dRet = ((_dCfudu)(pFn))((float)_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP64, TP_FP32):
	dRet = ((_dCfudf)(pFn))((float)_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_INT32, TP_FP64, TP_FP64):
	dRet = ((_dCfudd)(pFn))((float)_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_INT32, TP_INT32):
	dRet = ((_dCffuu)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_INT32, TP_FP32):
	dRet = ((_dCffuf)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_INT32, TP_FP64):
	dRet = ((_dCffud)(pFn))((float)_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP32, TP_INT32):
	dRet = ((_dCfffu)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP32, TP_FP32):
	dRet = ((_dCffff)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP32, TP_FP64):
	dRet = ((_dCfffd)(pFn))((float)_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP64, TP_INT32):
	dRet = ((_dCffdu)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP64, TP_FP32):
	dRet = ((_dCffdf)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP32, TP_FP64, TP_FP64):
	dRet = ((_dCffdd)(pFn))((float)_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_INT32, TP_INT32):
	dRet = ((_dCfduu)(pFn))((float)_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_INT32, TP_FP32):
	dRet = ((_dCfduf)(pFn))((float)_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_INT32, TP_FP64):
	dRet = ((_dCfdud)(pFn))((float)_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP32, TP_INT32):
	dRet = ((_dCfdfu)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP32, TP_FP32):
	dRet = ((_dCfdff)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP32, TP_FP64):
	dRet = ((_dCfdfd)(pFn))((float)_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP64, TP_INT32):
	dRet = ((_dCfddu)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP64, TP_FP32):
	dRet = ((_dCfddf)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP32, TP_FP64, TP_FP64, TP_FP64):
	dRet = ((_dCfddd)(pFn))((float)_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_INT32, TP_INT32):
	dRet = ((_dCduuu)(pFn))(_argsd[0], _args[0], _args[1], _args[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_INT32, TP_FP32):
	dRet = ((_dCduuf)(pFn))(_argsd[0], _args[0], _args[1], (float)_argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_INT32, TP_FP64):
	dRet = ((_dCduud)(pFn))(_argsd[0], _args[0], _args[1], _argsd[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP32, TP_INT32):
	dRet = ((_dCdufu)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP32, TP_FP32):
	dRet = ((_dCduff)(pFn))(_argsd[0], _args[0], (float)_argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP32, TP_FP64):
	dRet = ((_dCdufd)(pFn))(_argsd[0], _args[0], (float)_argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP64, TP_INT32):
	dRet = ((_dCdudu)(pFn))(_argsd[0], _args[0], _argsd[1], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP64, TP_FP32):
	dRet = ((_dCdudf)(pFn))(_argsd[0], _args[0], _argsd[1], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_INT32, TP_FP64, TP_FP64):
	dRet = ((_dCdudd)(pFn))(_argsd[0], _args[0], _argsd[1], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_INT32, TP_INT32):
	dRet = ((_dCdfuu)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_INT32, TP_FP32):
	dRet = ((_dCdfuf)(pFn))(_argsd[0], (float)_argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_INT32, TP_FP64):
	dRet = ((_dCdfud)(pFn))(_argsd[0], (float)_argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP32, TP_INT32):
	dRet = ((_dCdffu)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP32, TP_FP32):
	dRet = ((_dCdfff)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP32, TP_FP64):
	dRet = ((_dCdffd)(pFn))(_argsd[0], (float)_argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP64, TP_INT32):
	dRet = ((_dCdfdu)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP64, TP_FP32):
	dRet = ((_dCdfdf)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP32, TP_FP64, TP_FP64):
	dRet = ((_dCdfdd)(pFn))(_argsd[0], (float)_argsd[1], _argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_INT32, TP_INT32):
	dRet = ((_dCdduu)(pFn))(_argsd[0], _argsd[1], _args[0], _args[1]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_INT32, TP_FP32):
	dRet = ((_dCdduf)(pFn))(_argsd[0], _argsd[1], _args[0], (float)_argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_INT32, TP_FP64):
	dRet = ((_dCddud)(pFn))(_argsd[0], _argsd[1], _args[0], _argsd[2]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP32, TP_INT32):
	dRet = ((_dCddfu)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP32, TP_FP32):
	dRet = ((_dCddff)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP32, TP_FP64):
	dRet = ((_dCddfd)(pFn))(_argsd[0], _argsd[1], (float)_argsd[2], _argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP64, TP_INT32):
	dRet = ((_dCdddu)(pFn))(_argsd[0], _argsd[1], _argsd[2], _args[0]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP64, TP_FP32):
	dRet = ((_dCdddf)(pFn))(_argsd[0], _argsd[1], _argsd[2], (float)_argsd[3]);
	break;
case CALL4(TP_FP64, TP_FP64, TP_FP64, TP_FP64, TP_FP64):
	dRet = ((_dCdddd)(pFn))(_argsd[0], _argsd[1], _argsd[2], _argsd[3]);
	break;
