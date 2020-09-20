#ifndef GAME_SCORES_H
#define GAME_SCORES_H

#include "GameEntry.h"
#include <iostream>

class Scores {
  public:
    Scores(int maxEnt = 10);
    ~Scores();

    void add(const GameEntry& e);
    GameEntry remove(int i);

  private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;

    friend std::ostream& operator<<(std::ostream& os, const Scores& s);
};

#endif
