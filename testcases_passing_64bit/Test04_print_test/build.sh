#! /bin/bash

mcs \
/nostdlib /noconfig /out:Test04_print_test.exe \
/reference:../../tests_BIN/corlib.dll Program.cs

echo
echo copying Test04_print_test.exe to tests_BIN
echo

cp Test04_print_test.exe ../../tests_BIN

