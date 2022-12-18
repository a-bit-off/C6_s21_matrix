#include "s21_matrix.h"

///@brief Минор матрицы и матрица алгебраических дополнений
///@param A
///@param result
///@return 0 - OK 1 - Ошибка, некорректная матрица
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int ret = 0;
  double det = 0;
  if (s21_is_emty(A)) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      if (A->rows == 1 && A->columns == 1) {
        ret = s21_determinant(A, &det);
        ret == 0 ? result->matrix[0][0] = det : 0;
      } else {
        for (int i = 0; i < A->rows && ret == 0; i++) {
          for (int j = 0; j < A->columns && ret == 0; j++) {
            matrix_t minor = {0};
            s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
            s21_get_matrix(i, j, A, &minor);
            ret = s21_determinant(&minor, &det);
            ret == 0 ? result->matrix[i][j] = pow(-1, (i + j)) * det : 0;
            s21_remove_matrix(&minor);
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
