#include <stdio.h>
#define 名称 "巨人思维公司"
#define 地址 "兆富广场101号"
#define 地点 "巨都市, 加利福尼亚州 94904"
#define 宽度 40

void starbar(void);  // 函数原型，第一个void告诉编译器函数的类型
// void类型表明函数没有返回值，圆括号表示starbar是一个函数名，第二个void
// 表示函数不带参数,分号表明这是在声明函数不是定义函数，并告诉编译器在别处查找
// 该函数的定义
void 字符输出(char 字符, int 数字);  // 在函数声明也可以直接(char, int)即不出现形参
void 信输出(void);
void 比大小外部(void);
int 选小数(int, int);
void 演示递归(void);
void 递归函数(int);
void 计算阶乘(void);
long 循环计算(int);
long 递归计算(int);
void 二进打印(void);
void 二进递归(unsigned long);

int main(void){
    // 信输出();
    // 比大小外部();
    // 演示递归();
    // 计算阶乘();
    二进打印();

    return 0;
}

void 比大小外部(void){
    int 数字1, 数字2;

    printf("请你输入两个整数(输入q退出):\n");
    while (scanf("%d %d", &数字1, &数字2) == 2){
        printf("在%d和%d中较小的是%d.\n", 数字1,
            数字2, 选小数(数字1, 数字2));
        printf("请输入两个整数(输入q退出):");
    }
    printf("拜\n");
}

int 选小数(int 数字1, int 数字2){
    int 较小数;

    if (数字1 < 数字2)
        较小数 = 数字1;
    else
        较小数 = 数字2;

    return 较小数;
}

void 信输出(void){
    字符输出('*', 宽度);  // 这里的'*'和宽度是实际参数简称实参
    putchar('\n');
    printf("%s\n", 名称);
    printf("%s\n", 地址);
    printf("%s\n", 地点);
    starbar();
}

void starbar(void){
    int 计数;

    for (计数 = 1; 计数 <= 宽度; 计数++)
        putchar('*');
    putchar('\n');
}

void 字符输出(char 字符, int 数字){  // 这里的字符和数字是形式参数简称形参
    int 计数;

    for (计数 = 1; 计数 <= 数字; 计数++)
        putchar(字符);
}
// 如果是 int 函数 然后 return 100.0 等价于 返回 (int)100.0
// 当然我的示例是显示和隐式的区别
// 在返回值为void的函数时可以使用return;终止函数
/*
函数声明可以在主调函数里面如
#include <stdio.h>
int main(void){
    int imin(int, int);  函数原型都声明在使用函数之前
}
函数声明时的形参可以省略是假名，之后函数定义时可以不同
一种省略函数原型的方法是在使用前直接使用函数定义，这时函数定义也是函数原型
*/
void 递归函数(int 层){
    printf("当前层级是%d,位于 %p\n",层 ,&层);
    if (层 < 4)
        递归函数(层 + 1);
    printf("当后层级是%d,位于 %p\n",层 ,&层);
}

void 演示递归(void){
    递归函数(1);
}

void 计算阶乘(void){
    int 数字;

    printf("这是一个阶乘计算程序\n");
    printf("请输入一个0-12的值(输入q退出)");
    while (scanf("%d", &数字) == 1){
        if (数字 < 0)
            printf("负值无效，请重新输入\n");
        else if (数字 > 12)
            printf("输入不能超过12\n");
        else {
            printf("循环计算结果 %d 的阶乘为 %ld\n",
                数字, 循环计算(数字));
            printf("递归计算结果 %d 的阶乘为 %ld\n",
                数字, 递归计算(数字));
        }
        printf("请输入一个0-12的值(输入q退出)");
    }
    printf("拜\n");
}

long 循环计算(int n){
    long 结果;

    for (结果 = 1; n > 1; n--)
        结果 *= n;

    return 结果;
}

long 递归计算(int n){
    long 结果;

    if (n > 0)
        结果 = n * 递归计算(n - 1);
    else
        结果 = 1;

    return 结果;
}

void 二进打印(void){
    unsigned long 数字;
    printf("请输入一个整数(输入q退出):\n");
    while (scanf("%lu", &数字) == 1){
        printf("二进表示是: ");
        二进递归(数字);
        putchar('\n');
        printf("请输入一个整数(输入q退出):\n");
    }
    printf("结束\n");
}

void 二进递归(unsigned long n){
    int r;

    r = n % 2;
    if (n >= 2)
        二进递归(n / 2);
    putchar(r == 0 ? '0' : '1');

    return;
}
// main也可以递归或者被其他函数调用，它的特殊之处当和其他函数放在一起时
// 最开始执行的总是main()，函数中的第一条语句