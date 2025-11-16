/*
单字符I/O getchar()和putchar()
*/
#include <stdio.h>

void 重复输入(void);
void 打开显示(void);

int main(void){
    // 重复输入();
    打开显示();

    return 0;
}


void 重复输入(void){
    int ch;
    // 如果 char 是无符号的，这会出问题，所有不使用char改为使用int
    while ((ch = getchar()) != EOF)  // 不使用EOF即使输入了^Z也不会退出
        putchar(ch);
}
// 键盘输入通常是行缓冲输入
// 程序
// 8.1.exe < words > word,8.1.exe<words>word空格可选
// 重定向输入输出，与顺序无关，但是不能重名，可以不存在输出文件，是覆写
// 单对单，若要在文件末尾追加使用>>

#include <stdlib.h>  // 为了使用exit()
void 打开显示(void){
    int ch;
    FILE * fp;
    char fname[50];

    printf("请输入文件名:");
    scanf("%s", fname);
    fp = fopen(fname, "r");
    if (fp == NULL)  //如果失败
    {
        printf("文件打开失败\n");
        exit(1);  // 退出程序
    } 

    while ((ch = getc(fp)) != EOF) // 获取一个字符
        putchar(ch);
    fclose(fp);  // 关闭文件
}