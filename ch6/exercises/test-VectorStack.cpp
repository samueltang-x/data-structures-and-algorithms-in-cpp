#include "VectorStack.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void testVectorStack() {
  VectorStack<int> a;
  a.push(7);
  a.push(13);
  cout << a.top() << endl;
  a.pop();
  a.push(9);
  cout << a.top() << endl;
  cout << a;
  cout << a.top() << endl;
  a.pop();

  VectorStack<string> b;
  b.push("Bob");
  b.push("Alice");
  cout << b;
  cout << b.top() << endl;
  b.pop();
  b.push("Eve");
  cout << b << endl;

  const int CAP = 100;
  VectorStack<int> c;
  for (int i = 0; i < CAP; i++)
    c.push(i % 10);
  cout << c;
}

int main() {
  testVectorStack();
  return EXIT_SUCCESS;
}
