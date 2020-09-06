#ifndef SNODE_H
#define SNODE_H

template <typename> class SLinkedList;

template <typename E>
class SNode {
    E elem;
    SNode<E>* next;

    friend class SLinkedList<E>;
    // template <typename> friend class SLinkedList;
};

#endif
