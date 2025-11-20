#include <stdio.h>
char 进行选择(void);
char 获得首个(void);
int 获取整数(void);
void 计数(void);
int main(void){
    int 选择;
    // void 计数(void);

    while ((选择 = 进行选择()) != 'q'){
        switch (选择){
            case 'a': printf("低买高卖\n");
                break;
            case 'b': putchar('\a');
                break;
            case 'c': 计数();
                break;
        }
    }
    printf("拜\n");

    return 0;
}

void 计数(void){
    int n, i;

    printf("计算距离，请输入整数\n");
    n = 获取整数();
    for (i = 1; i <= n; i++)
        printf("%d\n", i);
    while (getchar() != '\n')
        continue;
}

char 进行选择(void){
    int ch;
    
    printf("请输入一个字母进行选择:\n");
    printf("a.建议          b.响铃\n");
    printf("c.计数          q.退出\n");
    ch = 获得首个();
    while ((ch < 'a' || ch > 'c') && ch != 'q'){
        printf("请输入一个回复a,b,c或者q");
        ch = 获得首个();
    }

    return ch;
}

char 获得首个(void){
    int ch;

    ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}

int 获取整数(void){
    int 输入;
    char ch;

    while (scanf("%d", &输入) != 1){
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf("不是一个整数.\n请输入一个整数例如25,-178或者3\n");
    }

    return 输入;
}