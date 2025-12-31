#include <stdio.h>

int jiecheng(int);

int main(void){
    int n;

    puts("输入计算的数");
    scanf("%d", &n);
    
    printf("%d的阶乘是%d", n, jiecheng(n));

    return 0;
}

int jiecheng(int n){
    if (n == 1 || n == 0)
        return 1;
    return jiecheng(n-1) * n;
}

