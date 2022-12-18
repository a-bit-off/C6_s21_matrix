#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define SUCCESS 1
#define FAILURE 0

//                                                              INITIALIZE

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

//                                                              COMPARISON

int s21_eq_matrix(matrix_t *A, matrix_t *B);

//                                                              ARITHMETICS

int s21_sum_sub_manager(matrix_t *A, matrix_t *B, matrix_t *result, int flag);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

//                                                                ANOTHER
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
void s21_get_matrix(int row, int col, matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

//                                                                HELPERS
int s21_is_emty(matrix_t *matrix);
double s21_det_2x2(matrix_t A);
double s21_det(matrix_t *A);

#endif  // SRC_S21_MATRIX_H_