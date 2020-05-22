#!/bin/bash

#codetest 128a, run abc128a.cpp
testcode=./rco_contest_2019_qual_a.cpp
testtxt=./input.txt

echo ${testcode}
echo "================"
g++ ${testcode} -std=c++17 -Wall
./a.out < ${testtxt}
./a.out < ${testtxt} > output.txt
echo "================"
