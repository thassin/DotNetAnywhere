#! /bin/bash

mcs \
/nostdlib /noconfig /out:Test01_print_args.exe \
/reference:../../tests_BIN/corlib.dll Program.cs

echo
echo copying Test01_print_args.exe to tests_BIN
echo

cp Test01_print_args.exe ../../tests_BIN

