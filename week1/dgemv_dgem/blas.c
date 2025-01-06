//
// Created by seb-sti1 on 06/01/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>

double *create_matrix(int rows, int cols, int row_major) {
  double *matrix = (double *) malloc(rows * cols * sizeof(double));
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      matrix[row_major ? (i * cols + j) : (j * rows + i)] = (double) (i * cols + j + 1);
    }
  }
  return matrix;
}

void print_matrix(const double *matrix, int rows, int cols, int row_major) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      printf("%5.1f ", matrix[row_major ? (i * cols + j) : (j * rows + i)]);
    }
    printf("\n");
  }
}

int main() {
  int M = 3, N = 3, K = 3;  // Matrix dimensions: A (MxK), B (KxN), C (MxN)
  double alpha = 1.0, beta = 0.0;

  // Create matrices A and B
  double *A = create_matrix(M, K, 1);  // Row-major
  double *B = create_matrix(K, N, 1);  // Row-major
  double *C = (double *) calloc(M * N, sizeof(double));  // Result matrix, initialized to 0

  printf("Matrix A:\n");
  print_matrix(A, M, K, 1);

  printf("\nMatrix B:\n");
  print_matrix(B, K, N, 1);

  // Perform matrix multiplication: C = alpha * A * B + beta * C
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
              M, N, K, alpha, A, K, B, N, beta, C, N);

  printf("\nMatrix C (Result):\n");
  print_matrix(C, M, N, 1);

  // Free allocated memory
  free(A);
  free(B);
  free(C);

  return 0;
}
