#ifndef RUNTIMEEXCEPTION_H
#define RUNTIMEEXCEPTION_H

#include <string>

class RuntimeException {
  public:
    RuntimeException(const std::string& err) { errorMsg = err; }
    std::string getMessage() const { return errorMsg; }
  private:
    std::string errorMsg;
};

#endif
