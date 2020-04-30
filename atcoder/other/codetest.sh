#!/bin/bash

testcode=./$1.cpp
testtxt=../test.txt

echo ${testcode}
echo "================"
g++ ${testcode} -std=c++17 -Wall
./a.out < ${testtxt}
echo "================"
