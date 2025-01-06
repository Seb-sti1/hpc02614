//
// Created by seb-sti1 on 06/01/25.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void displayMatrix(double **matrix, unsigned long n, unsigned long m) {
  for (unsigned long i = 0; i < n; i++) {
    for (unsigned long j = 0; j < m; j++) {
      printf("%.2f ", matrix[i][j]);
    }
    printf("\n");
  }
}

void displayVector(double *matrix, unsigned long n) {
  for (unsigned long i = 0; i < n; i++) {
    printf("%.2f ", matrix[i]);
    printf("\n");
  }
}

double *randomVector(unsigned long n) {
  srand(time(NULL) * rand());
  double *matrix = malloc(n * sizeof(double));

  for (unsigned long i = 0; i < n; i++) {
    matrix[i] = (double) (rand() % 100) / 10.0; // Random values [0.0, 9.9]
  }

  return matrix;
}

double **randomMatrix(unsigned long n, unsigned long m) {
  srand(time(NULL) * rand());
  double **matrix = malloc(n * sizeof(double *));

  for (unsigned long i = 0; i < n; i++) {
    matrix[i] = malloc(m * sizeof(double));
    for (unsigned long j = 0; j < m; j++) {
      matrix[i][j] = (double) (rand() % 100) / 10.0; // Random values [0.0, 9.9]
    }
  }

  return matrix;
}

double *emptyVector(unsigned long n) {
  double *matrix = malloc(n * sizeof(double));

  for (unsigned long i = 0; i < n; i++) {
    matrix[i] = 0;
  }

  return matrix;
}

double **emptyMatrix(unsigned long n, unsigned long m) {
  double **matrix = malloc(n * sizeof(double *));
  for (unsigned long i = 0; i < n; i++) {
    matrix[i] = malloc(m * sizeof(double));
    for (unsigned long j = 0; j < m; j++) {
      matrix[i][j] = 0.;
    }
  }
  return matrix;
}

void freeMatrix(double **A, unsigned long n) {
  for (unsigned long i = 0; i < n; i++) {
    free(A[i]);
  }
  free(A);
}

void add(double **C, double **A, double **B, unsigned long n, unsigned long m) {
  for (unsigned long i = 0; i < n; i++) {
    for (unsigned long j = 0; j < m; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

void productMatrixWithVector(double *c, double **A, double *b, unsigned long n, unsigned long m) {
  for (unsigned long i = 0; i < n; i++) {
    c[i] = 0;
    for (unsigned long j = 0; j < m; j++) {
      c[i] += A[i][j] * b[j];
    }
  }
}

void multiplication(double **C, double **A, double **B,
                    unsigned long m, unsigned long k, unsigned long n) {
  for (unsigned long i = 0; i < m; i++) {
    for (unsigned long j = 0; j < n; j++) {
      for (unsigned long l = 0; l < k; l++) {
        C[i][j] += A[i][l] * B[l][j];
      }
    }
  }
}