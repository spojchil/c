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
        plist->head = new_node;
    else{
        SLLNode* current = plist->head;
        while(current->next != NULL)
            current = current->next;
        current->next = new_node;
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
        plist->head = new_node;
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

int sll_find(const SLL* plist, const SLLElem elem,
    int (*elem_cmp)(const SLLElem, const SLLElem)){
    int i = 0;
    SLLNode* current = plist->head;
    while (current != NULL){
        if (elem_cmp(current->elements, elem) == 0)
            return i;
        i++;
        current = current->next;
    }
    return -1;
}

bool sll_get(const SLL* plist, const int index,
    SLLElem* pretelem){
    if (index >= plist->len){
        fprintf(stderr, "索引越界\n");
        return false;
    }
    SLLNode* current = plist->head;
    for (int i = 0; i < index; i++)
        current = current->next;
    *pretelem = current->elements;
    return true;
}

bool sll_remove(SLL* plist, const int index){
    if (index >= plist->len){
        fprintf(stderr, "索引越界\n");
        return false;
    }
    if (plist->len == 1){
        free(plist->head);
        plist->head = NULL;
        plist->len--;
        return true;
    }
    SLLNode* current = plist->head;
    for (int i = 0; i < index - 1; i++)
        current = current->next;
    if (current->next->next == NULL){
        free(current->next);
        current->next = NULL;
        plist->len--;
        return false;
    }
    SLLNode* temp;
    temp = current->next;
    current->next = temp->next;
    free(temp);
    plist->len--;
    return false;
}

void sll_traverse(const SLL* plist, void (*pfun)(SLLElem)){
    if (sll_is_empty(plist)){
        fprintf(stderr, "链表为空\n");
        return;
    }
    SLLNode* current = plist->head;
    while (current != NULL){
        pfun(current->elements);
        current = current->next;
    }
}

bool sll_reverse(SLL* plist){
    if (sll_is_empty(plist)){
        fprintf(stderr, "链表为空");
        return false;
    }

    SLLNode* prev = NULL;
    SLLNode* next = NULL;
    SLLNode* curr = plist->head;

    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    plist->head = prev;

    return true;
}

bool sll_remove_by_value(SLL* plist,
    const SLLElem elem,
    int (*elem_cmp)(const SLLElem, const SLLElem)){
    int index;
    if ((index = sll_find(plist, elem, elem_cmp)) == -1){
        fprintf(stderr, "值不存在\n");
        return false;
    }
    
    return sll_remove(plist, index);
}

void sll_clear(SLL* plist){
    SLLNode* current;
    current = plist->head;
    while(current != NULL){
        plist->head = current->next;
        free(current);
        current = plist->head;
    }
    plist->len = 0;
}

void sll_destroy(SLL* plist){
    sll_clear(plist);
    free(plist);
    plist = NULL;
}