#include "../include/segtree.h"

Segtree::Segtree(int size) {
  this->size = size;
  this->seg = new SegtreeNode[4 * size];
}

Segtree::~Segtree() { delete[] this->seg; }

Matrix *Segtree::build(int p, int l, int r) {
  if (l == r)
    return this->seg[p].matrix = new Matrix(2, 2);
  int m = (l + r) / 2;

  return seg[p].matrix = Matrix::matrix_mult(build(2 * p, l, m),
                                             build(2 * p + 1, m + 1, r));
}

Matrix *Segtree::query(int a, int b, int p, int l, int r) {
  if (b < l || r < a)
    return new Matrix(2, 2);

  if (a <= l && r <= b)
    return seg[p].matrix;

  int m = (l + r) / 2;

  return Matrix::matrix_mult(query(a, b, 2 * p, l, m),
                             query(a, b, 2 * p + 1, m + 1, r));
}

Matrix *Segtree::update(int i, Matrix *matrix, int p, int l, int r) {
  if (i < l || r < i)
    return seg[p].matrix;

  if (l == r) {
    return seg[p].matrix = matrix;
  }

  int m = (l + r) / 2;

  return seg[p].matrix =
             Matrix::matrix_mult(update(i, matrix, 2 * p, l, m),
                                 update(i, matrix, 2 * p + 1, m + 1, r));
}