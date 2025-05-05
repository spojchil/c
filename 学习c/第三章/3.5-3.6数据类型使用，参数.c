// 3.5
/*
可以
int apples = 3;
int iranges = 3.99;  // 会直接舍弃掉小数部分，而不是四舍五入
int apples = 4;  // 允许二次初始化但可能编译器会给出警告
float pi = 3.1415926536;  // 会损失精度可能会给警告
很多时候程序员会在变量名中体现出类型
i_smart 是int类型的变量
*/

/* 3.6
printf("a,b")有一个参数，逗号分隔参数
函数调用时需要保证参数的个数和类型的匹配
*/
#include <stdio.h>
int main(void)
{
    int n = 5;
    int m = 4;
    float f = 7.0f;
    float g = 8.0f;

    printf("%d\n", n, m);  // 参数太多
    printf("%d %d %d\n", n);  // 参数太少
    printf("%d %d\n",f ,g);  // 参数类型不匹配,这里的%d显示不会转换

    return 0;
}