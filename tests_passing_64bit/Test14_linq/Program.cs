using System;
﻿using System.Collections.Generic;
using System.Linq;

namespace Test14 {

    public class Program {

        private const string TESTCASE = "TESTCASE14 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test linq use." );
            
            List<int> data1 = new List<int> {
            	30,
            	10,
            	20
            };
            
            int findVal = data1.Single(x => x == 10);
            Console.WriteLine( "FIND RESULT = " + findVal );
            
            List<int> data2 = data1.OrderBy(p => p).ToList();

            Console.WriteLine( "data1.count=" + data1.Count );
            for ( int i = 0; i < data1.Count; i++ ) {
                Console.WriteLine( TESTCASE + "    data1 at i = " + i + " : " + data1[i] );
            }
            
            Console.WriteLine( "data2.count=" + data2.Count );
            for ( int i = 0; i < data2.Count; i++ ) {
                Console.WriteLine( TESTCASE + "    data2 at i = " + i + " : " + data2[i] );
            }

            Console.WriteLine( TESTCASE + TEST_PASSED );
        }
    }

}
