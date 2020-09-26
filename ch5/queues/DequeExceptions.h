#ifndef GUARD_DEQUEEXCEPTIONS_H
#define GUARD_DEQUEEXCEPTIONS_H

#include "../../misc/extendExceptions.h"
#include <string>

class DequeEmpty: public RuntimeException {
  public:
    DequeEmpty(const std::string& msg): RuntimeException(msg) {}
};

#endif
