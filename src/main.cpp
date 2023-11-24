#include "../include/segtree.h"
#include <iostream>
#include <string>

void Last8Digits(std::string &str) { str = str.substr(str.length() - 8); }

int main() {
  int numInst, inst, numOps;
  int tB, tD;
  long unsigned int x, y;
  Point initial_point;
  char op;

  std::cin >> numInst;
  std::cin >> numOps;

  Segtree seg(numInst);
  seg.build(1, 0, numInst - 1);

  std::string str_x;
  std::string str_y;

  while (numOps--) {
    std::cin >> op;

    if (op == 'q') {
      std::cin >> tB;
      std::cin >> tD;
      std::cin >> x;
      std::cin >> y;

      initial_point.x = x;
      initial_point.y = y;
      Matrix *queryMatrix = seg.query(tB, tD, 1, 0, numInst - 1);

      Point result = queryMatrix->linearTransformation(initial_point);

      str_x = std::to_string(result.x);
      str_y = std::to_string(result.y);

      if (str_x.length() > 8)
        Last8Digits(str_x);

      if (str_y.length() > 8)
        Last8Digits(str_y);

      std::cout << str_x << " " << str_y << std::endl;
    }

    if (op == 'u') {
      Matrix *newMatrix = new Matrix(2, 2);
      std::cin >> inst;
      std::cin >> newMatrix;

      seg.update(inst, newMatrix, 1, 0, numInst - 1);
    }
  }
}
