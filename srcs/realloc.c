/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   realloc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 14:32:08 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 15:04:02 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "malloc.h"

int				try_to_expand(t_page *page, t_alloc *alloc, size_t new_size)
{
	size_t		last_size;
	size_t		total;
	t_alloc		*tmp;

	last_size = alloc->size;
	if (get_size_align(new_size) == last_size)//error ?
		return (1);
	if ((size_t)alloc->ptr
		+ get_size_align(new_size) > (size_t)page + page->size)
		return (0);
	alloc->is_alloc = 0;
	tmp = alloc->next;
	total = last_size;
	while (tmp && total < get_size_align(new_size))
	{
		if (tmp->is_alloc)
			return (0);
		total += tmp->size + sizeof(t_alloc);
		tmp = tmp->next;
	}
	alloc->is_alloc = 1;
	alloc->size = get_size_align(new_size);
	alloc->next = tmp;
	return (1);
}

static int		verif_type(size_t size, int type)
{
	int			new_type;

	if (get_size_align(size) + sizeof(t_page) <= TINY_MAX)
		new_type = e_tiny_type;
	else if (get_size_align(size) + sizeof(t_page) <= SMALL_MAX)
		new_type = e_small_type;
	else
		new_type = e_large_type;
	return (new_type == type);
}

static t_page	*find_ptr(void *ptr, t_alloc **al, t_page *tmp)
{
	while (tmp)
	{
		if (ptr >= (void *)tmp && ptr <= (void *)((size_t)tmp + tmp->size))
		{
			*al = tmp->alloc;
			while (*al)
			{
				if ((*al)->ptr == ptr)
					return (tmp);
				*al = (*al)->next;
			}
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int				find_alloc_ptr(void *ptr, t_alloc **al, t_page **page)
{
	if ((*page = find_ptr(ptr, al, g_stock.tiny))
		|| (*page = find_ptr(ptr, al, g_stock.small))
		|| (*page = find_ptr(ptr, al, g_stock.large)))
		return (1);
	return (0);
}

void			*realloc(void *ptr, size_t new_size)
{
	t_page		*page;
	t_alloc		*alloc;
	void		*new;
	size_t		i;

	i = 0;
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size < 1
		|| new_size >= 0xFFFFFFFFFFFFFFFF - (sizeof(t_page) + sizeof(t_alloc))
		|| !find_alloc_ptr(ptr, &alloc, &page))
		return (NULL);
	if (verif_type(new_size, page->type)
		&& try_to_expand(page, alloc, new_size))
		return (ptr);
	new = malloc(new_size);
	while (new && i < new_size && i < alloc->size)
	{
		((char *)new)[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (new);
}
