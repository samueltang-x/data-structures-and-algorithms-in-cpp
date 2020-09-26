#ifndef GUARD_LINKEDDEQUE_H
#define GUARD_LINKEDDEQUE_H

#include "../../ch3/doublyLinkedLists/DLinkedList.h"
#include "./DequeExceptions.h"
#include <iostream>

template <typename>
class LinkedDeque;

template <typename E>
std::ostream& operator<<(std::ostream& os, const LinkedDeque<E>&l);

template <typename E>
class LinkedDeque {
public:
  LinkedDeque();

  int size() const;
  bool empty() const;
  const E& front() const;
  const E& back() const;
  void insertFront(const E& e);
  void insertBack(const E& e);
  void removeFront();
  void removeBack();

private:
  int n; // number of elements
  DLinkedList<E> d;

  friend std::ostream& operator<< <E>(std::ostream& os, const LinkedDeque& l);
};

template <typename E>
LinkedDeque<E>::LinkedDeque() : d(), n(0) {}

template <typename E>
int LinkedDeque<E>::size() const {
  return n;
}

template <typename E>
bool LinkedDeque<E>::empty() const {
  return n == 0;
}

template <typename E>
const E& LinkedDeque<E>::front() const {
  if (empty())
    throw DequeEmpty("Front of the empty Deque");
  return d.front();
}

template <typename E>
const E& LinkedDeque<E>::back() const {
  if (empty())
    throw DequeEmpty("Back of the empty Deque");
  return d.back();
}

template <typename E>
void LinkedDeque<E>::insertFront(const E& e) {
  d.addFront(e);
  n++;
}

template <typename E>
void LinkedDeque<E>::insertBack(const E& e) {
  d.addBack(e);
  n++;
}

template <typename E>
void LinkedDeque<E>::removeFront() {
  if (empty())
    throw DequeEmpty("Remove front of the empty Deque");
  d.removeFront();
  n--;
}

template <typename E>
void LinkedDeque<E>::removeBack() {
  if (empty())
    throw DequeEmpty("Remove back of the empty Deque");
  d.removeBack();
  n--;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const LinkedDeque<E>& l) {
  os << l.d;
  return os;
}

#endif
