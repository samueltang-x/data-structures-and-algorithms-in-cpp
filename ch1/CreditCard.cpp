#include "CreditCard.h"

using namespace std;

CreditCard::CreditCard(const string& no, const string& nm, int lim, double bal) {
  number = no;
  name = nm;
  limit = lim;
  bal = balance;
}

bool CreditCard::chargeIt(double price) {
  if (balance + price > limit) {
    return false;
  }

  balance += price;
  return true;
}

void CreditCard::makePayment(double payment) {
  balance -= payment;
}

ostream& operator<<(ostream& out, const CreditCard& c) {
  out << "Number = " << c.getNumber() << "\n"
      << "Name = " << c.getName() << "\n"
      << "Balance = " << c.getBalance() << "\n"
      << "Limit = " << c.getLimit() << "\n";
  return out;
}
