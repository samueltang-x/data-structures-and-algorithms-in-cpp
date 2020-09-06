#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include "../../ch2/RuntimeException.h"
#include "SNode.h"

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
  if (empty()) throw RuntimeException("get front of empty SLinkedList");
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
  if (empty()) throw RuntimeException("remove front of empty SLinkedList");
  SNode<E>* old = head;
  head = head->next;
  delete old;
}


#endif
