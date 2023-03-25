
#include <stdio.h>

void test1( void ) {
	printf( "libpinvoketest.so :: test1\n" );
}

int test2( int a, int b ) {
	int c = a + b;
	printf( "libpinvoketest.so :: test2 :: a=%d b=%d c=a+b=%d\n", a, b, c );
	return c;
}

static const char test3response[] = "response text from test3.";

const char * test3( const char * message ) {
	printf( "libpinvoketest.so :: stringTest1 :: %#llx\n", (void *) message );
	printf( "libpinvoketest.so :: stringTest1 :: '%s'\n", message );
	return test3response;
}

float test4( float x ) {
	float y = x + 1.1f;
	printf( "libpinvoketest.so :: test4 :: x=%f y=x+1.1=%f\n", x, y );
	return y;
}

double test5( double x ) {
	double y = x + 2.2;
	printf( "libpinvoketest.so :: test5 :: x=%f y=x+2.2=%f\n", x, y );
	return y;
}

