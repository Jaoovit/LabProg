#include "stack.h"
#include <stdlib.h>

struct Stack
{
    int *data;
    int top;
    int capacity;
};

StackPtr stack_create(int capacity)
{
    StackPtr stack = malloc(sizeof(struct Stack));

    stack->data = malloc(sizeof(int) * capacity);
    stack->capacity = capacity;
    stack->top = -1;

    return stack;
}

void stack_push(StackPtr stack, int value)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("%d", "Stack full");
    }
    stack->top = stack->top++;
    stack->data[stack->top] = value;
}

int stack_pop(StackPtr stack)
{
    if (stack->top == -1)
    {
        printf("%d", "Stack void");
        return -1;
    }
    int value = stack->data[stack->top];
    stack->top = stack->top--;
    return value;
}

int stack_void(StackPtr stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    else
    {
        stack->top = -1;
        return 0;
    }
}

void stack_destruct(StackPtr *stack)
{
    free((*stack)->data);
    free(*stack);
    stack = NULL;
}