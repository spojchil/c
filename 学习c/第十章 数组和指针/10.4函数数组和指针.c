// 声明数组函数的函数原型可以使用四种种形式
// int 函数(int *) 或者 int 函数(int *ar) 
// 或者 int 函数(int ar[]) 或者 int 函数(int [])
// 注意函数定义中不可以省略名称
#include <stdio.h>
#define 尺寸 10
int 求和(int *, int);
void 求和外部(void);
int 双指针求和(int *,int *);

int main(void){
    求和外部();
    return 0;
}

void 求和外部(void){
    int 数组[尺寸] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long 结果;

    // 结果 = 求和(数组, 尺寸);
    结果 = 双指针求和(数组, 数组 + 尺寸);
    printf("这些数字的和是%ld.\n", 结果);
    printf("这个数组的大小是%zd字节。\n", sizeof 数组);
}

int 求和(int 数组[], int n){
    int i;
    int 总共 = 0;

    for (i = 0; i < n; i++)
        总共 += 数组[i];
    printf("这个尺寸是%zd字节\n", sizeof 数组);
    // 这里sizeof 没有在实际数组的定义作用范围中，无法返回数组大小，返回了指针大小

    return 总共;
}

int 双指针求和(int *起始, int *末尾){
    int 总共 = 0;

    while (起始 < 末尾){
        总共 += *起始;
        起始++;
        // 甚至可以压缩为一行代码,总共+=*起始++,*和++同优先级，所以从左往右执
        // 等价于 *(起始++),这里先返回当前旧的起始的值，然后进行副作用即自增
        // 所以解引用的是旧的地址值
    return 总共;
}