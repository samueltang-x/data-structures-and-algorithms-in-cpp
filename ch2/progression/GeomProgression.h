#ifndef GEOMPROGRESSION_H
#define GEOMPROGRESSION_H

#include "Progression.h"

class GeomProgression: public Progression {
  public:
    GeomProgression(long b = 2);
  protected:
    virtual long nextValue();
  protected:
    long base;
};

#endif