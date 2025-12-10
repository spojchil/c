#include <stdio.h>
#include <stdlib.h>
extern void srand1(unsigned int);
extern int rand1(void);
int main(void){
    int count;
    unsigned seed;

    printf("请输出你选择的种子\n");
    while (scanf("%u", &seed) == 1){
        srand1(seed);
        for (count = 0; count < 5; count++)
            printf("%d\n", rand1());
        printf("请输入下一个种子（输入q退出)\n");
    }
    printf("Done\n");

    return 0;
}