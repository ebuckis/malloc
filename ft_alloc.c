/*
HEADER
*/

#include "ft_malloc.h"

t_alloc		*alloc_init(t_alloc *new)
{
	printf("start -> %s\n", __func__);
	new->is_alloc = 0;
	new->size = sizeof(t_alloc);//or 
	new->next = NULL;
	new->ptr = (void *)new + sizeof(t_alloc);
	printf("ptr(%p) = %p + 0x%lx\n",new->ptr, new, sizeof(t_alloc));
	return (new);
}

void	*alloc_find_place(t_page *page, size_t size)
{
	printf("start -> %s\n", __func__);
	t_alloc	*tmp;

	tmp = page->alloc;
	while (tmp->is_alloc)
	{
		if (tmp->next == NULL && (long)(tmp->ptr + tmp->size) > (long)(page + get_size_page(page->type)))//improve this calcul with a new alloc size
			return (NULL);
		if (tmp->next == NULL)
		{
			tmp->next = tmp + tmp->size;
			printf("next = %p + 0x%lx\n", tmp, tmp->size);
			tmp->next = alloc_init(tmp->next);
		}
		tmp = tmp->next;
	}
	printf("SIZE = 0x%lx\n", size);
	tmp->size = get_size_alloc(page->type) + get_size_align(size);
	tmp->is_alloc = 1;
	return (tmp->ptr);
}
