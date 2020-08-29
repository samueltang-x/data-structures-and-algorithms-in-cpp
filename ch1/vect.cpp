#include "vect.h"

Vect::Vect(int n) {
  size = n;
  data = new int[size];
}

Vect::Vect(const Vect& v) {
  size = v.size;
  data = new int[size];
  for (int i = 0; i < size; i++) {
    data[i] = v.data[i];
  }
}

Vect::~Vect() {
  delete [] data;
}

Vect& Vect::operator=(const Vect& v) {
  if (this == &v) {
    delete [] data;
    size = v.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = v.data[i];
    }
  }

  return *this;
}
