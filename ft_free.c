/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 10:26:42 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 15:25:13 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

void	page_first_elem(int type, t_page *next)
{
	if (type == e_tiny_type)
		g_stock.tiny = next;
	else if (type == e_small_type)
		g_stock.small = next;
	else if (type == e_large_type)
		g_stock.large = next;
}


static int		free_in_alloc(void *ptr, t_page *page)
{
	t_alloc	*tmp;

	tmp = page->alloc;
	while (tmp && ptr > (void *)tmp)
	{
		if (ptr == tmp->ptr)
		{
			tmp->is_alloc = 0;
			return (1);
		}
		tmp = tmp->next;
	}
	return (1);
}

static int		free_in_page(void *ptr, t_page *page)
{
	t_page	*tmp;
	t_page	*prev;

	tmp = page;
	prev = page;
	while (tmp)
	{
		if (ptr >= (void *)tmp && ptr <= (void *)((size_t)tmp + tmp->size))
		{
			if (free_in_alloc(ptr, tmp) && page_is_empty(tmp))
			{
			printf("on free la page !!!\n");
				if (tmp == page)
				{
					page_first_elem(page->type, tmp->next);
					
				}
				else
				{

					prev->next = tmp->next;
				}
				munmap(tmp, tmp->size);
			}
			return (1);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_free(void *ptr)
{
	if (ptr)
	{
		if (free_in_page(ptr, g_stock.tiny) ||
			free_in_page(ptr, g_stock.small) ||
			free_in_page(ptr, g_stock.large))
			;
	}
}
