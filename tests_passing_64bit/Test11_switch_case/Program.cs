using System;

namespace Test11 {

    public class Program {

        private const string TESTCASE = "TESTCASE11 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        private static int count1 = 0;
        private static int count2 = 0;
        private static int count3 = 0;

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test switch-case." );
            
            Test( 5 );
            Test( 10 );
            Test( 15 );
            Test( 20 );
            Test( 25 );

            Console.WriteLine( "count1 = " + count1 );
            Console.WriteLine( "count2 = " + count2 );

            Test( 100 );
            Test( 102 );
            Test( 104 );

            Test( 101 );
            Test( 103 );
            Test( 105 );
            
            string result = TEST_FAILED;
            if ( count1 == 2 && count2 == 3 && count3 == 6 ) result = TEST_PASSED;

            Console.WriteLine( TESTCASE + result );
        }

        static void Test( int i ) {
            switch ( i ) {
                case 10:
                Console.WriteLine("case 10 detected");
                count1++;
                break;

                case 20:
                Console.WriteLine("case 20 detected");
                count1++;
                break;

                // if there are not enough case statements, the compiler may
                // use if-else type commands instead of using switch command.

                case 100:
                Console.WriteLine("case 100 detected");
                count3++;
                break;
                
                case 101:
                Console.WriteLine("case 101 detected");
                count3++;
                break;
                
                // mcs compiler if-else vs switch limit seems to be here.
                
                case 102:
                Console.WriteLine("case 102 detected");
                count3++;
                break;
                
                case 103:
                Console.WriteLine("case 103 detected");
                count3++;
                break;
                
                case 104:
                Console.WriteLine("case 104 detected");
                count3++;
                break;
                
                case 105:
                Console.WriteLine("case 105 detected");
                count3++;
                break;

                default:
                Console.WriteLine("default case detected");
                count2++;
                break;
            }
        }
    }

}
