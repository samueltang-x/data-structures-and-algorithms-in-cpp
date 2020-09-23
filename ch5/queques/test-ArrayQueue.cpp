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
  q.dequeue();
  cout << q;
  cout << "top: " << q.top() << ", size: " << q.size() << ", is empty: " << (q.empty() ? "true" : "false") << endl;
}


int main() {
  testArrayQueue();
  return EXIT_SUCCESS;
}


