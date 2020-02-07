#include "ft_malloc.h"

int main()
{
	char	*test;
	char	*truc[500];
	size_t i = 2;

	while (1)
	{
		test = ft_malloc(i);
		printf("--->%zu\n", i);
		printf("--->%p\n", test);
		ft_free(test);
		i *= 2;
		if (i == 0)
			return 1;
	}
	
/*
	for (int i = 0; i < 10; i++)
	{
		test = (char *)ft_malloc(sizeof(char)*127);
		printf("|%p|\n", test);
	}
	for (int i = 0; i < 10; i++)
	{
		test = (char *)ft_malloc(sizeof(char)*12700);
		printf("|%p|\n", test);
	}*/

	show_alloc_mem();

	return 0;
}