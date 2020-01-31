/*
HEADER
*/

#include "ft_malloc.h"

t_alloc		*alloc_init(t_alloc *new)
{
	new->is_alloc = 0;
	new->size = 0;//or 
	new->next = NULL;
	new->ptr = (void *)(new + sizeof(t_alloc));
	return (new);
}

void	*alloc_find_place(t_page *page, size_t size)
{
	t_alloc	*tmp;

	if (page->is_full == 1)
		return (NULL);
	tmp = page->alloc;
	while (tmp->is_alloc)
	{
		if (tmp->next == NULL && (tmp->ptr + tmp->size) > (page + get_size_page(page->type)))//improve this calcul with a new alloc size
			return (NULL);
		if (tmp->next == NULL)
			tmp->next = alloc_init(tmp->next);
		tmp = tmp->next;
	}
	tmp->size += get_size_allign(size);
	tmp->is_alloc = 1;
	return (tmp->ptr);
}
