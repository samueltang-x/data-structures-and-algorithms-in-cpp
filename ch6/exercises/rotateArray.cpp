#include "utils.h"
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void rotateArray(T a[], int size, int dist) {
  if (dist <= 0) return;

  vector<T> v(a, a+size);
  for (int i = 0; i < size; ++i) a[i] = v[(i+dist)%size];
}

int main() {
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << "oritinal:  ";
  printArray(a, 10);
  cout << endl;

  rotateArray(a, 10, 2);
  cout << "rotated 2: ";
  printArray(a, 10);
  cout << endl;
  return EXIT_SUCCESS;
}
