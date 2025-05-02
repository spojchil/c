#include <stdio.h>  // 包含一个文件
/*
告诉编译器把stdio.h中的内容包含在当前程序中。
stdio.h是C编译器软件包的标准部分，
它提供键盘输入和屏幕输出支持。
*/
int main(void)  // 函数名
/*
C程序包含一个或者多个函数
*/
{
    int num;
    num = 1;

    printf("我有一台个人");
    printf("电脑.\n");
    printf("我最喜欢的数字是%d，因为它是第一个。\n",num);

    return 0;
}
