#! /bin/bash

mcs \
/nostdlib /noconfig /out:Test05_random_test.exe \
/reference:../../tests_BIN/corlib.dll Program.cs

echo
echo copying Test05_random_test.exe to tests_BIN
echo

cp Test05_random_test.exe ../../tests_BIN

