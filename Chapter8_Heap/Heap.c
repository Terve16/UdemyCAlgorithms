
/****************************/
/*         INCLUDES         */
/****************************/

#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"

/****************************/
/*        FUNCTIONS         */
/****************************/

heap_t *freeHeap(heap_t *heap)
{
    if (heap == NULL)
        return NULL;

    if (heap->data != NULL)
    {
        free(heap->data);
        heap->data = NULL;
    }

    free(heap);
    heap = NULL;

    return NULL;
}

heap_t *createHeap()
{
    heap_t *heap = (heap_t *)malloc(sizeof(heap_t));

    if (heap == NULL)
        return NULL;


    heap->data = (value_type_t *)malloc(DEFAULT_CAPACITY * sizeof(value_type_t));

    if (heap->data == NULL)
    {
        free(heap);
        heap = NULL;
        return NULL;
    }

    heap->capacity = DEFAULT_CAPACITY;
    heap->size = 0u;

    return heap;
}

uint32_t parentNode(uint32_t idx)
{
    if (idx == 0u)
        return 0u;
    else
        return ((idx - 1u) / 2u);
}

uint32_t leftChildNode(uint32_t idx)
{
    return ((idx * 2u) + 1u);
}

uint32_t rightChildNode(uint32_t idx)
{
    return ((idx * 2u) + 2u);
}

void swap(value_type_t *a, value_type_t *b)
{
    value_type_t temp = *a;
    *a = *b;
    *b = temp;
}

void insertValue(heap_t *heap, value_type_t value)
{
    if (heap == NULL || heap->data == NULL)
        return;

    if (heap->size >= heap->capacity)
        return;

    uint32_t idx = heap->size;
    heap->data[idx] = value;
    heap->size++;

    while ((idx != 0u) && (heap->data[parentNode(idx)] > heap->data[idx]))
    {
        swap(&heap->data[idx], &heap->data[parentNode(idx)]);
        idx = parentNode(idx);
    }
}

value_type_t removeMinimum(heap_t *heap)
{
    if (heap == NULL || heap->data == NULL)
        return NO_VALUE;

    if (heap->size == 1u)
    {
        heap->size--;

        return heap->data[0];
    }

    value_type_t root = heap->data[0];
    heap->size--;
    heap->data[0] = heap->data[heap->size];
    heapify(heap, 0);

    return root;
}

void heapify(heap_t *heap, uint32_t idx)
{
    if (heap == NULL || heap->data == NULL)
        return;

    if (idx >= heap->size)
        return;

    uint32_t i = idx;
    uint32_t smallest = i;

    while (true)
    {
        uint32_t left_idx = leftChildNode(i);
        uint32_t right_idx = rightChildNode(i);

        if ((left_idx < heap->size) && (heap->data[left_idx] < heap->data[smallest]))
        {
            smallest = left_idx;
        }

        if ((right_idx < heap->size) && (heap->data[right_idx] < heap->data[smallest]))
        {
            smallest = right_idx;
        }

        if (smallest != i)
        {
            swap(&heap->data[i], &heap->data[smallest]);
            i = smallest;
        }
        else
        {
            break;
        }
    }
}

void printHeap(heap_t *heap)
{
    if (heap == NULL || heap->data == NULL)
        return;

    uint32_t num_visited_nodes = 0u;
    uint32_t depth = (((uint32_t)floor(log2(heap->size))) + 1u);

    printf("\nPrint heap:\n");

    for (uint32_t i = 0u; i < depth; i++)
    {
        uint32_t num_layer_nodes = ((uint32_t)pow(2.0, i));

        printf("Layer: %u\n", i);

        for (uint32_t j = 0u; j < num_layer_nodes; j++)
        {
            uint32_t current_idx = num_visited_nodes + j;

            if (current_idx < heap->size)
            {
                printf("Node: %u, Value: %f\n", current_idx, heap->data[current_idx]);
            }
            else
            {
                break;
            }
        }

        num_visited_nodes += num_layer_nodes;
    }

    printf("\n");
}
