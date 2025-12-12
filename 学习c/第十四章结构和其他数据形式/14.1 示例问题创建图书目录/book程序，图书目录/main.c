#include <stdio.h>
char *s_gets(char *st, int n);
#define MAXTITL 41
#define MAXAUTL 31

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void){
    struct book library;

    printf("请输入图书名称.\n");
    s_gets(library.title, MAXTITL);
    puts("现在输入作者");
    s_gets(library.author, MAXAUTL);
    puts("现在输入书的价格");
    scanf("%f", &library.value);
    printf("%s 的作者是 %s,价格为%.2f\n",
            library.title, library.author, library.value);
    printf("结束\n");

    return 0;
}