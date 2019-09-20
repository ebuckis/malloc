#include "ft_malloc.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdalign.h>

int main()
{
    int *real_malloc;
    int *fake_malloc;

    for (int i = 1; i < 129; i++)
    {
        printf("test n : %d\n", i);
        for (int j = 0; j < 100; j++)
            fake_malloc = (int *)ft_malloc(i);
        printf("fake : |%ld|\n\n", (long)fake_malloc);
    }
    ft_display();
    return 0;
}