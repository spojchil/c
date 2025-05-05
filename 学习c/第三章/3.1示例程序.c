/* 
2025 5 3
换一种方式记笔记
*/

#include <stdio.h>
int main(void)
{
    float 体重;
    float value;

    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("请输入你的体重（斤）：");

    scanf("%f",&体重);  // 输入完不要一直等着，要按回车键
    // 假设白金的价格是每千克3141.59元
    // 转化为千克
    value = 2.0 * 体重 * 31415.26;

    printf("你的体重等值的白金价值%.2f.\n", value);
    // 如果输出一闪而过就在程序添加getchar()
    // getchar() 作用是读入下一个输入的字符，等待输入
    // 这个程序需要两个因为你按下回车就是一次
    return 0;
}
// float 浮点数类型可以储存小数，范围更大
// %f 处理浮点数 %.2f 指定输出浮点数只显示小数点后面两位
// scanf()是将输入传给一个地址,&去一个变量的地址