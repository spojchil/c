#include <stdio.h>
#include <limits.h>
#include <float.h>
#define 打印 printf  // 尝试宏定义,IDE可以识别
#define 整数 int
#define 主函数 main
#define 无参数 void
#define 返回 return
#define ； ;
整数 主函数(无参数)
{
    打印("一些数字在系统中的限制：\n");
    打印("最大整数：%d\n", INT_MAX);
    打印("最小的长长整数：%lld\n", LLONG_MIN);
    打印("一字节 = %d 位在这个系统中\n", CHAR_BIT);
    打印("最大的双精度浮点数：%e\n", DBL_MAX);
    打印("最小的正常浮点数：%e\n", FLT_MIN)；  // 这里使用中文分号
    打印("float precision = %d digits\n", FLT_DIG);
    printf("浮点数误差 = %e\n", FLT_EPSILON);

    返回 0;    
}
/*
一些数字在系统中的限制：
最大整数：2147483647
最小的长长整数：-9223372036854775808
一字节 = 8 位在这个系统中
最大的双精度浮点数：1.797693e+308
最小的正常浮点数：1.175494e-38
float precision = 6 digits  // 十进制精度
浮点数误差 = 1.192093e-07
*/