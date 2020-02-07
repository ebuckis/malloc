/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_large.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 13:35:30 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 12:00:05 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

t_page		*large_new_page(t_page *new, size_t size)
{
	size_t	total;

	total = get_size_align(size)
		+ sizeof(t_page) + sizeof(t_alloc);
	new = mmap(NULL, total,
		PROT_READ | PROT_WRITE,	MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (!new || (size_t)new == 0xFFFFFFFFFFFFFFFF)
		return (NULL);
	new->size = total;
	new->type = e_large_type;
	new->next = NULL;
	new->alloc = (void *)((size_t)new + sizeof(t_alloc));
	new->alloc = alloc_init(new->alloc, (size_t)new + get_size_page(new->type));
	return (new);
}

void		*large_alloc(t_page *page, size_t size)
{
	if (!page || !page->alloc)
		return (NULL);
	while (page->alloc->is_alloc)
	{
		if (page->next == NULL)
		{
			if (!(page->next = large_new_page(page->next, size)))
				return (NULL);
		}
		page = page->next;
	}
	page->alloc->size = get_size_align(size);
	page->alloc->is_alloc = 1;
	return (page->alloc->ptr);
}
