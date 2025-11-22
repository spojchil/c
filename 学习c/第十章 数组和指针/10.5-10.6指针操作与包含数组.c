#include <stdio.h>

void 指针操作(void);
void 显示数组(const double [], int);
// 这里的const是告诉编译器，该函数不修改数组
void 倍增数组(double [], int, double 乘数);
void 演示函数(void);

int main(){
    // 指针操作();
    演示函数();
    return 0;
}

void 指针操作(void){
    int urn[5] = {100, 200, 300, 400, 500};
    int *ptr1, *ptr2, *ptr3;

    ptr1 = urn;
    ptr2 = &urn[2];

    printf("指针的值，指向的值，指针的地址\n");
    printf("prt1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

    ptr3 = ptr1 + 4;
    printf("\n给指针增加一个int(四字节)\n");
    printf("\nptr1 + 4 = %p, *(ptr1 + 4) = %d", ptr1 + 4, *(ptr1 + 4));
    ptr1++;
    printf("\n自增指针ptr1++\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
    ptr2--;
    printf("\n自减 --ptr2--\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
    --ptr1;
    ++ptr2;  // 恢复为初始值
    printf("\n指针已被恢复\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
    printf("\n进行指针的差运算\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n", ptr2 ,ptr1, ptr2 - ptr1);
    // %td只用于表示两指针的差，指针做差要求必须指向同一个数组或者是一个数组之后的一位
    // 返回的是之间的元素个数，不是字节
    printf("\n指针减去一个整数\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 -2);
}

#define 尺寸 5
void 演示函数(void){
    double 数组[尺寸] = {20.0, 17.66, 8.2, 15.3, 22.22};

    printf("这是原始的dip:\n");
    显示数组(数组, 尺寸);
    倍增数组(数组, 尺寸, 2.5);
    printf("这是倍增的数组:\n");
    显示数组(数组, 尺寸);
}

void 显示数组(const double 数组[], int n){
    int i;

    for (i = 0; i < n; i++)
        printf("%8.3f", 数组[i]);
    putchar('\n');
}

void 倍增数组(double 数组[], int n,double 乘数){
    int i;

    for (i = 0; i < n; i++)
        数组[i] *= 乘数;
}
/* 
int days[2] = {31, 28};
const int *p = day;  // 这里是声明的指向的值被当作常量
*p = 3  // 不允许
p[1] = 2  // 不允许
days[1] = 2  // 允许，因为days未被const限定
实际是通过p的路径修改的不允许
但是可以修改p的值比如
p = &days[1];
int * const pc = days; // pc是一个常量指针，指向int
pc = &day[1]  // 不可以
但是 *pc = 1; 这个可以

const double locked[4] = {0.04, 3.2, 32.2, 2.4};
double *pnc;  // pnc是一个普通指针
pnc = locked;  // 无效，如果有效的话就可以通过该指针越过locked修改了

使用非const标识符的函数，修改const数据的结果是未定义的
可以使用两个const来创建一个只读的指针
const int * const p = days;
*/