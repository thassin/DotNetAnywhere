using System;
using System.Runtime.InteropServices;

namespace Test03 {

    public class Program {

        private const string TESTCASE = "TESTCASE03 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        private const string nativeLibName = "libpinvoketest";

        [DllImport(nativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void test1();

        [DllImport(nativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public static extern int test2(int a, int b);

        [DllImport(nativeLibName, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public static extern string test3(string message);

        [DllImport(nativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public static extern float test4(float x);

        [DllImport(nativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public static extern double test5(double x);

        public static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test pinvoke calls." );

            test1();

            int test2result = test2( 3, 7 );
            Console.WriteLine( TESTCASE + "test2 return value = " + test2result );

            string msg = "this is a test string!";
            string test3result = test3( msg );
            Console.WriteLine( TESTCASE + "test3 return value = '" + test3result + "'" );

            float test4result = test4( 1.234f );
            Console.WriteLine( TESTCASE + "test4 return value = " + test4result );

            double test5result = test5( 23.45 );
            Console.WriteLine( TESTCASE + "test5 return value = " + test5result );

            Console.WriteLine( TESTCASE + TEST_PASSED );
        }
    }

}
