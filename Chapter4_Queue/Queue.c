
/****************************/
/*         INCLUDES         */
/****************************/

#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

/****************************/
/*        FUNCTIONS         */
/****************************/

queue_t *freeQueue(queue_t *queue)
{
    if (queue == NULL)
        return NULL;

    if (queue->data != NULL)
    {
        free(queue->data);
        queue->data = NULL;
    }

    free(queue);
    queue = NULL;

    return NULL;
}

queue_t *createQueue(uint32_t capacity)
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

    if (queue == NULL || capacity <= 0)
        return NULL;


    queue->data = (value_type_t *)malloc(capacity * sizeof(value_type_t));

    if (queue->data == NULL)
    {
        queue = freeQueue(queue);
        return NULL;
    }

    queue->capacity = capacity;
    queue->size = 0u;
    queue->front_idx = 0u;
    queue->back_idx = queue->capacity - 1u;

    return queue;
}

bool isFull(queue_t *queue)
{
    if (queue == NULL)
        return false;

    if (queue->size >= queue->capacity)
        return true;
    else
        return false;
}

bool isEmpty(queue_t *queue)
{
    if (queue == NULL)
        return false;

    if (queue->size <= 0u)
        return true;
    else
        return false;
}

void push(queue_t *queue, value_type_t value)
{
    if (queue == NULL || queue->data == NULL)
        return;

    if (!isFull(queue))
    {
        /*
        if (isEmpty(queue))
        {
            queue->front_idx = 0;
            queue->back_idx = 0;
        }
        else if (queue->back_idx < (queue->capacity - 1))
        {
            queue->back_idx++;
        }
        else
        {
            queue->back_idx = 0;
        }
        */
        /*
        if (isEmpty(queue))
        {
            queue->front_idx = 0;
            queue->back_idx = 0;
        }
        else
        { */
        queue->back_idx = ((queue->back_idx + 1u) % queue->capacity);
        //}

        queue->size++;
        queue->data[queue->back_idx] = value;
    }
}

value_type_t pop(queue_t *queue)
{
    if (queue == NULL || queue->data == NULL)
        return NO_VALUE;

    if (!isEmpty(queue))
    {
        value_type_t value = queue->data[queue->front_idx];
        queue->data[queue->front_idx] = NO_VALUE;

        queue->size--;
        /*
        if (isEmpty(queue))
        {
            queue->front_idx = 0;
            queue->back_idx = 0;
        }
        else if (queue->front_idx < (queue->capacity - 1))
        {
            queue->front_idx++;
        }
        else
        {
            queue->front_idx = 0;
        }
        */
        /*
        if (isEmpty(queue))
        {
            queue->front_idx = 0;
            queue->back_idx = 0;
        }
        else
        { */
        queue->front_idx = ((queue->front_idx + 1u) % queue->capacity);
        // }

        return value;
    }
    else
        return NO_VALUE;
}

value_type_t front(queue_t *queue)
{
    if (queue == NULL || queue->data == NULL)
        return NO_VALUE;

    if (!isEmpty(queue))
    {
        return queue->data[queue->front_idx];
    }
    else
        return NO_VALUE;
}

value_type_t back(queue_t *queue)
{
    if (queue == NULL || queue->data == NULL)
        return NO_VALUE;

    if (!isEmpty(queue))
    {
        return queue->data[queue->back_idx];
    }
    else
        return NO_VALUE;
}

void printQueue(queue_t *queue)
{
    if (queue == NULL || queue->data == NULL)
        return;

    printf("\nQueue contains %u elements with a capacity of %u.\n", queue->size, queue->capacity);
    printf("Front index: %u, back index: %u\n", queue->front_idx, queue->back_idx);

    for (uint32_t i = 0; i < queue->size; i++)
    {
        /*
        uint32_t j = queue->front_idx + i;
        if (j >= queue->capacity)
        {
            j -= queue->capacity;
        }
        */
        uint32_t j = ((queue->front_idx + i) % queue->capacity);
        printf("Index: %d, Value: %f\n", j, queue->data[j]);
    }

    printf("\n");
}
