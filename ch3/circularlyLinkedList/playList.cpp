#include <cstdlib>
#include <iostream>
#include <string>

#include "CircleList.h"

using namespace std;

int main() {
  CircleList<string> playList;
  playList.add("Stayin Alive");
  playList.add("Le Freak");
  playList.add("Jive Talkin");

  cout << "playList before replaced: " << playList;

  playList.advance();
  playList.advance();
  playList.remove();
  playList.add("Disco Inferno");
  playList.advance();
  cout << "playList after  replaced: " << playList;

  return EXIT_SUCCESS;
}
