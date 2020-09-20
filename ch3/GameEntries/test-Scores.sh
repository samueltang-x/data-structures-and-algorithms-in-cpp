#!/bin/bash

g++ test-Scores.cpp Scores.cpp GameEntry.cpp -o test-Scores
time ./test-Scores

rm test-Scores
