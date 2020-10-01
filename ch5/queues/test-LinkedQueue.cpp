#include "LinkedQueue.h"
#include <cstdlib>
#include <iostream>
#include <string>

//using std::cout;
//using std::string;
using namespace std;

void testLinkedQueue() {
  LinkedQueue<string> q;
  q.enqueue("data");
  q.enqueue("structures");
  cout << "q: " << q;
  q.enqueue("and");
  q.enqueue("algorithem");
  cout << "q: " << q;
  cout << "front: " << q.front() << ", size: " << q.size() << ", is empty: " << (q.empty() ? "true" : "false") << endl;

  cout << "copy contructor, q2:\n";
  LinkedQueue<string> q2 = q;
  cout << "q2: " << q2;

  q.dequeue();
  cout << "q: " << q;
  cout << "atter dequeue q, front: " << q.front() << ", size: " << q.size() << ", is empty: " << (q.empty() ? "true" : "false") << endl;

  cout << "Assign q2 to q3:\n";
  LinkedQueue<string> q3;
  q3 = q2;
  cout << "q3: " << q3;

  cout << "dequeue q2:";
  q2.dequeue();
  cout << "finally, q: " << q;
  cout << "q2: " << q2;
  cout << "q3: " << q3;
}

int main() {
  testLinkedQueue();
  return EXIT_SUCCESS;
}
