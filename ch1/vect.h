class Vect {
  public:
    Vect(int n);
    Vect(const Vect& v);

    Vect& operator=(const Vect& v);

    ~Vect();
  private:
    int size;
    int* data;
};
