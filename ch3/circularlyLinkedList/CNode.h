#ifndef CNODE_H
#define CNODE_H

#include <iostream>
#include <string>

template <typename>
class CircleList;

template <typename E>
std::ostream& operator<<(std::ostream& os, const CircleList<E>& cl);

template <typename E>
class CNode {
  private:
    E elem;
    CNode* next;

    friend class CircleList<E>;
    friend std::ostream& operator<< <E>(std::ostream& os, const CircleList<E>& cl);
};

#endif
