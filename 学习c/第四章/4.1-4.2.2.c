// 2025 5 4 字符串和格式化输入/输出
// 演示与用户交互 4.1
#include <stdio.h>
#include <string.h>
#define DENSITY 1003.42
#define PRAISE "你是一个extraordinary being."
int main()  // 课本上就没有写void
{
    float weight, volums;
    int size, letters;
    char name[40];  // name是一个可容纳40字符的数组，方括号表明这是一个数组
    // 只能储存39个字符，剩余一个字符留给空字符，

    printf("你好！你的第一个名字是什么？\n");
    scanf("%s", name);  // %s处理字符串的输入和输出
    printf("%s, 你的体重是多少千克?\n", name);
    scanf("%f", &weight);
    size = sizeof name;
    letters = strlen(name);  // 获取字符串的长度
    volums = weight / DENSITY;
    printf("很好，%s,你的体积 是%2.2f立方米。\n", name, volums);
    printf("Also, 你的第一个名字有 %d lentters,\n", letters);
    printf("和我们%dbytes to store it.\n", size);

    //4.2.2
    char 名字[40];
    printf("你的名字是？");
    scanf("%s", 名字);  // 只会读取字符串的第一个单词，在遇到空格时停止
    printf("你好, %s. %s\n", 名字, PRAISE);
    // 's'是字符常量，而"s"是字符串字面量，后者由字符's'和空字符'\0'组成。

    return 0;
}
/*
C语言没有专门储存字符串的变量类型，字符串储存在char类型的数组中
数组是由连续的储存单元组成，字符串中的字符储存在相邻的存储单元中，
每个单元储存一个字符
数组末尾位置的字符\0是空字符(null),C语言用它标记字符串的结束
空字符不是0，是非打印字符，ASCII码是0
C语言一定以空字符结束
*/