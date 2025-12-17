#include <stdio.h>
#include <string.h>  // strcpy(),strlen()原型
#include <stdlib.h>  // malloc(),free()函数原型
#define SLEN 81
struct namect {
    char *fname;  // 使用指针
    char *lname;
    int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *);
char *s_gets(char *, int);

int main(void){
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);

    return 0;
}

void getinfo(struct namect *pst){
    char temp[SLEN];
    puts("请输入你的名字");
    s_gets(temp, SLEN);
    // 分配内存储存名
    pst->fname = (char *) malloc(strlen(temp) + 1);
    // 复制名到内存
    strcpy(pst->fname, temp);
    printf("请输入你的最后一个名");
    s_gets(temp, SLEN);
    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}

void makeinfo(struct namect *pst){
    pst->letters = strlen(pst->fname) +
        strlen(pst->lname);
}

void showinfo(const struct namect *pst){
    printf("%s %s,你的名子长度为%d个子.\n",
            pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect * pst){
    free(pst->fname);
    free(pst->lname);
}
