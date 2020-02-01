/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_size.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 10:37:51 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 11:48:49 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t		get_size_align(size_t size)
{
	size_t	ret;

	ret = size % 16;
	if (ret == 0)
		return (size);
	ret = 16 * ((size / 16) + 1);
	return (ret);
}

int		get_size_alloc(int type)
{
	if (type == e_small_type)
		return (SMALL_MAX);
	else if (type == e_small_type)
		return (TINY_MAX);
	return (0);
}

size_t		get_size_page(int type)
{
	static size_t	small_size = 0;
	static size_t	tiny_size = 0;

	if (type == e_small_type)
	{
		if (small_size == 0)
		{
			small_size = (sizeof(t_page) + (100 * (sizeof(t_alloc) + SMALL_MAX)));
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
