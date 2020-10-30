#ifndef GUARD_LINKEDBINARYTREE_H
#define GUARD_LINKEDBINARYTREE_H

#include "../../misc/extendExceptions.h"
#include <list>

template <typename E>
class LinkedBinaryTree {
protected:
  struct Node {
    E elem;
    Node* par;
    Node* left;
    Node* right;

    Node() : elem(), par(NULL), left(NULL), right(NULL) {}
  };

public:
  class Position {
  public:
    Position(Node* _v = NULL) : v(_v) {}
    E& operator*() { return v->elem; }
    Position parent() const { return Position(v->par); }  // TODO: error checking
    Position left() const { return Position(v->left); } // TODO: error checking
    Position right() const { return Position(v->right); } // TODO: error checking
    bool isRoot() const { return v->par == NULL; }
    bool isExternal() const { return v->left == NULL && v->right == NULL; }

  private:
    Node* v;

    friend class LinkedListTree;
  };
  typedef std::list<Position> PositionList;

public:
  LinkedBinaryTree();
  int size() const;
  bool empty() const;
  Position root() const;
  PositionList positions() const;
  void addRoot();
  void expandExternal(const Position& p);
  Position removeAboveExternal(const Position& p);

protected:
  void preorder(Node* v, PositionList& pl) const;

private:
  Node* _root;
  int n;
};

template <typename E>
LinkedBinaryTree<E>::LinkedBinaryTree() : _root(NULL), n(0) {
}

template <typename E>
int LinkedBinaryTree<E>::size() const { return n; }

template <typename E>
bool LinkedBinaryTree<E>::empty() const { return size() == 0; }

template <typename E>
typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::root() const { return Position(_root); }

template <typename E>
void LinkedBinaryTree<E>::addRoot() {
  if (!empty()) throw RuntimeException("addRoot() of a non-empty LinkedBinaryTree");

  _root = new Node;
  n = 1;
}

template <typename E>
void LinkedBinaryTree<E>::expandExternal(const Position& p) {
  if (!p.isExternal()) throw RuntimeException("expandExternal() of an internal position");

  Node* v = p.v;
  v->left = new Node;
  v->left->par = v;
  v->right = new Node;
  v->right->par = v;
  n += 2;
}

template <typename E>
typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::removeAboveExternal(const Position& p) {
  if (p.isExternal()) throw RuntimeException("removeAboveExternal() of an internal position");
  Node* cur = p.v;
  if (p.isRoot()) {
    delete cur;
    _root = NULL;
    n = 0;
    return Position();
  }

  Node* par = cur->par;
  Node* sib = par->left == cur ? par->right : par->left;
  Node* gpar = par->par;
  if (gpar == NULL) _root = sib;
  else {
    if (gpar->left == par) gpar->left = sib;
    else gpar->right = sib;
  }
  sib->par = gpar;

  delete cur;
  delete par;
  n -= 2;
  return Position(sib);
}

template <typename E>
void LinkedBinaryTree<E>::preorder(Node* v, PositionList& pl) const {
  pl.push_back(Position(v));
  if (v->left != NULL) preorder(v->left, pl);
  if (v->right != NULL) preorder(v->right, pl);
}

template <typename E>
typename LinkedBinaryTree<E>::PositionList LinkedBinaryTree<E>::positions() const {
  PositionList pl;
  preorder(_root, pl);
  return pl;
}

#endif

