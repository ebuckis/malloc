#include "ft_malloc.h"

int main()
{
	char	*test;

	test = NULL;
	for (int i = 0; i < 20; i++)
	{
		test = (char *)ft_malloc(sizeof(char)*90);
		printf("|%p|\n", test);
	}
	for (int i = 0; i < 10; i++)
	{
		test = (char *)ft_malloc(sizeof(char)*127);
		printf("|%p|\n", test);
	}
	for (int i = 0; i < 10; i++)
	{
		test = (char *)ft_malloc(sizeof(char)*12700);
		printf("|%p|\n", test);
	}

	ft_display();

	if (!g_stock.large)
		printf("large null\n");
	if (!g_stock.small)
		printf("small null\n");
	if (!g_stock.tiny)
		printf("tiny null\n");

	return 0;
}