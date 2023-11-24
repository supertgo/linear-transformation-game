#ifndef SEGTREE_H
#define SEGTREE_H

#include "matrix.h"

class SegtreeNode {
  Matrix *matrix;
  SegtreeNode() {
    matrix = new Matrix(2, 2);
  }

  ~SegtreeNode() {
    delete matrix;
  }

  friend class Segtree;
};

class Segtree {
public:
  Segtree(int size);
  ~Segtree();
  Matrix *build(int p, int l, int r);
  Matrix *query(int a, int b, int p, int l, int r);
  Matrix *update(int i, int x, int p, int l, int r);
  Matrix *matrix_mult(Matrix *a, Matrix *b);
  Matrix* update(int i, Matrix *m);

private:
  int size;
  SegtreeNode *v;
  SegtreeNode *seg;
};

#endif // !SEGTREE_H
