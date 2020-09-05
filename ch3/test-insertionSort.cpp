#include <cstdlib>
#include <iostream>
#include <string>

#include "insertionSort.h"

using namespace std;

void testInsertionSort() {
  string a = "UZBKRIYBDQOVHLIS";
  const char* tempA = a.c_str();
  int len = 16;
  char* A = new char[len];

  for (int i = 0; i < len; i++) {
    A[i] = tempA[i];
  }

  cout << "array A before sort: " << A << endl;

  insertionSort(A, len);
  cout << "array A after sort:  " << A << endl;
}

int main() {
  testInsertionSort();
  return EXIT_SUCCESS;
}
