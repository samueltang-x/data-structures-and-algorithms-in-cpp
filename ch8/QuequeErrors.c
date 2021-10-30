#include "../misc/extendExceptions.h"

class EmptyQueueException: public RuntimeException {
  public:
    EmptyQueue(std::string msg): RuntimeException(msg) {}
};
