/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_alloc.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 10:46:30 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 14:22:56 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "malloc.h"

t_alloc		*alloc_init(t_alloc *new, size_t last_ad)
{
	new->is_alloc = 0;
	new->next = NULL;
	new->ptr = (void *)((size_t)new + sizeof(t_alloc));
	if (last_ad < (size_t)new->ptr)
		new->size = 0;
	else
		new->size = last_ad - (size_t)new->ptr;
	return (new);
}

void		*alloc_find_place(t_page *page, size_t size)
{
	t_alloc	*tmp;
	size_t	last_address;

	tmp = page->alloc;
	while (tmp->is_alloc || get_size_align(size) > tmp->size)
	{
		if (tmp->next == NULL)
		{
			last_address = (size_t)tmp->ptr + tmp->size
				+ sizeof(t_alloc) + get_size_align(size);
			if (last_address >= (size_t)page + get_size_page(page->type))
			{
				return (NULL);
			}
			tmp->next = (void *)((size_t)tmp->ptr + tmp->size);
			tmp->next = alloc_init(tmp->next,
				(size_t)page + get_size_page(page->type));
		}
		tmp = tmp->next;
	}
	tmp->size = get_size_align(size);
	tmp->is_alloc = 1;
	return (tmp->ptr);
}
