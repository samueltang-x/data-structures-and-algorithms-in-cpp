#include "NodeList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void testNodeList() {
  NodeList<int> l;
  cout << l << endl;

  l.insertFront(8);
  cout << "after l.insertFront(8): " << l << endl;

  typedef NodeList<int>::Iterator it;

  l.insertBack(5);
  cout << "after l.insertBack(5): " << l << endl;

  it p = l.begin();
  it q = p;
  ++q;
  cout << "is p == l.begin(): " << (p==l.begin() ? "true" : "false") << endl;

  l.insert(q, 3);
  cout << "after l.insert(q, 3): " << l << endl;
  
  *q = 7;
  cout << "after *q = 7: " << l << endl;
  
  l.insertFront(9);
  cout << "after l.insertFront(9): " << l << endl;
  cout << "is p == l.begin(): " << (p==l.begin() ? "true" : "false") << endl;

  NodeList<int> m = l;
  NodeList<int> n;
  n = l;

  l.eraseBack();
  cout << "after l.eraseBack(): " << l << endl;

  l.erase(p);
  cout << "after l.erase(p): " << l << endl;
  
  l.eraseFront();
  cout << "after l.eraseFront(): " << l << endl;

  cout << "copied   m: " << m << endl;
  cout << "assigned n: " << n << endl;
}

int main() {
  testNodeList();
  return EXIT_SUCCESS;
}
