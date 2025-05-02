#include <stdio.h>
int main(void)
{
    float 体重;
    float 价值;

    scanf("%f",&体重);
    价值 = 1700.0 * 体重 * 14.1456;
    printf("价值是%.2f。\n",价值);
}