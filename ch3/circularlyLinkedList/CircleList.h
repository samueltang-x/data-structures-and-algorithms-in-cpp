#include <iostream>
#include "CNode.h"

class CircleList {
  public:
    CircleList();
    ~CircleList();
    
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void advance();
    void add(const Elem& e);
    void remove();
  private:
    CNode* cursor;

    friend std::ostream& operator<<(std::ostream& os, CircleList& cl);
};
