#include <stdio.h>
int main(void)
{
    int dogs;  // 可以使用中文名称如“狗的数量”。

    printf("你有多少条狗？\n");
    scanf("%d", &dogs);
    printf("所以你有%d条狗！\n", dogs);

    return  0;
}