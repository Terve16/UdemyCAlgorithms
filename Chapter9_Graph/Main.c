#include <assert.h>
#include <stdio.h>

#include "Graph.h"

int main(void)
{
    uint32_t no_vertices = 5;
    uint32_t no_edges = 6;

    edge_t edges[] = {{0, 1, 2.5f}, {0, 2, 1.0f}, {1, 4, 3.0f}, {2, 3, 2.0f}, {3, 1, 4.0f}, {4, 3, -3.0f}};

    graph_t *graph = createGraph(no_vertices, no_edges);

    addEdges(graph, edges);


    printGraph(graph);

    graph = freeGraph(graph);

    return 0;
}
