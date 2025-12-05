// 块中变量
#include <stdio.h>
int main(){
    int x = 30;  // 原始x

    printf("x在外部块的值是%d，地址是%p\n", x, &x);
    {
        int x = 77;
        printf("x在内部块的值是%d,地址是%p\n", x, &x);
    }
    printf("x在外部块的值是%d,地址是%p\n", x, &x);
    while (x++ < 33){
        int x = 100;  // 新的x隐藏了原始的x
        x++;
        printf("x在内部块的值是%d,地址是%p\n", x, &x);
    }
    printf("x 在外部块的值是%d，地址是%p\n", x, &x);

    return 0;
}