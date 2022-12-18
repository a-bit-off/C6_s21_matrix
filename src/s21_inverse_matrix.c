#include "s21_matrix.h"

/// @brief Обратная матрица
/// @param A
/// @param result
/// @return 0 - OK 1 - Ошибка, некорректная матрица 2 - Ошибка
/// вычисления(несовпадающие размеры матриц; матрица, для которой нельзя
/// провести вычисления и т.д.)
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int ret = 0;
  double det = 0;
  if (s21_is_emty(A)) {
    if ((s21_determinant(A, &det) == 0) && A->columns == A->rows &&
        fabs(det) >= 0.0000001) {
      if (A->rows == 1) {
        ret = s21_create_matrix(A->rows, A->columns, result);
        ret == 0 ? result->matrix[0][0] = 1 / det : 0;
      } else {
        matrix_t minor = {0};
        ret = s21_create_matrix(A->rows, A->columns, result);
        ret == 0 ? ret = s21_create_matrix(A->rows, A->columns, &minor) : 0;
        ret == 0 ? ret = s21_transpose(A, &minor) : 0;
        ret == 0 ? ret = s21_calc_complements(&minor, result) : 0;
        if (ret == 0) {
          for (int i = 0; i < result->rows; i++) {
            for (int j = 0; j < result->columns; j++) {
              result->matrix[i][j] *= 1 / det;
            }
          }
        }
        s21_remove_matrix(&minor);
      }
    } else {
      ret = 2;
    }
  } else {
    ret = 1;
  }
  return ret;
}
