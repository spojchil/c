#include "seqlist.h"
#include <stdlib.h>
#include <stdio.h>

void seq_list_init(SeqList *plist){
    plist->len = 0;
    plist->cap = SEQ_LIST_DEFAULT_CAP;
    plist->elements = malloc(plist->cap * sizeof(SeqListElem));
    if (plist->elements == NULL)
        fprintf(stderr, "内存分配失败\n");
}

bool seq_list_is_full(const SeqList* plist){
    if (plist->len < plist->cap)
        return false;
    return true;
}

bool seq_list_is_empty(const SeqList* plist){
    if (plist->len == 0)
        return true;
    return false;
}

bool seq_list_append(SeqList* plist, const SeqListElem* elem){
    if (seq_list_is_full(plist)){
        fprintf(stderr, "线性表已满");
        return false;
    }
    plist->elements[plist->len] = *elem;
    return true;
}

bool seq_list_insert(SeqList* plist, SeqListElem* elem, int index){
    if (seq_list_is_full(plist)){
        fprintf(stderr, "线性表已满");
        return false;
    }
    if (index > plist->len || index < 0){
        fprintf(stderr, "索引错误");
        return false;
    }
    for (int i = plist->len; i > index; i--)
        plist->elements[i] = plist->elements[i - 1];
    plist->elements[index] = *elem;
    return true;
}

void** seq_list_traverse(const SeqList* plist, void* (*pfun)(SeqListElem)){
    if (seq_list_is_empty(plist))
        return;
    void** ret = malloc(plist->len * sizeof(void*));
    for (int i = 0; i < plist->len; i++)
        ret[i] = pfun(plist->elements[i]);
    
    return ret;
}
