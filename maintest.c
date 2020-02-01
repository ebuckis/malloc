#include "ft_malloc.h"

int main()
{
	char	*test;

	test = NULL;
	for (int i = 0; i < 1000; i++)
	{
		if (i % 250 == 0)
			sleep(1);
		test = (char *)ft_malloc(sizeof(char)*17);
		printf("|%p|\n", test);
	}



	if (!g_stock.large)
		printf("large null\n");
	if (!g_stock.small)
		printf("small null\n");
	if (!g_stock.tiny)
		printf("tiny null\n");

	return 0;
}