#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int is_prime(int v) {

  int i;
  int bound = floor(sqrt(v)) + 1;

  for (i = 2; i < bound; i++) {
    if (v % i == 0) {
      return (0);
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {

  int i;
  int total = 0;
  int N = 200000;

  if (argc == 2) N = atoi(argv[1]);

  int primes[N];

#pragma omp parallel for
  for (i = 2; i < N; i++) {
    if (is_prime(i)) {
      primes[total] = i;
      total++;
    }
  }

  printf("# of prime numbers between 2 and %d: %d\n", N, total);
  return (0);
}