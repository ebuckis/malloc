#include "ft_malloc.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdalign.h>

int main()
{
    int *real_malloc;
    int *fake_malloc;

    for (int i = 0; i < 1000; i++)
    {
        printf("test n : %d\n", i);
        fake_malloc = (int *)ft_malloc(sizeof(int) * i);
        printf("fake : |%ld|\n\n", (long)fake_malloc);
    }
    return 0;
}