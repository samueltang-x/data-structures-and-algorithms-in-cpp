#include <iostream>
#include <cstdlib>
#include "GameEntry.h"

using namespace std;

void testArrayOfGameEntry() {
  GameEntry* entries = new GameEntry[10];
  for (int i = 0; i < 10; i++) {
    cout << i << ": " << entries[i].getName() << ", " << entries[i].getScore() << endl;
  }
}

int main() {
  testArrayOfGameEntry();
  return EXIT_SUCCESS;
}
