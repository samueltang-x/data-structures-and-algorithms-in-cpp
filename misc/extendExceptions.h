#ifndef EXTENDEXCEPTIONS_H
#define EXTENDEXCEPTIONS_H

#include <string>
#include <iostream>

class RuntimeException {
public:
  RuntimeException(const std::string& err) { errorMsg = err; }
  std::string getMessage() const { return errorMsg; }

private:
  std::string errorMsg;
  friend std::ostream& operator<<(std::ostream& os, const RuntimeException& e);
};

class ListEmpty: public RuntimeException {
public:
  ListEmpty(const std::string& err): RuntimeException(err) {}
};

class StackEmpty: public RuntimeException {
public:
  StackEmpty(const std::string& err): RuntimeException(err) {}
};

class StackFull: public RuntimeException {
public:
  StackFull(const std::string& err): RuntimeException(err) {}
};

class IndexOutOfBounds: public RuntimeException {
  public:
    IndexOutOfBounds(const std::string& msg): RuntimeException(msg) {}
};

std::ostream& operator<<(std::ostream& os, const RuntimeException& e) {
  os << e.errorMsg;
  return os;
}

#endif
