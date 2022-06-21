#include <assert.h>
#include <stdio.h>

#include "HashTable.h"

int main(void)
{
    hash_table_t *hash_table = createHashTable();

    item_t item1 = {.key = "Joseph", .value = 26.0f};
    item_t item2 = {.key = "Maxi", .value = 27.0f};
    item_t item3 = {.key = "Lena", .value = 21.0f};
    item_t item4 = {.key = "Peter", .value = 42.0f};
    item_t item5 = {.key = "Lara", .value = 30.0f};

    insertItem(hash_table, &item1);
    insertItem(hash_table, &item2);
    insertItem(hash_table, &item3);
    insertItem(hash_table, &item4);
    insertItem(hash_table, &item5);

    printHashTable(hash_table);

    item1.value = 31.0f;
    insertItem(hash_table, &item1);
    removeItem(hash_table, item2.key);
    removeItem(hash_table, item4.key);

    printHashTable(hash_table);

    hash_table = freeHashTable(hash_table);

    return 0;
}
