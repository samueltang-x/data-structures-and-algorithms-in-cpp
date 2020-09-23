#include "QueueExceptions.h"
#include <iostream>

template <typename>
class ArrayQueue;

template <typename E>
std::ostream& operator<<(std::ostream& os, const ArrayQueue<E>& q);

template <typename E>
class ArrayQueue {
  public:
    ArrayQueue(int cap = 100);

    int size() const;
    bool empty() const;
    const E& top() const;
    void enqueue(const E& e);
    void dequeue();

  private:
    E* a;
    int capacity;
    int f;
    int r;
    int n;

    friend std::ostream& operator<< <E>(std::ostream& os, const ArrayQueue& q);
};

template <typename E>
ArrayQueue<E>::ArrayQueue(const int cap)
: capacity(cap), f(0), r(0), n(0), a(new E[cap]) {}

template <typename E>
int ArrayQueue<E>::size() const {
  return n;
}

template <typename E>
bool ArrayQueue<E>::empty() const {
  return n == 0;
}

template <typename E>
const E& ArrayQueue<E>::top() const {
  if (empty()) throw QueueEmpty("Top of the empty ArrayQueue");
  return a[f];
}

template <typename E>
void ArrayQueue<E>::enqueue(const E& e) {
  if (n == capacity) throw QueueFull("Enqueue to the full ArrayQueue");
  a[n++] = e;
  r = ++r % capacity;
}

template <typename E>
void ArrayQueue<E>::dequeue() {
  f = ++f % capacity;
  n--;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const ArrayQueue<E>& q) {
  if (!q.empty()) {
    for (int i = 0; i < q.n; i++)
      os << q.a[q.f+i] << (i == q.n-1 ? "\n" : "->");
  }
  return os;
}
