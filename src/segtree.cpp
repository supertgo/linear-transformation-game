#include "../include/segtree.h"

// Implementations for Segtree methods
Segtree::Segtree(int size) : size(size), seg(new SegtreeNode[4 * size]) {
  this->identity_matrix.set_identity();
}
Segtree::~Segtree() { delete[] seg; }

Matrix Segtree::build(int p, int l, int r) {
  if (l == r) {
    seg[p].setMatrix(identity_matrix);
    return seg[p].getMatrix();
  }

  int m = (l + r) / 2;

  Matrix leftMatrix = build(2 * p, l, m);
  Matrix rightMatrix = build(2 * p + 1, m + 1, r);

  seg[p].setMatrix(Matrix::matrix_mult(leftMatrix, rightMatrix));
  return seg[p].getMatrix();
}

Matrix Segtree::query(int a, int b, int p, int l, int r) {
  if (b < l || r < a)
    return identity_matrix;

  if (a <= l && r <= b)
    return seg[p].getMatrix();

  int m = (l + r) / 2;

  return Matrix::matrix_mult(query(a, b, 2 * p, l, m),
                             query(a, b, 2 * p + 1, m + 1, r));
}

Matrix Segtree::update(int i, Matrix &matrix, int p, int l, int r) {
  if (i < l || r < i)
    return seg[p].getMatrix();

  if (l == r) {
    matrix.hasChanged = true;
    seg[p].setMatrix(matrix);

    return seg[p].getMatrix();
  }

  int m = (l + r) / 2;

  matrix.hasChanged = true;
  seg[p].setMatrix(Matrix::matrix_mult(update(i, matrix, 2 * p, l, m),
                                       update(i, matrix, 2 * p + 1, m + 1, r)));

  return seg[p].getMatrix();
}
