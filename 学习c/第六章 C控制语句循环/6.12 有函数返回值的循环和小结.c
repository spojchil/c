// 使用函数返回值
#include <stdio.h>
double 指数计算(double n, int p);
void 使用指数(void);
int main(void)
{
    使用指数();  // 首次遇到时需要知道返回类型

    return 0;
}

double 指数计算(double n, int p)
{
    double pow = 1;
    int i;

    for (i = 1; i <= p; i++)
        pow *= n;

    return pow;
}

void 使用指数(void)
{
    double x, xpow;
    int exp;

    printf("输入一个数字和正整数来计算次方\n");
    printf("输入q退出\n");
    while (scanf("%lf%d", &x, &exp) == 2)
    {
        xpow = 指数计算(x, exp);
        printf("%.3g的%d次方是%.5g\n", x, exp, xpow);
        printf("输入下一组数字或者输入q退出\n");
    }
    printf("应用结束");
}