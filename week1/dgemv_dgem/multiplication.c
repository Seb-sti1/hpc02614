//
// Created by seb-sti1 on 06/01/25.
// EX3: Matrix multiplication
//

#include "matrix.h"
#include <time.h>
#include <stdio.h>

void fill(double **A, unsigned long n, unsigned long m, double coef) {
  for (unsigned long i = 0; i < n; i++) {
    for (unsigned long j = 0; j < m; j++) {
      A[i][j] = coef * (i + 1) + j + 1;
    }
  }
}

int main() {
  const int N = 500;

  const unsigned long n = 100;
  const unsigned long k = 100;
  const unsigned long m = 100;

  double **A = emptyMatrix(3, 5);
  fill(A, 3, 5, 10.);
  double **B = emptyMatrix(5, 2);
  fill(B, 5, 2, 20.);
  double **C = emptyMatrix(3, 2);
  printf("A:\n");

  multiplication(C, A, B, 3, 5, 2);
  printf("A:\n");
  displayMatrix(A, 3, 5);
  printf("B:\n");
  displayMatrix(B, 5, 2);
  printf("C:\n");
  displayMatrix(C, 3, 2);
  freeMatrix(A, 3);
  freeMatrix(B, 5);
  freeMatrix(C, 3);

  clock_t duration = 0;

  for (int step = 0; step < N; step++) {
    double **A = randomMatrix(m, k);
    double **B = randomMatrix(k, n);
    double **C = emptyMatrix(m, n);

    clock_t s = clock();
    multiplication(C, A, B, m, k, n);
    duration += clock() - s;

    freeMatrix(A, m);
    freeMatrix(B, k);
    freeMatrix(C, m);
  }

  printf("%.2f ms for %d matrix (%ld x %ld) additions", 1000.0 * duration / CLOCKS_PER_SEC,
         N, n, m);

  return 0;
}