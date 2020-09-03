#ifndef ARITHPROGRESSION_H
#define ARITHPROGRESSION_H

#include "Progression.h"

class ArithProgression: public Progression {
  public:
    ArithProgression(long inc = 1);
  protected:
    virtual long nextValue();
  protected:
    long inc;
};

#endif