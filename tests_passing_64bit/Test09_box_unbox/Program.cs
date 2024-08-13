using System;

namespace Test09 {

    public class Program {

        private const string TESTCASE = "TESTCASE09 : ";

        private const string TEST_PASSED = "test_passed";
        private const string TEST_FAILED = "test_FAILED";

	private static int test_count = 0;
	private static int ok_count = 0;

        static void Main(string[] args) {
            Console.WriteLine( TESTCASE + "test box and unbox." );

            int intValue = 5;

            long longValue = 10;

            float floatValue = 2.5f;

            double doubleValue = 7.5;

            bool boolValue = true;

            DateTime dtValue = DateTime.Today;

            int? intValue1 = intValue;
            int? intValue2 = null;

            long? longValue1 = longValue;
            long? longValue2 = null;

            float? floatValue1 = floatValue;
            float? floatValue2 = null;

            double? doubleValue1 = doubleValue;
            double? doubleValue2 = null;

            bool? boolValue1 = boolValue;
            bool? boolValue2 = null;

            DateTime? dtValue1 = dtValue;
            DateTime? dtValue2 = null;

            // test using valuetypes.

            Test1( (object)intValue );
            Console.WriteLine( "ok_count = " + ok_count );

            Test2( (object)longValue );
            Console.WriteLine( "ok_count = " + ok_count );

            Test3( (object)floatValue );
            Console.WriteLine( "ok_count = " + ok_count );

            Test4( (object)doubleValue );
            Console.WriteLine( "ok_count = " + ok_count );

            Test5( (object)boolValue );
            Console.WriteLine( "ok_count = " + ok_count );

            Test6( (object)dtValue );
            Console.WriteLine( "ok_count = " + ok_count );

            // test using nullables.

            Test11( (object)intValue1, (object)intValue2 );
            Console.WriteLine( "ok_count = " + ok_count );

            Test12( (object)longValue1, (object)longValue2 );
            Console.WriteLine( "ok_count = " + ok_count );

            Test13( (object)floatValue1, (object)floatValue2 );
            Console.WriteLine( "ok_count = " + ok_count );

            Test14( (object)doubleValue1, (object)doubleValue2 );
            Console.WriteLine( "ok_count = " + ok_count );

            Test15( (object)boolValue1, (object)boolValue2 );
            Console.WriteLine( "ok_count = " + ok_count );

            Test16( (object)dtValue1, (object)dtValue2 );
            Console.WriteLine( "ok_count = " + ok_count );

            string result = TEST_FAILED;
            if ( ok_count == test_count ) result = TEST_PASSED;

            Console.WriteLine( TESTCASE + result );
        }

	static void Test1( object o ) {
            test_count++;
	    int i = (int)o;
            Console.WriteLine( "int-value = " + i );
            if ( i == 5 ) ok_count++;
	}

	static void Test2( object o ) {
            test_count++;
	    long l = (long)o;
            Console.WriteLine( "long-value = " + l );
            if ( l == 10 ) ok_count++;
	}

	static void Test3( object o ) {
            test_count++;
            
	    //float f = (long)o; // 20240809 noticed a bug/typo here, which DNA runtime does not check.
	    // => TODO no such check is implemented, should throw an exception in this case.
	    
	    float f = (float)o;
            Console.WriteLine( "float-value = " + f );
            if ( f == 2.5f ) ok_count++;
	}

	static void Test4( object o ) {
            test_count++;
	    double d = (double)o;
            Console.WriteLine( "double-value = " + d );
            if ( d == 7.5f ) ok_count++;
	}

	static void Test5( object o ) {
            test_count++;
	    bool b = (bool)o;
            Console.WriteLine( "bool-value = " + b );
           if ( b == true ) ok_count++;
	}

	static void Test6( object o ) {
            test_count++;
	    DateTime dt = (DateTime)o;
            Console.WriteLine( "DateTime-value = " + dt );
           if ( dt == DateTime.Today ) ok_count++;
	}

	static void Test11( object o1, object o2 ) {
            test_count++;
	    int? i1 = (int?)o1;
	    int? i2 = (int?)o2;
            if ( i1.HasValue == false ) return;
            if ( i2.HasValue == true ) return;
            Console.WriteLine( "nullable int-value = " + i1.Value );
            if ( i1.Value == 5 ) ok_count++;
	}

	static void Test12( object o1, object o2 ) {
            test_count++;
	    long? l1 = (long?)o1;
	    long? l2 = (long?)o2;
            if ( l1.HasValue == false ) return;
            if ( l2.HasValue == true ) return;
            Console.WriteLine( "nullable long-value = " + l1.Value );
            if ( l1.Value == 10 ) ok_count++;
	}

	static void Test13( object o1, object o2 ) {
            test_count++;
	    float? f1 = (float?)o1;
	    float? f2 = (float?)o2;
            if ( f1.HasValue == false ) return;
            if ( f2.HasValue == true ) return;
            Console.WriteLine( "nullable float-value = " + f1.Value );
            if ( f1.Value == 2.5f ) ok_count++;
	}

	static void Test14( object o1, object o2 ) {
            test_count++;
	    double? d1 = (double?)o1;
	    double? d2 = (double?)o2;
            if ( d1.HasValue == false ) return;
            if ( d2.HasValue == true ) return;
            Console.WriteLine( "nullable double-value = " + d1.Value );
            if ( d1.Value == 7.5f ) ok_count++;
	}

	static void Test15( object o1, object o2 ) {
            test_count++;
	    bool? b1 = (bool?)o1;
	    bool? b2 = (bool?)o2;
            if ( b1.HasValue == false ) return;
            if ( b2.HasValue == true ) return;
            Console.WriteLine( "nullable bool-value = " + b1.Value );
            if ( b1.Value == true ) ok_count++;
	}

	static void Test16( object o1, object o2 ) {
            test_count++;
	    DateTime? dt1 = (DateTime?)o1;
	    DateTime? dt2 = (DateTime?)o2;
            if ( dt1.HasValue == false ) return;
            if ( dt2.HasValue == true ) return;
            Console.WriteLine( "nullable DateTime-value = " + dt1.Value );
            if ( dt1.Value == DateTime.Today ) ok_count++;
	}
    }

}
