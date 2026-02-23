#include <stdio.h>

int main(void){
    int i = 0;
    int num;
    scanf("%d", &num);
    while (num != 1){
        if (num % 2 == 0)
            num /= 2;
        else num = (num * 3 + 1) / 2;
        i++;
    }
    printf("%d",i);
    return 0;
}