#include <iostream>
#include <cstdlib>
#include <string>

#include "DLinkedList.h"

using namespace std;

void testDLinkedList() {
  DLinkedList<string> a;
  a.addFront("BOS");
  a.addFront("ATL");
  a.addBack("LAX");
  a.addBack("MSP");

  cout << a;
  
  cout << "removeBack " << a.back();
  a.removeBack(); cout << ": " << a;
  
  cout << "removeFront " << a.front();
  a.removeFront(); cout << ": " << a;

  DLinkedList<int> b;
  cout << "before addFront(), b: " << b;
  b.addFront(24);
  b.addFront(13);
  b.addBack(39);
  b.addBack(78);

  cout << "after addFront(), b: " << b;
}

int main() {
  testDLinkedList();
  return EXIT_SUCCESS;
}
