// 2025 5 9
#include <stdio.h>
#define ADJUST 7.31
int 无循环(void);  // 函数声明，原因之一是调用在定义前
int 循环计算(void);
int main(void)
{
    // 无循环();
    循环计算();

    return 0;
}

int 无循环(void)
{
    const double SCALE = 0.333;  // 不可修改，需要定义时初始化
    double shoe, foot;

    shoe = 9.0;
    foot = SCALE * shoe + ADJUST;
    printf("Shoe size (men's)  foot length\n");
    printf("%8.1f %15.2f inches\n", shoe, foot);

    return 0;
}

int 循环计算(void)
{
    const double SCALE = 0.333;  // 不可修改，需要定义时初始化
    double shoe, foot;

    shoe = 3.0;
    printf("Shoe size (men's)  foot length\n");
    while (shoe < 18.5)  // 循环开始
    {                    // 块开始
        foot = SCALE * shoe + ADJUST;
        printf("%8.1f %15.2f inches\n", shoe, foot);
        shoe = shoe + 1.0;
    }                    // 块结束
    printf("If the shoe fits, wear it.\n");

    return 0;
}
