#include "CircleList.h"
#include "../../ch2/RuntimeException.h"

using namespace std;

CircleList::CircleList()
  : cursor(NULL) {}

CircleList::~CircleList() {
  while (!empty()) remove();
}

bool CircleList::empty() const {
  return (cursor == NULL);
}

void CircleList::advance() {
  if (empty()) throw RuntimeException("advance a empty CircleList");
  cursor = cursor->next;
}

const Elem& CircleList::front() const {
  if (empty()) throw RuntimeException("get front of a empty CircleList");
  return cursor->next->elem;
}

const Elem& CircleList::back() const {
  if (empty()) throw RuntimeException("get back of a empty CircleList");
  return cursor->elem;
}

void CircleList::add(const Elem& e) {
  CNode* n = new CNode;
  n->elem = e;

  if (empty()) {
    n->next = n;
    cursor = n;
  } else {
    n->next = cursor->next;
    cursor->next = n;
  }
}

void CircleList::remove() {
  if (empty()) throw RuntimeException("remove a empty CircleList");

  CNode* old = cursor->next;
  if (cursor->next == cursor) {
    cursor = NULL;
  } else {
    cursor->next = old->next;
  }

  delete old;
}

ostream& operator<<(ostream& os, CircleList& cl) {
  if (cl.empty()) return os;

  CNode* cur = cl.cursor;
  os << "[\"" << cl.front();

  cl.advance();
  while (cl.cursor != cur) {
    os << ", \"" << cl.front() << "\"";
    cl.advance();
  }

  os << "]\n";

  return os;
}
