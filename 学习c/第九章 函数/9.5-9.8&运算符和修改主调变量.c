// 查找地址: &运算符
#include <stdio.h>
void mikado(int);
void 查看地址();
void 交换函数1(int u, int v);
void 交换函数1外部(void);
void 交换函数3(int *u, int *v);

int main(void){
    // 查看地址();
    交换函数1外部();

    return 0;
}

void 查看地址(void){
    int pooh = 2, bah = 5;

    printf("在main()中, pooh = %d &pooh = %p\n", pooh, &pooh);
    printf("在main()中, bah  = %d &bah  = %p\n", bah , &bah);
    mikado(pooh);  // 这里只传递了值不是变量的地址
}

void mikado(int bah){
    int pooh = 10;

    printf("在mikado()中, pooh = %d &pooh = %p\n", pooh, &pooh);
    printf("在mikado()中, bah  = %d &bah  = %p\n", bah , &bah);
}
// 该输出的四个地址都不相同

void 交换函数1外部(void){
    int x = 5, y = 10;

    printf("原始值为 x = %d and y = %d.\n", x, y);
    // 交换函数1(x, y);  // 并不会修改
    交换函数3(&x, &y);  // 修改了
    printf("现在x = %d ,y = %d.\n", x, y);  // 并不会修改
}

void 交换函数1(int u, int v){
    int 临时;

    printf("原始u = %d,v = %d.\n", u, v);
    临时 = u;
    u = v;
    v = 临时;
    printf("现在u = %d,v = %d.\n", u, v);
}

/*
地址运算符&,*
也是间接运算符
int *ptr;
ptr = &bah; 把ptr指向bah
val = *bah;  找出ptr指向的值
*/
void 交换函数3(int *u, int *v){
    int 临时;
    临时 = *u;
    *u = *v;  // 获取v指向的地址的值如何赋予u指向的地址
    *v = 临时;
}