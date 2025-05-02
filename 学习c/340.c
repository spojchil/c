#include <stdio.h>
int main(void)
{
    int i = 2147483647;
    unsigned int j = 4294967295;
    long big = 65537;
    char 字符 = 'A';
    float a = 0.13;
    float b = 0.2;

    printf("%f\n",a+b);
    printf("%c and %d\n",字符,字符);
    printf("%ld and %hd and %x\n", big, big, big);
    printf("%u %d %hd\n", i+1, i+1, i+1);
    printf("%u %u %u\n", j, j+1, j+2);
    printf("%d %f\n",i,i);

    return 0;
}