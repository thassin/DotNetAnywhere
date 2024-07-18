#! /bin/bash

echo building the test-library.
bash -c "cd libpinvoketest && make"

mcs \
/nostdlib /noconfig /out:Test03_pinvoke.exe \
/reference:../../tests_BIN/corlib.dll Program.cs

echo
echo copying Test03_pinvoke.exe + library to tests_BIN
echo

cp Test03_pinvoke.exe ../../tests_BIN
cp libpinvoketest/libpinvoketest.so ../../tests_BIN

