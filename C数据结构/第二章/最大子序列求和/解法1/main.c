#include <stdio.h>
#include "list_fill_random.h"
#include <stdbool.h>
#define LISTSIZE 6
int max_subsequence_sum1(const int list[], int size);
int max_subsequence_sum2(const int list[], int size);
int max_subsequence_sum3(const int list[], int size);

int main(void){
    int list[LISTSIZE] = {7, -10, 4, 5, -11, 6};
    
    // list_fill_random(list, LISTSIZE, -9, 9);
    list_print(list, LISTSIZE);

    printf("解法1最大值为%d\n",
         max_subsequence_sum1(list, LISTSIZE));
    
    printf("解法2最大值为%d\n",
         max_subsequence_sum2(list, LISTSIZE));

    printf("解法3最大值为%d\n",
         max_subsequence_sum3(list, LISTSIZE));

    for (int i = 0; i < 10000; i++){
        list_fill_random(list, LISTSIZE, -9, 9);
        if ((max_subsequence_sum2(list, LISTSIZE) !=
            max_subsequence_sum3(list, LISTSIZE) && max_subsequence_sum2(list, LISTSIZE) != 0)){
            printf("解法2最大值为%d\n",
                max_subsequence_sum2(list, LISTSIZE));

            printf("解法3最大值为%d\n",
                max_subsequence_sum3(list, LISTSIZE));

            list_print(list, LISTSIZE);
        }
    }

    return 0;
}

// 直观的一种解法时间复杂为O(N3)，教材上的示例，抄写教材代码
int max_subsequence_sum1(const int list[], int size){
    int currsum = 0;
    int maxsum = 0;

    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++){
            for (int k = i; k <= j; k++)
                currsum += list[k];
            
            maxsum = currsum > maxsum ? currsum : maxsum;
            currsum = 0;
        }
    
    return maxsum;
}

// 解法2，同样是教材的示例，时间复杂度为O(N2),抄写教材代码
int max_subsequence_sum2(const int list[], int size){
    int currsum = 0;
    int maxsum = 0;

    for (int i = 0; i < size; i++){
        for (int j = i; j < size; j++){
            currsum += list[j];
            
            maxsum = currsum > maxsum ? currsum : maxsum;
        }
        currsum = 0;
    }

    return maxsum;
}

// 解法3, 教材思路，代码自己写
// 思路，最大子序列出现位置只有三种情况，整个在左边，整个在右边，横跨左右
typedef struct ShuDui {
    int maxsum;
    int leftbianjie;
    int rightbianjie;
} ShuDui;

static void max_sum(const int list[], ShuDui* shudui, int left, int right){
    ShuDui leftsum;
    ShuDui rightsum;
    int center = (left + right) / 2;

    if (left == right){
        shudui->maxsum = list[left];
        shudui->leftbianjie = left;
        shudui->rightbianjie = right;
        return;
    }
    max_sum(list, &leftsum, left, center);
    max_sum(list, &rightsum, center + 1, right);
    
    int bsum = leftsum.maxsum + rightsum.maxsum;
    for (int i = leftsum.rightbianjie + 1; i < rightsum.leftbianjie; i++)
        bsum += list[i];
    bool leftbig = leftsum.maxsum > rightsum.maxsum;
    if (leftbig) {
        if (leftsum.maxsum > bsum) {
            *shudui = leftsum;
        } else {
            shudui->rightbianjie = rightsum.rightbianjie;
            shudui->leftbianjie = leftsum.leftbianjie;
            shudui->maxsum = bsum;
        }
    } else {
        if (rightsum.maxsum > bsum) {
            *shudui = rightsum;
        } else {
            shudui->rightbianjie = rightsum.rightbianjie;
            shudui->leftbianjie = leftsum.leftbianjie;
            shudui->maxsum = bsum;
        }
    }
}

int max_subsequence_sum3(const int list[], int size){
    ShuDui maxsum = {0, false, false};
    max_sum(list, &maxsum, 0, size - 1);

    return maxsum.maxsum;
}


// 代码被豆包批评老惨了

// 代码有问题，忽略了一种情况


// 有一个动态规划的算法从时间复杂度是O(N)