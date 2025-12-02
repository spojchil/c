#include <stdio.h>
#define STLEN 81
void getsputs(void);
void fgets1(void);
void fgets2(void);
void fgets3(void);
char *s_gets(char *, int);
void scan_str(void);

int main(void){
    // getsputs();
    // fgets1();
    // fgets2();
    // fgets3();
    scan_str();
    
    return 0;
}

void getsputs(void){
    char words[STLEN];

    puts("Enter a string, please.");
    gets(words);  // 读取换行符,但是不会储存会丢弃,该函数危险
    // 会导致缓冲区溢出
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);  // 自带换行符
    puts("Done.");
}
/*
对于gets()的替代品fgets()和fputs()该函数专门设计用于处理文件输入输出
区别fgets()的第二个参数明确的指明了输入字符的最大数量，如果是n,那么就会
读入n-1个字符，或者遇到第一个换行符为止，它会存储换行符到字符串，fgets()的
第三个参数指明要输入的文件，如果是从键盘输入的数据。则以stdin(标准输入)为参数
fputs的第二个参数指明它要写入的文件，显示器上则是stdout（标准输出)
*/
#define STLEN1 10
void fgets1(void){
    char words[STLEN1];

    puts("请输入一个字符串");
    fgets(words, STLEN1, stdin);
    printf("你的字符串输出(puts(), fputs())\n");
    puts(words);  // 会输出一个空行
    fputs(words, stdout);  // fputs也会返回指向char的指针
    puts("请输入另一个字符串");  // 输入了一个超过10的字符串
    fgets(words, STLEN1, stdin);  // 没有读取到换行
    printf("你的字符串输出(puts(), fputs())\n");
    puts(words);
    fputs(words, stdout);
}
void fgets2(void){
    char words[STLEN1];

    puts("请输入一个字符串(空行退出)");
    while (fgets(words, STLEN1, stdin) != NULL && words[0] != '\n')
        // fgets读取不成功会返回NULL
        fputs(words, stdout);
    puts("结束");
}

void fgets3(void){
    char words[STLEN1];
    int i;

    puts("请输入一个字符串(空行退出)");
    // 空行退出
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n'){
        i = 0;
        // 选到字符串中的回车和字符串结束
        while (words[i] != '\n' && words[i] != '\0')
            i++;
        // 剔除掉字符串的换行
        if (words[i] == '\n')
            words[i] = '\0';
        else
        // 舍弃掉缓冲区超出的输入
            while (getchar() != '\n')
                continue;
        puts(words);
    }
    puts("结束");
}

char *s_gets(char *st, int n){
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val){
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void scan_str(void){
    char name1[11], name2[11];
    int count;

    printf("请输入两个名字\n");
    count = scanf("%5s %10s", name1, name2);
    printf("我读取了%d个名字%s和%s\n", count, name1, name2);
}