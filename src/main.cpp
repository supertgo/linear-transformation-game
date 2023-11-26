#include "segtree.h"
#include <iostream>
#include <stdexcept>

int main() {
  int instants, inst, operations_count;
  int t0, tD;
  long unsigned int x, y;
  char operation;

  std::cin >> instants;
  std::cin >> operations_count;

  Segtree seg(instants);
  seg.build(1, 0, instants - 1);
  try {
    while (operations_count--) {
      std::cin >> operation;

      switch (operation) {
        case 'q': {

          std::cin >> t0 >> tD >> x >> y;

          Point initial_point = {x, y};

          Matrix query_matrix = seg.query(t0, tD, 1, 0, instants - 1);

          std::cout << query_matrix.linear_transformation(initial_point)
                    << std::endl;
          break;
        }

        case 'u': {
          Matrix new_matrix(2, 2);

          std::cin >> inst;
          std::cin >> new_matrix;

          seg.update(inst, new_matrix, 1, 0, instants - 1);
          break;
        }
        default: {
          throw std::invalid_argument("Invalid operation: " + std::string(1, operation));
        }
      }
    }

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
