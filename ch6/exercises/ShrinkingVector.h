#ifndef GUARD_SHRINGKINGVECTOR_H
#define GUARD_SHRINGKINGVECTOR_H

#include "../vector/ArrayVector.h"

template <typename E>
class ShrinkingVector: public ArrayVector<E> {
  public:
    ShrinkingVector(int c = 0);
    void shrinkToFit();
};

template <typename E>
ShrinkingVector<E>::ShrinkingVector(int c): ArrayVector<E>(c) {}

template <typename E>
void ShrinkingVector<E>::shrinkToFit() {
  int s = ArrayVector<E>::size();
  E* old = ArrayVector<E>::a;
  if (old == NULL || s == ArrayVector<E>::capacity()) return;

  E* a = new E[s];
  for (int i = 0; i < s; ++i) a[i] = old[i];

  delete [] old;
  ArrayVector<E>::a = a;
  ArrayVector<E>::cap = s;
}

#endif
