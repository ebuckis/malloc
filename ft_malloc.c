/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 11:22:20 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 11:09:54 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

void			*malloc_search_area(size_t size)
{
	void		*ptr;

	if (size + sizeof(t_page) <= TINY_MAX)
	{
		if (!g_stock.tiny)
		{
			if (!(g_stock.tiny = little_new_page(g_stock.tiny, e_tiny_type)))
				return (NULL);
		}
		ptr = little_alloc(g_stock.tiny, e_tiny_type, size);
	}
	else if (size + sizeof(t_page) <= SMALL_MAX)
	{
		if (!g_stock.small)
		{
			if (!(g_stock.small = little_new_page(g_stock.small, e_small_type)))
				return (NULL);
		}
		ptr = little_alloc(g_stock.small, e_small_type, size);
	}
	else
		;//ptr = large_alloc(g_stock.large, e_large_type);
	return (ptr);
}

void			malloc_init(void)
{
	static int	is_init = 0;

	if (!is_init)
	{
		printf("start -> %s\n", __func__);
		g_stock.tiny = NULL;
		g_stock.small = NULL;
		g_stock.large = NULL;
		is_init = 1;
	}
}


void			*ft_malloc(size_t size)
{
	if (size < 1)
		return (NULL);
	malloc_init();
	return (malloc_search_area(size));
}
