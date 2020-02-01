/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_alloc.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 10:46:30 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 11:35:06 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

t_alloc		*alloc_init(t_alloc *new)
{
	new->is_alloc = 0;
	new->next = NULL;
	new->ptr = (void *)new + sizeof(t_alloc);
	return (new);
}

void	*alloc_find_place(t_page *page, size_t size)
{
	t_alloc	*tmp;
	size_t	last_address;

	tmp = page->alloc;
	while (tmp->is_alloc)
	{
		if (tmp->next == NULL)
		{
			last_address = (size_t)tmp->ptr + tmp->size + sizeof(t_alloc) + get_size_align(size);//improve this calcul with a new alloc size
			if (last_address >= (size_t)page + get_size_page(page->type))
			{
				printf("on arrive a la fin de la page dans %s\n", __func__);
				return (NULL);
			}
			tmp->next = tmp->ptr + tmp->size;
			tmp->next = alloc_init(tmp->next);
		}
		tmp = tmp->next;
	}
	tmp->size = get_size_align(size);
	tmp->is_alloc = 1;
	return (tmp->ptr);
}
