#!/bin/bash

#unzip gmock-1.6.0.zip
cd gmock/make

rm gmock-all.o
rm gmock_main.*
rm gmock_test*
rm gtest-all.o

make

cd ..
