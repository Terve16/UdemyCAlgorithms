
/****************************/
/*         INCLUDES         */
/****************************/

#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

/****************************/
/*        FUNCTIONS         */
/****************************/

stack_t *freeStack(stack_t *stack)
{
    if (stack == NULL)
        return NULL;

    if (stack->data != NULL)
    {
        free(stack->data);
        stack->data = NULL;
    }

    free(stack);
    stack = NULL;

    return NULL;
}

stack_t *createStack(uint32_t capacity)
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));

    if (stack == NULL || capacity <= 0)
        return NULL;


    stack->data = (value_type_t *)malloc(capacity * sizeof(value_type_t));

    if (stack->data == NULL)
    {
        stack = freeStack(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0u;

    return stack;
}

bool isFull(stack_t *stack)
{
    if (stack == NULL)
        return false;

    if (stack->size >= stack->capacity)
        return true;
    else
        return false;
}

bool isEmpty(stack_t *stack)
{
    if (stack == NULL)
        return false;

    if (stack->size <= 0u)
        return true;
    else
        return false;
}

void push(stack_t *stack, value_type_t value)
{
    if (stack == NULL || stack->data == NULL)
        return;

    if (!isFull(stack))
    {
        stack->data[stack->size] = value;
        stack->size++;
    }
}

value_type_t pop(stack_t *stack)
{
    if (stack == NULL || stack->data == NULL)
        return NO_VALUE;

    if (!isEmpty(stack))
    {
        stack->size--;
        value_type_t value = stack->data[stack->size];
        stack->data[stack->size] = NO_VALUE;
        return value;
    }
    else
        return NO_VALUE;
}

value_type_t top(stack_t *stack)
{
    if (stack == NULL || stack->data == NULL)
        return NO_VALUE;

    if (!isEmpty(stack))
    {
        return stack->data[stack->size - 1];
    }
    else
        return NO_VALUE;
}

void printStack(stack_t *stack)
{
    if (stack == NULL || stack->data == NULL)
        return;

    printf("\nStack contains %u elements with a capacity of %u.\n", stack->size, stack->capacity);

    for (uint32_t i = stack->size; i > 0; i--)
    {
        printf("Index: %d, Value: %f\n", (i - 1), stack->data[(i - 1)]);
    }

    printf("\n");
}
