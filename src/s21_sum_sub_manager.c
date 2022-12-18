#include "s21_matrix.h"

/// @brief Сложение / вычитание
/// @param A
/// @param B
/// @param result
/// @param flag 1 - Сложение / 0 - вычитание (определяет операцию)
/// @return 0 - OK 1 - Ошибка, некорректная матрица 2 - Ошибка
/// вычисления(несовпадающие размеры матриц; матрица, для которой нельзя
/// провести вычисления и т.д.)
int s21_sum_sub_manager(matrix_t *A, matrix_t *B, matrix_t *result, int flag) {
  int ret = 0;
  if (s21_is_emty(A) && s21_is_emty(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          if (flag) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          } else {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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