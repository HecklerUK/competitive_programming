#!/bin/bash

#codetest 128a, run abc128a.cpp
testcode=./abc$1.cpp
testtxt=../test.txt

echo ${testcode}
echo "================"
g++ -g ${testcode}
./a.out < ${testtxt}
echo "================"
