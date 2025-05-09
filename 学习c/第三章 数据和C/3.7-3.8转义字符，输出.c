// 3.7 
#include <stdio.h>
int main(void)
{
    float salary;

    printf("\a进入你的每月工资:");
    printf(" ￥______\b\b\b\b\b\b");  // 每个输入数字会覆盖一个_
    scanf("%f", &salary);
    printf("\n\t是$%.2f 一个月，是 ￥%.2f 一年",
         salary, salary * 12.0);
    printf("\rGee!\n");

    printf("\a第一行");
    printf(" 第二行\n");
    scanf("%f", &salary);  // 使用回车后会自动换行，可能是终端差异
    printf("[DEBUG]");  // 标记 scanf 后的位置
    printf("独占一行");
    printf("\n\t第三行");
    printf("\r第四行\n");  // 最后的\n不会产生空行，因为后面没有内容
    
    //3.8
    float a = 256.0;

    printf("%d\n", a);  // 输出为0
    /*
    在 x86-64 系统（或某些 ABI）中，
    float 参数会通过 ​​浮点寄存器​​（如 XMM0）传递，
    而 %d 会从 ​​整数寄存器​​（如 EAX）读取值。
    由于 printf 没有收到正确的整数参数
    ，可能读取到的是未初始化的寄存器值（如 0）
    */
   printf("%d\n", *(int *)&a);  // 这样可以了输出1132462080


    return 0;
}
/*
进入你的每月工资: ￥123456

Gee!    是$123456.00 一个月，是 ￥1481472.00 一年  // 
*/
/*
printf()先把输出发送到一个缓冲区，当缓冲区满、遇到换行符或者需要
输入内容时，把数据发送到屏幕上，称为刷新缓冲区
*/

