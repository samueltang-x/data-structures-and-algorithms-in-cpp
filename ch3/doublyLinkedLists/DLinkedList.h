#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <string>
#include "DNode.h"
#include "../../misc/extendExceptions.h"

template <typename T>
class DLinkedList;

template <typename T>
std::ostream& operator<<(std::ostream& os, DLinkedList<T>& dl);

template <typename T>
class DLinkedList {
  public:
    DLinkedList();
    ~DLinkedList();

    bool empty() const;
    const T& front() const;
    const T& back() const;
    void addFront(const T& n);
    void addBack(const T& n);
    void removeFront();
    void removeBack();

  protected:
    void add(DNode<T>* v, const T& n);
    void remove(DNode<T>* v);

  private:
    DNode<T>* header;
    DNode<T>* trailer;

    friend std::ostream& operator<< <T>(std::ostream& os, DLinkedList& dl);
};

template <typename T>
DLinkedList<T>::DLinkedList() {
  header = new DNode<T>;
  trailer = new DNode<T>;
  header->next = trailer;
  trailer->prev = header;
}

template <typename T>
DLinkedList<T>::~DLinkedList() {
  while (!empty()) removeFront();
  delete header;
  delete trailer;
}

template <typename T>
bool DLinkedList<T>::empty() const {
  return header->next == trailer;
}

template <typename T>
const T& DLinkedList<T>::front() const {
  if (empty()) throw ListEmpty("Get front of empty DLinkedList");
  return header->next->elem;
}

template <typename T>
const T& DLinkedList<T>::back() const {
  if (empty()) throw ListEmpty("Get back of empty DLinkedList");
  return trailer->prev->elem;
}

template <typename T>
void DLinkedList<T>::addFront(const T& e) {
  add(header->next, e);
}

template <typename T>
void DLinkedList<T>::addBack(const T& e) {
  add(trailer, e);
}

template <typename T>
void DLinkedList<T>::removeFront() {
  if (empty()) throw ListEmpty("Remove front of empty DLinkedList");
  remove(header->next);
}

template <typename T>
void DLinkedList<T>::removeBack() {
  if (empty()) throw ListEmpty("Remove back of empty DLinkedList");
  remove(trailer->prev);
}

template <typename T>
void DLinkedList<T>::add(DNode<T>* v, const T& e) {
  DNode<T>* n = new DNode<T>;
  n->elem = e;
  n->prev = v->prev;
  n->next = v;

  v->prev->next = n;
  v->prev = n;
}

template <typename T>
void DLinkedList<T>::remove(DNode<T>* v) {
  v->prev->next = v->next;
  v->next->prev = v->prev;
  delete v;
}

template <typename T>
void listReverse(DLinkedList<T>& dl) {
  DLinkedList<T> t;
  while (!dl.empty()) {
    t.addFront(dl.front());
    dl.removeFront();
  }

  while (!t.empty()) {
    dl.addBack(t.front());
    t.removeFront();
  }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, DLinkedList<T>& dl) {
  os << "[";
  DLinkedList<T> t;
  while (!dl.empty()) {
    T e = dl.front();
    t.addBack(e);
    os << e;

    dl.removeFront();

    if (!dl.empty()) os << ",";
  }
  os << "]";

  while(!t.empty()) {
    dl.addBack(t.front());
    t.removeFront();
  }

  return os;
}

#endif