#include <string>
#include "../../ch2/RuntimeException.h"

class StackEmpty: public RuntimeException {
  public:
    StackEmpty(const std::string& err): RuntimeException(err) {}
};

class StackFull: public RuntimeException {
  public:
    StackFull(const std::string& err): RuntimeException(err) {}
};
