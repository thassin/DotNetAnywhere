using System;

namespace Test10 {

    public class Program {

        private const string TESTCASE = "TESTCASE10 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

	private static int fail_count = 0;

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test casts and conversions." );

            // TODO "short" type not used in DNA, is converted to int?

            Test1();
            Test2();
            Test3();
            Test4();

            string result = TEST_FAILED;
            if ( fail_count == 0 ) result = TEST_PASSED;

            Console.WriteLine( TESTCASE + result );
        }

	static void Test1() {
            char val1 = (char)100;
            int val2 = (int)val1;
            long val3a = (long)val1;
            long val3b = (long)val2;

            if ( val2 != 100 ) fail_count++;
            if ( val3a != 100 ) fail_count++;
            if ( val3b != 100 ) fail_count++;

            Console.WriteLine( "Test1() complete: fail_count = " + fail_count );
	}

	static void Test2() {
            long val1 = 123;
            int val2 = (int)val1;
            char val3a = (char)val1;
            char val3b = (char)val2;

            if ( val2 != 123 ) fail_count++;
            if ( val3a != 123 ) fail_count++;
            if ( val3b != 123 ) fail_count++;

            Console.WriteLine( "Test2() complete: fail_count = " + fail_count );
	}

	static void Test3() {
            float val1 = 1.23f;
            double val2 = (double)val1;

            if ( Math.Abs( val2 - 1.23 ) > 0.000001 ) fail_count++;

            //Console.WriteLine( "Test3() diff = " + Math.Abs( val2 - 1.23 ) );
            Console.WriteLine( "Test3() complete: fail_count = " + fail_count );
	}

	static void Test4() {
            double val1 = 2.34;
            float val2 = (float)val1;

            if ( Math.Abs( val2 - 2.34 ) > 0.000001 ) fail_count++;

            //Console.WriteLine( "Test4() diff = " + Math.Abs( val2 - 2.34 ) );
            Console.WriteLine( "Test4() complete: fail_count = " + fail_count );
	}
   }

}
