#include <stdio.h>
#include <string.h>
#define 尺寸 81
#define 行数 20
#define 空字符 ""
void 排序函数(char *[], int);
// 区分(*)[],这里是指针数组，也即是数组中是指针
char *获取(char *, int);
void 字符串外部(void);
void 修改字符串1(void);
void 大写(char *);
int 标点计数(const char *);

int main(void){
    // 字符串外部();
    修改字符串1();

    return 0;
}

void 字符串外部(void){
    char 输入[行数][尺寸];
    char *指针数组[行数];
    int ct = 0;
    int k;
    printf("最多输入%d行,我将排列他们\n", 行数);
    puts("行首输入回车停止");
    while (ct < 行数 && 获取(输入[ct], 尺寸) != NULL 
            && 输入[ct][0] != '\0'){
                指针数组[ct] = 输入[ct];
                ct++;
            }
            排序函数(指针数组, ct);
            puts("\n这是排序完的\n");
            for (k = 0; k < ct; k++) puts(指针数组[k]);
}

void 排序函数(char *字符串[], int num){
    char *临时;
    int top, seek;

    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(字符串[top], 字符串[seek]) > 0){
                临时 = 字符串[top];
                字符串[top] = 字符串[seek];
                字符串[seek] = 临时;
            }
}
char *获取(char *st, int n){
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        while (st[i] != '\0' && st[i] != '\n') i++;
        if (st[i] == '\n') st[i] = '\0';
        else while (getchar() != '\n') continue;
    }
    return ret_val;
}
#include <ctype.h>

#define 尺寸1 81
void 修改字符串1(void){
    char 行[尺寸1];
    char *位置;

    puts("请输入一行");
    fgets(行, 尺寸1, stdin);
    位置 = strchr(行, '\n');
    if (位置) *位置 = '\0';
    大写(行);
    puts(行);
    printf("这一行有%d标点字符.\n", 标点计数(行));
}

void 大写(char *str){
    while (*str){
        *str = toupper(*str);
        str++;
    }
}

int 标点计数(const char *str){
    int ct = 0;
    while (*str){
        if (ispunct(*str)) ct++;
        str++;
    }

    return ct;
}