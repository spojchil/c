#include "../src/singlylinkedlist.h"
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

    // 尾部插入测试
    sll_insert(list, 4, 2);
    // 预期输出  1->2->4->3->
    sll_traverse(list, sll_print);
    putchar('\n');

    printf("返回值预期为3,实际值为%d\n", sll_find(list, 3, elem_cmp));

    // get首节点测试
    SLLElem tempelem;
    if (!sll_get(list, 0, &tempelem))
        puts("首节点测试失败");
    printf("首节点回值预期为1,实际返回%d\n", tempelem);

    // get中间节点测试
    if (!sll_get(list, 2, &tempelem))
        puts("中间节点测试失败");
    printf("中间节点回值预期为4,实际返回%d\n", tempelem);

    // get尾节点测试
    if (!sll_get(list, 3, &tempelem))
        puts("尾节点测试失败");
    printf("尾节点回值预期为3,实际返回%d\n", tempelem);

    // get越界节点测试
    if (sll_get(list, 4, &tempelem))
        puts("越界节点测试失败");

    // 删除测试
    sll_remove(list, 3);
    // 预期1->2->4->
    sll_traverse(list, sll_print);
    putchar('\n');
    
    

    return 0;
}

void sll_print(SLLElem elem){
    printf("%d->", (int)elem);
}

int elem_cmp(SLLElem elem1, SLLElem elem2){
    return (int)elem1 - elem2;
}
