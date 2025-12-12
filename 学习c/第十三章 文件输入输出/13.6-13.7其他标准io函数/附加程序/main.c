#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);
char *s_gets(char *st, int n);

int main(void){
    FILE *fa, *fs;  // fa目标文件, fs 源文件
    int file = 0;  // 附加文件数量
    char file_app[SLEN];  // 目标文件名
    char file_src[SLEN];  // 源文件名
    int ch;

    puts("请输入一个文件的地址");
    s_gets(file_app, SLEN);
    if ((fa = fopen(file_app, "a+")) == NULL){
        fprintf(stderr, "无法打开文件 \"%s\"\n", file_app);
        exit(EXIT_FAILURE);
    }
    // setvbuf 自定义缓冲区
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0){
        fputs("无法创建输出文件\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("请输入第一个源文件地址(空行退出)");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0'){
        if (strcmp(file_src, file_app) == 0)
            fputs("不能将文件追加到它自己\n", stderr);
        else if ((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "无法打开文件\"%s\"\n", file_src);
        else {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0){
                fputs("无法创建输入缓冲区\n", stderr);
                continue;
            }
            append(fs, fa);
            // ferror检测之前的文件读写中是否发生错误
            if (ferror(fs) != 0)
                fprintf(stderr, "读取文件\"%s\"时发送错误\n",
                        file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "写入文件\"%s\"时发送错误\n",
                        file_app);
            fclose(fs);
            file++;
            printf("文件\"%s\"已被追加\n", file_src);
            puts("输入下一个文件（空行退出）");
        }
    }
    printf("追加结束 %d个文件已被追加\n", file);
    rewind(fa);  // 将文件指针重置为开始
    printf("%s contents:\n", file_app);
    while ((ch = getc(fa)) != EOF) putchar(ch);
    puts("\n结束");

    fclose(fa);

    return 0;
}

void append(FILE *source, FILE *dest){
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) >0)
        fwrite(temp, sizeof(char), bytes, dest);
}

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
