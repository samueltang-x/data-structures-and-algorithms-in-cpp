#ifndef GUARD_ARRAYVECTOR_H
#define GUARD_ARRAYVECTOR_H

#include "../../misc/extendExceptions.h"
#include <iostream>
#include <algorithm>

template <typename>
class ArrayVector;

template <typename E>
std::ostream& operator<<(std::ostream& os, const ArrayVector<E>& v);

template <typename E>
class ArrayVector {
  public:
    ArrayVector(int c = 0); // default constructor
    ~ArrayVector(); // destructer
    ArrayVector(const ArrayVector& v);  // copy constructor
    ArrayVector& operator=(const ArrayVector& v); // assignment operator

    int size() const;
    bool empty() const;
    E& operator[](int i);
    E& at(int i);
    void insert(int i, const E& e);
    void erase(int i);
    void reserve(int c);
  private:
    int capacity;
    int n;
    E* a;

    friend std::ostream& operator<< <E>(std::ostream& os, const ArrayVector& v);
};

// default constructor
template <typename E>
ArrayVector<E>::ArrayVector(int c): capacity(c), n(0), a(NULL) {
  reserve(c);
}

// destructor
template <typename E>
ArrayVector<E>::~ArrayVector() {
  if (a != NULL) delete [] a;
}

// copy constructor
template <typename E>
ArrayVector<E>::ArrayVector(const ArrayVector& v) {
  capacity = v.capacity;
  n = v.n;
  a = NULL;
  if (v.a != NULL) a = new E[capacity];
  for (int i = 0; i < n; i++) {
    a[i] = v.a[i]; 
  }
}

// assignment operator
template <typename E>
ArrayVector<E>& ArrayVector<E>::operator=(const ArrayVector& v) {
  if (this == &v) return *this;

  if (a != NULL) {
    delete [] a;
    a = NULL;
  }

  capacity = v.capacity;
  n = v.n;
  if (v.a != NULL) {
    a = new E[capacity];
    for (int i = 0; i < n; i++) {
      a[i] = v.a[i];
    } 
  }

  return *this;
}

template <typename E>
int ArrayVector<E>::size() const {
  return n;
}

template <typename E>
bool ArrayVector<E>::empty() const {
  return n == 0;
}

template <typename E>
E& ArrayVector<E>::operator[](int i) {
  return a[i];
}

template <typename E>
E& ArrayVector<E>::at(int i) {
  if (i < 0 || i >= n) throw IndexOutOfBounds("illegal index in function at() of ArrayVector");
  return a[i];
}

template <typename E>
void ArrayVector<E>::insert(int i, const E& e) {
  if (n >= capacity) reserve(std::max(1, capacity * 2));

  for (int j = n-1; j >= i; j--) a[j+1] = a[j];

  a[i] = e;
  n++;
}

template <typename E>
void ArrayVector<E>::erase(int i) {
  for (int j = i+1; j < n; j++) a[j-1] = a[j];
  n--;
}

template <typename E>
void ArrayVector<E>::reserve(int c) {
  if (c <= capacity) return;
  E* temp = new E[c];
  for (int i = 0; i < n; i++) {
    temp[i] = a[i]; 
  }
  if (a != NULL) delete [] a;
  a = temp;
  capacity = c;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const ArrayVector<E>& v) {
  os << '(';
  for (int i=0; i<v.n; i++) os << (i==0 ? "" : ", ") << v.a[i];
  os << ')';
  return os;
}

#endif
