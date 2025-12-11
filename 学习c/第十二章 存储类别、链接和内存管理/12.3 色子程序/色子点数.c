#include "色子点数.h"
#include <stdio.h>
#include <stdlib.h>

int 点数计数 = 0;

// 文件私有函数
static int 点数em(int 面数){
    int 点数;

    点数 = rand() % 面数 + 1;
    点数计数++;

    return 点数;
}

int n面点数(int 色子数, int 面数){
    int d;

    int 总数 = 0;
    if (面数 < 2){
        puts("你至少需要两面");
        return -2;
    }
    if (色子数 < 1){
        puts("你至少需要一个色子");
        return -1;
    }
    
    for (d = 0; d < 色子数; d++)
        总数 += 点数em(面数);

    return 总数;
}
