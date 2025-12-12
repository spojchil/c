#include <stdio.h>
#include <stdlib.h>  // exit()原型
#include <string.h>  // strcpy,strcat()原型
#define LEN 200

int main(int argc, char *argv []){
    FILE *in, *out;
    int ch;
    char name[LEN];
    int count = 0;

    if (argc < 2){
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((in = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
            argv[1]);
        exit(EXIT_FAILURE);
    }

    strncpy(name, argv[1], LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL){
        fprintf(stderr, "无法创建输出文件\n");
        exit(3);
    }

    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);
    
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "文件无法关闭");

    return 0;
}