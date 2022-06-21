#ifndef HASH_TABLE_H
#define HASH_TABLE_H

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

#define TABLE_SIZE (uint32_t)13u
#define MAX_NAME_SIZE (uint32_t)256u
#define DELETED_KEY "DELETED"

typedef struct item
{
    char key[MAX_NAME_SIZE];
    value_type_t value;
} item_t;


typedef struct hash_table
{
    uint32_t size;
    uint32_t capacity;
    item_t *data;
} hash_table_t;

/****************************/
/*        FUNCTIONS         */
/****************************/

hash_table_t *freeHashTable(hash_table_t *hash_table);

hash_table_t *createHashTable(void);

uint32_t hash(char key[MAX_NAME_SIZE]);

void insertItem(hash_table_t *hash_table, item_t *item);

value_type_t getValue(hash_table_t *hash_table, char key[MAX_NAME_SIZE]);

value_type_t removeItem(hash_table_t *hash_table, char key[MAX_NAME_SIZE]);

void printHashTable(hash_table_t *hash_table);

#endif // HASH_TABLE_H
