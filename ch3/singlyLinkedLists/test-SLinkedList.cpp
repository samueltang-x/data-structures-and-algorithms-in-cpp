#include <iostream>
#include <cstdlib>
#include <string>

#include "SLinkedList.h"

using namespace std;

template <typename E>
void printSLinkedList(SLinkedList<E>& l) {
  while (!l.empty())
  {
    cout << l.front() << " --> ";
    l.removeFront();
  }
  cout << "NULL\n";
}

void testSLinkedList()
{
  SLinkedList<string> a;
  a.addFront("BOS");
  a.addFront("ATL");
  a.addFront("MSP");
  a.addFront("LAX");

  printSLinkedList(a);

  SLinkedList<int> b;
  b.addFront(13);
  b.addFront(39);
  b.addFront(78);
  b.addFront(24);

  printSLinkedList(b);
}

int main()
{
  testSLinkedList();
  return EXIT_SUCCESS;
}
