#include <stdio.h>
#include <math.h>

double dydt(double t, double y) {
  return t * y;
}

void rk4(double t0, double y0, double t_end, double h, double *y_out) {
  double y_n = y0;
  double k1, k2, k3, k4;

  for (double t = t0; t < t_end; t += h) {
    k1 = h * dydt(t, y_n);
    k2 = h * dydt(t + h / 2, y_n + k1 / 2);
    k3 = h * dydt(t + h / 2, y_n + k2 / 2);
    k4 = h * dydt(t + h, y_n + k3);

    y_out[t / h] = y_n + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    y_n = y_out[t / h];
  }
}

int main() {
  double t0 = 0.0;
  double y0 = 1.0;
  double t_end = 1.0;
  double h = 0.01;
  double *y_out = malloc(sizeof(double) * (t_end / h));

  rk4(t0, y0, t_end, h, y_out);

  for (int i = 0; i < (t_end / h); i++) {
    printf("t = %.2f, y = %.2f\n", i * h, y_out[i]);
  }

  free(y_out);

  return 0;
}