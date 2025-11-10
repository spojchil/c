/*
7.3逻辑运算符
逻辑运算符&& || !
含义：或与非
iso646.h
列出了关键字
and or not
*/
#include <stdio.h>

void 逻辑运算(void);
void 统计单词(void);
void 条件运算符(void);

int main(void){
    // 逻辑运算();
    // 统计单词();
    条件运算符();

    return 0;
}
void 逻辑运算(void){
    int a1 = 6 > 2 && 3 == 3;  // 一旦发现有整个表达式为假的因素，立刻停止求值
    int a2 = a1 != 0 && (20 / a1) < 5;  // 只有a1 != 0为真时，才会对第二个表达式求值
    printf("%d   %d",a1,a2);

    int *p;
    printf("请输入你的值：\n");
    scanf("%d",p);
    printf("输入是%d", *p);
    if (*p >= 90 && *p <= 100){  // 不能写为数学上的形式90 <= *p <=100
        // 那样会有语义错误，不是语法，编译器不会报错
        // 编译器的理解是(90 <= *p) <=100，也即是恒为真
        printf("好成绩");
    }
}


#include <ctype.h>  // 为isspace()函数提供原型
#include <stdbool.h>  // 为bool true false 提供定义
#define 停止 '|'
void 统计单词(void){
    char 读取字符;
    char 前一字符;
    long 字符数 = 0L;
    int 行数 = 0;
    int 单词数 = 0;
    int 不完整行数 = 0;
    bool 在单词中 = false;

    printf("请输入要分析的文本（输入|以停止");
    前一字符 = '\n';
    while ((读取字符 = getchar()) != 停止){
        字符数++;  // 统计字符
        if (读取字符 == '\n')
            行数++;
        if (!isspace(读取字符) && !在单词中){
            在单词中 = true;
            单词数++;
        }
        if (isspace(读取字符) && 在单词中)
            在单词中 = false;
        前一字符 = 读取字符;
    }

    if (前一字符 != '\n')
        不完整行数 = 1;
    printf("字符数=%ld, 单词=%d, 行数=%d",
            字符数,单词数, 行数);
    printf("不完整的行数=%d \n", 不完整行数);
    
}

#define 覆盖面积 350
void 条件运算符(void){
    int 平方米;
    int 桶数;

    printf("请输入要刷取的平方米");
    while (scanf("%d", &平方米) == 1){
        桶数 = 平方米 / 覆盖面积;
        桶数 += (平方米 % 覆盖面积 == 0) ? 0 : 1;
        printf("你需要%d桶\n", 桶数);
    }
}
// 格式 表达式1 ? 表达式2 : 表达式3
// 如果表达式1的值为真则整个表达式的值是表达式2，否则是表达式3

