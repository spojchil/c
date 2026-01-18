#include <stdio.h>
#include <stdlib.h>
#include <time.h>    // 用于获取时间作为种子

void list_fill_random(int* list, int size);

int main() {
    // 用当前时间作为随机数种子
    srand(time(NULL));
    

    for(int i = 0; i < 5; i++) {
        printf("%d ", rand());
    }
    return 0;
}

void list_fill_random(int* list, int size){
    srand(time(NULL));

    for (int i = 0; i < size; i++)
        list[i] = rand();
}

void list_print(const int* list, int size){
    print()
}