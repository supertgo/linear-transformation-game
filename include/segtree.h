#ifndef SEGTREE_H
#define SEGTREE_H

#include "matrix.h"

class SegtreeNode {
private:
  Matrix matrix;

public:
  SegtreeNode() = default;

  const Matrix &getMatrix() const { return matrix; }

  void setMatrix(const Matrix &newMatrix) { matrix = newMatrix; }

  SegtreeNode &operator=(const SegtreeNode &other) {
    if (this != &other) {
      matrix = other.matrix;
    }
    return *this;
  }
};

class Segtree {
public:
  Segtree(int size);
  ~Segtree();

  Matrix build(int p, int l, int r);
  Matrix query(int a, int b, int p, int l, int r);
  Matrix update(int i, Matrix &matrix, int p, int l, int r);

private:
  int size;
  SegtreeNode *seg;
  Matrix identity_matrix;
};

#endif // !SEGTREE_H
