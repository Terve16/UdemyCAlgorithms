#include <assert.h>
#include <stdio.h>

#include "BinarySearchTree.h"

int main(void)
{
    node_t *root = createBST(42.0f);
    node_t *node2 = createBST(22.0f);
    node_t *node3 = createBST(52.0f);
    node_t *node4 = createBST(60.0f);

    insertNode(root, node2);
    insertNode(root, node3);
    insertNode(root, node4);

    printf("\nBST print:\n");
    printBST(root);

    removeNode(root, 60.0f);

    printf("\nBST print:\n");
    printBST(root);

    removeNode(root, 42.0f);

    printf("\nBST print:\n");
    printBST(root);

    root = freeBST(root);

    return 0;
}
