/*
int zippo[2][4]
*/
#include <stdio.h>
void 二维数组外(void);
void 数组指针(void);
#define 行 3
#define 列 4

void 求和行(int ar[][列], int 行数);
void 求和列(int [][列], int);
int 二维求和(int (*ar)[列], int 行数);
// int (*ar)[列] 中的ar可以省略但是(*ar)中的括号不能省略
void 求和外(void);
void 二维求和1外(void);
int 二维求和1(int, int, int [*][*]);

int main(void){
    // 二维数组外();
    // 数组指针();
    // 求和外();
    二维求和1外();

    return 0;
}

void 二维数组外(void){
    int 数组[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};

    printf("   数组 = %p,    数组 + 1 = %p\n", 数组, 数组 + 1);
    printf("数组[0] = %p, 数组[0] + 1 = %p\n", 数组[0], 数组[0] + 1);
    printf("  *数组 = %p,   *数组 + 1 = %p\n", *数组, 数组 + 1);
    printf("数组[0][0] = %d\n", 数组[0][0]);
    printf("  *数组[0] = %d\n", *数组[0]);
    printf("    **数组 = %d\n", **数组);
    printf("       数组[2][1] = %d\n", 数组[2][1]);
    printf(" *(*(数组+2) + 1) = %d\n", *(*(数组 + 2) + 1));
}

/* 
声明指向多维数的指针
int (*pz)[2];  // 声明了一个指针指向一个包含两个int类型的数组
int *pz[2];  // []的优先级比*的高，这是声明了一个包含两个元素的数组，
每个元素都指向int


*/
void 数组指针(void){
    int 数组[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
    int (*pz)[2];
    pz = 数组;

    printf("   pz = %p,  pz + 1 = %p\n", pz, pz + 1);
    printf("pz[0] = %p, pz[0] + = %p\n", pz[0], pz[0] + 1);
    printf("  *pz = %p, *pz + 1 = %p\n", *pz, *pz + 1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("  *pz[0] = %d\n", *pz[0]);
    printf("    **pz = %d\n", **pz);
    printf("      pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d", *(*(pz + 2) + 1));
}

void 求和外(void){
    int 数组[行][列] = {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8 ,6}
    };

    求和行(数组, 行);
    求和列(数组, 行);
    printf("数组中的和为%d\n", 二维求和(数组, 行));
}

void 求和行(int ar[][列], int 行数){
    int r, c, tot;

    for (r = 0; r < 行数; r++){
        tot = 0;
        for (c = 0; c < 列; c++)
            tot += ar[r][c];
        printf("行%d的和为%d\n", r, tot);
    }
}

void 求和列(int ar[][列], int 列数){
    int r, c, tot;

    for (c = 0; c < 列; c++ ){
        tot = 0;
        for (r = 0; r < 列数; r++)
            tot += ar[r][c];
        printf("列%d的和为%d\n", c, tot);

    }
}

int 二维求和(int ar[][列], int 行数){
    int r, c;
    int tot = 0;

    for (r = 0; r < 行数; r++)
        for (c = 0; c < 列; c++)
            tot += ar[r][c];

    return tot;
}
/*
变长数组VLA,运行用变量表示数组的维数
int q = 4;
int r = 5;
int s[q][r];  // 一个变长数组
函数中，下面的原型是错误的
int sum(int ar[r][c], int r, int c);
必须先在声明形参列表中声明r,c,可以省略参数名，但是必须使用*号来替代
int sum(int ,int ,int [*][*]);


*/

void 二维求和1外(void){
    int i,j;
    int rs = 3;
    int cs = 10;
    int 数组[行][列] = {
        {2, 4, 6, 8},
        {3, 5 ,7, 9},
        {12, 10, 8, 6}
    };

    int 数组2[行 - 1][列 + 2] = {
        {20, 30, 40, 50, 60, 70},
        {5, 6, 7, 8, 9, 10}
    };

    int 数组3[rs][cs];

    for (i = 0; i < rs; i++)
        for (j = 0; j < cs; j++)
            数组3[i][j] = i * j + j;

    printf("3x4数组\n");
    printf("求和结果是%d\n", 二维求和1(行, 列, 数组));

    printf("2x6数组\n");
    printf("求和结果是%d\n", 二维求和1(行 - 1, 列 + 2, 数组2));

    printf("3x10数组\n");
    printf("求和结果是%d\n", 二维求和1(rs, cs, 数组3));
}

int 二维求和1(int 行数, int 列数, int ar[行数][列数]){
    int r,c;
    int tot = 0;

    for (r = 0; r < 行数; r++)
        for (c = 0; c < 列数; c++)
            tot += ar[r][c];

    return tot;
}
