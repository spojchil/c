#include <stdio.h>
#include <stdbool.h>

long 验证整数(void);
bool 验证范围限制(long 起始, long 结束,
                long 下限, long 上限);

double 计算平方和(long a, long b);
int main(void){
    const long MIN = -10000000L;  // 范围下限
    const long MAX = +10000000L;  // 范围上限
    long 起始,结束;  // 用户指定的范围
    double 结果;
    
    printf("本程序计算某个整数范围内所有整数的平方和。\n"
           "范围下限不应小于 %+ld，\n"
           "且范围上限不应大于 %+ld。\n"
           "请输入范围界限（输入两个 0 即可退出程序）：\n"
           "下限：", MIN, MAX);
    
    起始 = 验证整数();
    printf("上限；");
    结束 = 验证整数();
    while (起始 != 0  || 结束 != 0){
        if (验证范围限制(起始, 结束, MIN, MAX))
            printf("请再次输入\n");
        else{
            结果 = 计算平方和(起始, 结束);
            printf("从%ld到%ld的平方和是 %g\n", 起始, 结束, 结果);
        }
        printf("请输入范围界限（输入两个 0 即可退出程序）：\n");
        printf("下限：");
        起始 = 验证整数();
        printf("上限；");
        结束 = 验证整数();
    }
    printf("结束.\n");

    return 0;
}

long 验证整数(void){
    long 输入;
    int ch;
    while (scanf("%ld", &输入) != 1){
        while ((ch = getchar()) != '\n')
            putchar(ch);  // 错误输入
        printf("不是一个整数。\n请再次输入整数");
        printf("整数是形如25, -188 或者3的数：");
    }
    
    return 输入;
}

double 计算平方和(long a, long b){
    double 总数 = 0;
    long i;

    for (i = a; i <= b; i++)
        总数 += (double) i * (double) i;

    return 总数;
}

bool 验证范围限制(long 起始, long 结束,
                long 下限, long 上限){
    bool 不好 = false;

    if (起始 > 结束){
        printf("%ld不应该比%ld大\n", 起始, 结束);
        不好 = true;
    }
    if (起始 < 下限 || 结束 < 下限){
        printf("值必须大于等于%ld\n", 下限);
        不好 = true;
    }
    if (起始 > 上限 || 结束 > 上限)
        printf("值必须小于等于%ld\n", 上限),不好 = true;

    return 不好;
}

