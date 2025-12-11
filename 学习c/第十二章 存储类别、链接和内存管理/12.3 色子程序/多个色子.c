// 多次掷色子模拟
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "色子点数.h"

int main(void){
    int 色子数, 点数;
    int 面数;
    int 状态;

    srand((unsigned int) time(0));  // 随机种子
    puts("请输入色子的数量,输入0停止");
    while (scanf("%d", &面数) == 1 && 面数 > 0){
        puts("需要多少面");
        if ((状态 = scanf("%d", &色子数)) != 1){
            puts("需要多少个色子");
            if (状态 == EOF) break;
            else {
                puts("你应该输入一个整数,请重新输入");
                while (getchar() != '\n') continue;
            }
            puts("请你输入需要的面数,输入0输出");
            continue;
        }
        点数 = n面点数(色子数, 面数);
        printf("你投的%d个%d面色子的点数是%d\n", 色子数, 面数, 点数);
        puts("请你输入需要的面数,输入0输出");
    }
    printf("函数点数em()被调用了%d次\n", 点数计数);

    return 0;
}