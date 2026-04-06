#include "stack.h"
#include <stdio.h>

int main()
{
    StackPtr stack = stack_create(3);

    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);

    printf("Top: %d\n", stack_pop(stack));
    printf("Top: %d\n", stack_pop(stack));

    stack_destruct(&stack);
    return 0;
}
