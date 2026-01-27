#include "stack.h"
#include "singlylinkedlist.h"
#include <stdbool.h>

Stack* stack_create(void){
    return sll_create();
}

bool stack_is_empty(const Stack* pstack){
    return sll_is_empty(pstack);
}

bool stack_push(Stack* pstack, const StackElem elem){
    return sll_insert(pstack, elem, 0);
}

bool stack_pop(Stack* pstack, StackElem* pelem){
    if (!sll_get(pstack, 0, pelem)) {
        return false;  // 获取失败
    }
    return sll_remove(pstack, 0);  // 返回删除结果
}

bool stack_top(const Stack* pstack, StackElem* pelem){
    return sll_get(pstack, 0, pelem);
}

void stack_destroy(Stack* pstack){
    sll_destroy(pstack);
}