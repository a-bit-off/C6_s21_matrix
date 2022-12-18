#include "s21_matrix.h"

/// @brief Умножение матриц
/// @param A Множитель А
/// @param B Множитель В
/// @param result Произведение
/// @return 0 - OK 1 - Ошибка, некорректная матрица 2 - Ошибка
/// вычисления(несовпадающие размеры матриц; матрица, для которой нельзя
/// провести вычисления и т.д.)
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = 0;
  if (s21_is_emty(A) && s21_is_emty(B)) {
    if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < B->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      ret = 2;
    }
  } else {
    ret = 1;
  }
  return ret;
}