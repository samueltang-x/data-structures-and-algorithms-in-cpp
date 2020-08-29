#include <cstdlib>
#include <iostream>
#include "151-counter.h"

using std::cout;

Counter::Counter() {
  count = 0;
}

int Counter::getCount() {
  return count;
}

void Counter::increaseBy(int n) {
  count += n;
}

int main() {
  Counter ctr;
  cout << "init count:" << ctr.getCount() << std::endl;
  ctr.increaseBy(3);
  cout << "after first increased, count:" << ctr.getCount() << std::endl;
  ctr.increaseBy(5);
  cout << "after second increased, count:" << ctr.getCount() << std::endl;
  return EXIT_SUCCESS;
}
