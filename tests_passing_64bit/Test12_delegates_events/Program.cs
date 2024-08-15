using System;

namespace Test12 {

    public delegate int TestFunction( int x, bool b );

    public class TestClass1 {
        public static int TestFuncImpl1( int x, bool incrementBy2 ) {
            Console.WriteLine( "TestFuncImpl1() called: x=" + x + " incrementBy2=" + incrementBy2 );
            
            if ( incrementBy2 ) x += 2;
            else x++;
            
            return x;
        }
    }

    public class TestClass2 {
        public event TestFunction EventHandler;
        public int LaunchEvent() {
            if ( EventHandler != null ) {
                return EventHandler( 10, false );
            } else {
                return -1;
            }
        }
    }

    public class Program {

        private const string TESTCASE = "TESTCASE12 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        private static int score = 0;

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test delegates and events." );

            int tmp;

            // test delegate.

            TestFunction del = TestClass1.TestFuncImpl1;

            tmp = del( 5, true );
            Console.WriteLine( TESTCASE + "delegate call returned result: " + tmp );
            if ( tmp == 7 ) score++;

            // test event.

            TestClass2 tc2 = new TestClass2();
            tc2.EventHandler += TestClass1.TestFuncImpl1;

            tmp = tc2.LaunchEvent();
            Console.WriteLine( TESTCASE + "event-launch-1 returned result: " + tmp );
            if ( tmp == 11 ) score++;

            /* this is not working with DNA?
            tc2.EventHandler -= TestClass1.TestFuncImpl1;
            tmp = tc2.LaunchEvent();
            Console.WriteLine( TESTCASE + "event-launch-2 returned result: " + tmp );
            if ( tmp == -1 ) score++; */

            string result = TEST_FAILED;
            if ( score == 2 ) result = TEST_PASSED;

            Console.WriteLine( TESTCASE + result );
        }
    }

}
