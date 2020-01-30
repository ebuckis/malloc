/**
HEADER
*/

#include "ft_malloc.h"


void	little_new_page(t_page *new, t_page *prev, int type)
{
	//alloc
	new->type = type;
	new->prev = prev;
	new->next = NULL;
	new->alloc = (void *)(new + sizeof(t_page));
	if (type == e_tiny_type)
		new->size = sizeof(t_page) + (100 * (sizeof(t_alloc) + TINY_MAX));
		//arrondi a page size
	else
		new->size = sizeof(t_page) + (100 * (sizeof(t_alloc) + SMALL_MAX));
		//arrondi a page size
	return (new);
}

void	*little_alloc(t_page *page, int type)
{
	void	*ptr;

	if (!page)
	{//this case is only for the first page
		page = little_new_page(page, NULL, type);
		return (little_alloc(page, type));
	}
	else
	{
		ptr = little_find_place(page, type);
		if (ptr == NULL)// ->recursive sur page ->next
		{
			page = little_new_page(page->next, page, type);
		}

	}
	return (ptr);
}