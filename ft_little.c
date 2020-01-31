/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_little.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 13:38:22 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 13:56:16 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_page	*little_new_page(t_page *new, int type)
{
	//TODO: alloc nmap 
	if (!(new = mmap(NULL, get_size_page(type), MMAP_ARG)))
		return (NULL);
	new->type = type;
	new->next = NULL;
	new->alloc = (t_alloc *)(new + sizeof(t_page));
	if (type == e_tiny_type)
	{
		new->alloc = alloc_init(new->alloc);
	}
	else
	{
		new->alloc = alloc_init(new->alloc);
	}
	return (new);
}

void	*little_alloc(t_page *page, int type, size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (!page)
	{//this case is only for the first page
		if (!(page = little_new_page(page, type)))
			return (NULL);
		return (little_alloc(page, type, size));
	}
	else
	{
		ptr = alloc_find_place(page, size);
		if (ptr == NULL)// ->recursive sur page ->next
		{
			if (!(page->next = little_new_page(page->next, type)))
				return (NULL);
			return (little_alloc(page->next, type, size));
		}
	}
	return (ptr);
}