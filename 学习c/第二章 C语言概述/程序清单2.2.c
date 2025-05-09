// fathm_ft.c -- 把2音寻准换为英寸
#include <stdio.h>
int main(void)
{
    int 英寸, fathoms;

    fathoms = 2;
    英寸 = 6 * fathoms;
    printf("There are %d feed in %d fathoms!\n", 英寸, fathoms);
    printf("是的，我说%d英寸！", 6 * fathoms);

    return 0;
}