/*
数组介绍
*/
#include <stdio.h>
#define SIZE 10
#define PAR 72
void 循环处理数组(void);
double 指数(double n,int p);
void 测试指数(void);
int main(void)
{
    循环处理数组();

    return 0;
}

void 循环处理数组(void)
{
    int index, score[SIZE];
    int sum = 0;
    float average;

    printf("请输入%d个得分2\n", SIZE);
    for (index = 0; index < SIZE; index++)
        scanf("%d", &score[index]);
    printf("你的输入是这些吧");
    for (index = 0; index < SIZE; index++)
        printf("%5d", score[index]);
    printf("\n");
    for (index = 0; index < SIZE; index++)
        sum += score[index];
    average = (float) sum / SIZE;
    printf("分数的和是%d, 平均数是%.2f\n", sum, average);
    printf("与标准数的差为%.0f\n", average - PAR);
}

double 指数(double n, int p)
{
    double pow = 1;
    int i;

    for (i = 1; i <= p; i++)
        pow *= n;

    return pow;
}