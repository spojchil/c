#include <stdio.h>

void 猜数字(void);
void 修正猜数字(void);
void 无问题IO的程序(void);
void 展示程序(int 字符, int 行, int 宽);

int main(void){
    // 猜数字();
    // 修正猜数字();
    无问题IO的程序();
    return 0;
}
void 猜数字(void){  // 一个错误且拖沓的程序
    int 猜测 = 1;

    printf("请确定一个1到100内的整数，我将尝试猜测你的数字\n");
    printf("请输入y表示我猜对了，猜错了请输入n\n");
    printf("你的数字是%d吗\n", 猜测);
    while (getchar() != 'y')  // 这里同时读取了换行符
        printf("好吧，你的数字是%d吗\n", ++猜测);  // 也即是程序至少打印了两条信息
    printf("我猜对了\n");
}

void 修正猜数字(void){  // 
    int 猜测 = 1;

    printf("请确定一个1到100内的整数，我将尝试猜测你的数字\n");
    printf("请输入y表示我猜对了，猜错了请输入n\n");
    printf("你的数字是%d吗\n", 猜测);

    int 回应;
    while ((回应 = getchar() )!= 'y'){  // 这里同时读取了换行符
        if (回应 == 'n')
            printf("好吧，你的数字是%d吗\n", ++猜测);
        else
            printf("请输入y或者n\n");
        while (getchar() != '\n')
            continue;  // 跳过换行符和一行中的其他输入
    }
    printf("我猜对了\n");
}

void 无问题IO的程序(void){
    int 字符;
    int 行数, 列数;
    printf("请输入一个字符和两个整数\n");
    while ((字符 = getchar()) != '\n'){
        if (scanf("%d %d", &行数,&列数) != 2)
            break;
        // scanf不会读取换行符，把换行符留在了缓冲区
        展示程序(字符, 行数, 列数);
        while (getchar() != '\n')
            continue;
        printf("请输入另一个字符和两个整数\n");
        printf("请再次输入回车退出\n");
    }
    printf("结束\n");
}

void 展示程序(int 字符, int 行, int 列){
    int 行数, 列数;

    for (行数 = 1; 行数 <= 行; 行数++){
        for (列数 = 1; 列数 <= 列; 列数++)
            putchar(字符);
        putchar('\n');  // 开始新行
    }
}
