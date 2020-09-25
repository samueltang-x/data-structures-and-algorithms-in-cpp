#include "ArrayQueue.h"
#include <cstdlib>
#include <iostream>
#include <string>

//using std::cout;
//using std::string;
using namespace std;

void testArrayQueue() {
  ArrayQueue<string> q(10);
  q.enqueue("data");
  q.enqueue("structures");
  cout << q;
  q.enqueue("and");
  q.enqueue("algorithems");
  cout << q;
  cout << "top: " << q.top() << ", size: " << q.size() << ", is empty: " << (q.empty() ? "true" : "false") << endl;

  cout << "copy contructor, q2:\n";
  ArrayQueue<string> q2 = q;
  cout << q2;

  q.dequeue();
  cout << q;
  cout << "atter dequeue q, top: " << q.top() << ", size: " << q.size() << ", is empty: " << (q.empty() ? "true" : "false") << endl;

  cout << "Assign q2 to q3:\n";
  ArrayQueue<string> q3;
  q3 = q2;
  cout << q3;
}


int main() {
  testArrayQueue();
  return EXIT_SUCCESS;
}


