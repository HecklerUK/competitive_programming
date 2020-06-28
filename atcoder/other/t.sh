#!/bin/bash

testcode=./intro_heuristics_a.cpp
testtxt=./tester/input.txt

echo ${testcode}
echo "================"
g++ ${testcode} -std=c++17 -Wall
./a.out < ${testtxt}
echo "================"
