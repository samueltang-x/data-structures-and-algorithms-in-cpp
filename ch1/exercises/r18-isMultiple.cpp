#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool isMultiple(long n, long m) {
  return n % m == 0;
}

void testIsMultiple() {
  long testNumbers[2][2] = { {51, 17}, {24, 5} };

  for (int i = 0; i < 2; i++) {
    string assertStr = isMultiple(testNumbers[i][0], testNumbers[i][1]) ? " is" : " is not";
    cout << testNumbers[i][0] << assertStr << " a multiple of " << testNumbers[i][1] << "\n";
  }
}

int main() {
  testIsMultiple();
  return EXIT_SUCCESS;
}
