#include <assert.h>
#include <stdio.h>

#include "DoubleLinkList.h"

int main(void)
{
    list_t *list = createList();

    node_t *a = createNode(1.0f);
    node_t *b = createNode(2.0f);
    node_t *c = createNode(3.0f);

    printList(list);

    pushBack(list, a);
    pushBack(list, b);
    pushBack(list, c);

    assert(list->front->next == getNode(list, 1)); // check if getNode works

    printList(list);

    node_t *d = createNode(2.5f);
    pushNode(list, d, 2);

    printList(list);

    popNode(list, 1);

    printList(list);

    popBack(list);
    popBack(list);
    popBack(list);

    printList(list);

    list = freeList(list);

    return 0;
}
