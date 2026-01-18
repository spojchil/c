#include <stdio.h>
#include "list_fill_random.h"
#define SIZE 10

int main() {
    int list1[SIZE];

    list_fill_random(list1, SIZE, -3, 3);
    list_print(list1, SIZE);

    return 0;
}