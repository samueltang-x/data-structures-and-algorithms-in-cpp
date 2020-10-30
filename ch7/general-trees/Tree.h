#ifndef GUARD_TREE_H
#define GUARD_TREE_H

#include <list>

template <typename>
class Position;

template <typename E>
class Position {
  public:
    E& operator*();
    const E& operator*();
    Position parent() const;
    PositionList children() const;
    bool isRoot() const;
    bool isExternal();
  private:
    E elem;
    Position* p;
    std::list<Position*> c;
};


template <typename E>
class Tree {
  public:
    class Position;
    typedef std::list<Position> PositionList;
  public:
    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;
  private:
    position* _root;  // root of the Tree
    int num;  // the number of nodes of Tree
};

#endif
