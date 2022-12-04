using System;

namespace Test01 {

    public class Program {

        private const string TESTCASE = "TESTCASE01 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        static void Main( string[] args ) {
            Console.WriteLine( TESTCASE +  "args count = " + args.Length );

            for ( int i = 0; i < args.Length; i++ ) {
                Console.WriteLine( TESTCASE +  "argument at index " + i + " is '" + args[i] + "'.");
            }

            Console.WriteLine( TESTCASE +  TEST_PASSED );
        }
    }

}
