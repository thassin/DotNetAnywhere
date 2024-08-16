using System;
﻿﻿using System.Collections.Generic;
﻿
namespace Test13 {

    public class Program {

        private const string TESTCASE = "TESTCASE13 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test yield use." );

            // https://stackoverflow.com/questions/39476/what-is-the-yield-keyword-used-for-in-c

            int sum = 0;
            foreach(int i in Numbers()) {
                Console.WriteLine( TESTCASE + "got number " + i );
                sum += i;
            }            

            string result = TEST_FAILED;
            if ( sum == 255 ) result = TEST_PASSED;

            Console.WriteLine( TESTCASE + result );
        }

        static IEnumerable<int> Numbers() {
            yield return 1;
            yield return 2;
            yield return 4;
            yield return 8;
            yield return 16;
            yield return 32;
            yield return 64;
            yield return 128;
        }        
    }

}
