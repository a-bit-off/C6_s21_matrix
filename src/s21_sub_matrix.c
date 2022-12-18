#include "s21_matrix.h"

/// @brief Вычитание
/// @param A Уменьшаемое
/// @param B Вычитаемое
/// @param result Разность
/// @return 0 - OK 1 - Ошибка, некорректная матрица 2 - Ошибка
/// вычисления(несовпадающие размеры матриц; матрица, для которой нельзя
/// провести вычисления и т.д.)
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_sum_sub_manager(A, B, result, 0);
}
