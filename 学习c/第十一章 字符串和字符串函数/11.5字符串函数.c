#include <stdio.h>
#include <string.h>

void test_fit(void);
void fit(char *, unsigned int);
void str_cat(void);
char *s_gets(char *, int);
void 检查加入(void);
char *读取(char *, int);
void 比较(void);
char *读取1(char *, int);
void cmp返回值(void);
void 快速检查(void);
char *读取2(char *, int);
void 查找字符头(void);
void 复制字符串(void);
char *读取3(char *, int);
void 复制2(void);
void 复制3(void);

int main(void){
    // test_fit();
    // str_cat();
    // 检查加入();
    // 比较();
    // cmp返回值();
    // 快速检查();
    // 查找字符头();
    // 复制字符串();
    // 复制2();
    复制3();

    return 0;
}
void test_fit(void){
    char mesg [] = "Things should be as simple as possible,"
                        " but not simpler.";

    puts(mesg);
    fit(mesg, 38);
    puts(mesg);
    puts("Let's look at some more of the string.");
    puts(mesg + 39);
}
#include <string.h>
void fit(char *string, unsigned int size){
    if (strlen(string) > size)
        string[size] = '\0';
}
#define SIZE 80
void str_cat(void){
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";

    puts("What is your favorite flower?");

    if (s_gets(flower, SIZE)){
        strcat(flower, addon);
        puts(flower);
        puts(addon);
    }
    else
        puts("End of file encountered!");
    puts("Bye");
}

char *s_gets(char *st, int n){
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        while (st[i] != '\n' && st[i] != '\0') i++;
        if (st[i] == '\n') st[i] = '\0';
        else while (getchar() != '\n') continue;
    }
    return ret_val;
}
#define 尺寸 90
#define 袋子尺寸 40
void 检查加入(void){
    char 花[尺寸];
    char 要加的[] = "闻起来像一个臭鞋";
    char 袋子[袋子尺寸];
    int 可用值;

    puts("你最喜欢的花是？");
    读取(花, 尺寸);
    if ((strlen(要加的) + strlen(花) + 1) <= 尺寸) strcat(花, 要加的);
    puts(花);
    puts("你最喜欢的袋子是");
    读取(袋子, 袋子尺寸);
    可用值= 袋子尺寸 - strlen(袋子) - 1;
    strncat(袋子, 要加的, 可用值);  // 自带截断
    puts(袋子);
}

char *读取(char *st, int n){
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val){
        while (st[i] != '\n' && st[i] != '\0') i++;
        if (st[i] == '\n') st[i] = '\0';
        else while (getchar() != '\n') continue;
    }
    return ret_val;
}
#define 答案 "格兰特"
#define 尺寸1 100
void 比较(void){
    char 尝试[尺寸1];
    puts("谁长眠在格兰特墓中?");
    读取1(尝试, 尺寸1);
    while (strcmp(尝试, 答案) != 0){  // 可以写为 while (strcmp(尝试, 答案))
        puts("回答错误，请在尝试一次");
        读取1(尝试, 尺寸1);
    }
    puts("回答正确");
}

char *读取1(char *st, int n){
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        while (st[i] != '\n' && st[i] != '\0') i++;
        if (st[i] == '\n') st[i] = '\0';
        else while (getchar() != '\n') continue;
    }
    return ret_val;
}

void cmp返回值(void){
    printf("strcmp(\"A\", \"A\")的值为");
    printf("%d\n", strcmp("A", "A"));

    printf("strcmp(\"A\", \"B\")的值为");
    printf("%d\n", strcmp("A", "B"));

    printf("strcmp(\"B\", \"A\")的值为");
    printf("%d\n", strcmp("B", "A"));

    printf("strcmp(\"C\", \"A\")的值为");
    printf("%d\n", strcmp("C", "A"));

    printf("strcmp(\"Z\", \"a\")的值为");
    printf("%d\n", strcmp("Z", "a"));

    printf("strcmp(\"apples\", \"apple\")的值为");
    printf("%d\n", strcmp("apples", "apple"));
}

#define 尺寸2 90
#define LIM 10
#define 停止 "退出"
void 快速检查(void){
    char 输入[LIM][尺寸2];
    int ct = 0;

    printf("请输入%d行(输入退出退出)", LIM);
    while (ct < LIM && 读取2(输入[ct], 尺寸2) != NULL &&
            strcmp(输入[ct], 停止) != 0) ct++;
    printf("输入了%d个字符串\n", ct);
}

char *读取2(char *st, int n){
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        while (st[i] != '\n' && st[i] != '\0') i++;
        if (st[i] == '\n') st[i] = '\0';
        else while (getchar() != '\n')  continue;
    }
    return ret_val;
}
#define 字符串数 6
#define 字符串头 "蓝色"
void 查找字符头(void){
    const char *列表[字符串数] = {
        "蓝色的花", "红色的床",
        "黄色的墙面", "蓝色的书",
        "紫色的花", "绿色的地面"
    };
    int 计数 = 0;
    int i;

    for (i = 0; i < 字符串数; i++)
        if (strncmp(列表[i], 字符串头, strlen(字符串头)) == 0){
            printf("找到了:%s\n", 列表[i]);
            计数++;
        }
    printf("这个列表一个有%d个%s开头的", 计数, 字符串头);
}

#define 尺寸3 40
#define 行数 5

void 复制字符串(void){
    char 词[行数][尺寸3];
    char 临时[尺寸3];
    int i = 0;

    printf("请输入%d个词，以q开头的\n", 行数);
    while (i < 行数 && 读取3(临时, 尺寸3)){
        if (临时[0] != 'q')
            printf("%s 不能以，因为它的开头不为q\n", 临时);
        else {
            strcpy(词[i], 临时);  // 类似于赋值表达式
            // 返回是第一个参数的值
            i++;
        }
    }
    puts("Here are the words accepted:");
    for (i == 0; i < 行数; i++) puts(词[i]);
}

char *读取3(char *st, int n){
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        while (st[i] != '\n' && st[i] != '\0') i++;
        if (st[i] == '\n') st[i] = '\0';
        else while (getchar() != '\n') continue;
    }
    return ret_val;
}
#define 尺寸4 40
#define 词1 "最好"
void 复制2(void){
    const char *初始 = 词1;
    char 复制[尺寸4] = "你是最棒的，你可以做到。";
    char *ps;

    puts(初始);
    puts(复制);
    ps = strcpy(复制 + 6, 初始);
    puts(复制);
    puts(ps);
}
#define 拼尺寸1 7

void 复制3(void){
    char 词[行数][拼尺寸1];
    char 临时[尺寸];
    int i = 0;

    printf("请输入%d个q开头的单词\n", 行数);
    while (i < 行数 && 读取2(临时, 尺寸)){
        if (临时[0] != 'q')
            printf("%s不是q开头的单词", 临时);
        else{
            strncpy(词[i], 临时, 拼尺寸1 - 1);
            词[i][拼尺寸1 - 1] = '\0';
            // 副本中不一定有空字符
            i++;
        }
    }
    puts("这是输入的单词");
    for (i = 0; i < 行数; i++) puts(词[i]);
}

/*
sprintf()用法通printf()
但是第一个参数是目表字符串的地址
sprintf()把组合后的字符串存储在数组中
sprintf(存储地址,"%d,%s", 数字, 字符串);
*/