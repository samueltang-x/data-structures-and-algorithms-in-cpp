#ifndef DNODE_H
#define DNODE_H

template <typename> class DLinkedList;

template <typename E>
class DNode {
  private:
    E elem;
    DNode<E>* prev;
    DNode<E>* next;

    friend class DLinkedList<E>;
};

#endif
