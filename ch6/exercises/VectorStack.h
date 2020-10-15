#include <iostream>
#include <vector>

template <typename>
class VectorStack;

template <typename E>
std::ostream& operator<<(std::ostream& os, const VectorStack<E>& s);

template <typename E>
class VectorStack {
  public:
    VectorStack();

    int size() const;
    bool empty() const;
    const E& top() const;
    void push(const E& e);
    void pop();
  private:
    std::vector<E> v;
    friend std::ostream& operator<< <E>(std::ostream& os, const VectorStack& s);
};

template <typename E>
VectorStack<E>::VectorStack(): v() {}

template <typename E>
int VectorStack<E>::size() const {
  return v.size();
}

template <typename E>
bool VectorStack<E>::empty() const {
  return v.size() == 0;
}

template <typename E>
const E& VectorStack<E>::top() const {
  return v.back();
}

template <typename E>
void VectorStack<E>::push(const E& e) {
  v.push_back(e);
}

template <typename E>
void VectorStack<E>::pop() {
  v.pop_back();
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const VectorStack<E>& s) {
  if (s.empty()) return std::cout;

  typedef typename std::vector<E>::const_iterator it;
  for (it i = s.v.begin(); i != s.v.end(); ++i) std::cout << (i == s.v.begin() ? "" : ",") << *i;
  return std::cout;
}
