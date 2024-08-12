<?php

if ( $argc !== 2 ) {
	echo "ERROR: specify runtime at commandline: mono dna32 dna64 etc." . PHP_EOL;
	exit;
}

$outputFileName = "allTestsOutput-" . $argv[1] . "-" . date( "Ymd-His" ) . ".txt";

echo "RESULTS TO FILE : $outputFileName" . PHP_EOL;

// clear a possibly existing output-file.
exec( "rm -f \"$outputFileName\"" );

$runtime = $argv[1];
if ( $runtime !== "mono" ) {
	// assume all other runtimes except mono are at local directory.
	$runtime = "./$runtime";
	$runtimeID = "dna";
} else {
	$runtimeID = "mono";
}

// prepare the 32/64-bit pinvoke-test-library.
$libName = "libpinvoketest.so-" . (string)( PHP_INT_SIZE * 8 ) . "bit";
if ( is_file( $libName ) ) exec( "cp $libName libpinvoketest.so" );

$allTests = array();
$allTests[] = "Test01_cmdline_args";
$allTests[] = "Test02_fields_test";
$allTests[] = "Test03_array_test";
$allTests[] = "Test04_pinvoke";
$allTests[] = "Test05_print_test";
$allTests[] = "Test06_random_test";
$allTests[] = "Test07_methodcalls_test";
$allTests[] = "Test08_gc_test";
$allTests[] = "Test09_box_unbox";

// TODO add more tests here.
// TODO add more tests here..
// TODO add more tests here...

foreach ( $allTests as $testName ) {
	echo "running test: $testName" . PHP_EOL;

	$output = "";
	$output .= "##" . PHP_EOL;
	$output .= "## OUTPUT FROM TEST : $testName " . PHP_EOL;
	$output .= "##" . PHP_EOL;
	$output .= PHP_EOL;
	$output .= runTest( $runtime, $runtimeID, $testName );
	$output .= PHP_EOL;

	file_put_contents( $outputFileName, $output, FILE_APPEND );
}

echo "--OK--" . PHP_EOL;
exit;

function runTest( string $runtime, string $runtimeID, string $testName ) : string {
	$cmd = $runtime . " " . $testName . "_" . $runtimeID . ".exe";

	$outputLines = array();
	$resultCode = false;

	$lastLine = exec( $cmd, $outputLines, $resultCode);

	if ( $resultCode !== 0 ) {
		echo "\t" . "ERROR: result code $resultCode" . PHP_EOL;
	}

	$dnaExecutionTimeLineStart = "Total execution time = ";
	if ( $runtimeID === "dna" && substr( $lastLine, 0, strlen( $dnaExecutionTimeLineStart ) ) === $dnaExecutionTimeLineStart ) {
		array_pop( $outputLines ); // remove the total-execution-time line from DNA output.
	}

	return implode( PHP_EOL, $outputLines ) . PHP_EOL;
}

