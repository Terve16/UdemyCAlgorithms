#ifndef STACK_H
#define STACK_H

/****************************/
/*         INCLUDES         */
/****************************/

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

/****************************/
/*     DEFINES AND TYPES    */
/****************************/

typedef float value_type_t;

#define NO_VALUE (value_type_t) INFINITY

typedef struct stack
{
    uint32_t size;
    uint32_t capacity;
    value_type_t *data;
} stack_t;

/****************************/
/*        FUNCTIONS         */
/****************************/

stack_t *freeStack(stack_t *stack);

stack_t *createStack(uint32_t capacity);

bool isFull(stack_t *stack);

bool isEmpty(stack_t *stack);

void push(stack_t *stack, value_type_t value);

value_type_t pop(stack_t *stack);

value_type_t top(stack_t *stack);

void printStack(stack_t *stack);

#endif // STACK_H
