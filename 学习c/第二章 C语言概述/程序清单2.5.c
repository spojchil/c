/* stillbad.c -- 修复了语法错误的程序 */
#include <stdio.h>
int main(void)
{
    int n, n2, n3;

    /* 该程序有一个语义错误 */
    n = 5;
    n2 = n * n;
    n3 = n2 * n2;  //这里
    printf("n = %d, n的平方 = %d, n的立方 = %d\n", n, n2, n3);

    return 0;
}