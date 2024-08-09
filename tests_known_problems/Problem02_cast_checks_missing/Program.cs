using System;

namespace Problem02 {

    public class Program {

        private const string TESTCASE = "Problem02 / TESTCASE08 modified : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

	private static int test_count = 0;
	private static int ok_count = 0;

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test box and unbox." );

            int intValue = 5;

            Test1( (object)intValue );

            string result = TEST_FAILED;
            if ( ok_count == test_count ) result = TEST_PASSED;

            Console.WriteLine( TESTCASE + result );
        }

	static void Test1( object o ) {
            test_count++;
	    long l = (long)o; // cast here to long, while the original type was int.
	    
	    // mono / correct operation : InvalidCastException is thrown.
	    // DNA : error is not detected, wrong data is read and stack contents is corrupted.
	    
            Console.WriteLine( "long-value = " + l );
            if ( l == 5 ) ok_count++;
	}
    }

}
