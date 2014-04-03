#!bin/bash

GMOCK_DIR=./3rd_party/gmock
OUTPUT_DIR=./bin

if [ -d "$OUTPUT_DIR" ]; then rm -rf "$OUTPUT_DIR"; fi
mkdir "$OUTPUT_DIR"

echo "compile geek..."
g++ -g src/* -o $OUTPUT_DIR/geek -I./include
if [ $? -ne 0 ]; then echo "Compile source code failed!" && exit 1; fi

echo "compile test..."
g++ -g src/*.cpp test/* -o $OUTPUT_DIR/test_geek -I./include -I$GMOCK_DIR/gtest/include -I$GMOCK_DIR/include $GMOCK_DIR/make/gmock_main.a -lpthread
if [ $? -ne 0 ]; then echo "Compile test failed !" && exit 1; fi

echo "run geek tests..."
./bin/test_geek
if [ $? -ne 0 ]; then echo "Run test !" && exit 1; fi

echo "calc cc..."
chmod 755 ./3rd_party/cppncss/bin/cppncss
./3rd_party/cppncss/bin/cppncss -r -k -x -f=cppncss-report-guidance.xml ./src
if [ $? -ne 0 ]; then echo "Calc cc failed !" && exit 1; fi

