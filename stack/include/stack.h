#ifndef STACK_H
#define STACK_H

typedef struct Stack *StackPtr;

StackPtr stack_create(int capacity);
void stack_push(StackPtr stack, int value);
int stack_pop(StackPtr stack);
int stack_void(StackPtr stack);
void stack_destruct(StackPtr *stack);

#endif