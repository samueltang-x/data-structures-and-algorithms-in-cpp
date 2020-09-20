#ifndef CNODE_H
#define CNODE_H

#include <string>

typedef std::string Elem;

class CNode {
  private:
    Elem elem;
    CNode* next;

  friend class CircleList;
};

#endif