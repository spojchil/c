#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void){
    double x, y, z;

    puts("请输两个数字:(输入0 0退出");
    while (scanf("%lf%lf", &x, &y) == 2
        && (x != 0 || y != 0)){
        z = x * x - y * y;
        assert(z >= 0);
        printf("答案是%f\n", sqrt(z));
        puts("下一组数字:");
    }       
    puts("Done");

    return 0;
}