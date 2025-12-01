#include <stdio.h>
#define MSG "我是一个符号字符串"
#define 最大长度 81
void 字符串1外部(void);
void 字符串2外部(void);
void 字符串3外部(void);
void 字符和指针数组(void);
void 字符和指针(void);

int main(void){
    // 字符串1外部();
    // 字符串2外部();
    // 字符串3外部();
    // 字符和指针数组();
    字符和指针();
    return 0;
}


void 字符串1外部(void){
    char 句子[最大长度] = "这m是一个字符串。";
    const char *pt1 = "一个指针指向我";
    puts("这有一个字符串");  // puts 函数只显示字符串，而且自动在末尾加换行
    puts(MSG);  // 可以直接传入字符串字面量(字符串常量)
    puts(句子);  // 
    puts(pt1);
    句子[3] = 'p';
    puts(句子);
}
/*
如果字符串字面量直接无间隔或者没有空白符分隔C会将其视为串联起来的
字符串字面量，例如
char 句[100] = "这是""一个""句子""。"
改行代码与下面的代码等价
char 句[100] = "这是一个句子。"
在字符串内部使用双引号需要在双引号前面加上反斜杠
被双引号括起来的内容被视为指向该数组位置的指针
*/

void 字符串2外部(void){
    printf("%s, %p, %c\n", "We", "are", *"space farers");
}

#define 字符串 "zfc"
void 字符串3外部(void){
    char ar[] = 字符串;
    const char *pt = 字符串;
    // 字符串字面量被视为const数据，因此应该把pt声明为指向const的指针
    printf("\"zfc\"地址为%p \n", "zfc");
    printf("        ar地址为%p\n", ar);
    printf("      pt地址为%p\n", pt);
    printf("   字符串宏地址为%p\n", 字符串);
    printf("\"zfc\"地址为%p \n", "zfc");
}
/*
只有ar输出了不同的地址,ar是在栈内存上，其他的是在数据段
*/
#define SLEN 40
#define LIM 5
void 字符和指针数组(void){
    const char *mytalents[LIM] = {
        "Adding numbers",
        "Multiplying accurately", "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"
    };
    char yourtalents[LIM][SLEN] = {
        "Walking in a straight line",
        "Sleeping", "Watching relevision",
        "Mailing letters", "Reading email"
    };
    int i;

    puts("Let's compare talents.");
    printf("%-36s  %-25s\n", "My Talents", "Your Talents");
    for (i = 0; i < LIM; i++)
        printf("%-36s  %-25s\n", mytalents[i], yourtalents[i]);
    printf("\nsizeof mytalents: %zd, szeof yourtalents:%zd \n",
                sizeof(mytalents), sizeof(yourtalents));
}

void 字符和指针(void){
    const char *mesg = "Don't be a fool!";
    const char *copy;

    copy = mesg;
    printf("%s\n", copy);
    printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
    printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);
}