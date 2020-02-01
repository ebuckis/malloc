/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_little.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 13:38:22 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 12:41:45 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

t_page	*little_new_page(t_page *new, int type)
{
	printf("start -> %s\n", __func__);
	//TODO: alloc nmap 
	if (!(new = mmap(NULL, get_size_page(type), MMAP_ARG)))
		return (NULL);
	new->type = type;
	new->next = NULL;
	new->alloc = (t_alloc *)new + sizeof(t_page);
	new->alloc = alloc_init(new->alloc, (size_t)new + get_size_page(new->type));
	return (new);
}

void	*little_alloc(t_page *page, int type, size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (!page)
		return (NULL);
	ptr = alloc_find_place(page, size);
	if (ptr == NULL)// ->recursive sur page ->next
	{
		if (page->next == NULL)
		{
			printf("Plus de place, nouvelle page\n");
			if (!(page->next = little_new_page(page->next, type)))
				return (NULL);
		}
		return (little_alloc(page->next, type, size));
	}
	return (ptr);
}
