#include <stdio.h>
int units = 0;  // 定义式声明
void critic(void);

int main(void){
    extern int units;  // 可选的重复声明
    // 引用式声明
    printf("How many pounds to a firkin of btter?\n");
    scanf("%d", &units);
    while (units != 56) critic();
    puts("You must have looked it up!");

    return 0;
}
void critic(void){
    puts("No luck, mu friend. Try again.");
    scanf("%d", &units);
}