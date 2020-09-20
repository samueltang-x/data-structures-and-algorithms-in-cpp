#include "../../misc/extendExceptions.h"
#include "Score.h"

Score::Score(int maxEnt)
  : maxEntries(maxEnt), numEntries(0) {
  entries = new GameEntry[maxEntries];
}

~Score::Score() {
  delete [] entries;
}

void Score::add(const GameEntry& e) {
  int newScore = e.getScore();
  // when the array is full
  if (numEntries == maxEntries) {
    if (newScore < entries[numEntries - 1].getScore())
      return;

    numEntries--;
  }

  for (int i = numEntries - 1; i >= 0 && newScore > entries[i].getScore(); i--)
    entries[i + 1] = entries[i];

  entries[i+1] = e;
  numEntries++;
}

GameEntry Score::remove(int i) throw(IndexOutOfBounds) {
  if (i < 0 || i >= numEntries)
    throw IndexOutOfBounds("Invalid index");

  GameEntry e = entries[i];
  for (int j = i + 1; j < numEntries; j++)
    entries[j - 1] = entries[j];

  numEntries--;
  return e;
}
