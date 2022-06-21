#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

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

typedef struct node
{
    struct node *next;
    struct node *prev;
    value_type_t *value;
} node_t;

typedef struct list
{
    node_t *front;
    node_t *back;
    uint32_t size;
} list_t;

/****************************/
/*        FUNCTIONS         */
/****************************/

node_t *freeNode(node_t *node);

node_t *createNode(value_type_t value);

list_t *freeList(list_t *list);

list_t *createList(void);

void pushBack(list_t *list, node_t *node);

value_type_t popBack(list_t *list);

void pushFront(list_t *list, node_t *node);

value_type_t popFront(list_t *list);

node_t *getNode(list_t *list, u_int32_t idx);

value_type_t popNode(list_t *list, uint32_t idx);

void pushNode(list_t *list, node_t *node, u_int32_t idx);

value_type_t valueAtIdx(list_t *list, uint32_t idx);

void printList(list_t *list);

#endif // DOUBLE_LINKED_LIST_H
