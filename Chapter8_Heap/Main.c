#include <assert.h>
#include <stdio.h>

#include "Heap.h"

int main(void)
{
    heap_t *heap = createHeap();

    insertValue(heap, 42.0f);
    insertValue(heap, 22.0f);
    insertValue(heap, 60.0f);
    insertValue(heap, 72.0f);
    insertValue(heap, -20.0f);

    printHeap(heap);

    removeMinimum(heap);

    printHeap(heap);

    heap = freeHeap(heap);

    return 0;
}
