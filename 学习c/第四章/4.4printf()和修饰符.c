// 2025 5 5
/*
printf()和scanf()
他们都是输入输出函数或者I/O函数

printf() 
%d %c等等被称为转换说明

*/
// 转换说明示例
#include <stdio.h>
#define PI 3.141593
#define 数字 "一二三 四五六"
int main(void)
{
    int number = 7;
    float pies = 12.75;
    int cost = 7800;

    printf("The %d contestants ate %f berry pies.\n", number, pies);
    printf("The value of pi is %f.\n", PI);
    printf("Farewell! thou art too dear for my possessing ,\n");
    printf("%c%d\n", '$', 2 * cost);

    int pc = 2*6;

    printf("Only %d%% of sally's gribbles were edible.\n", pc);

    // 最小字段宽度 %4d
    printf("%4d\n", 10);  // 输出
    // Only 12% of sally's gribbles were edible.
    //   10 前面有两个空格补了四个宽度

    // h​​长度修饰符 还有其他的hh j l ll L(长双精度浮点数) 
    unsigned short num = 42;
    printf("%hu\n", num);  // 输出：42

    // -左对齐
    printf("%-8s123\n", "125");  // 125     123补齐空格后左对齐

    printf("%+d\n", 4);  // 显示符号  输出+4
    printf("%+d\n", -3); // -3

    printf("% d\n", 4);  // 正显示为空格输出 4
    printf("% d\n", -4);  // -4

    const double RENT = 3852.99;

    // 两端的1是标记符
    printf("1%f1\n", RENT);  // 13852.9900001
    printf("1%e1\n", RENT);  // 13.852990e+031
    printf("1%4.2f1\n", RENT);  // 13852.991
    printf("1%3.1f1\n", RENT);  // 13853.01
    printf("1%10.3f1\n", RENT);  // 1  3852.9901
    printf("1%10.3E1\n", RENT);  // 1 3.853E+031
    printf("1%+4.2f1\n", RENT);  // 1+3852.991
    printf("1%010.2f1\n", RENT);  // 10003852.991

    printf("%x %X %#x\n", 31, 31, 31);  // 1f 1F 0x1f
    printf("11%d11% d11% d11\n", 42, 42, -42);
    // 114211 4211-4211
    printf("11%5d11%5.3d11%05d11%05.3d11\n", 6, 6, 6, 6);
    // 11    611  006110000611  00611

    printf("[%s]\n", 数字);  // [一二三 四五六]
    printf("[%2s]\n", 数字);  // [一二三 四五六] 扩展为可容纳所有字符
    printf("[%24s]\n", 数字);  // [     一二三 四五六] 右对齐，补空格
    printf("[%24.5s]\n", 数字);  // [                   一�] 
    // .5 表示最多输出 5 字节​​，但中文字符被截断导致乱码 中文三个字符
    printf("[%24.6s]\n", 数字);  // [                  一二]
    printf("[%-24.5s]\n", 数字);  // [一�                   ] 左对齐

    return 0;
}
/*
printf(格式字符串, 待打印项1, 待打印项2...)
格式字符串是双引号括起来的内容
打印%使用%%

printf()的修饰符

最小字段宽度指在格式化输出（如printf）中，
通过格式说明符（如%4d）指定的​​最小占用空间​​。
例如，%4d表示至少占用4个字符宽度来显示整数。

# 修饰符
​​显示八进制前缀 0​​	%#o	052
​​显示十六进制前缀 0x​​	%#x	0xff
​​强制浮点数显示小数点​​	%#.0f	42.
​​防止 %g 删除末尾 0​​	%#g	42.000000
*/