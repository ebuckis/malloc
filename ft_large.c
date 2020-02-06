/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_large.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 13:35:30 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 12:27:12 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

t_page		*large_new_page(t_page *new, size_t size)
{
	printf("start -> %s\n", __func__);
	size_t	total;

	total = get_size_align(size)
		+ get_size_align(sizeof(t_page) + sizeof(t_alloc));
	if (!(new = mmap(NULL, total, MMAP_ARG)))
		return (NULL);
	new->size = total;
	new->type = e_large_type;
	new->next = NULL;
	new->alloc = (t_alloc *)new + sizeof(t_page);
	new->alloc = alloc_init(new->alloc, (size_t)new + get_size_page(new->type));
	return (new);
}

void	*large_alloc(t_page *page, size_t size)
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
