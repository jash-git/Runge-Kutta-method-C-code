#include <stdio.h>

// 定義微分方程式
double f(double t, double y) {
    return t + y; // 這是一個示例方程式，可以根據需要更改
}

// Runge-Kutta方法的實現
double rungeKutta(double t0, double y0, double h, double tn) {
    double t = t0;
    double y = y0;

    while (t < tn) {
        double k1 = h * f(t, y);
        double k2 = h * f(t + h/2, y + k1/2);
        double k3 = h * f(t + h/2, y + k2/2);
        double k4 = h * f(t + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        t = t + h;
    }

    return y;
}

int main() {
    double t0 = 0.0;   // 初始時間
    double y0 = 1.0;   // 初始條件
    double h = 0.1;    // 步進值
    double tn = 1.0;   // 結束時間

    double result = rungeKutta(t0, y0, h, tn);

    printf("在時間 %f 的時候，方程式的解為：%f\n", tn, result);

    return 0;
}
