#!/bin/bash

g++ testProgression.cpp ArithProgression.cpp FibonacciProgression.cpp GeomProgression.cpp Progression.cpp -o testProgression
./testProgression

rm -v ./testProgression
