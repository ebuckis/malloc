#include "ft_malloc.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdalign.h>

int main()
{
	char *real_malloc;
	char *fake_malloc;

    for (int i = 1; i < 18; i++)
    {
        printf("test n : %d\n", i);
        for (int j = 0; j < 100; j++)
        {
            fake_malloc = ft_malloc(i);
            if (i > 3 && i < 16)
                ft_free(fake_malloc);
        }
        //printf("fake : |%ld|\n\n", (long)fake_malloc);
    }
    ft_display();
   /*
	real_malloc = malloc(6);
	real_malloc[0] = 's';
	real_malloc[1] = 'a';
	real_malloc[2] = 'l';
	real_malloc[3] = 'u';
	real_malloc[4] = 't';
	real_malloc[5] = '\0';
	printf("%s\n", real_malloc);
	free(real_malloc);
	printf("%s\n", real_malloc);
	*/
    return 0;
}