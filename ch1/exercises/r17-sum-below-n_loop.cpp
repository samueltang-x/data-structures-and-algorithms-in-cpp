#include <cstdlib>
#include <iostream>

using namespace std;

// to calculate the sum of all the integers smaller than n (and bigger then 0)
long sumToN(long n) {
  long sum = 0;
  while (n >=0 ) {
    sum += n;
    n--;
  }

  return sum;
}

void testSumToN() {
  for (long i = -3; i <= 10; i++) {
    cout << i << ": " << sumToN(i) << "\n";
  }

  long j = 261805L;
  cout << j << ": " << sumToN(j) << "\n";
}


int main() {
  testSumToN();
  return EXIT_SUCCESS;
}
