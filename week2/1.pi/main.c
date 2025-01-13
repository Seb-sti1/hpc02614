//
// Created by seb-sti1 on 13/01/25.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
  long N = 1000000000;
  long i;
  double x, y;
  double sum = 0;

  double invN = 1. / N;
  double invNsquared = invN / N;

#pragma omp parallel for default(none) shared(N, invN, invNsquared) \
  private(i, x, y) reduction(+: sum) if (N>10000000)
  for (i = 1; i <= N; i++) {
    x = (i - 0.5) * (i - 0.5) * invNsquared;
    y = 1. / (1. + x);

    sum += y;
  }

  sum = 4. * invN * sum;

  printf("%lf\n", sum);
}