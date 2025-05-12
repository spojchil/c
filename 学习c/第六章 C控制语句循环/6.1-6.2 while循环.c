/*
三种循环for, while ,do while
*/
#include <stdio.h>
void 整数求和(void);
void 何时退出(void);
int main(void)
{
    // 整数求和();
    何时退出();

    return 0;
}

void 整数求和(void)
{
    long num;
    long sum = 0L;
    int status;

    printf("请输入一个整数作为求和上限");
    printf("(输入q退出)");
    status = scanf("%ld", &num);
    // 可以替换为while (scanf("%ld", &num) == 1)
    while (status == 1)  // 相等运算符
    {
        sum = sum + num;
        printf("请输入下一个整数(输入q退出)");
        status = scanf("%ld", &sum);  // 注意读取成为为一个长整数返回0
        // 输入非整数时解释失败返回1
    }
    printf("这些整数的和是%ld.\n", sum);
}

void 何时退出(void)
{
    int n = 5;

    while (n < 7)
    {
        printf("n = %d\n", n);
        n++;
        printf("现在n = %d\n", n);
    }
    printf("完成");
}