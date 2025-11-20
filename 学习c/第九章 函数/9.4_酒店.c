#include <stdio.h>
#include "9.4_酒店.h"
int 菜单(void){
    int 状态代码, 状态;

    printf("\n%s%s\n", 开始, 开始);
    printf("请输入一个数字，来选择公寓\n");
    printf("1) 一级公寓     2) 二级公寓\n");
    printf("3) 三级公寓     4) 四级公寓\n");
    printf("5) 退出\n");
    printf("\n%s%s\n", 开始, 开始);
    while ((状态 = scanf("%d", &状态代码)) != 1 ||
            (状态代码 < 1 || 状态代码 > 5)){
                if (状态 != 1)
                    scanf("%*s");  // *抑制赋值
                printf("请输入一个1-5范围内的数字\n");
    }
    
    return 状态代码;
}

int 预定天数(void){
    int 天数;

    printf("你需要居住多少天？\n");
    while (scanf("%d", &天数) != 1){
        scanf("%*s");
        printf("请输入一个整数\n");
    }

    return 天数;
}

void 展示费用(double 费率, int 天数){
    int n;
    double 总共 = 0.0;
    double 因子 = 1.0;

    for (n = 1; n <= 天数;n++, 因子 *= 倍率)
        总共 += 费率 * 因子;
    printf("你的总费用是 %0.2f\n", 总共);
}