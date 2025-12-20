#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81

char *s_gets(char *st, int n);
char showmenu(void);
void eatline(void);
void show(void (*fp)(char *), char *);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);

int main(void){
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *) = NULL;
    puts("输入一个字符串(空行退出)");
    while (s_gets(line, LEN) != NULL && line[0] != '\0'){
        while ((choice = showmenu()) != 'n'){
            switch (choice){
                case 'u': pfun = ToUpper; break;
                case 'l': pfun = ToLower; break;
                case 't': pfun = Transpose; break;
                case 'o': pfun = Dummy; break;
            }
            strcpy(copy, line);
            show(pfun, copy);
        }
        puts("请输入一个字符(空行退出)");
    }
    puts("Bye");

    return 0;
}

char showmenu(void){
    char ans;
    puts("请输入菜单选择");
    puts("u) 大写   l) 小写");
    puts("t) 大小写转换     o) 原始字符串");
    puts("n) 下一个字符");
    ans = getchar();
    ans = tolower(ans);
    eatline();  // 清理输入行
    while (strchr("ulton", ans) == NULL){
        puts("请输入一个u l t o 或者 n:");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

void eatline(void){
    while (getchar() != '\n') continue;
}

void ToUpper(char *str){
    while (*str){
        if (*str >= 'a' && *str <= 'z')
            *str -= 'a' - 'A';
        // *str = toupper(*str);
        str++;
    }
}

void ToLower(char *str){
    while (*str){
        *str = tolower(*str);
        str++;
    }
}

void Transpose(char *str){
    while (*str){
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}

void Dummy(char *str){
    
}

void show(void (*fp)(char *), char *str){
    fp(str);
    puts(str);
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