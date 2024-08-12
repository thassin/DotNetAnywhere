#! /bin/bash

TESTNAME="Test04_pinvoke"

CORLIBDLL="../../tests_BIN/corlib.dll"
TESTDIR="../../tests_BIN"

## build the test library.

LIBFILE="libpinvoketest/libpinvoketest.so"

echo building the test-library.
bash -c "cd libpinvoketest && make"

if [ -f $LIBFILE ];
then

    echo
    echo copying $LIBFILE to tests_BIN
    echo
    cp $LIBFILE $TESTDIR

else

    echo
    echo ERROR build failed: $LIBFILE
    echo

fi

bash -c "cd libpinvoketest && make clean"

## build DNA binary.

EXENAME="${TESTNAME}_dna.exe"

rm -f $EXENAME

mcs /nostdlib /noconfig /out:$EXENAME \
    /reference:$CORLIBDLL \
    Program.cs

if [ -f $EXENAME ];
then

    echo
    echo copying $EXENAME to tests_BIN
    echo
    cp $EXENAME $TESTDIR
    rm -f $EXENAME

else

    echo
    echo ERROR build failed: $EXENAME
    echo

fi

## build MONO binary.

EXENAME="${TESTNAME}_mono.exe"

rm -f $EXENAME

mcs /out:$EXENAME \
    Program.cs

if [ -f $EXENAME ];
then

    echo
    echo copying $EXENAME to tests_BIN
    echo
    cp $EXENAME $TESTDIR
    rm -f $EXENAME

else

    echo
    echo ERROR build failed: $EXENAME
    echo

fi

