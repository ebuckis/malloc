/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_size.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 10:37:51 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 15:18:08 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "malloc.h"

int					page_is_empty(t_page *page)
{
	t_alloc			*tmp;

	tmp = page->alloc;
	while (tmp)
	{
		if (tmp->is_alloc)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

size_t				get_size_align(size_t size)
{
	size_t			ret;

	ret = size % 16;
	if (ret == 0)
		return (size);
	ret = 16 * ((size / 16) + 1);
	return (ret);
}

size_t				get_round_pagesize(size_t size)
{
	size_t			ret;
	size_t			p_size;

	p_size = getpagesize();
	ret = size % p_size;
	if (ret == 0)
		return (size);
	ret = p_size * ((size / p_size) + 1);
	return (ret);
}

size_t				get_size_alloc(int type)
{
	if (type == e_small_type)
		return (SMALL_MAX);
	else if (type == e_small_type)
		return (TINY_MAX);
	return (0);
}

size_t				get_size_page(int type)
{
	static size_t	small_size = 0;
	static size_t	tiny_size = 0;

	if (type == e_small_type)
	{
		if (small_size == 0)
		{
			small_size = (sizeof(t_page)
				+ (100 * (sizeof(t_alloc) + SMALL_MAX)));
			small_size = ((small_size / getpagesize()) + 1) * getpagesize();
		}
		return (small_size);
	}
	else if (type == e_tiny_type)
	{
		if (tiny_size == 0)
		{
			tiny_size = (sizeof(t_page) + (100 * (sizeof(t_alloc) + TINY_MAX)));
			tiny_size = ((tiny_size / getpagesize()) + 1) * getpagesize();
		}
		return (tiny_size);
	}
	return (0);
}
