#include "ft_malloc.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdalign.h>

int main()
{
    int *real_malloc;
    int *fake_malloc;

    real_malloc = (int *)malloc(sizeof(int) * 5);
    fake_malloc = (int *)ft_malloc(sizeof(int) * 5);
    printf("fake : |%ld|\n", (long)fake_malloc);
    fake_malloc = (int *)ft_malloc(sizeof(int) * 5);
    printf("fake : |%ld|\n", (long)fake_malloc);
    fake_malloc = (int *)ft_malloc(sizeof(int) * 5);
    printf("fake : |%ld|\n", (long)fake_malloc);
    fake_malloc = (int *)ft_malloc(sizeof(int) * 5);
    printf("fake : |%ld|\n", (long)fake_malloc);
    fake_malloc = (int *)ft_malloc(sizeof(int) * 5);
    printf("fake : |%ld|\n", (long)fake_malloc);
    fake_malloc = (int *)ft_malloc(sizeof(int) * 5);
    printf("fake : |%ld|\n", (long)fake_malloc);
    fake_malloc = (int *)ft_malloc(sizeof(int) * 5);
    printf("fake : |%ld|\n", (long)fake_malloc);
    fake_malloc = (int *)ft_malloc(sizeof(int) * 5);
    printf("fake : |%ld|\n", (long)fake_malloc);
    real_malloc = (int *)malloc(sizeof(int) * 1000);
    fake_malloc = (int *)ft_malloc(sizeof(int) * 1000);
    printf("real : |%ld|\n", (long)real_malloc);
    printf("fake : |%ld|\n", (long)fake_malloc);
    return 0;
}