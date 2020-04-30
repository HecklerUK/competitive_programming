#!/bin/bash

#codetest 128a, run abc128a.cpp
testcode=./arc$1.cpp
testtxt=../test.txt

echo ${testcode}
echo "================"
g++ ${testcode}
./a.out < ${testtxt}
echo "================"
