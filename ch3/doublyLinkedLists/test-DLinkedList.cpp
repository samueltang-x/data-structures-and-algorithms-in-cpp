#include <iostream>
#include <cstdlib>
#include <string>

#include "DLinkedList.h"

using namespace std;

template <typename E>
void printDLinkedList(DLinkedList<E>& l) {
  while (!l.empty())
  {
    cout << l.front() << " --> ";
    l.removeFront();
  }
  cout << "NULL\n";
}

void testDLinkedList()
{
  DLinkedList<string> a;
  a.addFront("BOS");
  a.addFront("ATL");
  a.addBack("LAX");
  a.addBack("MSP");

  printDLinkedList(a);

  DLinkedList<int> b;
  b.addFront(24);
  b.addFront(13);
  b.addBack(39);
  b.addBack(78);

  printDLinkedList(b);
}

int main()
{
  testDLinkedList();
  return EXIT_SUCCESS;
}
