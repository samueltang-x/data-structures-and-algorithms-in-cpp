#include "exceptions.h"
#include "ArrayStack.h"

template <typename E>
ArrayStack<E>::ArrayStack(int cap)
  : capacity(cap), t(-1), s(new E[cap]) {}

template <typename E>
ArrayStack<E>::~ArrayStack() {
  delete [] s;
}

template <typename E>
ArrayStack<E>::ArrayStack(const ArrayStack& as) {
  capacity = as.capacity;
  t = as.t;
  s = new E[capacity];
  for (int i = 0; i < t; i++) s[i] = as.s[i];
}

template <typename E>
const ArrayStack<E>& ArrayStack<E>::operator=(const ArrayStack& as) {
  if (this == &as) return *this;  // self-assignment

  capacity = as.capacity;
  t = as.t;
  for (int i = 0; i < t; i ++) s[i] = as.s[i];
  return *this;
}

template <typename E>
bool ArrayStack<E>::empty() const {
  return t < 0;
}

template <typename E>
int ArrayStack<E>::size() const {
  return t + 1;
}

template <typename E>
const E& ArrayStack<E>::top() const {
  if (empty()) throw StackEmpty("Top of empty stack");
  return s[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e) {
  if (size() == capacity) throw StackFull("Push to full stack");
  s[++t] = e;
}

template <typename E>
void ArrayStack<E>::pop() {
  if (empty()) throw StackEmpty("Pop from empty stack");
  --t;
}
