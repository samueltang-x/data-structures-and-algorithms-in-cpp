#ifndef GUARD_QUEUEEXCEPTIONS.H
#define GUARD_QUEUEEXCEPTIONS.H

#include "../../misc/extendExceptions.h"
#include <string>

class QueueEmpty: public RuntimeException {
  public:
    QueueEmpty(const std::string& msg): RuntimeException(msg) {}
};

class QueueFull: public RuntimeException {
  public:
    QueueFull(const std::string& msg): RuntimeException(msg) {}
};

#endif
