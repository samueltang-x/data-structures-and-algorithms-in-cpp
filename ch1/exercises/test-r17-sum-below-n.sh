#!/bin/bash

g++ r17-sum-below-n_recursion.cpp -o r17-sum-below-n_recursion
time ./r17-sum-below-n_recursion

g++ r17-sum-below-n_loop.cpp -o r17-sum-below-n_loop
time ./r17-sum-below-n_loop

rm -v ./r17-sum-below-n_recursion ./r17-sum-below-n_loop
