#!/bin/bash

g++ testCreditCard.cpp CreditCard.cpp -o testCreditCard
./testCreditCard
rm -v testCreditCard
