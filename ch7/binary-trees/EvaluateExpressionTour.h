#ifndef GUARD_EVALUATEEXPRESSIONTOUR_H
#define GUARD_EVALUATEEXPRESSIONTOUR_H

#include "EulerTour.h"
#include <iostream>

template <typename E, typename R>
class EvaluateExpressionTour: public EulerTour<E, R> {
  protected:
    typedef EulerTour<E, R>::BinaryTree BinaryTree;
    typedef EulerTour<E, R>::Position Position;
    typedef EulerTour<E, R>::Result Result;

  public:
    void execute(const BinaryTree& t) {
      initialize(t);
      std::cout << "The value is: " << eulerTour(t.root()) << std::endl;
    }

  protected:
    virtual void visitExternal(const Position& p, Result& r) const {
      r.finalResult = p->value();
    }

    virtual void visitRight(const Position& p, Result& r) const {
      r.finalResult = p->operation(r.left, r.right);
    }
};

#endif
