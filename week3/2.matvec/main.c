//
// Created by seb-sti1 on 13/01/25.
//
#include <time.h>
#include <stdlib.h>
#include <omp.h>
#include <stdio.h>

double *randomVector(unsigned long n) {
  double *matrix = malloc(n * sizeof(double));

  for (unsigned long i = 0; i < n; i++) {
    matrix[i] = i;
  }

  return matrix;
}

double *randomMatrix(unsigned long n, unsigned long m) {
  double *matrix = malloc(n * m * sizeof(double));

  for (unsigned long i = 0; i < n; i++) {
    for (unsigned long j = 0; j < n; j++) {
      matrix[i * m + j] = i + j;
    }
  }

  return matrix;
}

void printVector(double *v, int n) {
  for (int i = 0; i < n; i++) {
    printf("%f\n", v[i]);
  }
}

void printMatrix(double *M, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%f ", M[i * m + j]);
    }
    printf("\n");
  }

}

int main() {
  int n = SIZE;

  double *v = randomVector(n);
  double *m = randomMatrix(n, n);
  double *c = malloc(n * sizeof(double));

#ifdef SHOULD_PRINT
  printVector(v, n);
  printf("\n");
  printMatrix(m, n, n);
#endif

  printf("\n%d\n", n);
  double t1 = omp_get_wtime();
#pragma omp target teams num_teams(1875) thread_limit(16) distribute parallel for map(to:n, m[0:n*n], v[0:n]) map(tofrom:c[0:n])
  for (int i = 0; i < n; i++) {
    double sum = 0;
    for (int j = 0; j < n; j++) {
      sum += m[i * n + j] * v[j];
    }
    c[i] = sum;
  }

  double t2 = omp_get_wtime();

#ifdef SHOULD_PRINT
  printf("\n");
  printVector(c, n);
#endif

  printf("\n%f\n", t2 - t1);

  free(v);
  free(m);
  free(c);
}