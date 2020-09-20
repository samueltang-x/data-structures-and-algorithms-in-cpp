#ifndef COUNTER_H
#define COUNTER_H

class Counter {
  public:
    Counter();
    int getCount();
    void increaseBy(int n);
  private:
    int count;
};

#endif