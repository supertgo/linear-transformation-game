#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>

typedef struct point_t {
  long unsigned int x, y;
} Point;

class Matrix {
private:
  int rows, cols;
  bool hasChanged;

public:
  int *data;
  Matrix() : rows(2), cols(2) { Matrix(2, 2); }

  Matrix(int rows, int cols) {
    this->data = new int[rows * cols];
    this->cols = cols;
    this->rows = rows;
    this->hasChanged = false;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (i == j) {
          (*this)(i, j) = 1;
        } else {
          (*this)(i, j) = 0;
        }
      }
    }
  }

  Point linearTransformation(Point point) {
    Point result;
    result.x = ((*this)(0, 0) * point.x) + ((*this)(0, 1) * point.y);
    result.y = ((*this)(1, 1) * point.x) + ((*this)(1, 1) * point.y);
    return result;
  }

  ~Matrix() { delete[] this->data; }

  int &operator()(int i, int j) { return data[i * cols + j]; }

  const int &operator()(int i, int j) const { return data[i * cols + j]; }

  Matrix *operator*(Matrix *b) {
    if (this->cols != b->rows)
      throw std::invalid_argument("Number of columns in first matrix must be "
                                  "equal to number of rows in second matrix");

    Matrix *c = new Matrix(this->rows, b->cols);

    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < b->cols; j++) {
        for (int k = 0; k < this->cols; k++) {
          (*c)(i, j) += (*this)(i, k) * (*b)(k, j);
        }
      }
    }
    return c;
  }
  Matrix *matrix_mult(Matrix *a, Matrix *b) {
    if (a->cols != b->rows)
      throw std::invalid_argument("Number of columns in first matrix must be "
                                  "equal to number of rows in second matrix");

    Matrix *c = new Matrix(a->rows, b->cols);

    for (int i = 0; i < a->rows; i++) {
      for (int j = 0; j < b->cols; j++) {
        for (int k = 0; k < a->cols; k++) {
          (*c)(i, j) += (*a)(i, k) * (*b)(k, j);
        }
      }
    }
    return c;
  }

  friend std::istream &operator>>(std::istream &is, Matrix *m) {
    for (int i = 0; i < m->rows; ++i) {
      for (int j = 0; j < m->cols; ++j) {
        is >> (*m)(i, j);
      }
    }
    return is;
  }

  friend std::ostream &operator<<(std::ostream &os, const Matrix *m) {
    for (int i = 0; i < m->rows; ++i) {
      os << (*m)(i, 0);
      for (int j = 1; j < m->cols; ++j) {
        os << " " << (*m)(i, j);
      }
      os << std::endl;
    }
    return os;
  }
};

#endif // !MATRIX_H
