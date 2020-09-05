#!/bin/bash

g++ test-insertionSort.cpp insertionSort.cpp -o test-insertionSort
./test-insertionSort

rm -v ./test-insertionSort
