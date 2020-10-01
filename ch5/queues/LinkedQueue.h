#ifndef GUARD_LINKEDQUEUE_H
#define GUARD_LINKEDQUEUE_H

#include "../../ch3/circularlyLinkedList/CircleList.h"
#include "QueueExceptions.h"
#include <iostream>

template <typename>
class LinkedQueue;

template <typename E>
std::ostream &operator<<(std::ostream &os, const LinkedQueue<E> &q);

template <typename E>
class LinkedQueue {
public:
  LinkedQueue();

  int size() const;
  bool empty() const;
  const E &front() const;
  void enqueue(const E &e);
  void dequeue();

private:
  CircleList<E> c;
  int n;

  friend std::ostream &operator<<<E>(std::ostream &os, const LinkedQueue &q);
};

template <typename E>
LinkedQueue<E>::LinkedQueue() : c(), n(0) {}

template <typename E>
int LinkedQueue<E>::size() const {
  return n;
}

template <typename E>
bool LinkedQueue<E>::empty() const {
  return n == 0;
}

template <typename E>
const E &LinkedQueue<E>::front() const {
  if (empty()) throw QueueEmpty("Front of an empty LinkedQueue");
  return c.front();
}

template <typename E>
void LinkedQueue<E>::enqueue(const E &e) {
  c.add(e);
  n++;
}

template <typename E>
void LinkedQueue<E>::dequeue() {
  if (empty()) throw QueueEmpty("Dequeue of an empty LinkedQueue");
  c.remove();
  n--;
}

template <typename E>
std::ostream &operator<<(std::ostream &os, const LinkedQueue<E> &q) {
  os << q.c;
  return os;
}

#endif
