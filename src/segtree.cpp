#include "../include/segtree.h"

Segtree::Segtree(int size) {
  this->size = size;
  this->v = new SegtreeNode[size];
  this->seg = new SegtreeNode[4 * size];
}

Segtree::~Segtree() {
  delete[] this->v;
  delete[] this->seg;
}

Matrix *Segtree::build(int p, int l, int r) {
  if (l == r)
    return this->seg[p].matrix = this->v[l].matrix;
  int m = (l + r) / 2;

  Matrix *a = build(2 * p, l, m);
  Matrix *b = build(2 * p + 1, m + 1, r);

  return seg[p].matrix = a->matrix_mult(a, b);
}

Matrix *Segtree::query(int a, int b, int p, int l, int r) {
  if (b < l || r < a)
    return new Matrix(2, 2);
  if (a <= l && r <= b)
    return seg[p].matrix;

  int m = (l + r) / 2;

  Matrix *m1 = query(a, b, 2 * p, l, m);
  Matrix *m2 = query(a, b, 2 * p + 1, m + 1, r);

  return m1->matrix_mult(m1, m2);
}

// Matrix *Segtree::update(int i, int x, int p, int l, int r) {
//   if (i < l || r < i)
//     return seg[p].matrix;
//   if (l == r)
//     return seg[p].matrix;

//   int m = (l + r) / 2;

//   Matrix *m1 = update(i, x, 2 * p, l, m);
//   Matrix *m2 = update(i, x, 2 * p + 1, m + 1, r);

//   return seg[p].matrix = matrix_mult(m1, m2);
// }

Matrix *Segtree::update(int i, Matrix *m) { return v[i].matrix = m; }
