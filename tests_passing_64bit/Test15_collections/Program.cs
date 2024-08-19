using System;
﻿using System.Collections.Generic;
using System.Linq;
﻿using RNGen;

namespace Test15 {

    public class Program {

        private const string TESTCASE = "TESTCASE15 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

        private static RandomNumberGenerator rnd = new RandomNumberGenerator( 1234 );

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test generic-collections use." );

            const int default_wordCount = 20;
            int wordCount = default_wordCount;

            if ( args.Length > 0 ) {
                if ( int.TryParse( args[0], out wordCount ) ) {
                    Console.WriteLine( TESTCASE + "using wordCount from commandline = " + wordCount );
                } else {
                    wordCount = default_wordCount;
                    Console.WriteLine( TESTCASE + "commandline PARSE ERROR, using default wordCount = " + wordCount );
                }
            } else {
                Console.WriteLine( TESTCASE + "using default wordCount = " + wordCount );
            }

            // generate random words to a list.
            // also push initial positions of words into a dictionary.

            List<string> words = new List<string>();
            Dictionary<string,int> dict = new Dictionary<string,int>();

            for ( int i = 0; i < wordCount; i++ ) {
                string word = GenerateRandomWord();
                Console.WriteLine( TESTCASE + "gen " + i + " :    " + word );
                words.Add( word );
                dict.Add( word, i );
            }

            // now sort the wordlist.

            words = words.OrderBy(p => p).ToList();

            Console.WriteLine( "WORDS IN ALPHABETICAL ORDER:" );

            for ( int i = 0; i < words.Count; i++ ) {
                string word = words[i];
                int origIndex = dict[word];
                Console.WriteLine( TESTCASE + "i = " + i + "   " + word + "   original index = " + origIndex );
            }

            Console.WriteLine( TESTCASE + TEST_PASSED );
        }

        private static string charSet = "abcdefghijklmnopqrstuvwxyz";

        static string GenerateRandomWord() {
            int wordLength = rnd.Next( 5, 16 );
            string word = "";
            for ( int i = 0; i < wordLength; i++ ) {
                int nextChar = rnd.Next( 0, charSet.Length );
                word += charSet[nextChar];
            }
            return word;
        }
    }

}
