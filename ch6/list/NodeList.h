#ifndef GUARD_NODELIST_H
#define GUARD_NODELIST_H

#include <iostream>

template <typename>
class NodeList;

template <typename E>
std::ostream &operator<<(std::ostream &os, const NodeList<E> &l);

template <typename E>
typename NodeList<E>::Iterator operator+(typename NodeList<E>::Iterator p, int i);

template <typename E>
typename NodeList<E>::Iterator operator-(typename NodeList<E>::Iterator p, int i);

template <typename E>
class NodeList {
private:
  struct Node {
    E elem;
    Node *prev;
    Node *next;
  };

public:
  class Iterator {
  public:
    E &operator*();
    bool operator==(const Iterator &p) const;
    bool operator!=(const Iterator &p) const;
    Iterator &operator++();
    Iterator &operator--();
    Iterator operator++(int); // postfix
    Iterator operator--(int); // postfix
  private:
    Node *v;
    Iterator(Node *u);
    friend class NodeList;
    friend Iterator operator+<E>(Iterator p, int i);
    friend Iterator operator-<E>(Iterator p, int i);
  };

public:
  NodeList();
  ~NodeList();

  int size() const;
  bool empty() const;
  Iterator begin() const;
  Iterator end() const;
  void insertFront(const E &e);
  void insertBack(const E &e);
  void insert(const Iterator &p, const E &e);
  void eraseFront();
  void eraseBack();
  void erase(const Iterator &p);

private:
  int n;
  Node *header;
  Node *trailer;
  friend std::ostream &operator<<<E>(std::ostream &os, const NodeList &l);
};

template <typename E>
NodeList<E>::Iterator::Iterator(Node *u) : v(u) {}

template <typename E>
E &NodeList<E>::Iterator::operator*() {
  return v->elem;
}

template <typename E>
bool NodeList<E>::Iterator::operator==(const Iterator &p) const {
  return v == p.v;
}

template <typename E>
bool NodeList<E>::Iterator::operator!=(const Iterator &p) const {
  return v != p.v;
}

template <typename E>
typename NodeList<E>::Iterator &NodeList<E>::Iterator::operator++() {
  v = v->next;
  return *this;
}

template <typename E>
typename NodeList<E>::Iterator &NodeList<E>::Iterator::operator--() {
  v = v->prev;
  return *this;
}

template <typename E>
typename NodeList<E>::Iterator NodeList<E>::Iterator::operator++(int) {
  Iterator temp(v);
  v = v->next;
  return temp;
}

template <typename E>
typename NodeList<E>::Iterator NodeList<E>::Iterator::operator--(int) {
  Iterator temp(v);
  v = v->prev;
  return temp;
}

template <typename E>
NodeList<E>::NodeList() {
  n = 0;
  header = new Node;
  trailer = new Node;
  header->next = trailer;
  trailer->prev = header;
}

template <typename E>
NodeList<E>::~NodeList() {
  while (!empty())
    eraseFront();
  delete header;
  delete trailer;
}

template <typename E>
int NodeList<E>::size() const {
  return n;
}

template <typename E>
bool NodeList<E>::empty() const {
  return n == 0;
}

template <typename E>
typename NodeList<E>::Iterator NodeList<E>::begin() const {
  return Iterator(header->next);
}

template <typename E>
typename NodeList<E>::Iterator NodeList<E>::end() const {
  return Iterator(trailer);
}

template <typename E>
void NodeList<E>::insertFront(const E &e) {
  insert(begin(), e);
}

template <typename E>
void NodeList<E>::insertBack(const E &e) {
  insert(end(), e);
}

template <typename E>
void NodeList<E>::insert(const Iterator &p, const E &e) {
  Node *v = new Node;
  v->elem = e;

  Node *w = p.v;
  Node *u = w->prev;

  v->prev = u;
  u->next = v;

  v->next = w;
  w->prev = v;
  n++;
}

template <typename E>
void NodeList<E>::eraseFront() {
  erase(begin());
}

template <typename E>
void NodeList<E>::eraseBack() {
  erase(--end());
}

template <typename E>
void NodeList<E>::erase(const Iterator &p) {
  Node *v = p.v;
  Node *u = v->prev;
  Node *w = v->next;

  u->next = w;
  w->prev = u;

  delete v;
  n--;
}

template <typename E>
std::ostream &operator<<(std::ostream &os, const NodeList<E> &l) {
  std::cout << '(';
  for (typename NodeList<E>::Iterator i = l.begin(); i != l.end(); ++i)
    std::cout << (i == l.begin() ? "" : ", ") << *i;
  std::cout << ')';
  return os;
}

template <typename E>
typename NodeList<E>::Iterator operator+(typename NodeList<E>::Iterator p, int i) {
  for (int j = 0; j < i; ++j) ++p;
  return p;
}

template <typename E>
typename NodeList<E>::Iterator operator-(typename NodeList<E>::Iterator p, int i) {
  for (int j = 0; j < i; ++j) --p;
  return p;
}

#endif
