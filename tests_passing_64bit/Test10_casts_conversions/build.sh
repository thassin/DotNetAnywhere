#! /bin/bash

TESTNAME="Test10_casts_conversions"

CORLIBDLL="../../tests_BIN/corlib.dll"
TESTDIR="../../tests_BIN"

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

