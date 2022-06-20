#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint32_t number[4] = {0, 1, 2, 3};

    for (uint32_t i = 0; i < 4; i++)
    {
        printf("%u, %p\n", number[i], &number[i]);
    }

    return 0;
}
