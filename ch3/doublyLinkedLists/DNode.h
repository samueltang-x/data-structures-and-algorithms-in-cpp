#ifndef DNODE_H
#define DNODE_H

template <typename> class DLinkedList;

template <typename E>
std::ostream& operator<<(std::ostream& os, const DLinkedList<E>& dl);

template <typename E>
class DNode {
  private:
    E elem;
    DNode* prev;
    DNode* next;

    friend class DLinkedList<E>;
    friend std::ostream& operator<< <E>(std::ostream& os, const DLinkedList<E>& dl);
};

#endif
