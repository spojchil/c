#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};  // 结构体的右分号后面需要分号

int main(void){
    struct book library[MAXBKS];  // book类型结构数组
    int count = 0;
    int index;

    printf("请输入书的名字\n");
    printf("请按下[Enter] 在新的一行结束\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
        && library[count].title[0] != '\0'){
            printf("请输入作者\n");
            s_gets(library[count].author, MAXAUTL);
            printf("现在输入价格\n");
            scanf("%f", &library[count++].value);
            while (getchar() != '\n') continue;
            if (count < MAXBKS) printf("请输入下一个书名\n");
    }
    if (count > 0){
        printf("现在展示书的列表\n");
        for (index = 0; index < count; index++)
            printf("%s 作者为%s 价格为 %.2f\n", library[index].title,
            library[index].author, library[index].value);
    }
    else printf("没有书了，太坏了\n");

    return 0;
}