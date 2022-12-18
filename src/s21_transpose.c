#include "s21_matrix.h"

/// @brief Транспонирование матрицы
/// @param A
/// @param result
/// @return  0 - OK 1 - Ошибка, некорректная матрица
int s21_transpose(matrix_t *A, matrix_t *result) {
  int ret = 0;
  if (s21_is_emty(A)) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  } else {
    ret = 1;
  }
  return ret;
}