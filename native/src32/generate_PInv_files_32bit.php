<?php 

// this script will generate the PInvoke typedef and casecode files as 32bit versions: 
// *) the parameter and return types are int32, int64, fp32 and fp64:
//	=> int32 = U32 (char-code u)
//	=> fp32 = float (char-code f)
//	=> fp64 = double (char-code d)

$returnTypes = array( "int32", "fp32", "fp64" );
$paramTypes = array( "int32", "fp32", "fp64" );

$typedef_contents = "// generated using " . $argv[0] . PHP_EOL;
$casecode_contents = "// generated using " . $argv[0] . PHP_EOL;

for ( $paramCount = 0; $paramCount < 5; $paramCount++ ) {

	foreach ( $returnTypes as $rt ) {

		$typedef = "";
		$typedef .= "typedef ";
		$typedef .= rt_2_type( $rt ) . " ";
		$typedef .= "(STDCALL * _";
		$typedef .= rt_2_char( $rt );
		$typedef .= "C##TL##)(##PL##);" . PHP_EOL;

		$td_typeList0 = "";
		$td_paramList0 = "";

		$casecode = "";
		$casecode .= "case CALL";
		$casecode .= $paramCount;
		$casecode .= "(##TL1##):" . PHP_EOL;
		$casecode .= "\t";
		$casecode .= rt_2_char( $rt );
		$casecode .= "Ret = ((_";
		$casecode .= rt_2_char( $rt );
		$casecode .= "C##TL2##)(pFn))(##PL##);" . PHP_EOL;
		$casecode .= "\t";
		$casecode .= "break;" . PHP_EOL;

		$cc_typeList0 = pt_2_ccparam1( $rt, $paramCount < 1 );
		$cc_paramList0 = "";

		if ( $paramCount === 0 ) {
			write_td( $td_typeList0, $td_paramList0 );
			write_cc( $cc_typeList0, $td_typeList0, $cc_paramList0 );
			continue;
		}

		foreach ( $paramTypes as $pt1 ) {

			$td_typeList1 = $td_typeList0 . pt_2_char( $pt1 );
			$td_paramList1 = $td_paramList0 . pt_2_tdparam( $pt1, 1, $paramCount < 2 );

			$cc_typeList1 = $cc_typeList0 . pt_2_ccparam1( $pt1, $paramCount < 2 );
			$cc_paramList1 = $cc_paramList0 . tl_2_ccparam2( $td_typeList1, $paramCount < 2 );

			if ( $paramCount === 1 ) {
				write_td( $td_typeList1, $td_paramList1 );
				write_cc( $cc_typeList1, $td_typeList1, $cc_paramList1 );
				continue;
			}

			foreach ( $paramTypes as $pt2 ) {

				$td_typeList2 = $td_typeList1 . pt_2_char( $pt2 );
				$td_paramList2 = $td_paramList1 . pt_2_tdparam( $pt2, 2, $paramCount < 3 );

				$cc_typeList2 = $cc_typeList1 . pt_2_ccparam1( $pt2, $paramCount < 3 );
				$cc_paramList2 = $cc_paramList1 . tl_2_ccparam2( $td_typeList2, $paramCount < 3 );

				if ( $paramCount === 2 ) {
					write_td( $td_typeList2, $td_paramList2 );
					write_cc( $cc_typeList2, $td_typeList2, $cc_paramList2 );
					continue;
				}

				foreach ( $paramTypes as $pt3 ) {

					$td_typeList3 = $td_typeList2 . pt_2_char( $pt3 );
					$td_paramList3 = $td_paramList2 . pt_2_tdparam( $pt3, 3, $paramCount < 4 );

					$cc_typeList3 = $cc_typeList2 . pt_2_ccparam1( $pt3, $paramCount < 4 );;
					$cc_paramList3 = $cc_paramList2 . tl_2_ccparam2( $td_typeList3, $paramCount < 4 );

					if ( $paramCount === 3 ) {
						write_td( $td_typeList3, $td_paramList3 );
						write_cc( $cc_typeList3, $td_typeList3, $cc_paramList3 );
						continue;
					}

					foreach ( $paramTypes as $pt4 ) {

						$td_typeList4 = $td_typeList3 . pt_2_char( $pt4 );
						$td_paramList4 = $td_paramList3 . pt_2_tdparam( $pt4, 4, $paramCount < 5 );

						$cc_typeList4 = $cc_typeList3 . pt_2_ccparam1( $pt4, $paramCount < 5 );
						$cc_paramList4 = $cc_paramList3 . tl_2_ccparam2( $td_typeList4, $paramCount < 5 );

						write_td( $td_typeList4, $td_paramList4 );
						write_cc( $cc_typeList4, $td_typeList4, $cc_paramList4 );
					}
				}
			}
		}
	}
}

// write the files.

file_put_contents( "PInvoke_TypeDef.h", $typedef_contents );
file_put_contents( "PInvoke_CaseCode.h", $casecode_contents );

echo "--OK--" . PHP_EOL;
exit;

//////////////////////////////////////////////////////////////////////////////////////////////

function rt_2_type( $rt ) {
	switch ( $rt ) {
		case "int32":
		return "U32";

		case "fp32":
		return "float";

		case "fp64":
		return "double";

		default:
		die( "ERROR: at line " . __LINE__ . " unknown returnType: $rt" . PHP_EOL );
	}
}

function rt_2_char( $rt ) {
	switch ( $rt ) {
		case "int32":
		return "u";

		case "fp32":
		return "f";

		case "fp64":
		return "d";

		default:
		die( "ERROR: at line " . __LINE__ . " unknown returnType: $rt" . PHP_EOL );
	}
}

function pt_2_char( $pt ) {
	switch ( $pt ) {
		case "int32":
		return "u";

		case "fp32":
		return "f";

		case "fp64":
		return "d";

		default:
		die( "ERROR: at line " . __LINE__ . " unknown paramType: $pt" . PHP_EOL );
	}
}

function pt_2_tdparam( $pt, $index, $isLast ) {
	switch ( $pt ) {
		case "int32":
		$param = "U32 ";
		break;

		case "fp32":
		$param = "float ";
		break;

		case "fp64":
		$param = "double ";
		break;

		default:
		die( "ERROR: at line " . __LINE__ . " unknown paramType: $pt" . PHP_EOL );
	}
	$param .= "_" . ( $index - 1 );
	if ( $isLast === false ) $param .= ", ";
	return $param;
}

function pt_2_ccparam1( $pt, $isLast ) {
	switch ( $pt ) {
		case "int32":
		$param = "TP_INT32";
		break;

		case "fp32":
		$param = "TP_FP32";
		break;

		case "fp64":
		$param = "TP_FP64";
		break;

		default:
		die( "ERROR: at line " . __LINE__ . " unknown paramType: $pt" . PHP_EOL );
	}
	if ( $isLast === false ) $param .= ", ";
	return $param;
}

function tl_2_ccparam2( $typeList, $isLast ) {

	$itypes = 0;
	$ftypes = 0;

	for ( $i = 0; $i < strlen( $typeList) - 1; $i++ ) {
		$char = $typeList[$i];
		if ( $char === "u" ) $itypes++;
		if ( $char === "f" || $char === "d" ) $ftypes++;
	}

	$pt = substr( $typeList, -1 );
	if( strlen( $pt ) !== 1 ) die( "bad type: '$pt' " . PHP_EOL );

	switch ( $pt ) {
		case "u":
		$param = "_args[$itypes]";
		break;

		case "f":
		$param = "(float)_argsd[$ftypes]";
		break;

		case "d":
		$param = "_argsd[$ftypes]";
		break;

		default:
		die( "ERROR: at line " . __LINE__ . " unknown paramType: $pt" . PHP_EOL );
	}
	if ( $isLast === false ) $param .= ", ";
	return $param;
}

function write_td( $typeList, $paramList ) {

	global $typedef;
	global $typedef_contents;

	$typedef2 = str_replace( "##TL##", $typeList, $typedef );
	$typedef3 = str_replace( "##PL##", $paramList, $typedef2 );

	//echo $typedef3;

	$typedef_contents .= $typedef3;
}

function write_cc( $typeList1, $typeList2, $paramList ) {

	global $casecode;
	global $casecode_contents;

	$casecode2 = str_replace( "##TL1##", $typeList1, $casecode );
	$casecode3 = str_replace( "##TL2##", $typeList2, $casecode2 );
	$casecode4 = str_replace( "##PL##", $paramList, $casecode3 );

	//echo $casecode4;

	$casecode_contents .= $casecode4;
}

