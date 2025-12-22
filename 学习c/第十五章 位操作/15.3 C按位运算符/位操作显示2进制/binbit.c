#include <stdio.h>
#include <limits.h>

char *itons(int, char *);
void show_bstr(const char *);

int main(void){
    char bin_str[CHAR_BIT *sizeof(int) + 1];
    int number;

    puts("请输入整数并查看其二进制表示。");
    puts("输入非数字停止");
    while (scanf("%d", &number)  == 1){
        itons(number, bin_str);
        printf("%d 是 ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("Bye!");

    return 0;
}

char *itons(int n, char * ps){
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}

void show_bstr(const char *str){
    int i = 0;

    while (str[i]){
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
}