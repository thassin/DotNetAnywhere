
CC =		gcc

CFLAGS=		-Wno-pointer-sign -Os -I. -Wall -g \
		-DENABLE_JITOPS_TYPEINFO \
		-DENABLE_STACKITEMS_TYPEINFO

LDFLAGS=	-ldl -lm

SOURCES=	CLIFile.c \
		Delegate.c \
		dna.c \
		Finalizer.c \
		Generics.c \
		Heap.c \
		InternalCall.c \
		JIT.c \
		JIT_Execute.c \
		JIT_OpCodeNames.c \
		JSInterop.c \
		MetaData.c \
		MetaData_Fill.c \
		MetaData_Search.c \
		MethodState.c \
		PInvoke.c \
		Reflection.c \
		RVA.c \
		Sys.c \
		System.Array.c \
		System.Char.c \
		System.Console.c \
		System.DateTime.c \
		System.Diagnostics.Debugger.c \
		System.Enum.c \
		System.Environment.c \
		System.GC.c \
		System.IO.FileInternal.c \
		System.Math.c \
		System.Net.Dns.c \
		System.Net.Sockets.Socket.c \
		System.Object.c \
		System.Runtime.CompilerServices.RuntimeHelpers.c \
		System.RuntimeType.c \
		System.String.c \
		System.Threading.Interlocked.c \
		System.Threading.Monitor.c \
		System.Threading.Thread.c \
		System.Type.c \
		System.ValueType.c \
		System.WeakReference.c \
		Thread.c \
		Type.c

OBJECTS=	$(SOURCES:.c=.o)

RESULT=		dna32

all:		$(SOURCES) $(RESULT)

$(RESULT):	$(OBJECTS)
		$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.c.o:
		$(CC) -c $(CFLAGS) $< -o $@

clean:
		rm -f *.o $(RESULT)

