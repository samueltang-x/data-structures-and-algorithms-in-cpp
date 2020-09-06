#include <cstdlib>
#include <iostream>

#include "CircleList.h"

using namespace std;

int main() {
  CircleList playList;
  playList.add("Stayin Alive");
  playList.add("Le Freak");
  playList.add("Jive Talkin");

  cout << "playList before replaced: " << playList << endl;

  playList.advance();
  playList.advance();
  playList.remove();
  playList.add("Disco Inferno");
  playList.advance();
  cout << "playList after  replaced: " << playList << endl;

  return EXIT_SUCCESS;
}
