/*
ch != 'c'  // 比较的是机器字符码如ASCII
*/
#include <math.h>
#include <stdio.h>
void 浮点数比较(void);
int main(void)
{
    浮点数比较();

    return 0;
}

void 浮点数比较(void)
{
    const double ANSWER = 3.14159;
    double response;

    printf("pi的值是多少？\n");
    scanf("%lf", &response);
    while (fabs(response - ANSWER) > 0.0001)
    {
        printf("再试一次\n");
        scanf("%lf", &response);
    }
    printf("对了");
}
/*
什么是真
int true_val, false_val;
true_val = (10 > 2);  // 关系为真的值 为1
false_val = (10 == 2);  //关系为假的值 为0
一般而言所以非0值都为真
m = 5  // 可以
5 = n  //语法错误
5 == n  // 没问题

关系运算符比算术运算符低，比赋值运算符高。
高优先级组 < <= > >=
低优先级组 == !=
顺序也是从左往右
除了赋值运算都是从左往右
*/
