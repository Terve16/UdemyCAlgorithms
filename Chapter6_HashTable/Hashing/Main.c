#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE (uint32_t)13u
#define MAX_NAME_SIZE (uint32_t)256u

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

int main()
{
    char name1[] = "Joseph";
    char name2[] = "Maxi";
    char name3[] = "Lena";
    char name4[] = "Peter";
    char name5[] = "Lara";

    printf("Key: %s, Idx: %u\n", name1, hash(name1));
    printf("Key: %s, Idx: %u\n", name2, hash(name2));
    printf("Key: %s, Idx: %u\n", name3, hash(name3));
    printf("Key: %s, Idx: %u\n", name4, hash(name4));
    printf("Key: %s, Idx: %u\n", name5, hash(name5));

    return 0;
}
