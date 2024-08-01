#! /bin/bash

mcs \
/nostdlib /noconfig /out:Test06_methodcalls_test.exe \
/reference:../../tests_BIN/corlib.dll Program.cs

echo
echo copying Test06_methodcalls_test.exe to tests_BIN
echo

cp Test06_methodcalls_test.exe ../../tests_BIN

