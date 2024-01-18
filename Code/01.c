#include <stdio.h>
#include <math.h>

// 定義洛倫茲方程的參數
#define SIGMA 10.0
#define RHO 28.0
#define BETA 8.0/3.0

// 定義時間間隔和步數
#define DT 0.01
#define N 10000

// 定義洛倫茲方程的函數
double f(double x, double y, double z) {
    return SIGMA * (y - x);
}

double g(double x, double y, double z) {
    return x * (RHO - z) - y;
}

double h(double x, double y, double z) {
    return x * y - BETA * z;
}

// 定義四階 Runge-Kutta 方法的函數
void rk4(double *x, double *y, double *z, double t, double dt) {
    double k1, k2, k3, k4;
    double l1, l2, l3, l4;
    double m1, m2, m3, m4;

    k1 = dt * f(*x, *y, *z);
    l1 = dt * g(*x, *y, *z);
    m1 = dt * h(*x, *y, *z);

    k2 = dt * f(*x + k1/2, *y + l1/2, *z + m1/2);
    l2 = dt * g(*x + k1/2, *y + l1/2, *z + m1/2);
    m2 = dt * h(*x + k1/2, *y + l1/2, *z + m1/2);

    k3 = dt * f(*x + k2/2, *y + l2/2, *z + m2/2);
    l3 = dt * g(*x + k2/2, *y + l2/2, *z + m2/2);
    m3 = dt * h(*x + k2/2, *y + l2/2, *z + m2/2);

    k4 = dt * f(*x + k3, *y + l3, *z + m3);
    l4 = dt * g(*x + k3, *y + l3, *z + m3);
    m4 = dt * h(*x + k3, *y + l3, *z + m3);

    *x += (k1 + 2*k2 + 2*k3 + k4) / 6;
    *y += (l1 + 2*l2 + 2*l3 + l4) / 6;
    *z += (m1 + 2*m2 + 2*m3 + m4) / 6;
}

// 主函數
int main() {
    // 定義初始條件
    double x = 1.0;
    double y = 1.0;
    double z = 1.0;
    double t = 0.0;

    // 輸出表頭
    printf("t\tx\ty\tz\n");

    // 迭代求解並輸出結果
    for (int i = 0; i < N; i++) {
        printf("%.2f\t%.2f\t%.2f\t%.2f\n", t, x, y, z);
        rk4(&x, &y, &z, t, DT);
        t += DT;
    }

    return 0;
}