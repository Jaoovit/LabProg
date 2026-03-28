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
    if (!stack)
    {
        return NULL;
    }

    stack->data = malloc(sizeof(int) * capacity);
    if (!stack->data)
    {
        free(stack);
        return NULL;
    }

    stack->top = -1;
    stack->capacity = capacity;

    return stack;
}

void stack_push(StackPtr stack, int value)
{
    if (stack->top == stack->capacity - 1)
    {
        return;
    }
    stack->data[++stack->top] = value;
}

int stack_pop(StackPtr stack)
{
    if (stack->top == -1)
    {
        return -1;
    }

    return stack->data[stack->top--];
}

int stack_void(StackPtr stack)
{
    return stack->top == -1;
}

void stack_destruct(StackPtr *stack)
{
    if (!stack || !*stack)
    {
        return;
    }

    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}