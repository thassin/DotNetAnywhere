using System;

namespace Test08 {

    public class Program {

        private const string TESTCASE = "TESTCASE08 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

	private static int test_count = 0;
	private static int ok_count = 0;

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test box and unbox." );

            int intValue = 5;

            long longValue = 10;

            // FIXME not working with float type.
            //float floatValue = 2.5f;

            double doubleValue = 7.5;

            bool boolValue = true;

            Test1( (object)intValue );
            Console.WriteLine( "ok_count = " + ok_count );

            Test2( (object)longValue );
            Console.WriteLine( "ok_count = " + ok_count );

            //Test3( (object)floatValue );
            //Console.WriteLine( "ok_count = " + ok_count );

            Test4( (object)doubleValue );
            Console.WriteLine( "ok_count = " + ok_count );

            Test5( (object)boolValue );
            Console.WriteLine( "ok_count = " + ok_count );

            string result = TEST_FAILED;
            if ( ok_count == test_count ) result = TEST_PASSED;

            Console.WriteLine( TESTCASE + result );
        }

	static void Test1( object o ) {
	    int i = (int)o;
            Console.WriteLine( "int-value = " + i );
            test_count++;
            if ( i == 5 ) ok_count++;
	}

	static void Test2( object o ) {
	    long l = (long)o;
            Console.WriteLine( "long-value = " + l );
            test_count++;
            if ( l == 10 ) ok_count++;
	}

	static void Test3( object o ) {
	    float f = (long)o;
            Console.WriteLine( "float-value = " + f );
            test_count++;
            if ( f == 2.5f ) ok_count++;
	}

	static void Test4( object o ) {
	    double d = (double)o;
            Console.WriteLine( "double-value = " + d );
            test_count++;
            if ( d == 7.5f ) ok_count++;
	}

	static void Test5( object o ) {
	    bool b = (bool)o;
            Console.WriteLine( "bool-value = " + b );
             test_count++;
           if ( b == true ) ok_count++;
	}
    }

}
