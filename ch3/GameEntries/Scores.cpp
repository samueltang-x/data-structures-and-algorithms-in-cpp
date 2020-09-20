#include "../../misc/extendExceptions.h"
#include "Scores.h"

using namespace std;

Scores::Scores(int maxEnt)
  : maxEntries(maxEnt), numEntries(0) {
  entries = new GameEntry[maxEntries];
}

Scores::~Scores() {
  delete [] entries;
}

void Scores::add(const GameEntry& e) {
  int newScores = e.getScore();
  // when the array is full
  if (numEntries == maxEntries) {
    if (newScores < entries[numEntries - 1].getScore())
      return;

    numEntries--;
  }

  int i = numEntries - 1;
  while (i >= 0 && newScores > entries[i].getScore()) {
    entries[i + 1] = entries[i];
    i--;
  }

  entries[i+1] = e;
  numEntries++;
}

GameEntry Scores::remove(int i) {
  if (i < 0 || i >= numEntries)
    throw IndexOutOfBounds("Invalid index");

  GameEntry e = entries[i];
  for (int j = i + 1; j < numEntries; j++)
    entries[j - 1] = entries[j];

  numEntries--;
  return e;
}

ostream& operator<<(ostream& os, const Scores& s) {
  if (s.numEntries == 0) os << "No scores\n";
  else {
    for (int i = 0; i < s.numEntries; i++) {
      os << i+1 << ": " << s.entries[i].getName() << '(' << s.entries[i].getScore() << ')';
      os << ( (i == s.numEntries-1) ? "\n" : ", " );
    }
  }
  return os;
}
