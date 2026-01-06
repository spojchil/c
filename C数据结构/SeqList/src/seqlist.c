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
        fprintf(stderr, "线性表已满\n");
        return false;
    }
    plist->elements[plist->len] = *elem;
    plist->len++;

    return true;
}

bool seq_list_insert(SeqList* plist, const SeqListElem* elem, const int index){
    if (seq_list_is_full(plist)){
        fprintf(stderr, "线性表已满\n");
        return false;
    }
    if (index > plist->len || index < 0){
        fprintf(stderr, "索引错误\n");
        return false;
    }
    for (int i = plist->len; i > index; i--)
        plist->elements[i] = plist->elements[i - 1];
    plist->elements[index] = *elem;
    plist->len++;

    return true;
}

void seq_list_traverse(const SeqList* plist, void (*pfun)(int index, SeqListElem)){
    for (int i = 0; i < plist->len; i++)
        pfun(i, plist->elements[i]);
}


bool seq_list_set(SeqList* plist, const SeqListElem* elem, const int index){
    if (index >= plist->len || index < 0){
        fprintf(stderr, "索引错误\n");
        return false;
    }
    plist->elements[index] = *elem;
    return true;
}

int seq_list_find(const SeqList* plist,const SeqListElem* elem,
     int (*elem_cmp)(const SeqListElem* elem1,
        const SeqListElem* elem2)){
    for (int i = 0; i < plist->len; i++)
        if (elem_cmp(elem, &(plist->elements[i])) == 0)
            return i;
    
    return -1;
}

bool seq_list_get(const SeqList* plist, const int index,
     SeqListElem* value){
    if (index >= plist->len || index < 0){
        fprintf(stderr, "索引错误\n");
        return false;
    }
    
    *value = plist->elements[index];
    return true;
}

bool seq_list_remove(SeqList* plist, const int index){
    if (index >= plist->len || index < 0){
        fprintf(stderr, "索引错误\n");
        return false;
    }
    for (int i = index; i < plist->len - 1; i++)
        plist->elements[i] = plist->elements[i+1];

    plist->len--;
    return true;
}

int seq_list_lenght(const SeqList* plist){
    return plist->len;
}

void seq_list_destroy(SeqList* plist){
    free(plist->elements);
    plist->elements = NULL;
}

void seq_list_clear(SeqList* plist){
    plist->len = 0;
}