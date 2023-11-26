#ifndef SEGTREE_H
#define SEGTREE_H

#include "matrix.h"

class SegtreeNode {
private:
  Matrix matrix;

public:
  SegtreeNode() = default;

  /**
   * Obtém a matriz associada ao nó.
   *
   * @return Referência constante à matriz associada ao nó.
   */
  const Matrix &get_matrix() const { return matrix; }

  /**
   * Define a matriz associada ao nó.
   *
   * @param newMatrix Nova matriz a ser associada ao nó.
   */
  void set_matrix(const Matrix &newMatrix) { matrix = newMatrix; }

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

  /**
   * Constrói a árvore de segmentos a partir de uma posição especificada.
   *
   * @param p Índice do nó atual na árvore.
   * @param l Índice do início do intervalo associado ao nó.
   * @param r Índice do final do intervalo associado ao nó.
   * @return Matriz construída para o nó atual.
   */
  Matrix build(int p, int l, int r);

  /**
   * Realiza uma consulta na árvore de segmentos para o intervalo [a, b].
   *
   * @param a Índice inicial do intervalo de consulta.
   * @param b Índice final do intervalo de consulta.
   * @param p Índice do nó atual na árvore.
   * @param l Índice do início do intervalo associado ao nó.
   * @param r Índice do final do intervalo associado ao nó.
   * @return Matriz resultante da consulta.
   */
  Matrix query(int a, int b, int p, int l, int r);

  /**
   * Atualiza a árvore de segmentos com uma nova matriz.
   *
   * @param i Índice do elemento a ser atualizado.
   * @param matrix Nova matriz a ser associada ao elemento.
   * @param p Índice do nó atual na árvore.
   * @param l Índice do início do intervalo associado ao nó.
   * @param r Índice do final do intervalo associado ao nó.
   * @return Matriz resultante da atualização.
   */
  Matrix update(int i, Matrix &matrix, int p, int l, int r);

private:
  int size;
  SegtreeNode *seg;
  Matrix identity_matrix;
};

#endif // !SEGTREE_H
