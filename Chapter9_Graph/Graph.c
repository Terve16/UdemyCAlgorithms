
/****************************/
/*         INCLUDES         */
/****************************/

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

/****************************/
/*        FUNCTIONS         */
/****************************/

graph_t *freeGraph(graph_t *graph)
{
    if (graph == NULL)
        return NULL;

    if (graph->vertices != NULL)
    {
        free(graph->vertices);
        graph->vertices = NULL;
    }

    free(graph);
    graph = NULL;

    return NULL;
}

graph_t *createGraph(uint32_t no_vertices, uint32_t no_edges)
{
    graph_t *graph = (graph_t *)malloc(sizeof(graph_t));

    if (graph == NULL)
        return NULL;

    graph->vertices = (node_t **)malloc(no_vertices * sizeof(node_t *));

    if (graph->vertices == NULL)
    {
        free(graph);
        graph = NULL;
        return NULL;
    }

    for (uint32_t i = 0u; i < no_vertices; i++)
    {
        graph->vertices[i] = NULL;
    }

    graph->no_edges = no_edges;
    graph->no_vertices = no_vertices;

    return graph;
}

node_t *freeNode(node_t *node)
{
    if (node == NULL)
        return NULL;

    free(node);
    node = NULL;

    return NULL;
}

node_t *createNode(uint32_t node_idx, value_type_t weight, node_t *node)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    if (new_node == NULL)
        return NULL;

    new_node->next = node;
    new_node->node_idx = node_idx;
    new_node->weight = weight;

    return new_node;
}

void addEdges(graph_t *graph, edge_t edges[])
{
    if (graph == NULL)
        return;

    for (uint32_t i = 0u; i < graph->no_edges; i++)
    {
        graph->vertices[edges[i].start_idx] =
            createNode(edges[i].end_idx, edges[i].weight, graph->vertices[edges[i].start_idx]);
    }
}


void printGraph(graph_t *graph)
{
    if (graph == NULL || graph->vertices == NULL)
        return;

    printf("\nPrint graph:\n");

    for (uint32_t i = 0u; i < graph->no_vertices; i++)
    {
        printf("Vertex: %u\n", i);

        node_t *node = graph->vertices[i];

        while (node != NULL)
        {
            printf("(%u, %f)\n", node->node_idx, node->weight);

            node = node->next;
        }
    }

    printf("\n");
}
