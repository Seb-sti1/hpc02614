void mandel(int disp_width, int disp_height, int *array, int max_iter) {
  double scale_real, scale_imag;
  double x, y, u, v, u2, v2;
  int i, iter;

  scale_real = 3.5 / (double) disp_width;
  scale_imag = 3.5 / (double) disp_height;

  // array can be shared as long as each cell is access by only one thread
#pragma omp parallel for private(i, iter, x, y, u, v, u2, v2) schedule(dynamic, 200)
  for (i = 0; i < disp_width * disp_height; i++) {
    x = ((double) (i / disp_height) * scale_real) - 2.25;
    y = ((double) (i % disp_height) * scale_imag) - 1.75;
    u = 0.0;
    v = 0.0;
    u2 = 0.0;
    v2 = 0.0;
    iter = 0;
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
