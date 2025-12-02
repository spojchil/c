#include <stdio.h>
#define DEF "我是一个#define"
void put_out(void);
void nono(void);
void put1(const char *);
int put2(const char *);
void put_put(void);

int main(void){
    // put_out();
    // nono();
    put_put();

    return 0;
}

void put_out(void){
    char str1[80] = "An array was inintialized to me.";
    const char *str2 = "A pointer was initialized to me.";

    puts("我是一个puts()的参数");
    puts(DEF);
    puts(str1);
    puts(str2);
    puts(&str1[5]);
    puts(str2 + 4);
}
// gets会丢弃输入中的换行符,puts会在输出在添加换行符
// 危险示例
void nono(void){
    char side_a[] = "Side A";
    char dont[] = {'W', 'O', 'W', '!'};
    char side_b[] = "Side B";

    puts(dont);  // dont不是一个字符串
}

void put1(const char *string){
    while (*string != '\0')  // 常见写法while (*string)
        putchar(*string++);
}

int put2(const char *string){
    int count = 0;
    while (*string){
        putchar(*string++);
        count++;
    }
    putchar('\n');

    return(count);  // 两种写法均可
}

void put_put(void){
    put1("如果我的钱");
    put1("多到花不完,\n");
    printf("我将数%d字符,\n",
        put2("I never would cry old chairs to mend."));

}

