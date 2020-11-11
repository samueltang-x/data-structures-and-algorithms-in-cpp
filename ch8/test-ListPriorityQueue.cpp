#include "ListPriorityQueue.h"
#include <cstdlib>
#include <iostream>

using namespace std;

struct Point2D {
  double x;
  double y;

  Point2D(double _x = 0, double _y = 0) {
    x = _x;
    y = _y;
  }
};

ostream& operator<<(ostream& os, const Point2D& p) {
  cout << "(" << p.x << ", " << p.y << ")" << endl; 
  return os;
}

class LeftRight {
  public:
    bool operator()(const Point2D& p, const Point2D& q) const {
      return p.x < q.x;
    }
};

class BottomTop {
  public:
    bool operator()(const Point2D& p, const Point2D& q) const {
      return p.y < q.y;
    }
};

class IntComparator {
  public:
    bool operator()(const int& p, const int& q) const {
      return p < q;
    }
};

void testPriorityQueueInt() {
  ListPriorityQueue<int, IntComparator> intQ;
  intQ.push(5);
  intQ.push(9);
  intQ.push(2);
  intQ.push(7);

  cout << "intQ, size: " << intQ.size() << ",\n";
  cout << "  content: ";
  while(!intQ.empty()) {
    cout << intQ.top() << " ";
    intQ.pop();
  }

  cout << endl;
}

void testPoint2D() {
  ListPriorityQueue<Point2D, LeftRight> p1;
  p1.push(Point2D(8.5, 4.6));
  p1.push(Point2D(1.3, 5.7));
  p1.push(Point2D(2.5, 0.6));
  cout << "LeftRight" << endl;
  cout << p1.top(); p1.pop();
  cout << p1.top(); p1.pop();
  cout << p1.top(); p1.pop();

  ListPriorityQueue<Point2D, BottomTop> p2;
  p2.push(Point2D(8.5, 4.6));
  p2.push(Point2D(1.3, 5.7));
  p2.push(Point2D(2.5, 0.6));
  cout << "BottomTop" << endl;
  cout << p2.top(); p2.pop();
  cout << p2.top(); p2.pop();
  cout << p2.top(); p2.pop();
}

int main() {
  testPriorityQueueInt();
  testPoint2D();
  return EXIT_SUCCESS;
}
