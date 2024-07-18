#! /bin/bash

mcs \
/nostdlib /noconfig /out:Test02_array_sum.exe \
/reference:../../tests_BIN/corlib.dll Program.cs

echo
echo copying Test02_array_sum.exe to tests_BIN
echo

cp Test02_array_sum.exe ../../tests_BIN

