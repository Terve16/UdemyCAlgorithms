
/****************************/
/*         INCLUDES         */
/****************************/

#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

/****************************/
/*        FUNCTIONS         */
/****************************/

hash_table_t *freeHashTable(hash_table_t *hash_table)
{
    if (hash_table == NULL)
        return NULL;

    if (hash_table->data != NULL)
    {
        free(hash_table->data);
        hash_table->data = NULL;
    }

    free(hash_table);
    hash_table = NULL;

    return NULL;
}

hash_table_t *createHashTable(void)
{
    hash_table_t *hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));

    if (hash_table == NULL)
        return NULL;


    hash_table->data = (item_t *)malloc(TABLE_SIZE * sizeof(item_t));

    if (hash_table->data == NULL)
    {
        hash_table = freeHashTable(hash_table);
        return NULL;
    }

    for (uint32_t i = 0; i < TABLE_SIZE; i++)
    {
        strncpy(hash_table->data[i].key, DELETED_KEY, MAX_NAME_SIZE);
        hash_table->data[i].value = NO_VALUE;
    }

    hash_table->capacity = TABLE_SIZE;
    hash_table->size = 0u;

    return hash_table;
}

uint32_t hash(char key[MAX_NAME_SIZE])
{
    uint32_t hash_value = 0u;

    for (uint32_t i = 0; i < MAX_NAME_SIZE; i++)
    {
        if ('\0' != key[i])
        {
            hash_value = ((hash_value * 128 + key[i]) % TABLE_SIZE);
        }
        else
        {
            break;
        }
    }

    return hash_value;
}

void insertItem(hash_table_t *hash_table, item_t *item)
{
    if (hash_table == NULL || hash_table->data == NULL || item == NULL)
        return;

    if (hash_table->size >= hash_table->capacity) // full
        return;

    uint32_t idx = hash(item->key);
    bool compare = false;

    while (strncmp(hash_table->data[idx].key, DELETED_KEY, MAX_NAME_SIZE) != 0) // index not aviable
    {
        compare = (strncmp(hash_table->data[idx].key, item->key, MAX_NAME_SIZE) == 0);
        if (compare) // item exists already
        {
            break;
        }
        idx = (idx + 1u) % hash_table->capacity;
    }

    hash_table->data[idx] = *item;

    if (!compare)
    {
        hash_table->size++;
    }
}

value_type_t getValue(hash_table_t *hash_table, char key[MAX_NAME_SIZE])
{
    if (hash_table == NULL || hash_table->data == NULL || key == NULL)
        return NO_VALUE;

    if (hash_table->size <= 0u) // empty
        return NO_VALUE;

    uint32_t idx = hash(key);

    uint32_t i = 0;
    while (strncmp(hash_table->data[idx].key, key, MAX_NAME_SIZE) != 0) // item not aviable
    {
        if (i >= hash_table->size) // item does not exist
        {
            return NO_VALUE;
        }
        idx = (idx + 1u) % hash_table->capacity;
        i++;
    }

    return hash_table->data[idx].value;
}

value_type_t removeItem(hash_table_t *hash_table, char key[MAX_NAME_SIZE])
{
    if (hash_table == NULL || hash_table->data == NULL || key == NULL)
        return NO_VALUE;

    if (hash_table->size <= 0u) // empty
        return NO_VALUE;

    uint32_t idx = hash(key);

    uint32_t i = 0;
    while (strncmp(hash_table->data[idx].key, key, MAX_NAME_SIZE) != 0) // item not aviable
    {
        if (i >= hash_table->size) // item does not exist
        {
            return NO_VALUE;
        }
        idx = (idx + 1u) % hash_table->capacity;
        i++;
    }

    value_type_t value = hash_table->data[idx].value;
    hash_table->data[idx].value = NO_VALUE;
    strncpy(hash_table->data[idx].key, DELETED_KEY, MAX_NAME_SIZE);

    hash_table->size--;

    return value;
}

void printHashTable(hash_table_t *hash_table)
{
    if (hash_table == NULL || hash_table->data == NULL)
        return;

    printf("\nHashTable contains %u elements with a capacity of %u.\n", hash_table->size, hash_table->capacity);

    for (uint32_t i = 0; i < hash_table->capacity; i++)
    {
        printf("Index: %d, Key: %s, Value: %f\n", i, hash_table->data[i].key, hash_table->data[i].value);
    }

    printf("\n");
}
