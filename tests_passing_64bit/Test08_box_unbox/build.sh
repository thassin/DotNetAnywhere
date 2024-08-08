#! /bin/bash

mcs \
/nostdlib /noconfig /out:Test08_box_unbox.exe \
/reference:../../tests_BIN/corlib.dll Program.cs

echo
echo copying Test08_box_unbox.exe to tests_BIN
echo

cp Test08_box_unbox.exe ../../tests_BIN

