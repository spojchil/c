// 4.3 
/*
#define TAXRATE 0.015  // 宏常量
编译程序时，程序中的所有TAXTATE都会被替换，运行程序时所有的替换均以完成
大写表示符号常量是C语言的传统
不常用的命名约定
在名称前带c_或k_来表示常量如c_level或k_line
*/
#include <stdio.h>
#define PI 3.14159  // 宏常量 不占用空间等等在编译时确定
int main(void)
{
    float area, circum, radius;

    printf("What is the radius if your pizza?\n");
    scanf("%f", &radius);
    area = PI * radius * radius;
    circum = 2.0 * PI * radius;  // 此处的2.0 就是明示常量
    printf("Your basic pizza parameters are as follows:\n");
    printf("circumference = %1.2f, area = %1.2f\n", circum, area);
    // %1.2f表示四舍五入为两位小数输出

    return 0;
}
/*
#define BEEF '\a'  // 替换字符
#define TEE 'T'
#define ESC '\033'
#define OOPS "Now you have done it!"  // 替换字符串

#define TOES = 20  // 错误的格式
会把TOES替换为= 20

const 限定符
const in MONTHS = 12;  // MONTHS 在程序中不可更改，只能只读
*/

/*
1. ​​宏常量（Macro Constants）​​
​​定义方式​​：通过预处理器 #define 定义
#define PI 3.14159
​​特点​​：
​​文本替换​​：预编译阶段直接替换代码中的宏名（如 PI 替换为 3.14159），​​无类型检查​​。
​​无作用域​​：从定义处到文件末尾有效（或遇到 #undef）。
​​可能副作用​​：若宏参数未加括号，可能导致表达式求值错误（如 #define SQUARE(x) x*x 调用 SQUARE(1+2) 会展开为 1+2 * 1+2）。
​​用途​​：简单常量、条件编译、代码片段复用。
2. ​​符号常量（Symbolic Constants）​​
​​广义概念​​：泛指所有通过符号（名称）表示的常量，包括宏常量和 const 常量。
​​狭义用法​​：有时特指枚举常量（enum）：
enum { MAX_SIZE = 100 };
​​特点​​：
有类型（默认为 int），编译时确定值。
作用域遵循普通变量规则（如函数内定义的 enum 仅函数内可见）。
3. ​​明示常量（Manifest Constants）​​
​​定义​​：直接出现在代码中的字面量（如 42, 'A', "hello"）。
​​特点​​：
无符号名称，可读性差。
类型由字面量形式决定（如 3 是 int，3.0 是 double）。
​​改进​​：通常建议用宏或 const 替代明示常量，提高可维护性。
4. ​​const 定义的“常量”​​
​​定义方式​​：使用 const 关键字：
const double PI = 3.14159;
*/