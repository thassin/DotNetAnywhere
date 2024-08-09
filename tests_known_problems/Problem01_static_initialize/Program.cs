using System;
﻿
namespace Problem01 {

    public class Program {

        private const string TESTCASE = "Problem01 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        private static Random rnd = null; // FIXME this is not working.
        //private static Random rnd; // works OK (without default value initialization).

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test static initialization." );

            const int randomSeed = 1111;
            Console.WriteLine( TESTCASE + "using randomSeed = " + randomSeed );

            // PROBLEM : if "rnd" is assigned null (or any?) value on initialization,
            // then this later initialization has no effect at all.
            rnd = new Random( randomSeed );

            if( rnd == null ) Console.WriteLine( TESTCASE + "WARNING rnd is null" );

            Console.WriteLine( TESTCASE + "now request new random number." );
            int number = rnd.Next();
            Console.WriteLine( TESTCASE + "got new random number: " + number );

            Console.WriteLine( TESTCASE + TEST_PASSED );
        }
    }

}
