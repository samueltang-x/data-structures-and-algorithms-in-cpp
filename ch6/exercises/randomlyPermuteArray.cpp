#include "utils.h"
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void randomArray(T a[], int size) {
  if (size < 1) return;
  srand(time(NULL));
  vector<T> v(a, a+size);
  for (int i = size; i > 1; --i) {
    int r = rand() % i;
    typename vector<T>::iterator p = v.begin() + r;
    a[i-1] = *p;
    v.erase(p);
  }
  a[0] = v[0];
}

int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

  cout << "original: ";
  printArray(a, 10);
  cout << endl;

  randomArray(a, 10);
  cout << "random:   ";
  printArray(a, 10);
  cout << endl;

  return EXIT_SUCCESS;
}
