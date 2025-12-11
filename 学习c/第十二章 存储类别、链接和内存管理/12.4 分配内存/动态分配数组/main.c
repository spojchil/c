#include <stdio.h>
#include <stdlib.h>  // malloc() 和 free()提供原型

int main(void){
    double *双浮点指针;
    int 最大;
    int 数量;
    int i = 0;

    puts("双精度类型数字的最大数量是多少？");
    if (scanf("%d", &最大) != 1){
        puts("输入的数量不正确");
        exit(EXIT_FAILURE);
    }
    双浮点指针 = (double *) malloc(最大 * sizeof(double));
    // calloc()函数也可以分配内存
    // 这里可以改写为calloc(最大, sizeof(double))
    // 并且calloc()会将块初始化全为0
    if (双浮点指针 == NULL){
        puts("内存分配失败");
        exit(EXIT_FAILURE);
    }
    puts("请输入数值(输入q退出)");
    while (i < 最大 && scanf("%lf", &双浮点指针[i]) == 1) i++;
    printf("你已经输入了%d个数字了\n", 数量 = i);
    for (i = 0; i < 数量; i++){
        printf("%7.2f ", 双浮点指针[i]);
        if (i % 7 == 6) putchar('\n');
    }
    if (i % 7 != 0) putchar('\n');
    puts("结束");
    free(双浮点指针);

    return 0;
}