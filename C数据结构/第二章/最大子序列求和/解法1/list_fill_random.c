#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list_fill_random.h"

void list_fill_random(int list[], int size,
     int min, int max){
    srand(time(NULL));

    for (int i = 0; i < size; i++)
        list[i] = rand()%(max - min) + min;
}

void list_print(const int list[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", list[i]);
    putchar('\n');
}