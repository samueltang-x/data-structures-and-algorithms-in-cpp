#ifndef RUNTIMEEXCEPTION.H
#define RUNTIMEEXCEPTION.H

class RuntimeException {
  public:
    RuntimeException(const string& err) { errorMsg = err; }
    string getMessage() const { return errorMsg; }
  private:
    string errorMsg;
};

#endif
