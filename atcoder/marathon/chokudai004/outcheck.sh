#!/bin/bash

#codetest 128a, run abc128a.cpp
testcode=./output_checker.cpp
in1=./in/example_01.txt
out1=./out/example_01.txt
in2=./in/example_02.txt
out2=./out/example_02.txt
in3=./in/example_03.txt
out3=./out/example_03.txt

echo ${testcode}
echo "================"
g++ ${testcode} -std=c++17 -Wall
./a.out ${in1} ${out1} ${out1}
./a.out ${in2} ${out2} ${out2}
./a.out ${in3} ${out3} ${out3}
echo "================"
