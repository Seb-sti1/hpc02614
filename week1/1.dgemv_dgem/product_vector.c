//
// Created by seb-sti1 on 06/01/25.
// EX2: Matrix multiplication with vector
//

#include "matrix.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  const int N = 10000;

  const unsigned long n = 100;
  const unsigned long m = 100;

  double **A = randomMatrix(3, 3);
  double b[3] = {0.0, 1.0, 2.0};
  double *c = emptyVector(3);
  productMatrixWithVector(c, A, b, 3, 3);
  printf("A:\n");
  displayMatrix(A, 3, 3);
  printf("b:\n");
  displayVector(b, 3);
  printf("c:\n");
  displayVector(c, 3);
  freeMatrix(A, 3);
  free(c);

  clock_t duration = 0;

  for (int step = 0; step < N; step++) {
    double **A = randomMatrix(n, m);
    double *b = randomVector(m);
    double *c = emptyVector(n);

    clock_t s = clock();
    productMatrixWithVector(c, A, b, n, m);
    duration += clock() - s;

    freeMatrix(A, n);
    free(b);
    free(c);
  }

  printf("%.2f ms for %d matrix (%ld x %ld) multiplication", 1000.0 * duration / CLOCKS_PER_SEC,
         N, n, m);

  return 0;
}