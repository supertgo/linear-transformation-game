#include "segtree.h"
#include <iostream>
#include <string>

int main() {
  int instants, inst, operations_count;
  int t0, tD;
  long unsigned int x, y;
  char op;

  std::cin >> instants;
  std::cin >> operations_count;

  Segtree seg(instants);
  seg.build(1, 0, instants - 1);

  while (operations_count--) {
    std::cin >> op;

    switch (op) {
    case 'q': {

      std::cin >> t0 >> tD >> x >> y;

      Point initial_point = {x, y};

      Matrix *queryMatrix = seg.query(t0, tD, 1, 0, instants - 1);

      std::cout << queryMatrix->linear_transformation(initial_point)
                << std::endl;
      break;
    }

    case 'u': {
      Matrix *newMatrix = new Matrix(2, 2);
      std::cin >> inst;
      std::cin >> newMatrix;

      seg.update(inst, newMatrix, 1, 0, instants - 1);
      break;
    }
    }
  }
}
