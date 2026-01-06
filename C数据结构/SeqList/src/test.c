#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>

void list_print(int index, SeqListElem elem);

int list_cmp(const SeqListElem* elem1, const SeqListElem* elem2);

int main(void){
    SeqList list1;
    seq_list_init(&list1);

    SeqListElem elem1 = 1;
    SeqListElem elem2 = 2;
    seq_list_append(&list1, &elem1);
    seq_list_insert(&list1, &elem2, 1);

    elem2 = 3;
    seq_list_insert(&list1, &elem2, 1);
    elem2 = 30;
    seq_list_insert(&list1, &elem2, 3);

    seq_list_traverse(&list1, list_print);

    printf("设置测试\n");
    seq_list_set(&list1, &elem1, 3);
    seq_list_traverse(&list1, list_print);

    printf("设置测试\n");
    elem1 = 44;
    seq_list_set(&list1, &elem1, 4);
    seq_list_traverse(&list1, list_print);

    puts("查找测试");
    printf("%d的索引是%d\n", elem1, seq_list_find(&list1, &elem1, list_cmp));

    puts("读取测试");
    SeqListElem elem3;
    if (seq_list_get(&list1, 5, &elem3))
        printf("索引1的值是%d\n", elem3);

    puts("删除测试");
    seq_list_remove(&list1, 0);
    seq_list_traverse(&list1, list_print);

    return 0;
}

void list_print(int index, SeqListElem elem){
    printf("第%d个的值为%d\n", index + 1, elem);
}

int list_cmp(const SeqListElem* elem1, const SeqListElem* elem2){
    return *elem1 - *elem2;
}
