// for循环
#include <stdio.h>
void for循环(void);
void 逗号运算符(void);
int main(void)
{
    // for循环();
    逗号运算符();

    return 0;
}

void for循环(void)
{
    const int 数字 = 22;
    int 数;

    for (数 = 1; 数 <= 数字; 数++)  //最后一个可以是空for (...;...;)
        printf("值\n");
}
/*
其他赋值运算符+=,-+,*=,/=,%=
scores += 20 与scores = scores + 20相同
*/

void 逗号运算符(void)
{
    const int FIRST_OZ = 46;
    const int NEXT_OZ = 20;
    int ounces, cost;

    printf(" ounces cost\n");
    // 逗号运算符从左往右
    for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
        printf("%5d  ￥%4.2f\n", ounces, cost / 100.0);
}
/*x = (y = 3, (z = ++y + 2) + 5)

1. ​​逗号表达式的规则​​
逗号表达式按从左到右顺序执行，最终结果为最右侧子表达式的值。
结构：(表达式1, 表达式2, ..., 表达式N) → 返回表达式N的值。

步骤分解：​​

​​y = 3​​
将变量 y 赋值为 3。
此时 y 的值为 3。
​​++y​​
++y 是​​前缀自增​​，先执行 y = y + 1，再返回 y 的新值。
y 从 3 变为 4，表达式返回 4。
​​z = ++y + 2​​
计算 ++y + 2：4 (++y的结果) + 2 = 6。
将 6 赋值给 z，此时 z = 6。
子表达式 (z = ++y + 2) 的值为 6（赋值表达式的值即被赋的值）。
​​(z = ++y + 2) + 5​​
上一步结果为 6，因此 6 + 5 = 11。
这是逗号表达式的最右侧子表达式，因此整个逗号表达式的值为 11。
​​最终赋值 x = 11​​
将逗号表达式的结果 11 赋值给 x。
注意x=3, 4
仅仅是将x赋值为3
，表达式中的,有一个序列点
*/
