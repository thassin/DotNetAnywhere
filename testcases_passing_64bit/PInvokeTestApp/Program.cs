using System;
using System.Runtime.InteropServices;

namespace PInvokeTestApp
{
    class MainClass
    {
        private const string nativeLibName = "pinvoketest";

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

        public static void Main(string[] args)
        {
            test1();

            int test2result = test2( 3, 7 );
            Console.WriteLine("test2 return value = " + test2result);

            string msg = "this is a test string!";
            string test3result = test3( msg );
            Console.WriteLine("test3 return value = '" + test3result + "'");

            float test4result = test4( 1.234f );
            Console.WriteLine("test4 return value = " + test4result);

            double test5result = test5( 23.45 );
            Console.WriteLine("test5 return value = " + test5result);
        }
    }
}
