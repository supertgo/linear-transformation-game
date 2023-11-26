#ifndef POINT_H
#define POINT_H

#include <iostream>

#define matrix_type long unsigned int

class Point {
public:
  matrix_type x, y;

  /**
   * Sobrecarga do operador de saída para imprimir as coordenadas do ponto em
   * uma stream.
   *
   * @param os Stream de saída.
   * @param p Ponto a ser impresso.
   * @return Referência à stream de saída após a impressão.
   */
  friend std::ostream &operator<<(std::ostream &os, const Point p) {
    matrix_type delimiter = 1e8;
    os << p.x % delimiter << " " << p.y % delimiter << std::endl;
    return os;
  }
};

#endif // !POINT_H
