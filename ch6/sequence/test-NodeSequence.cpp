#include <cstdlib>
#include <iostream>
#include "NodeSequence.h"

using namespace std;

void testNodeSequence() {
  NodeSequence<int> s;
  s.insertBack(3);
  s.insertBack(5);
  s.insertBack(7);
  cout << "1. " << s << endl;
  NodeSequence<int>::Iterator p = s.begin();
  cout << "2. " << (p == s.begin() ? "true" : "false") << endl;
  s.insertFront(1);
  cout << "3. " << s << endl;
  cout << "4. " << (p == s.begin() ? "true" : "false") << endl;
  NodeSequence<int>::Iterator q = --s.end();
  cout << "5. " << (q == --s.end() ? "true" : "false") << endl;
  s.insertBack(9);
  cout << "6. " << s << endl;
  cout << "7. " << (q == --s.end() ? "true" : "false") << endl;
  cout << "8. " << "*s.atIndex(2): " << *s.atIndex(2) << endl;
  cout << "9. " << "*s.atIndex(3): " << *s.atIndex(3) << endl;
  cout << "10. p:" << *p << ", q:" << *q << ", s:" << s << endl;
  cout << "11. indexOf(p):" << s.indexOf(p) << ", indexOf(q):" << s.indexOf(q) << endl;
}

int main() {
  testNodeSequence();
  return EXIT_SUCCESS;
}
