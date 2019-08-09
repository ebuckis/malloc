#include "ft_malloc.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdalign.h>

int main()
{
    int i, j;
    long    tab[1000] = {0};

    i = 1;
    while (i < 1000)
    {
        tab[i] = (long)malloc(i % 100);
        printf("%d : |%lu|\n", i, tab[i]);
        j = 2;
        if (tab[i] % 16 != 0)
            printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        while (j <= 256 && tab[i] %j == 0)
        {
            printf("         mod%d : %d\n", j, tab[i] % j);
            j *= 2;
        }
        printf("\n");
        i++;
    }
    return 0;
}