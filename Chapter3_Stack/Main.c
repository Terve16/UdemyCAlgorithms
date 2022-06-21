#include <assert.h>
#include <stdio.h>

#include "Stack.h"

int main(void)
{
    uint32_t capacity = 10u;
    stack_t *stack = createStack(capacity);

    push(stack, 0.0f);
    push(stack, 1.0f);
    push(stack, 2.0f);
    push(stack, 3.0f);

    printStack(stack);

    assert(0.0f == stack->data[0]);
    assert(1.0f == stack->data[1]);
    assert(2.0f == stack->data[2]);
    assert(3.0f == stack->data[3]);

    assert(10u == stack->capacity);
    assert(4u == stack->size);

    value_type_t value1 = pop(stack);
    value_type_t value2 = pop(stack);

    printStack(stack);

    value_type_t value3 = top(stack);
    value_type_t value4 = pop(stack);

    printStack(stack);

    value_type_t value5 = top(stack);
    value_type_t value6 = pop(stack);

    printStack(stack);

    stack = freeStack(stack);

    return 0;
}
