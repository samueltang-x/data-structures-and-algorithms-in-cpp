#ifndef SNODE_H
#define SNODE_H

#include <iostream>

template <typename> class SLinkedList;

template <typename E>
std::ostream& operator<<(std::ostream& os, const SLinkedList<E>& l);

template <typename E>
class SNode {
  private:
    E elem;
    SNode* next;

    friend class SLinkedList<E>;
    friend std::ostream& operator<< <E>(std::ostream& os, const SLinkedList<E>& l);
};

#endif
