#include <cstdlib>
#include <vector>
#include "CreditCard.h"

using namespace std;

void testCreditCard() {
  vector<CreditCard*> wallet(10);

  wallet[0] = new CreditCard("5391 0375 9387 5309", "Samuel Tang", 2500);
  wallet[1] = new CreditCard("3485 0399 3395 1954", "Samuel Tang", 3500);
  wallet[2] = new CreditCard("6011 4902 3294 2994", "Samuel Tang", 5000);

  for (int j = 1; j <= 16; j++) {
    wallet[0]->chargeIt(double(j));
    wallet[1]->chargeIt(2 * j);
    wallet[2]->chargeIt(double(3 * j));
  }

  cout << "Card payments:\n";
  for (int i = 0; i < 3; i++) {
    CreditCard* card = wallet[i];
    cout << *card;
    while (card->getBalance() > 100.0) {
      card->makePayment(100.0);
      cout << "New balance = " << card->getBalance() << "\n";
    }
    cout << "\n";
    delete card;
  }
}

int main() {
  testCreditCard();
  return EXIT_SUCCESS;
}
