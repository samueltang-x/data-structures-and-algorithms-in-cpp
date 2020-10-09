#ifndef GUARD_EXCERSISESUTILS_H
#define GUARD_EXCERSISESUTILS_H

#include <iostream>

template <typename T>
void printArray(T a[], int size) {
  for (int i = 0; i < size; ++i) std::cout << (i == 0 ? "" : ",") << a[i];
}

#endif
