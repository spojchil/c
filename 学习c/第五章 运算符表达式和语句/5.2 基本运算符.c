/*
C的基本算数运算符有=, +, -, *和/，没有指数运算符
C的标准数学库提供了一个pow()函数用于指数运算，pow(3.4,2.2)返回3.4的2.2次幂
=并不意味这相等，而是一个赋值运算符,顺序从右向左
左边是一个 可修改的左值，使用术语对象定位值
可以三重赋值
int a, b, c
a = b = c = 1;

二元运算符+，-,1 + 2,2 - 1
一元运算符+,-,-3,+4

*/
// 计算平方
#include <stdio.h>
int 计算平方(void);
int 指数增长(void);
int 演示除法(void);
int main(void)
{
    // 计算平方();
    // 指数增长();
    演示除法();

    return 0;
}
int 计算平方(void)
{
    int num = 1;

    while (num < 21)
    {
        printf("%4d %6d\n", num, num * num);
        num = num + 1;
    }

    return 0;
}
#define 总方格数 64
int 指数增长(void)
{
    const double CROP = 2E16;
    double current, total;
    int conut = 1;

    printf("square  grains    total     ");
    printf("fraction of \n");
    printf("        added     grains    ");
    printf("world total\n");
    total = current = 1.0;
    printf("%2d %13.2e %12.2e %12.2e\n", conut,
        current, total / CROP);
    while (conut < 总方格数)
    {
        conut = conut + 1;
        current = 2.0 * current;  // 下一个翻倍
        total = total + current;  // 更新总数
        printf("%2d %13.2e %12.2e %12.2e\n", conut,
            current, total / CROP);
    }
    printf("这是全部\n");

    return 0;
}
/*
除法运算符
*/
int 演示除法(void)
{
    printf("整数除法：5/4 是 %d \n", 5/4);  // 1
    printf("整数除法：5/-4 是 %d \n", 5/-4);  // -1
    printf("整数除法：6/3 是 %d \n", 6/3);  // 2
    printf("整数除法：7/4 是 %d \n", 7/4);  // 1 
    printf("整数除法：-7/4 是 %d \n", -7/4);  // -1
    // 整数除法会丢弃整个小数部分
    printf("浮点数除法：7.0/4.0 是 %1.2f \n", 7.0/4.0);  // 1.75
    printf("混合除法：7.0/4 是 %1.2f \n", 7.0/4);  // 1.75
    printf("混合除法：7/4.0 是 %1.2f \n", 7/4.0);  // 1.75
    // 混合运算转换为浮点数


    return 0;
}
/*
运算符优先级
x = y = 1;  // 从右向左，y先被赋值为1，然后x被赋值为y的值
​​赋值运算符 =​​（优先级最低）
结合律：从右往左
示例：a = b = 5 等价于 a = (b = 5)
注意：这不是数学中的等号，而是赋值操作

​​二元加减 + -​​（如 a + b）
结合律：从左往右
示例：5 - 3 + 2 等价于 (5 - 3) + 2 = 4
注意：这里的+ -是加减法运算，不是正负号

​​乘除 * /​​
结合律：从左往右
示例：8 / 4 * 2 等价于 (8 / 4) * 2 = 4
特殊：整数除法会截断小数部分，如 5 / 2 = 2

​​一元正负 + -​​（如 -x）
结合律：从右往左
示例：- -5 等价于 -(-5) = 5
注意：这里的+ -是正负号，不是加减法

​​括号 ()​​（优先级最高）
结合律：从左往右
示例：(3 + 2) * 4 先计算括号内
作用：强制改变运算顺序
*/