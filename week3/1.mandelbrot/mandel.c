#include <omp.h>
#include <stdio.h>

void mandel(int disp_width, int disp_height, int *array, int max_iter) {
  double scale_real = 3.5 / (double) disp_width;
  double scale_imag = 3.5 / (double) disp_height;

  // array can be shared as long as each cell is access by only one thread
#pragma omp target teams distribute parallel for map(to:disp_width, disp_height, scale_real, scale_imag, max_iter) map(tofrom:array[0:disp_height * disp_width])
  for (int i = 0; i < disp_width * disp_height; i++) {
    double x = ((double) (i / disp_height) * scale_real) - 2.25;
    double y = ((double) (i % disp_height) * scale_imag) - 1.75;
    double u = 0.0;
    double v = 0.0;
    double u2 = 0.0;
    double v2 = 0.0;
    int iter = 0;
    while (u2 + v2 < 4.0 && iter < max_iter) {
      v = 2 * v * u + y;
      u = u2 - v2 + x;
      u2 = u * u;
      v2 = v * v;
      iter++;
    }
    // if we exceed max_iter, reset to zero
    iter = iter == max_iter ? 0 : iter;
    array[i] = iter;
  }
}
