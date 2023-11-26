#ifndef MATRIX_H
#define MATRIX_H

#include "point.h"
#include <iostream>
#include <stdexcept>

#define matrix_type long unsigned int

class Matrix {
private:
  int rows, cols;
  // Matriz sendo representada como um vetor
  matrix_type data[4];

public:
  Matrix() : rows(2), cols(2) { Matrix(2, 2); }

  Matrix(int rows, int cols);
  ~Matrix();

  /**
   * Define a matriz como uma matriz identidade.
   */
  void set_identity();

  /**
   * Multiplica duas matrizes e retorna o resultado.
   *
   * @param a Primeira matriz.
   * @param b Segunda matriz.
   * @return Resultado da multiplicação de a por b.
   */
  static Matrix matrix_mult(const Matrix &a, const Matrix &b);

  /**
   * Realiza uma transformação linear em um ponto usando a matriz.
   *
   * @param point Ponto a ser transformado.
   * @return Ponto transformado.
   */
  Point linear_transformation(Point point);

  /**
   * Sobrecarga do operador de acesso a elementos da matriz.
   *
   * @param i Índice da linha.
   * @param j Índice da coluna.
   * @return Referência ao elemento na posição (i, j).
   */
  matrix_type &operator()(int i, int j);

  /**
   * Sobrecarga do operador de acesso constante a elementos da matriz.
   *
   * @param i Índice da linha.
   * @param j Índice da coluna.
   * @return Valor constante do elemento na posição (i, j).
   */
  const matrix_type &operator()(int i, int j) const;

  /**
   * Sobrecarga do operador de atribuição.
   *
   * @param m Matriz a ser atribuída.
   * @return Referência à matriz atual após a atribuição.
   */
  Matrix &operator=(const Matrix &);

  /**
   * Sobrecarga do operador de entrada para ler os elementos da matriz a partir
   * de uma stream.
   *
   * @param is Stream de entrada.
   * @param m Matriz a ser lida.
   * @return Referência à stream de entrada após a leitura.
   */
  friend std::istream &operator>>(std::istream &is, Matrix &m);

  /**
   * Sobrecarga do operador de saída para imprimir a matriz em uma stream.
   *
   * @param os Stream de saída.
   * @param m Matriz a ser impressa.
   * @return Referência à stream de saída após a impressão.
   */
  friend std::ostream &operator<<(std::ostream &os, const Matrix &m);
};

#endif // !MATRIX_H
