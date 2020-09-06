#include <string>

typedef std::string Elem;

class CNode {
  private:
    Elem elem;
    CNode* next;

  friend class CircleList;
};
