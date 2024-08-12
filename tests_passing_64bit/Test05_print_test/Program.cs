using System;

namespace Test05 {

    public class Program {

        private const string TESTCASE = "TESTCASE05 : ";

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

            //DateTime dt = DateTime.UtcNow; // 20240717 TODO "Now" not implemented in DNA.
            //DateTime dt = DateTime.Today.AddHours( 12 ).AddMinutes( 30 ); // write fixed time.
            DateTime dt = DateTime.Today;
            dt = dt.AddHours( 12 ); // FIXME something goes wrong here.
            //dt = dt.AddMinutes( 30 ); // FIXME something goes wrong here.
            
            Console.WriteLine( TESTCASE + "DateTime default : " + dt );
            Console.WriteLine( TESTCASE + "DateTime formatted : " + dt.ToString( "yyyy-MM-dd HH:mm:ss" ) );

            Console.WriteLine( TESTCASE + TEST_PASSED );
        }
    }

}
