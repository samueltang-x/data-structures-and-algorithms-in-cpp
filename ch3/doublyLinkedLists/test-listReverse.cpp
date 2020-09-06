#include <cstdlib>
#include <iostream>
#include "DLinkedList.h"

using namespace std;

void testListReverse() {
  DLinkedList<double> l;
  l.addBack(34.7);
  l.addBack(83.3);
  l.addBack(13.5);
  l.addBack(63.5);

  cout << "origin:   " << l << endl;
  listReverse(l);
  cout << "reversed: " << l << endl;
}

int main() {
  testListReverse();
  return EXIT_SUCCESS;
}
