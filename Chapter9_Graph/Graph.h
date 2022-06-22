#ifndef GRAPH_H
#define GRAPH_H

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
    uint32_t node_idx;
    value_type_t weight;
    struct node *next;
} node_t;

typedef struct edge
{
    uint32_t start_idx;
    uint32_t end_idx;
    value_type_t weight;
} edge_t;

typedef struct graph
{
    uint32_t no_vertices;
    uint32_t no_edges;
    node_t **vertices;
} graph_t;


/****************************/
/*        FUNCTIONS         */
/****************************/

graph_t *freeGraph(graph_t *graph);

graph_t *createGraph(uint32_t no_vertices, uint32_t no_edges);

node_t *freeNode(node_t *node);

node_t *createNode(uint32_t node_idx, value_type_t weight, node_t *node);

void addEdges(graph_t *graph, edge_t edges[]);

void printGraph(graph_t *graph);

#endif // GRAPH_H
