// 带参数的main
#include <stdio.h>
int main(int argc, char *argv[]){
    int 计数;

    printf("这个命令行一共有%d个参数:\n", argc - 1);
    for (计数 = 1; 计数 < argc; 计数++)
        printf("%d: %s\n", 计数, argv[计数]);
    printf("\n");

    return 0;
}
// 第一个参数是命令行是程序名字
