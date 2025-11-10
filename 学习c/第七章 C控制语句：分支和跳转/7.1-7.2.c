#include <stdio.h>
void if1(void);
void 字符函数(void);
void 字符函数1(void);
void 多重选择(void);

int main(void)
{
    // if1();
    // 字符函数1();
    多重选择();

    return 0;
}

void if1(void)
{
    const int 零度 = 0;
    float 温度;
    int 冷天 = 0;
    int 总天数 = 0;

    printf("输入一些天中的最低温度\n");
    printf("只输入实数,输入q退出\n");
    while (scanf("%f", &温度) == 1)
    {
        总天数++;
        if (温度 < 零度)
            冷天++;
    }
    if (总天数 != 0)
        printf("一共有%d天，%.lf%% 的冷天。\n",
            总天数, 100.0 * (float) 冷天 / 总天数);  // float的优先级比运算符高
    else
        printf("没有输入数据");        
}
/*
函数getchar()  不带参数从输入队列中返回下一个字符
ch = getchar()把下一个字符给ch，等价于
scanf("%c", &ch);
putchar(ch)打印ch，等价于
printf("%c", ch);
因为只处理字符所以速度更快
*/

#define 空格 ' '
void 字符函数(void)
{
    char ch;

    ch = getchar();  // 读取一个字符
    while (ch != '\n')  // 一行结束
    {
        if (ch == 空格)
            putchar(ch);
        else
            putchar(ch+1);
        ch = getchar();
    }
    putchar(ch);  // 注意输入输出缓冲区
}
/*
功能示例：
如果输入"abc d"，程序会输出：
"bcd e"
解释：
a→b, b→c, c→d, 空格保持, d→e
*/
#include <ctype.h>
void 字符函数1(void)
{
    char ch;

    while ((ch = getchar()) != '\n')  // 一行结束
    {
        if (isalpha(ch))
            putchar(ch + 1);
        else
            putchar(ch);
    }
    putchar(ch);  // 注意输入输出缓冲区
}

// #define A B C... // 除了注释
// 会把所有的A替换为A空格后面的所有内容直到行尾，
// 替换宏名后的所有内容直到行尾​​。

#define 费用1 0.13230
#define 费用2 0.15040
#define 费用3 0.30025
#define 费用4 0.34025
#define 分1 360.0
#define 分2 468.0
#define 分3 720.0
#define 阶段1 (费用1 * 分1)  // 会递归展开
#define 阶段2 (阶段1 + (费用2 * (分2 - 分1)))
#define 阶段3 (阶段1 + 阶段2 + (费用3 - (分3 - 分2)))
void 多重选择(void)
{
    double kwh;
    double bill;
-
    printf("请输入使用的千瓦时\n");
    scanf("%lf", &kwh);
    if (kwh <= 分1)
        bill = 费用1 * kwh;
    else if (kwh <= 分2)  // 通用写法，便于理解
        bill = 阶段1 + (费用2 * (kwh - 分1));  // 预处理时不计算的，但是编译会计算
        else  // 这是等价的写法
            if (kwh <= 分3)
                bill = 阶段2 + (费用3 * (kwh - 分2));
    else 
        bill = 阶段3 + (费用4 * (kwh - 分3));  // 编译器计算后，就直接变为一个数了，不是表达式
    printf("你使用了%.1f千瓦时，这些电费是%.2f。\n", kwh, bill);
}
/*
if (number > 6)
    if (number < 12)
    printf("大于6且小于12");
else
    printf("抱歉，你输了")

else 与第二个if 匹配
没有花括号else与离他最近的if匹配

*/

