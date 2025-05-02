#include <stdio.h>
void 新函数(void);
int main(void)
{
    int 数字甲,数字乙;
    数字甲 = 1;
    数字乙 = 2;
    数字乙 = 数字甲;
    数字甲 = 数字乙;
    printf("这是甲：%d，这是乙：%d。",数字甲,数字乙);
    新函数();
    printf("我有一个苹果");
    printf("电脑\n");
    printf("这个数字是%d\n",数字甲);

    return 0;
}
void 新函数(void)
{
    printf("输出\n");
}