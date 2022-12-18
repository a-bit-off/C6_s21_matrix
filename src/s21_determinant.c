#include "s21_matrix.h"

/// @brief Определитель матрицы
/// @param A
/// @param result
/// @return 0 - OK 1 - Ошибка, некорректная матрица 2 - Ошибка
/// вычисления(несовпадающие размеры матриц; матрица, для которой нельзя
/// провести вычисления и т.д.)
int s21_determinant(matrix_t *A, double *result) {
  int ret = 0;
  if (s21_is_emty(A)) {
    if (A->columns == A->rows) {
      *result = s21_det(A);
    } else {
      ret = 2;
    }
  } else {
    ret = 1;
  }
  return ret;
}

/// @brief Возвращает определитель матрицы 2x2
/// @param A
/// @return
double s21_det_2x2(matrix_t A) {
  double ret =
      A.matrix[0][0] * A.matrix[1][1] - A.matrix[1][0] * A.matrix[0][1];
  return ret;
}

/// @brief Возвращает определитель
/// @param A
/// @return
double s21_det(matrix_t *A) {
  double ret = 0;
  if (A->columns == 1 && A->rows == 1) {
    ret = A->matrix[0][0];
  } else if (A->columns == 2 && A->rows == 2) {
    ret += s21_det_2x2(*A);
  } else {
    int i = 0;
    for (i = 0; i < A->rows; i++) {
      matrix_t minor = {0};
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      int minor_row = 0;
      int j = 0;
      for (j = 0; j < A->columns; j++) {
        if (j != i) {
          for (int k = 0; k < minor.rows; k++) {
            minor.matrix[minor_row][k] = A->matrix[j][1 + k];
          }
          minor_row++;
        }
      }
      if (minor.columns == 2 && minor.rows == 2) {
        ret += pow(-1, i + 2) * A->matrix[i][0] * s21_det_2x2(minor);
      } else {
        ret += pow(-1, i + 2) * A->matrix[i][0] * s21_det(&minor);
      }
      s21_remove_matrix(&minor);
    }
  }
  return ret;
}