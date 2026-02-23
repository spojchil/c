#include <stdio.h>
#include <string.h>  // 用于 strlen 函数

void pinyin(int n);

int main(void) {
    char num[101];  // n 最多 100 位，加 1 用于空字符
    scanf("%s", num);

    int sum = 0;
    // 计算各位数字之和
    for (int i = 0; i < strlen(num); i++) {
        sum += num[i] - '0';  // 字符数字转整数
    }

    // 处理和为 0 的情况
    if (sum == 0) {
        printf("ling");
    } else {
        int digits[10];  // 存储和的各位数字，最大 900（最多 3 位）
        int count = 0;
        int temp = sum;
        // 提取各位数字（从低位到高位）
        while (temp > 0) {
            digits[count] = temp % 10;
            count++;
            temp /= 10;
        }
        // 从高位到低位输出拼音
        for (int i = count - 1; i >= 0; i--) {
            pinyin(digits[i]);
            if (i != 0) {
                printf(" ");  // 数字间空格，最后一个不输出
            }
        }
    }
    printf("\n");  // 换行
    return 0;
}

void pinyin(int n) {
    switch (n) {
        case 0: printf("ling"); break;
        case 1: printf("yi"); break;
        case 2: printf("er"); break;
        case 3: printf("san"); break;
        case 4: printf("si"); break;
        case 5: printf("wu"); break;
        case 6: printf("liu"); break;
        case 7: printf("qi"); break;
        case 8: printf("ba"); break;
        case 9: printf("jiu"); break;
        default: printf(" ");  // 不会触发，仅保留
    }
}