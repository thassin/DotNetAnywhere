using System;
﻿using System.Collections.Generic;
using System.Linq;
using RNGen;

namespace Test08 {

    public class Program {

        private const string TESTCASE = "TESTCASE08 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        private static RandomNumberGenerator rnd;

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test garbage-collection." );

            const int randomSeed_default = 1111;

            int randomSeed = randomSeed_default;
            if ( args.Length > 0 ) {
                if ( int.TryParse( args[0], out randomSeed ) == false ) {
                    randomSeed = 1111;
                }
            }

            Console.WriteLine( TESTCASE + "using randomSeed__ = " + randomSeed );
            rnd = new RandomNumberGenerator( randomSeed );

            int count = 5;		// tämä OK, alkuperäinen testi. molemmat ok.
            int increment = 1;
            int loops = 50;

            // retain some of the data.
            List<string> specialWords = new List<string>();

            for ( int i = 0; i < loops; i++ ) {
                Console.WriteLine( TESTCASE + "LOOP " + i + " begin" );

                // allocate some memory.
                List<string> list = new List<string>();
                for ( int x = 0; x < count; x++ ) {
                    string word = GenerateRandomWord(out int vocals,out int consonants);
                    list.Add( word );

                    // retain some of the data.
                    if ( vocals == consonants ) {
                        specialWords.Add( word );
                    }
                }

                // now discard the memory...
                list = null;

                // ...and then request GC.
                Console.WriteLine( TESTCASE + "LOOP " + i + " garbage-collect" );
                GC.Collect();

                Console.WriteLine( TESTCASE + "LOOP " + i + " complete" );

                count += increment;
            }

            Console.WriteLine( TESTCASE + "print retained words:" );

            for ( int i = 0; i < specialWords.Count; i++ ) {
                Console.WriteLine( TESTCASE + "WORD " + i + " : " + specialWords[i] );
            }

            Console.WriteLine( TESTCASE + TEST_PASSED );
        }

        private static string charSet = "abcdefghijklmnopqrstuvwxyz";

        private static string vocalChars = "aeiouy";

        static string GenerateRandomWord(out int vocals,out int consonants) {
            int wordLength = rnd.Next( 5, 16 );
            string word = "";
            vocals = 0;
            consonants = 0;
            for ( int i = 0; i < wordLength; i++ ) {
                int nextCharIndex = rnd.Next( 0, charSet.Length );
                char nextChar = charSet[nextCharIndex];
                if ( vocalChars.Contains( nextChar ) ) vocals++;
                else consonants++;
                word += nextChar;
            }
            return word;
        }
    }

}
