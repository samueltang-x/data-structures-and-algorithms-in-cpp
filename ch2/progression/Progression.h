#ifndef PROGRESSION_H
#define PROGRESSION_H

class Progression {
  public:
    Progression(long f = 0)
      : first(f), cur(f) {}

    ~Progression() {}

    void printProgression(int n);

  protected:
    virtual long firstValue();
    virtual long nextValue();
  protected:
    long first;
    long cur;
};

#endif