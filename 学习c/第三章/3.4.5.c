// 3.4.5
/*
stdint.h
创建了更多类型名
int32_t表示32位有符号整数类型 使用32位int的系统中
头文件会把int32_t作为int的别名
int为16位、long为32位的系统会把int32_t作为long的别名
然后，使用int32_t类型编写程序，并包含stdint.h头文件时
编译器会把int或long替换为与当前系统匹配的类型
增强了可一直性不需要关系int在不同系统之间不同的位数了
这些是精确宽度类型

还有最小宽度类型如
int_least8_t 
也有最快最小宽度类型 int_fast8_t
最大有符号整数类型intmax_t 64位系统中是64位
*/
#include <stdio.h>
#include <inttypes.h>  // 这里这两个头文件没有依赖关系可以互换顺序
int main(void)
{
    int32_t me32;

    me32 = 45933945;

    printf("First, assume int32_t is int: ");
    printf("me32 = %d\n", me32);
    printf("Next, let's not make any assumptions.\n");
    printf("Instend, use a \"macro\" from inttypes.h: ");
    printf("me32 = %" PRId32 "\n", me32);
    // 在C语言中可以把多个字符串拼接
    // PRId32是字符串宏，被替换为"d"

    return 0;
}

