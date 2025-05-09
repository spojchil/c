// 2025 5 2
/*
​​1. C 程序的核心结构（自上而下）​​
​​预处理器指令​​
图中以 #include 为例，表示程序在编译前会先处理这些指令（如头文件引入、宏定义等）。
​​作用​​：为编译器提供必要的信息（如 #include <stdio.h> 导入输入输出函数）。
​​main() 函数​​
图中强调 int main(void) 是​​程序入口​​，执行时第一个被调用的函数。
​​关键点​​：
每个 C 程序必须有且仅有一个 main() 函数。
void 表示无参数，返回值 int 通常用于返回程序状态（如 return 0; 表示成功）。
​​其他自定义函数​​
图中示例 function a() 和 function b()，代表用户定义的子函数。
​​作用​​：模块化代码，提高复用性（通过函数调用组织逻辑）。
*/

/*
变量名，一般不超过63个字符，使用有意义的的名称
可以使用中文，不可以以数字开头
"eaw_e照片wd2"是10个字符
int num时预留了空间
num = 1进行赋值
*/

/*
printf()圆括号表示printf()是一个函数名
printf("实际参数")运行到这一行时控制权交给printf()
函数执行结束后，控制权返还给main()
\n的意思是换行
\t代表Tab
\b代表Backspace键，退格键
*/

/*
C11 关键字 不可以作为标识符
auto        _Alignas     _Atomic      _Bool        
break       case         char         const        
continue    default      do           double       
else        enum         extern       float        
for         goto         if           _Imaginary   
inline      int          long         register     
return      restrict     short        signed       
sizeof      static       struct       switch       
typedef     union        unsigned     void         
volatile    while        _Alignof     _Complex     
_Generic    _Noreturn    _Static_assert _Thread_local
*/