#include <stdio.h>

int main() {
    int num;
    printf("请输入一个数字: ");
    scanf("%d", &num);  // 从用户获取输入
    for (int i = num;i > 1;) {
        if (i%2==1) {
            i = 3 * i + 1;
            printf("%d\n", i);
        } else {
            i /=2;
            printf("%d\n", i);
        };
    };
    printf("你输入的数字是: %d\n", num);
    for (int i = 0; i < 10; ) {
        printf("%d ", i);
        i++;
    };
    return 0;
}