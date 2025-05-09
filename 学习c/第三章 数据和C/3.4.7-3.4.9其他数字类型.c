/* 2025 5 4 
3.4.7
复数和虚数类型
C语言三种数据类型
float_Complex, double_Complex和long double_Complex
float_Complex 包含两个float类型的值，分别表示复数的实部和虚部

三种虚数类型
float _Imaginary,double _Imaginary ,long dounle _Imaginary
如果包含complex.h头文件，可以使用complex来代替_Complex
还可以使用I代替-1的平方根
*/

/* 3.4.8
C语言没有字符串类型,但有办法出来
还有一些衍生的类型包括数组、指针、结构和联合
*/

// 3.4.9 类型大小
#include <stdio.h>
int main(void)
{
    // C99为类型大小提供%zd准换说明
    printf("整数有%zd个字节\n", sizeof(int));
    printf("字符有%zd字节\n", sizeof(char));
    printf("长整数有%zd字节\n", sizeof(long));
    printf("长长整数有%zd字节\n", sizeof(long long));
    printf("双精度浮点数有%zd字节\n", sizeof(double));
    printf("长双精度浮点数有%zd字节\n", sizeof(long double));
    printf("布尔值有%zd字节\n",
        sizeof(_Bool));  // 即使布尔值只需要一位但还是分配了一字节

    return 0;
}