// 控制模块，房间费率程序
#include <stdio.h>
#include "9.4_酒店.h"

int main(void){
    int 天数;
    double 酒店费用;
    int 状态代码;

    while ((状态代码 = 菜单()) != 退出){
        switch (状态代码){
        case 1: 酒店费用 = 酒店1;
                break;
        case 2: 酒店费用 = 酒店2;
                break;
        case 3: 酒店费用 = 酒店3;
                break;
        case 4: 酒店费用 = 酒店4;
                break;
        default: 酒店费用 = 0.0;
                 printf("Oops\n");
                 break;
        }
        天数 = 预定天数();
        展示费用(酒店费用, 天数);
    }
    printf("拜\n");

    return 0;
}