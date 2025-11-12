/* 循环辅助:continue 和break 
3中循环都可以使用continue
*/
#include <stdio.h>

void 跳过(void);
void 跳出(void);
void 选择(void);
int main(void){

    // 跳过();
    // 跳出();
    选择();
    return 0;
}
void 跳过(void){
    const float 最小值 = 0.0f;
    const float 最大值 = 100.0f;

    float 得分;
    float 总分 = 0.0f;
    int n = 0;
    float 最小值1 = 最大值;

    float 最大值1 = 最小值;
    printf("请输入第一个得分(输入q退出)");
    while (scanf("%f",&得分) == 1){
        if (得分 < 最小值 || 得分 > 最大值){
            printf("%0.1f 是一个无效的值，请重试", 得分);
            continue;  // 跳转至while循环的测试条件
        }
        printf("Accepting %0.1f:\n", 得分);
        最小值1 = (得分 < 最小值1) ? 得分 : 最小值1;
        最大值1 = (得分 > 最大值1) ? 得分 : 最大值1;
        总分 += 得分;
        n++;
        printf("请输入下一个分数(输入q退出)");
    }
    if (n > 0){
        printf("一共有%d个得分,平均值为%0.1f\n", n, 总分/n);
        printf("最低分为%0.1f,最高分是%0.1f\n", 最小值1, 最大值1);
    }
    else
        printf("没有输入一个得分");
}
// break语句会终止包含它的循环
void 跳出(void){
    float 长度,宽度;

    printf("请输入矩形的长");
    while (scanf("%f", &长度) == 1){
        printf("长度=%0.2f:\n", 长度);
        printf("请输入宽度:");
        if (scanf("%f", &宽度) != 1)
            break;
        printf("宽度 = %0.2:\n", 宽度);
        printf("面积 = %0.2f:\n", 长度*宽度);
        printf("请输入矩形长度\n");
    }
    printf("结束\n");
}

#include <ctype.h>
void 选择(void){
    char ch;
    printf("Give me a letter of the alphbet, and I will give");
    printf("an animal name\nbeginning with that letter.\n");
    printf("Please type in a letter; type # to end my act.");
    while ((ch = getchar()) != '#'){
        if ('\n' == ch)
            continue;
        if (islower(ch))
            switch (ch){  // 整数表达式 switch是直接定位 
                case 'a':  // 标签是常量或者常量表达式
                    printf("argali, a wild sheep of Asia\n");
                    break;
                case 'b':
                    printf("babirusa, a wild pig of Malay");
                    break;
                case 'c':
                    printf("coati, racoomlike mammal\n");
                    break;
                default:  // 如果没有就执行下一个语句
                    printf("That's a stumper!\n");

            }
            else
                printf("I recongnize only lowercase letters.\n");
            while (getchar() != '\n')
                continue;
            printf("Please type another letter or a #.\n");
    }
    printf("Bye!\n");
    
}