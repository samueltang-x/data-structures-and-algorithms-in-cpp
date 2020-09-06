#ifndef STRINGNODE_H
#define STRINGNODE_H

#include <string>

class StringNode {
  private:
    std::string elem;
    StringNode* next;

    friend class StringLinkedList;
};

#endif
