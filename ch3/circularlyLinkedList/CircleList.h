#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include "../../misc/extendExceptions.h"
#include "CNode.h"
#include <iostream>

template <typename E>
std::ostream& operator<<(std::ostream& os, const CircleList<E>& cl);

template <typename E>
class CircleList {
  public:
    CircleList();
    ~CircleList();
    
    bool empty() const;
    const E& front() const;
    const E& back() const;
    void advance();
    void add(const E& e);
    void remove();
  private:
    CNode<E>* cursor;

    friend std::ostream& operator<< <E>(std::ostream& os, const CircleList& cl);
};

template <typename E>
CircleList<E>::CircleList()
  : cursor(NULL) {}

template <typename E>
CircleList<E>::~CircleList() {
  while (!empty()) remove();
}

template <typename E>
bool CircleList<E>::empty() const {
  return (cursor == NULL);
}

template <typename E>
void CircleList<E>::advance() {
  if (empty()) throw ListEmpty("advance a empty CircleList");
  cursor = cursor->next;
}

template <typename E>
const E& CircleList<E>::front() const {
  if (empty()) throw ListEmpty("get front of a empty CircleList");
  return cursor->next->elem;
}

template <typename E>
const E& CircleList<E>::back() const {
  if (empty()) throw ListEmpty("get back of a empty CircleList");
  return cursor->elem;
}

template <typename E>
void CircleList<E>::add(const E& e) {
  CNode<E>* n = new CNode<E>;
  n->elem = e;

  if (empty()) {
    n->next = n;
    cursor = n;
  } else {
    n->next = cursor->next;
    cursor->next = n;
  }
}

template <typename E>
void CircleList<E>::remove() {
  if (empty()) throw ListEmpty("remove a empty CircleList");

  CNode<E>* old = cursor->next;
  if (cursor->next == cursor) {
    cursor = NULL;
  } else {
    cursor->next = old->next;
  }

  delete old;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const CircleList<E>& cl) {
  if (cl.empty()) return os;

  os << "[current] -> ";
  
  for (CNode<E>* cur = cl.cursor->next; ; cur = cur->next) {
    os << cur->elem << " -> ";
    if (cur == cl.cursor) break;
  }
  os << "[current]\n";

  return os;
}

#endif
