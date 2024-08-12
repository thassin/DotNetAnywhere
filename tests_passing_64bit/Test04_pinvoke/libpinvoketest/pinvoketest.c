
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// uncomment to enable debug-output.
// => output appears in different order at DNA vs mono.
//#define VERBOSE

void test1( void ) {
#ifdef VERBOSE
	printf( "libpinvoketest.so :: test1\n" );
#endif // VERBOSE
}

int test2( int a, int b ) {
	int c = a + b;
#ifdef VERBOSE
	printf( "libpinvoketest.so :: test2 :: a=%d b=%d c=a+b=%d\n", a, b, c );
#endif // VERBOSE
	return c;
}

static const char test3response[] = "response text from test3.";

const char * test3( const char * message ) {
#ifdef VERBOSE
	printf( "libpinvoketest.so :: stringTest1 :: %#llx\n", (void *) message );
	printf( "libpinvoketest.so :: stringTest1 :: '%s'\n", message );
#endif // VERBOSE

	// allocate memory for the response using malloc(), the runtime should call free() on it.
	// => that's how it goes with mono.

	char * buffer = malloc( strlen( test3response ) );
	strcpy( buffer, test3response );

	return buffer;
}

float test4( float x ) {
	float y = x + 1.1f;
#ifdef VERBOSE
	printf( "libpinvoketest.so :: test4 :: x=%f y=x+1.1=%f\n", x, y );
#endif // VERBOSE
	return y;
}

double test5( double x ) {
	double y = x + 2.2;
#ifdef VERBOSE
	printf( "libpinvoketest.so :: test5 :: x=%f y=x+2.2=%f\n", x, y );
#endif // VERBOSE
	return y;
}

