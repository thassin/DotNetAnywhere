using System;

namespace Test03 {

    public class Program {

        private const string TESTCASE = "TESTCASE03 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test looping, array-usage, methodcall." );

            const int sz = 100;

            int[] arr = new int[sz];
            for ( int i = 0; i < sz; i++ ) {
                arr[i] = i;
            }

            int sum = 0;

// FIXME there is no conversion like this?!? cast from int to long:
// 0xD4 	conv.ovf.i 	Convert to a native int (on the stack as native int) and throw an exception on overflow.
            //for ( long x = 0; x < (long) sz; x++ ) {
            for ( int x = 0; x < sz; x++ ) {
                sum += arr[x];
            }
            
            // TODO test separately: int,float,DateTime arrays at least.
            // TODO test separately: int,float,DateTime arrays at least.
            // TODO test separately: int,float,DateTime arrays at least.

            Program p = new Program();
            p.FinalReport( sum );

            if ( sum == 4950 ) Console.WriteLine( TESTCASE + TEST_PASSED );
            else Console.WriteLine( TESTCASE + TEST_FAILED );
        }

        void FinalReport( int x ) {
            Console.WriteLine( TESTCASE + "sum = " + x );
        }
    }

}
