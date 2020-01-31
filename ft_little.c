/**
HEADER
*/

#include "ft_malloc.h"

t_page	*little_new_page(t_page *new, int type)
{
	//alloc nmap
	new->is_full = 0;
	new->type = type;
	new->next = NULL;
	new->alloc = (t_alloc *)(new + sizeof(t_page));
	if (type == e_tiny_type)
	{
		//arrondi a page size
		new->page->alloc = alloc_init(new->alloc);
	}
	else
	{
		new->size = sizeof(t_page) + (100 * (sizeof(t_alloc) + SMALL_MAX));
		//arrondi a page size
		new->alloc_size = SMALL_MAX;
		new->page->alloc = alloc_init(new->alloc);
	}
	return (new);
}

void	*little_alloc(t_page *page, int type, size_t size)
{
	void	*ptr;

	if (!page)
	{//this case is only for the first page
		page = little_new_page(page, type);
		return (little_alloc(page, type, size));
	}
	else
	{
		ptr = alloc_find_place(page, size);
		if (ptr == NULL)// ->recursive sur page ->next
		{
			page->next = little_new_page(page->next, type);
			return (little_alloc(page->next,type, size));
		}

	}
	return (ptr);
}