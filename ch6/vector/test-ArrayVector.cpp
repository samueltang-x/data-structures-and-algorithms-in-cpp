#include "../../misc/extendExceptions.h"
#include "ArrayVector.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void testArrayVector() {
  ArrayVector<int> v;
  cout << v << endl;
  v.insert(0, 7);
  cout << v << endl;
  v.insert(0, 4);
  cout << v << endl;
  cout << v.at(1) << endl;
  v.insert(2, 2);
  cout << v << endl;
  try {
    v.at(3);
  } catch ( RuntimeException e) {
    cout << "v.at(3) got exception: " << e << endl;
  }
  v.erase(1);
  cout << v << endl;
  v.insert(1, 5);
  cout << v << endl;
  v.insert(1, 3);
  cout << v << endl;
  v.insert(4, 9);
  cout << v << endl;
  cout << v.at(2) << endl;
  
  cout << "copy construct v2 from v: ";
  ArrayVector<int> v2 = v;
  cout << v2 << endl;

  cout << "v2.insert(0, 2):" << endl;
  v2.insert(0, 2);
  cout << "v2: " << v2 << endl;
  cout << "v: " << v << endl;

  cout << "assign v to v3: ";
  ArrayVector<int> v3;
  v3 = v;
  cout << v3 << endl;
  cout << "v3.erase(0)" << endl;
  v3.erase(0);
  cout << "v3: " << v3 << endl;
  cout << "v: " << v << endl;

  ArrayVector<string> v4(2);
  v4.insert(0, "blue");
  v4.insert(1, "sky");
  cout << "v4: " << v4 << endl;
  v4.erase(1);
  cout << "v4: " << v4 << endl;

  ArrayVector<int> v5(2);
  v5.insert(0, 1);
  v5.insert(1, 2);
  cout << "v5: " << v5 << endl;
  v5.erase(1);
  cout << "v5: " << v5 << endl;
}

int main() {
  testArrayVector();
  return EXIT_SUCCESS;
}
