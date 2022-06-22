#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

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

typedef struct node
{
    value_type_t value;
    struct node *left;
    struct node *right;
} node_t;


/****************************/
/*        FUNCTIONS         */
/****************************/

node_t *freeBST(node_t *node);

node_t *createBST(value_type_t value);

void insertNode(node_t *root, node_t *node);

node_t *minValueNode(node_t *node);

node_t *removeNode(node_t *root, value_type_t value);

void printBST(node_t *node);

#endif // BINARY_SEARCH_TREE_H
