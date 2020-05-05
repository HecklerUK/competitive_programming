#!/bin/bash

#codetest 128a, run abc128a.cpp
testcode=./chokudai004.cpp
testtxt1=./in/example_01.txt
testtxt2=./in/example_02.txt
testtxt3=./in/example_03.txt

echo ${testcode}
echo "================"
g++ ${testcode} -std=c++17 -Wall
./a.out < ${testtxt1}
./a.out < ${testtxt2}
./a.out < ${testtxt3}
echo "================"
