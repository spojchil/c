#include <stdio.h>
void trystat(void);

int main(void){
    int 计数;

    for (计数 = 1; 计数 <= 3; 计数++){
        printf("Here comes iteration %d:\n", 计数);
        trystat();
    }

    return 0;
}

void trystat(void){
    int fade = 1;
    static int stay = 1;

    printf("fade = %d and stay = %d\n", fade++, stay++);
    printf("fade at %p and stay at %p\n", &fade, &stay);
}