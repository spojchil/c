// while循环和for循环都是入口条件循环，即在循环的每次迭代前检测条件
// do while是入口条件循环
#include <stdio.h>
void 出口检测(void);
void 嵌套循环(void);
long long pow_mod(long long a, long long b, long long m);
int main(void)
{
    // 出口检测();
    // 嵌套循环();
    long long result = pow_mod(4242, 1000000, 123);
    printf("结果: %lld\n", result);

    return 0;
}

void 出口检测(void)
{
    const int secret_code = 13;
    int code_entered;

    do
    {
        printf("请猜测密码数字\n");
        scanf("%d", &code_entered);
    } while (code_entered != secret_code);
    printf("猜对了\n");
}

#define ROWS 6
#define CHARS 1
// 嵌套循环
void 嵌套循环(void)
{
    int row;
    char ch;

    for (row = 0; row < ROWS; row++)
    {
        for (ch = 'A'; ch < ('A' + CHARS + row); ch++)
            printf("%c", ch);
        printf("\n");
    }
}

long long pow_mod(long long a, long long b, long long m) {
    long long res = 1;
    a = a % m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}