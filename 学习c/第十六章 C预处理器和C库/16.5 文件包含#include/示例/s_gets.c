#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n){
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        find = strchr(st, '\n');  // 查找换行符
        if (find)  // 如果地址不是NULL
            *find ='\0';
        else while (getchar() != '\n') continue;
    }
    return ret_val;
}