#include "matrix.h"

Matrix::Matrix(int rows, int cols) {
  this->data = new matrix_type[rows * cols];
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

Matrix::~Matrix() { delete[] this->data; }

Matrix *Matrix::matrix_mult(Matrix *a, Matrix *b) {
  Matrix *c = new Matrix(a->rows, b->cols);

  for (int i = 0; i < c->rows * c->cols; i++) {
    c->data[i] = 0;
  }

  matrix_type delimiter = 1e8;

  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < b->cols; j++) {
      for (int k = 0; k < a->cols; k++) {
        (*c)(i, j) += (*a)(i, k) * (*b)(k, j);
      }
      (*c)(i, j) %= delimiter;
    }
  }

  return c;
}

Point Matrix::linear_transformation(Point point) {
  return {((*this)(0, 0) * point.x) + ((*this)(0, 1) * point.y),
          ((*this)(1, 0) * point.x) + ((*this)(1, 1) * point.y)};
}

matrix_type &Matrix::operator()(int i, int j) { return data[i * cols + j]; }

const matrix_type &Matrix::operator()(int i, int j) const {
  return data[i * cols + j];
}

Matrix &Matrix::operator=(const Matrix &m) {
  for (int i = 0; i < this->rows * this->cols; i++) {
    this->data[i] = m.data[i];
  }

  return *this;
}

std::istream &operator>>(std::istream &is, Matrix *m) {
  for (int i = 0; i < m->rows; ++i) {
    for (int j = 0; j < m->cols; ++j) {
      is >> (*m)(i, j);
    }
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, const Matrix *m) {
  for (int i = 0; i < m->rows; ++i) {
    os << (*m)(i, 0);
    for (int j = 1; j < m->cols; ++j) {
      os << " " << (*m)(i, j);
    }
    os << std::endl;
  }
  return os;
}
