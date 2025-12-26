#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film{
    char title[TSIZE];
    int rating;
    struct film *next;
};

char *s_gets(char *, int);
typedef struct film films;

int main(void){
    films *头指针 = NULL;
    films *前指针, *当前指针;
    char input[TSIZE];

    puts("请输入首个电影标题名");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0'){
        当前指针 = (films *) malloc(sizeof(films));
        if (头指针 == NULL)
            头指针 = 当前指针;
        else 前指针->next = 当前指针;

        当前指针->next = NULL;
        strcpy(当前指针->title, input);
        puts("请输入你的评级");
        scanf("%d", &当前指针->rating);
        while (getchar() != '\n') continue;
        puts("请输入下一个电影名(空行退出)");
        前指针 = 当前指针;
    }

    if (头指针 == NULL)
        printf("无数据");
    else 
    printf("这是电影列表\n");
    当前指针 = 头指针;

    while (当前指针 != NULL){
        printf("电影：%s 评级 %d\n",
            当前指针->title, 当前指针->rating);
        当前指针 = 当前指针->next;
    }
    当前指针 = 头指针;
    while (头指针!= NULL){
        当前指针 = 头指针;俄法为
        头指针 = 当前指针->next;
        free(当前指针);
    }

    return 0;

}

char *s_gets(char *st, int n){
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        find = strchr(st, '\n');
        if (find) *find = '\0';
        else while (getchar() != '\n') continue;
    }
    return ret_val;
}
