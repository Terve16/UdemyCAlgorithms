
/****************************/
/*         INCLUDES         */
/****************************/

#include <stdio.h>
#include <stdlib.h>

#include "DoubleLinkList.h"

/****************************/
/*        FUNCTIONS         */
/****************************/

node_t *freeNode(node_t *node)
{
    if (node == NULL)
        return NULL;

    if ((node->value != NULL))
    {
        free(node->value);
        node->value = NULL;
    }

    free(node);
    node = NULL;

    return NULL;
}

node_t *createNode(value_type_t value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (node == NULL)
        return NULL;

    node->value = (value_type_t *)malloc(sizeof(value_type_t));

    if (node->value == NULL)
    {
        freeNode(node);
        return NULL;
    }

    node->next = NULL;
    node->prev = NULL;
    *node->value = value;

    return node;
}

list_t *freeList(list_t *list)
{
    if (list == NULL)
        return NULL;

    while (list->back != NULL)
    {
        node_t *node = list->back->prev;
        freeNode(list->back);
        list->back = node;
    }

    free(list);
    list = NULL;

    return NULL;
}

list_t *createList(void)
{
    list_t *list = (list_t *)malloc(sizeof(list_t));

    if (list == NULL)
        return NULL;

    list->back = NULL;
    list->front = NULL;
    list->size = 0u;

    return list;
}

void pushBack(list_t *list, node_t *node)
{
    if (list == NULL || node == NULL)
        return;

    if (list->back == NULL) // empty list
    {
        node->prev = NULL;
        node->next = NULL;
        list->front = node;
        list->back = node;
    }
    else
    {
        node->prev = list->back;
        node->next = NULL;
        list->back->next = node;
        list->back = node;
    }
    list->size++;
}

value_type_t popBack(list_t *list)
{
    if (list == NULL || list->back == NULL)
        return NO_VALUE;

    value_type_t value = NO_VALUE;
    if (list->back->value != NULL)
    {
        value = *(list->back->value);
    }

    if (list->back->prev == NULL) // list is empty afterwards
    {
        freeNode(list->back);
        list->front = NULL;
        list->back = NULL;
    }
    else
    {
        node_t *temp = list->back->prev;
        freeNode(list->back);
        temp->next = NULL;
        list->back = temp;
    }
    list->size--;

    return value;
}

void pushFront(list_t *list, node_t *node)
{
    if (list == NULL || node == NULL)
        return;

    if (list->front == NULL) // empty list
    {
        node->prev = NULL;
        node->next = NULL;
        list->front = node;
        list->back = node;
    }
    else // list has at least one element
    {
        node->next = list->front;
        node->prev = NULL;
        list->front->prev = node;
        list->front = node;
    }
    list->size++;
}

value_type_t popFront(list_t *list)
{
    if (list == NULL || list->front == NULL)
        return NO_VALUE;

    value_type_t value = NO_VALUE;
    if (list->front->value != NULL)
    {
        value = *(list->front->value);
    }

    if (list->front->next == NULL) // list is empty afterwards
    {
        freeNode(list->front);
        list->front = NULL;
        list->back = NULL;
    }
    else
    {
        node_t *temp = list->front->next;
        freeNode(list->front);
        temp->prev = NULL;
        list->front = temp;
    }
    list->size--;

    return value;
}

node_t *getNode(list_t *list, u_int32_t idx)
{
    if (list == NULL || idx >= list->size)
        return NULL;

    node_t *node = NULL;

    if (idx <= (list->size / 2)) // closer to start of list
    {
        node = list->front;
        uint32_t i = 0;
        while (node != NULL)
        {
            if (i == idx)
            {
                break;
            }

            node = node->next;
            i++;
        }
    }
    else
    {
        node = list->back;
        uint32_t i = (list->size - 1);
        while (node != NULL)
        {
            if (i == idx)
            {
                break;
            }

            node = node->prev;
            i--;
        }
    }

    return node;
}

value_type_t popNode(list_t *list, uint32_t idx)
{
    if (list == NULL || idx >= list->size)
        return NO_VALUE;

    value_type_t value = NO_VALUE;
    node_t *node = getNode(list, idx);

    if (node != NULL && node->value != NULL)
    {
        value = *(node->value);
    }

    if (node != NULL)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        list->size--;
        node = freeNode(node);
    }

    return value;
}

void pushNode(list_t *list, node_t *node, u_int32_t idx)
{
    if (list == NULL || node == NULL || idx >= list->size)
        return;

    node_t *temp = getNode(list, idx);

    if (temp != NULL)
    {
        node->prev = temp->prev;
        node->next = temp;

        temp->prev->next = node;
        temp->prev = node;

        list->size++;
    }
}

value_type_t valueAtIdx(list_t *list, uint32_t idx)
{
    if (list == NULL || idx >= list->size)
        return NO_VALUE;

    value_type_t value = NO_VALUE;
    node_t *node = getNode(list, idx);

    if (node != NULL && node->value != NULL)
    {
        value = *(node->value);
    }

    return value;
}

void printList(list_t *list)
{
    if (list == NULL)
        return;

    printf("\nList contains %u elements.\n", list->size);

    node_t *node = list->front;
    uint32_t i = 0;
    while (node != NULL)
    {
        printf("Index: %d, Value: %f\n", i, *node->value);

        node = node->next;
        i++;
    }

    printf("\n");
}
