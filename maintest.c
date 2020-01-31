#include "ft_malloc.h"

int main()
{
	char	*test;

	test = NULL;
	test = (char *)ft_malloc(sizeof(char)*6);
	for (int i = 0; i < 6; i++)
		test[i] = 'p';
	printf("|%s|\n", test);
	return 0;
}