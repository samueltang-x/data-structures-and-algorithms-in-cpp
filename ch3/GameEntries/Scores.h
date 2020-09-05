#ifndef GAME_SCORES_H
#define GAME_SCORES_H

#include "GameEntry.h"

class Scores {
  public:
    Scores(int maxEnt = 10);
    ~Scores();

    void add(const GameEntry& e);
    GameEntry remove(int i) throw(IndexOutOfBounds);
  private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
};

#endif
