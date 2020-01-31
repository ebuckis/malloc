/*
HEADER
*/

#include "ft_malloc.h"

void	*alloc_init(t_alloc *new);
{
	new->is_alloc = 0;
	new->size = 0;
	new->new = NULL;
	new->ptr = new + sizeof(t_alloc);
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
		//verif depassement de la memoire
		//return (NULL);
		if (tmp->next == NULL)
			tmp->next = alloc_init(tmp->next);
		tmp = tmp->next;
	}
	tmp->size = size;
	tmp->is_alloc = 1;
	return (tmp->next);

	
}