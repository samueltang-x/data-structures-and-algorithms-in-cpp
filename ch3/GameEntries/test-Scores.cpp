#include "Scores.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void testScores() {
  Scores s;
  cout << "init: " << s; 
  GameEntry n("Nora", 33);
  s.add(n);
  cout << s;
  GameEntry m("Mia", 28);
  s.add(m);
  cout << s;
  GameEntry l("Levi", 68);
  s.add(l);
  cout << s;
  GameEntry a("Asher", 51);
  s.add(a);
  cout << s;
  GameEntry f("Finn", 87);
  s.add(f);
  cout << s;
  GameEntry r("Rose", 66);
  s.add(r);
  cout << s;
  GameEntry i("Iris", 91);
  s.add(i);
  cout << s;
  GameEntry j("Jude", 79);
  s.add(j);
  cout << s;
  GameEntry w("Wyatt", 82);
  s.add(w);
  cout << s;
  GameEntry v("Voilet", 90);
  s.add(v);
  cout << s;
  GameEntry c("Clara", 75);
  s.add(c);
  cout << s;
  GameEntry h("Hugo", 93);
  s.add(h);
  cout << s;
}


int main() {
  testScores();
  return EXIT_SUCCESS;
}

