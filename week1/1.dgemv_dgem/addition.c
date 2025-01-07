//
// Created by seb-sti1 on 06/01/25.
// EX1: Matrix addition
//

#include "matrix.h"
#include <time.h>
#include <stdio.h>

int main() {
  const int N = 10000;

  const unsigned long n = 100;
  const unsigned long m = 100;

  double **A = randomMatrix(3, 3);
  double **B = randomMatrix(3, 3);
  double **C = emptyMatrix(3, 3);
  add(C, A, B, 3, 3);
  printf("A:\n");
  displayMatrix(A, 3, 3);
  printf("B:\n");
  displayMatrix(B, 3, 3);
  printf("C:\n");
  displayMatrix(C, 3, 3);
  freeMatrix(A, 3);
  freeMatrix(B, 3);
  freeMatrix(C, 3);

  clock_t duration = 0;

  for (int step = 0; step < N; step++) {
    double **A = randomMatrix(n, m);
    double **B = randomMatrix(n, m);
    double **C = emptyMatrix(n, m);

    clock_t s = clock();
    add(C, A, B, n, m);
    duration += clock() - s;

    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);
  }

  printf("%.2f ms for %d matrix (%ld x %ld) additions", 1000.0 * duration / CLOCKS_PER_SEC,
         N, n, m);

  return 0;
}