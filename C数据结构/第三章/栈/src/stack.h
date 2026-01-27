#ifndef STACK_H_
#define STACK_H_

#include "singlylinkedlist.h"
#include <stdbool.h>

typedef SLL Stack;
typedef SLLElem StackElem;

#endif // STACK_H_

bool stack_is_empty(const Stack* pstack);
bool stack_push(Stack* pstack, const StackElem elem);
bool stack_pop(Stack* pstack, StackElem* pelem);
bool stack_top(const Stack* pstack, StackElem* pelem);
Stack* stack_create(void);
void stack_destroy(Stack* pstack);
