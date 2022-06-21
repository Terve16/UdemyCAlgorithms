#include <assert.h>
#include <stdio.h>

#include "Queue.h"

int main(void)
{
    uint32_t capacity = 10u;
    queue_t *queue = createQueue(capacity);

    push(queue, 0.0f);
    push(queue, 1.0f);
    push(queue, 2.0f);
    push(queue, 3.0f);

    printQueue(queue);

    assert(0.0f == queue->data[0]);
    assert(1.0f == queue->data[1]);
    assert(2.0f == queue->data[2]);
    assert(3.0f == queue->data[3]);

    assert(10u == queue->capacity);
    assert(4u == queue->size);

    value_type_t value1 = pop(queue);
    value_type_t value2 = pop(queue);

    printQueue(queue);

    value_type_t value3 = front(queue);
    value_type_t value4 = pop(queue);
    push(queue, 4.0f);

    printQueue(queue);

    value_type_t value5 = back(queue);
    value_type_t value6 = pop(queue);
    value_type_t value7 = pop(queue);

    printQueue(queue);

    queue = freeQueue(queue);

    return 0;
}
