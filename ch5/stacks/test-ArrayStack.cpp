#include <cstdlib>
#include <iostream>
#include <string>
#include "ArrayStack.h"

using namespace std;

void testArrayStack() {
  ArrayStack<int> a;
  a.push(7);
  a.push(13);
  cout << a.top() << endl; a.pop();
  a.push(9);
  cout << a.top() << endl;
  cout << a.top() << endl; a.pop();

  ArrayStack<string> b(10);
  b.push("Bob");
  b.push("Alice");
  cout << b.top() << endl; b.pop();
  b.push("Eve");

  const int CAP = 10000;
  ArrayStack<int> c(CAP);
  for (int i = 0; i < CAP; i++) c.push(i % 10);
  while (!c.empty()) {
    //c.top(); c.pop();
    cout << c.top(); c.pop();
  }
  cout << endl;
}

int main() {
  testArrayStack();
  return EXIT_SUCCESS;
}
