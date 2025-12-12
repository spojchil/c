#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void){
    FILE *fp;
    char words[MAX];

    if ((fp = fopen("wordy", "a+")) == NULL){
        fprintf(stderr, "我无法打开\"wordy\"文件。\n");
        exit(EXIT_FAILURE);
    }

    puts("请输入你要在文件追加的内容，新一行书写输入#可以终止输入");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%s\n", words);

    puts("Flie contents:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1) puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "文件无法关闭\n");

    return 0;
}