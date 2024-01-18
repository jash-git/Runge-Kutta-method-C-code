#include <stdio.h>

// 計算方程的右側函數的值
double f(double x, double y)
{
    return x + y;
}

// 計算四階Runge-Kutta方法的控制輸入，並返回變量的下一個值
double rk4(double x, double y, double h)
{
    double k1, k2, k3, k4; // 定義四個函數值
    k1 = f(x, y); // 計算k1
    k2 = f(x + h / 2, y + h / 2 * k1); // 計算k2
    k3 = f(x + h / 2, y + h / 2 * k2); // 計算k3
    k4 = f(x + h, y + h * k3); // 計算k4
    return y + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4); // 返回變量的下一個值
}

// 主函數
int main()
{
    double x0 = 0.0; // 設定初始條件
    double y0 = 1.0;
    double x1 = 1.0; // 設定求解的區間
    double h = 0.1; // 設定步長
    double x, y; // 定義變量
    x = x0; // 初始化變量
    y = y0;
    while (x <= x1) // 進行求解循環
    {
        printf("x = %.1f, y = %.4f\n", x, y); // 輸出變量的值
        y = rk4(x, y, h); // 計算變量的下一個值
        x += h; // 更新變量
    }
    return 0; // 程式結束
}	