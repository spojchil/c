#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "chs");
    
    FILE *file = fopen("测试.txt", "r");
    if (file == NULL) {
        printf("文件打开失败！\n");
        return 1;
    }
    
    // 获取文件大小
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // 分配缓冲区
    char *buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        printf("内存分配失败！\n");
        fclose(file);
        return 1;
    }
    
    // 读取整个文件
    size_t bytes_read = fread(buffer, 1, file_size, file);
    buffer[bytes_read] = '\0';  // 添加字符串结束符
    
    printf("文件内容（%ld 字节）：\n", file_size);
    printf("====================\n");
    
    // 输出所有字符
    for (int i = 0; i < bytes_read; i++) {
        putchar(buffer[i]);  // 保留所有字符，包括换行
    }
    
    printf("\n====================\n");
    
    free(buffer);
    fclose(file);
    return 0;
}