#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 学习词法分析
int main() {
    FILE *文件 = fopen("测试.txt", "r");  // 假设是纯文本ASCII源文件
    if (文件 == NULL) {
        printf("无法打开文件\n");
        return -1;
    }
    int 半区大小 = 16;  // 这里是测试，实际不会这么小
    signed char *缓冲区 = malloc(半区大小 * 2 + 1);
    if (缓冲区 == NULL) {
        // 处理分配失败
        printf("内存分配失败\n");
        return -1;
    }
    // 双缓冲区

    fread(缓冲区, sizeof(char), 半区大小 - 1, 文件);
    *(缓冲区+半区大小 - 1)=EOF;
    *(缓冲区+半区大小 * 2)=1;
    signed char *词素开始指针 = 缓冲区;
    signed char *前进指针 = 缓冲区;

    int 行号 = 1;
    int 列号 = 1;

    bool 文件结束 = 0;
    while (!文件结束){
        printf("行号%d 列号%d",行号,列号);
        列号++;
        printf("    当前内容%c\n",*前进指针);
        switch (*前进指针++){
            case '\n':
                行号++;
                列号 = 1;
            case EOF:
                if (前进指针 == 缓冲区+半区大小){
                    fread(缓冲区+半区大小, sizeof(char), 半区大小 - 1, 文件);
                    *(缓冲区+半区大小 * 2 - 1)=EOF;
                }

                else if (前进指针 == 缓冲区+半区大小 * 2){
                    fread(缓冲区, sizeof(char), 半区大小 - 1, 文件);
                    *(缓冲区+半区大小 - 1)=EOF;
                    前进指针 = 缓冲区;
                }

                else {  // 此处执行情况为读取到真正的文件结束标志
                    文件结束=1;
                    break;
                }

            
            default:
                /*其他字符情况使用多个case此处省略*/
                break;
        }
    }
    free(缓冲区);
    fclose(文件);
    return 0;
}