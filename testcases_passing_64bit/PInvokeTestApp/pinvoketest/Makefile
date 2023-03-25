
AR =		ar
CC =		gcc

CFLAGS=		-Wall -g -fPIC

LDFLAGS=	
LDLIBS=		

SOURCES=	pinvoketest.c

OBJECTS=	$(SOURCES:.c=.o)

RESULT=		libpinvoketest.so

all:		$(OBJECTS) $(RESULT)

$(RESULT):	$(OBJECTS)
		$(CC) -shared -o $(RESULT) $(OBJECTS) $(LDLIBS)

.c.o:
		$(CC) -c $(CFLAGS) $< -o $@

clean:
		rm -f *.o
		rm -f $(RESULT)

distclean:	clean
		rm -f Makefile

