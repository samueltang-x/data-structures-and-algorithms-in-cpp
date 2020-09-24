#ifndef GUARD_LINKEDSTACK.H
#define GUARD_LINKEDSTACK.H

#include "../../ch3/singlyLinkedLists/SLinkedList.h"
#include <iostream>

template <typename>
class LinkedStack;

template <typename E>
std::ostream& operator<<(std::ostream& os, const LinkedStack<E>& s);

template <typename E>
class LinkedStack {
  public:
    LinkedStack();

    bool empty() const;
    int size() const;
    const E& top() const;
    void push(const E& e);
    void pop();
  private:
    SLinkedList<E> l;
    int n;

    friend std::ostream& operator<< <E>(std::ostream& os, const LinkedStack& s);
};

template <typename E>
LinkedStack<E>::LinkedStack()
  : l(), n(0) {}

template <typename E>
bool LinkedStack<E>::empty() const {
  return n == 0;
}

template <typename E>
int LinkedStack<E>::size() const {
  return n;
}

template <typename E>
const E& LinkedStack<E>::top() const {
  return l.front();
}

template <typename E>
void LinkedStack<E>::push(const E& e) {
  l.addFront(e);
  n++;
}

template <typename E>
void LinkedStack<E>::pop() {
  l.removeFront();
  n--;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const LinkedStack<E>& s) {
  os << s.l;
  return os;
}

#endif
