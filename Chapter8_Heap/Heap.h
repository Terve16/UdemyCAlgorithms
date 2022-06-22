#ifndef HEAP_H
#define HEAP_H

/****************************/
/*         INCLUDES         */
/****************************/

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/****************************/
/*     DEFINES AND TYPES    */
/****************************/

typedef float value_type_t;

#define NO_VALUE (value_type_t) INFINITY

#define DEFAULT_CAPACITY (uint32_t)10u

typedef struct heap
{
    uint32_t size;
    uint32_t capacity;
    value_type_t *data;
} heap_t;


/****************************/
/*        FUNCTIONS         */
/****************************/

heap_t *freeHeap(heap_t *heap);

heap_t *createHeap();

uint32_t parentNode(uint32_t idx);

uint32_t leftChildNode(uint32_t idx);

uint32_t rightChildNode(uint32_t idx);

void swap(value_type_t *a, value_type_t *b);

void insertValue(heap_t *heap, value_type_t value);

value_type_t removeMinimum(heap_t *heap);

void heapify(heap_t *heap, uint32_t idx);

void printHeap(heap_t *heap);

#endif // HEAP_H
