#include "segtree.h"

Segtree::Segtree(int size) : size(size), seg(new SegtreeNode[4 * size]) {
  this->identity_matrix.set_identity();
}

Segtree::~Segtree() { delete[] seg; }

Matrix Segtree::build(int p, int l, int r) {
  if (l == r) {
    // Setando as posições do array de segmentos com  a matriz identidade
    seg[p].set_matrix(identity_matrix);
    return seg[p].get_matrix();
  }

  int m = (l + r) / 2;

  seg[p].set_matrix(
      Matrix::matrix_mult(build(2 * p, l, m), build(2 * p + 1, m + 1, r)));

  return seg[p].get_matrix();
}

Matrix Segtree::query(int a, int b, int p, int l, int r) {
  if (b < l || r < a)
    // Retornando a matrix identidade para não afetar os outros cálculos
    return identity_matrix;

  if (a <= l && r <= b)
    return seg[p].get_matrix();

  int m = (l + r) / 2;

  return Matrix::matrix_mult(query(a, b, 2 * p, l, m),
                             query(a, b, 2 * p + 1, m + 1, r));
}

Matrix Segtree::update(int i, Matrix &matrix, int p, int l, int r) {
  if (i < l || r < i)
    return seg[p].get_matrix();

  if (l == r) {
    seg[p].set_matrix(matrix);

    return seg[p].get_matrix();
  }

  int m = (l + r) / 2;

  seg[p].set_matrix(Matrix::matrix_mult(
      update(i, matrix, 2 * p, l, m), update(i, matrix, 2 * p + 1, m + 1, r)));

  return seg[p].get_matrix();
}
