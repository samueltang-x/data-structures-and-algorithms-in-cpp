#include "utils.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
void reverseArray(T a[], int size) {
  for(int i = 0, j = size - 1; i < j; ++i, --j) {
    T temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
}

template <typename T>
void reverseArrayRecursive(T a[], int size) {
  if (size <= 1) return;
  T temp = a[0];
  a[0] = a[size-1];
  a[size-1] = temp;
  reverseArrayRecursive(++a, size-2);
}

int main() {
  int a[] = {3, 0, 7, 4, 1, 2, 9, 6, 3, 5};
  cout << "original:     ";
  printArray(a, 10);
  cout << endl;

  reverseArray(a, 10);
  cout << "reversed:     ";
  printArray(a, 10);
  cout << endl;

  reverseArrayRecursive(a, 10);
  cout << "2nd reversed: ";
  printArray(a, 10);
  cout << endl;

  return EXIT_SUCCESS;
}

