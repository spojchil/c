#include "singlylinkedlist.h"
#include <stdio.h>

void sll_print(SLLElem elem);
int elem_cmp(SLLElem elem1, SLLElem elem2);

int main(void){
    SLL* list = sll_create();

    //
    sll_append(list, 1);
    // 预期输出  1->
    sll_traverse(list, sll_print);
    putchar('\n');

    sll_append(list, 3);
    // 预期输出  1->3->
    sll_traverse(list, sll_print);
    putchar('\n');
    
    sll_insert(list, 2, 1);
    // 预期输出  1->2->3->
    sll_traverse(list, sll_print);
    putchar('\n');

    sll_insert(list, 4, 2);
    // 预期输出  1->2->4->3->
    sll_traverse(list, sll_print);
    putchar('\n');

    printf("返回值预期为2,实际值为%d\n", sll_find(list, 4, elem_cmp));

    

    return 0;
}

void sll_print(SLLElem elem){
    printf("%d->", (int)elem);
}

int elem_cmp(SLLElem elem1, SLLElem elem2){
    return (int)elem1 - elem2;
}
