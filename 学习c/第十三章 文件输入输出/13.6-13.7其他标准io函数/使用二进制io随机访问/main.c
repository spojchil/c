#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main(){
    double 数据[ARSIZE];
    double value;
    const char *file = "数字.dat";
    int i;
    long pos;
    FILE *iofile;

    for (i = 0; i < ARSIZE; i++)
        数据[i] = 100.0 * i + 1.0 / (i + 1);
    
    if ((iofile = fopen(file, "wb")) == NULL){
        fprintf(stderr, "无法打开输出文件\"%s\"\n", file);
        exit(EXIT_FAILURE);
    }
    // 二进制把数字写入文件
    fwrite(数据, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL){
        fprintf(stderr,
                "无法打开\"%s\"文件作为随机读取\n", file);
        exit(EXIT_FAILURE);
    }
    printf("Enter an index in the range 0-%d\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE){
        pos = (long) i * sizeof(double);  // 计算偏移量
        fseek(iofile, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, iofile);
        printf("这个值是%f\n", value);
        printf("下一个索引是(输入范围外的退出)\n");
    }

    fclose(iofile);
    puts("结束");

    return 0;
}