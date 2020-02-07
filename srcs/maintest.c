#include "malloc.h"

int main()
{
	char	*test;
	char	*truc[500];
	size_t i = 1;
	int j;

	for (j = 0; j < 50; j++)
		truc[j] = malloc(j);

	for (j = 50; j < 100; j++)
		truc[j + 50] = malloc(j + 128);

	for (j = 100; j < 150; j++)
		truc[j + 100] = malloc(j + 5000);

	test = malloc(i);
	while (1)
	{
		printf(" i --->%zu\n", i);
		printf("ptr--->%p\n", test);
		test = realloc(test, i);
		i *= 2;
		if (i > 268435456)
			break ;
	}
	
	show_alloc_mem();

	return 0;
}
