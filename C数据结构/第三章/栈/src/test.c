#include <stdio.h>
#include "stack.h"

int main(void){
    Stack* stack = stack_create();
    for(int i = 0; i < 5; i++){
        stack_push(stack, i);
    }
    int tmp;
    stack_top(stack, &tmp);
    printf("栈顶元素: %d\n", tmp);
    printf("出栈元素: \n");
    while(!stack_is_empty(stack)){
        int value;
        stack_pop(stack, &value);
        printf("%d ", value);
    }
    printf("\n");
    stack_destroy(stack);
    return 0;
}