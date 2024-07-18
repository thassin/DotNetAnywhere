using System;

namespace Test01 {

    public class Program {

        private const string TESTCASE = "TESTCASE01 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        static void Main( string[] args ) {
            Console.WriteLine( TESTCASE + "test looping over args-array." );

            Console.WriteLine( TESTCASE + "args-array length = " + args.Length );

            if ( args.Length == 0 ) {
                Console.WriteLine( TESTCASE + "NOTICE try setting some COMMANDLINE-OPTIONS for this test!" );
            }

            for ( int i = 0; i < args.Length; i++ ) {
                Console.WriteLine( TESTCASE + "argument at index " + i + " is '" + args[i] + "'.");
            }

            Console.WriteLine( TESTCASE + TEST_PASSED );
        }
    }

}
