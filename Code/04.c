#include <stdio.h>
#include <math.h>

// 微分方程的右端函數
double f(double t, double y) {
  // 替換成您要解的微分方程的右端函數
  return y;
}

// 四階 Runge-Kutta 算法
double rk4(double t_n, double y_n, double h, double (*f)(double, double)) {
  double k1, k2, k3, k4;
  k1 = h * f(t_n, y_n);
  k2 = h * f(t_n + h/2, y_n + k1/2);
  k3 = h * f(t_n + h/2, y_n + k2/2);
  k4 = h * f(t_n + h, y_n + k3);
  return y_n + (k1 + 2*k2 + 2*k3 + k4) / 6;
}

int main() {
  // 初始條件
  double t_0 = 0.0, y_0 = 1.0;

  // 步長
  double h = 0.1;

  // 終止時間
  double t_end = 1.0;

  // 迭代求解
  for (double t = t_0; t <= t_end; t += h) {
    y_0 = rk4(t, y_0, h, f);
    printf("t = %.2f, y = %.4f\n", t, y_0);
  }

  return 0;
}