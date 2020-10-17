#include "ShrinkingVector.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void testShrinkingVector() {
  ShrinkingVector<string> v(10);
  string s[] = {"data", "structure", "and", "algorithem"};
  for (int i = 0; i < 4; ++i)
    // FIXME
    //v[i] = s[i];
    v.insert(i, s[i]);
  ShrinkingVector<string> v1 = v;
  ShrinkingVector<string> v2, v3;
  v3 = v2 = v;
  v1.shrinkToFit();
  v2.shrinkToFit();
  cout << "v, size: " << v.size() << ", capacity: " << v.capacity() << ", elements: " << v << endl;
  cout << "v1, size: " << v1.size() << ", capacity: " << v1.capacity() << ", elements: " << v1 << endl;
  cout << "v2, size: " << v2.size() << ", capacity: " << v2.capacity() << ", elements: " << v2 << endl;

  v3.erase(3);
  v3.shrinkToFit();
  cout << "v3, size: " << v3.size() << ", capacity: " << v3.capacity() << ", elements: " << v3 << endl;
}

int main() {
  testShrinkingVector();
  return EXIT_SUCCESS;
}
