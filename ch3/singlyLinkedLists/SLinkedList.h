#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include "../../misc/extendExceptions.h"
#include "SNode.h"
#include <iostream>

template <typename E>
std::ostream& operator<<(std::ostream& os, const SLinkedList<E>& s);

template <typename E>
class SLinkedList {
  public:
    SLinkedList();
    ~SLinkedList();

    bool empty() const;
    const E& front() const;
    void addFront(const E& e);
    void removeFront();

  private:
    SNode<E>* head;

    friend std::ostream& operator<< <E>(std::ostream& os, const SLinkedList& s);

};

template <typename E>
SLinkedList<E>::SLinkedList()
  : head(NULL) {}

template <typename E>
SLinkedList<E>::~SLinkedList() {
  while (!empty()) removeFront();
}

template <typename E>
bool SLinkedList<E>::empty() const {
  return (head == NULL);
}

template <typename E>
const E& SLinkedList<E>::front() const {
  if (empty()) throw ListEmpty("Get front of empty SLinkedList");
  return head->elem;
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {
  SNode<E>* s = new SNode<E>;
  s->elem = e;
  s->next = head;
  head = s;
}

template <typename E>
void SLinkedList<E>::removeFront() {
  if (empty()) throw ListEmpty("Remove front of empty SLinkedList");
  SNode<E>* old = head;
  head = head->next;
  delete old;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const SLinkedList<E>& s) {
  if (s.empty()) os << "Empty list\n";
  else {
    for (SNode<E>* n = s.head; n != NULL; n = n->next)
      os << (n == s.head ? "" : "->") << n->elem;

    os << std::endl;
  }
  return os;
}


#endif
