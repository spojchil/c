#include "singlylinkedlist.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

SLL* sll_create(void){
    SLL* ret = malloc(sizeof(SLL));
    ret->head = NULL;
    ret->len = 0;

    return ret;
}

bool sll_is_empty(const SLL* plist){
    return plist->len == 0 ? true : false;
}

bool sll_append(SLL* plist, const SLLElem elem){
    SLLNode* new_node = malloc(sizeof(SLLNode));
    if (new_node == NULL){
        fprintf(stderr, "内存分配失败\n");
        return false;
    }
    new_node->elements = elem;
    new_node->next = NULL;
    if (sll_is_empty(plist))
        plist->head == new_node;
    else{
        SLLNode* current = plist->head;
        while(current->next != NULL)
            current = current->next;
    }
    plist->len++;
    return true;
}

bool sll_insert(SLL* plist, const SLLElem elem,
    const int index){
    SLLNode* new_node = malloc(sizeof(SLLNode));
    if (new_node == NULL){
        fprintf(stderr, "内存分配失败\n");
        return false;
    }
    new_node->elements = elem;
    new_node->next = NULL;
    if (index >= plist->len){
        fprintf(stderr, "索引越界\n");
        return false;
    }
    if (sll_is_empty(plist))
        plist->head == new_node;
    else {
        SLLNode* current = plist->head;
        for (int i = 0; i < index - 1; i++)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
    plist->len++;
    return true;
}

