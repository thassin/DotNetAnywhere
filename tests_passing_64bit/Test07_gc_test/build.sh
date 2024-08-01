#! /bin/bash

mcs \
/nostdlib /noconfig /out:Test07_gc_test.exe \
/reference:../../tests_BIN/corlib.dll Program.cs

echo
echo copying Test07_gc_test.exe to tests_BIN
echo

cp Test07_gc_test.exe ../../tests_BIN

