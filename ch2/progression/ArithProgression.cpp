#include "ArithProgression.h"

ArithProgression::ArithProgression(long i):
  Progression(), inc(i) {};

long ArithProgression::nextValue() {
  cur += inc;
  return cur;
}