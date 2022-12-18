#include "s21_matrix.h"

/// @brief Создание матриц
/// @param rows
/// @param columns
/// @param result
/// @return 0 - OK 1 - Ошибка, некорректная матрица
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = 1;
  if (rows > 0 && columns > 0) {
    double **matrix =
        calloc(rows * columns * sizeof(double) + rows * sizeof(double *), 1);

    if (matrix != NULL) {
      double *ptr = (double *)(matrix + rows);
      for (int i = 0; i < rows; i += 1) {
        matrix[i] = ptr + columns * i;
      }
      result->columns = columns;
      result->matrix = matrix;
      result->rows = rows;
      res = 0;
    }
  }
  return res;
}