#include "ft_malloc.h"

int main()
{
	char	*test;
	char	*truc[500];

	test = NULL;
	for (int i = 0; i < 500; i++)
	{
		truc[i] = (char *)ft_malloc(sizeof(char)*90);
	}
	for (int i = 0; i < 500; i++)
	{
		ft_free(truc[i]);
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

	ft_display();

	return 0;
}