
/****************************/
/*         INCLUDES         */
/****************************/

#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"

/****************************/
/*        FUNCTIONS         */
/****************************/

node_t *freeBST(node_t *node)
{
    if (node == NULL)
        return NULL;

    free(node);
    node = NULL;

    return NULL;
}

node_t *createBST(value_type_t value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (node == NULL)
        return NULL;


    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insertNode(node_t *root, node_t *node)
{
    if (root == NULL || node == NULL)
        return;

    node_t *parent = root;

    while (parent != NULL)
    {
        if (node->value < parent->value)
        {
            if (parent->left == NULL)
            {
                parent->left = node;
                break;
            }
            else
            {
                parent = parent->left;
            }
        }
        else
        {
            if (parent->right == NULL)
            {
                parent->right = node;
                break;
            }
            else
            {
                parent = parent->right;
            }
        }
    }
}

node_t *minValueNode(node_t *node)
{
    if (node == NULL)
        return NULL;

    node_t *current_node = node;

    while (current_node->left != NULL)
    {
        current_node = current_node->left;
    }

    return current_node;
}

node_t *removeNode(node_t *root, value_type_t value)
{
    if (root == NULL)
        return NULL;

    if (value < root->value)
    {
        root->left = removeNode(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = removeNode(root->right, value);
    }
    else // value equal
    {
        if (root->left == NULL) // no left child
        {
            node_t *temp = root->right; // return right child

            return temp;
        }
        else if (root->right == NULL) // no right child
        {
            node_t *temp = root->left; // return left child

            return temp;
        }
        else // two children
        {
            node_t *temp = minValueNode(root->right);           // go down to left leave of right branch
            root->value = temp->value;                          // replace value with left leave value from right branch
            root->right = removeNode(root->right, temp->value); // remove left leave of right branch
        }
    }

    return root;
}

void printBST(node_t *node)
{
    if (node == NULL)
        return;

    node_t *left_node = node->left;
    node_t *right_node = node->right;

    if (left_node != NULL && right_node != NULL)
    {
        printf("  %.2f\n"
               " /  \\\n"
               "%.2f  %.2f\n",
               node->value,
               left_node->value,
               right_node->value);
    }
    else if (left_node != NULL)
    {
        printf("  %.2f\n"
               " /  \\\n"
               "%.2f    \n",
               node->value,
               left_node->value);
    }
    else if (right_node != NULL)
    {
        printf("  %.2f\n"
               " /  \\\n"
               "    %.2f\n",
               node->value,
               right_node->value);
    }
    else // no children
    {
        printf("  %.2f\n"
               " /  \\\n\n",
               node->value);
    }

    /*
    value_type_t left_value = (left_node != NULL) ? left_node->value : NO_VALUE;
    value_type_t right_value = (right_node != NULL) ? right_node->value : NO_VALUE;

    printf("%.2f\n"
           "/  \\\n"
           "%.2f %.2f\n\n",
           node->value,
           left_value,
           right_value);
    */

    printBST(node->left);
    printBST(node->right);
}
