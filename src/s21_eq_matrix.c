#include "s21_matrix.h"

/// @brief Сравнеине
/// @param A
/// @param B
/// @return 1 - SUCCESS, 0 - FAILURE
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ret = SUCCESS;
  if (s21_is_emty(A) && s21_is_emty(B) && A->columns == B->columns &&
      A->rows == B->rows) {
    for (int i = 0; i < A->rows && ret; i++) {
      for (int j = 0; j < A->columns && ret; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 0.0000001) {
          ret = FAILURE;
        }
      }
    }
  } else {
    ret = FAILURE;
  }
  return ret;
}
