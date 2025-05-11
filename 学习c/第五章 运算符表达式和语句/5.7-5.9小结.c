#include <stdio.h>
const int 每分秒数 = 60;
const int 每时秒数 = 3600;
const double 每公英里 = 0.62137;
int main(void)
{
    double distk, distm;  // 跑过距离（分别以公里和英里为单位）
    double rate;  // 平均速度（以英里/小时为单位）
    int min, sec;  // 跑步用时（以分钟和秒为单位）
    int time;  // 跑步用时（以秒为单位）
    double mtime;  // 跑1英里需要的时间，以秒为单位
    int mmin, msec;  // 跑1英里需要的时间，以分钟和秒为单位

    printf("本程序将把您在公制比赛中的时间\n");
    printf("转换为跑一英里所需的时间以及您的平均速度（英里/小时）。\n");
    printf("请输入您跑步的距离（单位：公里）。\n");
    scanf("%lf", &distk);  // %lf表示读取一个double类型的值
    printf("接下来请输入时间（分钟和秒数）。\n");
    printf("请先输入分钟数。\n");
    scanf("%d", &min);
    printf("现在请输入秒数。\n");
    scanf("%d", &sec);

    time = 每分秒数 * min + sec;
    distm = 每公英里 * distk;
    rate = distm / time * 每时秒数;
    mtime = (double) time / distm;
    mmin = (int) mtime / 每分秒数;
    msec = (int) mtime % 每分秒数;

    printf("您以%d分%d秒跑完了%1.2f公里（约%1.2f英里）。\n", 
        min, sec, distk, distm);
    printf("这个配速相当于跑一英里需要%d分", mmin);
    printf("%d秒。\n您的平均速度为%1.2f英里/小时。\n", msec, rate);

    return 0;
}