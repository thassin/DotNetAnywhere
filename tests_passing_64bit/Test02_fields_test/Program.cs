using System;

namespace Test02 {

    public class TestClass {

        private int intField;
        private long longField;
        private DateTime dtField;

        private static int intStaticField;
        private static long longStaticField;
        private static DateTime dtStaticField;

        public int Score { get; private set; }

        public TestClass() {
            Score = 100;
        }

        public void Test1() {
            intField = 32;
            Score += 1;

            longField = 64;
            Score += 1;

            dtField = DateTime.Today;
            Score += 1;
        }

        public void Test2() {
            Console.WriteLine( "intField = " + intField );
            if ( intField == 32 ) Score += 1;

            Console.WriteLine( "longField = " + longField );
            if ( longField == 64 ) Score += 1;

            Console.WriteLine( "dtField = " + dtField );
            if ( dtField == DateTime.Today ) Score += 1;
        }


        public void Test3() {
            intStaticField = 3232;
            Score += 1;

            longStaticField = 6464;
            Score += 1;

            dtStaticField = DateTime.Today.AddDays( 7 );
            Score += 1;
        }

        public void Test4() {
            Console.WriteLine( "intStaticField = " + intStaticField );
            if ( intStaticField == 3232 ) Score += 1;

            Console.WriteLine( "longStaticField = " + longStaticField );
            if ( longStaticField == 6464 ) Score += 1;

            Console.WriteLine( "dtStaticField = " + dtStaticField );
            if ( dtStaticField == DateTime.Today.AddDays( 7 ) ) Score += 1;
        }
    }

    public class Program {

        private const string TESTCASE = "TESTCASE02 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test field and static-field usage." );

            TestClass t = new TestClass();

            t.Test1();
            t.Test2();

            t.Test3();
            t.Test4();

            if ( t.Score == 112 ) Console.WriteLine( TESTCASE + TEST_PASSED );
            else Console.WriteLine( TESTCASE + TEST_FAILED );
        }
    }

}
