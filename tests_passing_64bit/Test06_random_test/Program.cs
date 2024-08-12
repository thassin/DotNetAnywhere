using System;
using RNGen;

namespace Test06 {

    public class Program {

        private const string TESTCASE = "TESTCASE06 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        private static RandomNumberGenerator rnd = new RandomNumberGenerator( 1234 );

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test random-number generation." );
            
            const int count = 20;
            
            for ( int i = 0; i < count; i++ ) {
                Console.WriteLine( TESTCASE + "i=" + i + "  =>  " + rnd.Next() );
            }

            Console.WriteLine( TESTCASE + TEST_PASSED );
        }
    }

}
