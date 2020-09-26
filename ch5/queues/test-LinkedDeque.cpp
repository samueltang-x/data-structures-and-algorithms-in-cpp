#include "./LinkedDeque.h"
#include <cstdlib>
#include <string>

using namespace std;

void testLinkedDeque() {
  LinkedDeque<string> q;
  q.insertBack("data");
  q.insertBack("structures");
  cout << q;
  q.insertBack("and");
  q.insertBack("algorithms");
  cout << q;
  cout << "front: " << q.front();
  cout << ", back: " << q.back();
  cout << ", size: " << q.size();
  cout << ", is empty: " << (q.empty() ? "true" : "false") << endl;

  cout << "copy contructor, q2:";
  LinkedDeque<string> q2 = q;
  cout << q2;

  q.removeBack();
  q.removeBack();
  cout << "after remove back q: " << q;
  cout << "atter remove back q, front: " << q.front() << ", size: " << q.size() << ", is empty: " << (q.empty() ? "true" : "false") << endl;

  cout << "Assign q2 to q3:\n";
  LinkedDeque<string> q3;
  q3 = q;

  q3.insertFront("and");
  q3.insertFront("algorithms");

  cout << "q3:" << q3;

  q3.removeBack();
  cout << "after removeBack() of q3: " << q3;
}

int main() {
  testLinkedDeque();
  return EXIT_SUCCESS;
}
