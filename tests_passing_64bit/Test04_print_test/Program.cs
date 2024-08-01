using System;

namespace Test04 {

    public class Program {

        private const string TESTCASE = "TESTCASE04 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test printing various datatypes." );

            int i = 42;
            Console.WriteLine( TESTCASE + "int : " + i );

            string s = "teststring!";
            Console.WriteLine( TESTCASE + "string : " + s );

            bool b = true;
            Console.WriteLine( TESTCASE + "bool : " + b );

            float f = 3.141592f;
            Console.WriteLine( TESTCASE + "float : " + f );

            double d = 3.141592 * 2;
            Console.WriteLine( TESTCASE + "double : " + d );

            TimeSpan ts = new TimeSpan( 1234567890 );
            Console.WriteLine( TESTCASE + "TimeSpan milliseconds = " + ts.TotalMilliseconds );

            DateTime dt = DateTime.UtcNow; // 20240717 TODO "Now" not implemented in DNA.
            Console.WriteLine( TESTCASE + "DateTime default : " + dt );
            Console.WriteLine( TESTCASE + "DateTime formatted : " + dt.ToString( "yyyy-MM-dd HH:mm:ss" ) );

            Console.WriteLine( TESTCASE + TEST_PASSED );
        }
    }

}
