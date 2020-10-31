#ifndef GUARD_EULERTOUR_H
#define GUARD_EULERTOUR_H

#include "LinkedBinaryTree.h"

template <typename E, typename R>
class EulerTour {
  protected:
    struct Result {
      R leftResult;
      R rightResult;
      R finalResult;
    };

    typedef LinkedBinaryTree<E> BinaryTree;
    typedef BinaryTree::Position Position;

  protected:
    BinaryTree* tree;
  public:
    void initialize(const BinaryTree& t) { tree = &t; }
  protected:
    R eulerTour(const Position& p) const;
    virtual void visitExternal(const Position& p, Result& r) const {}
    virtual void visitLeft(const Position& p, Result& r) const {}
    virtual void visitBelow(const Position& p, Result& r) const {}
    virtual void visitRight(const Position& p, Result& r) const {}
    Result initResult() const { return Result(); }
    R result(const Result& r) const { return r.finalResult; }
};

template <typename E, typename R>
R EulerTour<E, R>::eulerTour(const Position& p) const {
  Result r = initResult();

  if (p.isExternal()) {
    visitExternal(p, r);
  } else {
    visitLeft(p, r);
    r.leftResult = eulerTour(p.left());
    visitBelow(p, r);
    r.right = eulerTour(p.right());
    visitRight(p, r);
  }

  return result();
}

#endif
