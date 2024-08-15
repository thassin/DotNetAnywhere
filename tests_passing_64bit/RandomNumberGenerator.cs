using System;

namespace RNGen {

    public class RandomNumberGenerator {

        private const long maxResult = 0x7fffffff; // result bit mask.

        private const long m = 0x7fffffff; // see glibc generator
        private const long a = 1103515245;
        private const long c = 12345;

        private long prev;

        public RandomNumberGenerator() {
            //prev = (long)Guid.NewGuid().GetHashCode(); TODO Guid and GetHashCode() both missing?
            prev = (long)DateTime.UtcNow.Millisecond; // use DateTime to get a random seed number.
            prev &= maxResult;
        }

        public RandomNumberGenerator( int seed ) {
            prev = (long)seed;
            prev &= maxResult;
        }

        // System.Random is implemented differently in DNA vs mono, yielding different result sequences.
        // => this RandomNumberGenerator class yields identical results in DNA vs mono, using the same seed.

        public int Next() {

            // https://en.wikipedia.org/wiki/Linear_congruential_generator

            long next = unchecked( ( a * prev ) + c ) % m;
            int result = (int)next;
            prev = next;

            return result;
        }

        public int Next( int maxValue ) {
            return Next( 0, maxValue );
        }

        public int Next( int minValue, int maxValue ) {
            int range = maxValue - minValue;
            return minValue + ( Next() % range );
        }
    }

}
