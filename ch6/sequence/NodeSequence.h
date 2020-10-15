#ifndef GUARD_NODESEQUENCE_H
#define GUARD_NODESEQUENCE_H

#include "../../misc/extendExceptions.h"
#include "../list/NodeList.h"

template <typename E>
class NodeSequence : public NodeList<E> {
public:
  typename NodeList<E>::Iterator atIndex(int i) const;
  int indexOf(const typename NodeList<E>::Iterator &p) const;
};

template <typename E>
typename NodeList<E>::Iterator NodeSequence<E>::atIndex(int i) const {
  int n = NodeList<E>::size();
  if (i < 0 || i >= n)
    throw IndexOutOfBounds("illegal index in function atIndex of NodeSequence");
  if (i > n / 2) {  // walks from end
    /*
     * FIXME: issue when using iterator arithmetic
    typename NodeList<E>::Iterator e = NodeList<E>::end();
    return e - (n - i);
    */
    // workaround start
    typename NodeList<E>::Iterator p = NodeList<E>::end();
    for (int j = n - 1; j >= i; --j)
      --p;
    return p;
    // workaround end
  } else {  // walks from header
    /*
     * FIXME: inssue when using iterator arithmetic
    return NodeList<E>::begin() + i;
     */
    // workaround start
    typename NodeList<E>::Iterator q = NodeList<E>::begin();
    for (int j = 0; j < i; ++j)
      ++q;
    return q;
    // workaround end
  }
}

template <typename E>
int NodeSequence<E>::indexOf(const typename NodeList<E>::Iterator &p) const {
  int idx = -1;
  for (typename NodeList<E>::Iterator i = NodeList<E>::begin(); i != NodeList<E>::end(); ++i) {
    ++idx;
    if (i == p)
      return idx;
  }
  return -1;
}

#endif
