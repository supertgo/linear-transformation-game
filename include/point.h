#ifndef POINT_H
#define POINT_H

#include <iostream>

#define matrix_type long unsigned int

class Point {
public:
  matrix_type x, y;

  friend std::ostream &operator<<(std::ostream &os, const Point p) {
    matrix_type delimiter = 1e8;
    os << p.x % delimiter << " " << p.y % delimiter << std::endl;
    return os;
  }
};

#endif // !POINT_H
