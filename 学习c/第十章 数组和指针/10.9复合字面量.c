#include <stdio.h>
#define COLS 4
int 二维求和(const int ar[][COLS], int rows);
int 求和(const int ar[], int n);
int main(void){
    int 和1, 和2, 和3;
    int * pt1;
    int (*pt2)[COLS];

    pt1 = (int[2]) {10, 20};  // 这里是复合字面量
    pt2 = (int[2][COLS]) {{1, 2, 3, -9},{4, 5, 6, -8}};

    和1 = 求和(pt1, 2);
    和2 = 二维求和(pt2, 2);
    和3 = 求和((int []){4, 4, 4, 5, 5, 5},6);
    printf("和1为%d\n", 和1);
    printf("和2为%d\n", 和2);
    printf("和3为%d\n", 和3);
    
    return 0;
}
int 求和(const int ar [],int n){
    int i;
    int 总和 = 0;

    for (i = 0; i < n; i++)
        总和 += ar[i];

    return 总和;
}

int 二维求和(const int ar [][COLS], int rows){
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];

    return tot;
}