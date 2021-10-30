#include "../ch6/list/NodeList.h"
#include "QuequeErrors.c"

template <typename E, typename C>
class ListPriorityQueue {
public:
  int size() const;
  bool empty() const;
  void push(const E& e);
  const E& top() const;
  void pop();
private:
  NodeList<E> l;
  C isLess;
};

template <typename E, typename C>
int ListPriorityQueue<E, C>::size() const {
  return l.size();
}

template <typename E, typename C>
bool ListPriorityQueue<E, C>::empty() const {
  return l.empty();
}

template <typename E, typename C>
void ListPriorityQueue<E, C>::push(const E& e) {
  typename NodeList<E>::Iterator iter = l.begin();
  while ( iter != l.end() && !isLess(e, *iter) ) ++iter;

  l.insert(iter, e);
}

template <typename E, typename C>
const E& ListPriorityQueue<E, C>::top() const {
  if (empty()) throw EmptyQueue("top() of an empty ListPriorityQuque");

  return *(l.begin());
}

template <typename E, typename C>
void ListPriorityQueue<E, C>::pop() {
  if (empty()) throw EmptyQueue("pop() of an empty ListPriorityQueue");

  l.eraseFront();
}
