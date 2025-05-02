// two_func.c -- 一个文件中包含两个函数
#include <stdio.h>
void butler(void);  // 函数原型
int main(void)  // 无论在什么位置C程序都会从main()开始执行
{
    printf("I will summon the butler function.\n");
    butler();  // 函数调用
    printf("是的，带给我一些茶和writeable DVDs.\n");
    
    return 0;
}
void butler(void) /*函数定义，何时执行取决于在main()中调用位置*/
{
    printf("你的戒指，先生？\n");
}