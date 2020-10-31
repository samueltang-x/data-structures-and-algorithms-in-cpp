#ifndef GUARD_PRINTEXRESSIONTOUR_H
#define GUARD_PRINTEXRESSIONTOUR_H

#include "EulerTour.h"
#include <iostream>

template <typename E, typename R>
class PrintExpressionTour: public EulerTour<E, R> {
  protected:
    typedef EulerTour<E, R>::BinaryTree BinaryTree;
    typedef EulerTour<E, R>::Position Position;
    typedef EulerTour<E, R>::Result Result;

  public:
    void execute(const BinaryTree& t) const {
      initialize(t);
      std::cout << "Expression: ";
      eulerTour(t.root());
      std::cout << endl;
    };

  protected:
    virtual void visitExternal(const Position& p, Result& r) const {
      std::cout << p->value();
    }

    virtual void visitLeft(const Position& p, Result& r) const {
      std::cout << "(";
    }

    virtual void visitBelow(cosnt Position& p, Result& r) const {
      std::cout << " " << p->value() << " ";
    }

    virtual void visitRigth(const Position& p, Result& r) const {
      std::cout << ")";
    }
}

#endif
