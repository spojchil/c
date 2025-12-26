#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void showmovies(Item item);
char *s_gets(char *st, int);
int main(void){
    List movies;
    Item temp;

    InitializeList(&movies);
    if (ListIsFull(&movies)){
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }

    puts("请输入电影标题");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0'){
        puts("请输入评级(0-10)");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;
        if (AddItem(temp, &movies) == false){
            fprintf(stderr, "程序内存已满");
            break;
        }
        if (ListIsEmpty(&movies)){
            puts("这个链表现在满了");
            break;
        }
        puts("请输入下一个标题（空行退出）：");
    }

    if (ListIsEmpty(&movies))
        printf("没有数据\n");
    else {
        printf("这是输入的电影列表\n");
        Traverse(&movies, showmovies);
    }
    printf("你一共输入了%d个数据\n", ListItemCount(&movies));

    EmptyTheList(&movies);
    printf("Bye!\n");

    return 0;
}

void showmovies(Item item){
    printf("电影: %s,评级: %d\n", item.title, item.rating);
}

