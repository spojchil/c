// sizeof.c
#include <stdio.h>
int 程序5_8(void);
int 分转秒(void);
int 递增运算(void);
int main(void)
{
    // 程序5_8();
    // 分转秒();
    递增运算();

    return 0;
}

int 程序5_8(void)
{
    int n = 0;
    size_t intsize;

    intsize = sizeof (int);  // size_t返回suze_t类型的值
    // 这是一个无符号整数，是使用typedef将size_t作为unsigned int 
    // 或者unsigned long 的别名，这样使用这个类型时编译器会自动选择替换
    printf("n = %d, n有%zd字节；所有的整数都有%zd字节。\n", n,
        sizeof n, intsize);  // 如果不支持%zd可以使用%u或者%lu代替%zd

    return 0;
}

#define 分秒比 60
int 分转秒(void)
{
    int sec, min, left;

    printf("将秒转换为分钟和秒\n");
    printf("请输入秒数（输入非正数退出）：\n");
    scanf("%d", &sec);
    while (sec > 0)
    {
        min = sec / 分秒比;  // 截断分钟
        left = sec % 分秒比;  // 剩下的秒数 求模或者说取余
        printf("%d 秒是%d分钟,%d秒\n", sec, min, left);
        printf("请输入下一个值（输入非正数退出）：\n");
        scanf("%d", &sec);
    }
    printf("结束\n");

    return 0;
}

// 递增运算符
int 递增运算(void)
{
    int ultra = 0, super = 0;

    while (super < 5)
    {
        super++;  // 先作为值，在递增
        ++ultra;  // 先递增在作为值
        // a-- --a 用法相同
        printf("super = %d, ultra = %d \n", super, ultra);
    }

    return 0;
}
/* 
> < 为关系运算符
x*y++表示(x)*(y++)，++的优先级很高而不是(x+y)++,
而且后者无效，因为++运算符只能影响一个可修改的左值
*/

/*
不要自作聪明
printf("%d %d", num, num*num++);
可能是
5 25 或者6 25 甚至还可能6 30
y = b++ + b++也不确定值是多少
尽量让递增单独出现
*/