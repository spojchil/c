/* 3.3
在C语言中整数是没有小数部分的数
3.14,2.000都不是整数
计算机以二进制储存整数
数字7的二进制是111在8位字节中
00000111 字长8位
*/

/*
浮点数
2.75 3.16E7 7.00 2e-8都是浮点数
计算机把浮点数分为两部分表示小数部分和整数部分
而且分开储存这两部分
符号 小数 指数
+    .314 1
*/
// 3.4
#include <stdio.h>
int main(void)
{
    int 十 = 10;  // 可以在声明时初始化
    int two = 2;

    printf("%d %d %d\n", two, 十);  // 遗漏一个参数
    // 会输出一个随机的数


    int 一百 = 100;  // 尝试不同的进制

    printf("十进制 = %d； 八进制 = %o； 十六进制 = %x\n", 一百, 一百, 一百);
    printf("十进制 = %d； 八进制 = %#o； 十六进制 = %#x\n", 一百, 一百, 一百);
    // 显示前缀0，0x需要使用#号


    int i = 2147483647;
    unsigned int j = 4294967295;

    printf("%d %d %d\n", i, i+1, i+2);
    printf("%u %u %u\n", j, j+1, j+2);
    // %u用于无符号整数unsigned int
    // %ld 用于 long %lx 十六进制打印long类型的整数
    // #lu 用于 unsigned long 类型

    // 3.4.2
    unsigned int un = 3000000000;
    short end = 200;
    long big = 65537;
    long long 非常大 = 12345678908642;

    printf("un = %u 不是 %d\n", un, un);
    printf("end = %hd 也是 %d\n", end, end);  // h表示short类型
    printf("big = %ld 不是 %hd\n", big, big);
    printf("非常大 = %lld 不是 %ld\n", 非常大, 非常大);
    // 655337的二进制32位省略前面的0：1000000000000001
    // 使用%hd printf()只会查看big的最后15位

    // 3.4.3
    // char 是一个1一节的整数，储存一个字符使用ASCII
    char response;
    char itable, latan;  // 声明使用char
    //初始化可以直接使用字符
    char grade = 'A';  // 使用 A 错误此时A是一个变量
    // 使用"A"也是错误，此时"A"是一个字符串
    char grade1 = 65;  // 也是可以，但是不推荐
    // 有些ASCII字符打印不出来。比如退格、换行、终端响铃和蜂鸣
    // C语言提供了三种方式表示这些字符
    // 直接使用ASCII码 
    char beep = 7;
    // 使用转义字符
    // \a警报 \b退格 \f换页 \n换行 \r回车 \t水平制表符 \v垂直制表符
    // \\反斜杠 \'单引号 \"双引号 \?问号 \0oo八进制只 \xhh十六进制
    beep = '\007';  // 表示8进制可以省略前面的0 范围0-377(0-255)
    beep = '\x7'; // 十六进制 范围0-FF超出可能报错或者截断
    long num = 199L;  // 后缀L声明199为long类型,UL为无符号长类型
    char ch = 'B';
    
    printf("%c 是 %d", ch, ch);  // 使用%c指明待打印的字符
    // 3.4.4
    // _Bool表示布尔值占用一位，0表示假1表示真
    _Bool 假 = 0;  // 赋予非0的值都会准换为1即真
    
    return 0;
}
// 注释不会进入程序中，在预处理时会移除所有注释

