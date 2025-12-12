#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'
#define SLEN 81

int main(void){
    char file[SLEN];
    char ch;
    FILE *fp;
    long count, last;

    puts("输入要处理的文件名称");
    scanf("%80s", file);
    if ((fp = fopen(file, "rb")) == NULL){
        printf("无法打开文件%s\n", file);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);  // 当前位置
    for (count = 1L; count <= last; count++){
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        if (ch != CNTL_Z && ch != 'r') /* MS-DOS文件*/
            putchar(ch);
    }
    putchar('\n');
    fclose(fp);

    return 0;
}
