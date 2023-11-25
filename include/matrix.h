#ifndef MATRIX_H
#define MATRIX_H

#include "point.h"
#include <iostream>
#include <stdexcept>

#define matrix_type long unsigned int

class Matrix {
private:
  int rows, cols;
  matrix_type *data;

public:
  bool hasChanged;

  Matrix() : rows(2), cols(2) { Matrix(2, 2); }

  Matrix(int rows, int cols);
  ~Matrix();

  static Matrix* apply_delimiter(Matrix* m);

  static Matrix *matrix_mult(Matrix *a, Matrix *b);

  Point linear_transformation(Point point);
  
  matrix_type &operator()(int i, int j);
  const matrix_type &operator()(int i, int j) const;

  Matrix& operator=(const Matrix&);

  friend std::istream &operator>>(std::istream &is, Matrix *m);

  friend std::ostream &operator<<(std::ostream &os, const Matrix *m);
};

#endif // !MATRIX_H
