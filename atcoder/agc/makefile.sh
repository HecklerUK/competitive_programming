#!/bin/bash

#copy template 128a, edit abc128a.cpp
editfile=./agc$1.cpp
template=../template.cpp

cp ${template} ${editfile}
#vim ${editfile}
