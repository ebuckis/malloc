/**
HEADER
*/

#include "ft_malloc.h"

void	*malloc_search_area(size_t size)
{
	void	*ptr;
	if (size <= TINY_MAX)
		ptr = little_alloc(g_stock.tiny, e_tiny_type);
	else (size <= SMALL_MAX)
		ptr = little_alloc(g_stock.small, e_small_type);
	else
		ptr = large_alloc(g_stock.large, e_large_type);
}

void	malloc_init(void)
{
	static int	is_init = 0;

	if (!is_init)
	{
		g_stock.tiny = NULL;
		g_stock.small = NULL;
		g_stock.large = NULL;
	}
}


void	*ft_malloc(size_t size)
{
	if (size < 1)
		return (NULL);
	malloc_init();
	return (malloc_search_area(size));
}
