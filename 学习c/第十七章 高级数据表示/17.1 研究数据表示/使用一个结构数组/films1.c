#include <stdio.h>
#include <string.h>
#define TSIZE 45
#define FMAX 5

struct film {
    char title[TSIZE];
    int rating;
};

char *s_gets(char str[], int lim);
int main(void){
    struct film movies[FMAX];
    int i = 0;
    int j;

    puts("请输入首个电影名");
    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL &&
        movies[i].title[0] != '\0'){
        puts("Enter your raring <0-10>:");
        scanf("%d", &movies[i++].rating);
        while (getchar() != '\n')
            continue;
        puts("输入下一个电影标题(空行退出)");
    }
    if (i == 0) printf("没有数据输入");
    else printf("这是电影列表\n");

    for (j = 0; j < i; j++)
        printf("电影名: %s 得分%d \n", movies[j].title, movies[j].rating);
    printf("Bye!\n");

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