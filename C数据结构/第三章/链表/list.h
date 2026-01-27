#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

#define TSIZE 45

typedef int Item;

typedef struct node{
    Item item;
    struct node *next;
} Node;

typedef Node *List;

void InitializeList(List *plist);

bool ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

unsigned int ListItemCount(const List *plist);

bool AddItem(Item item, List *plist);

void Traverse(List *plist, void(*pfun)(Item item));

void EmptyTheList(List *plist);

#endif
