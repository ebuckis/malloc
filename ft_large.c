/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_large.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/09 13:20:00 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 17:26:15 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*ft_large(size_t size)
{
	int		check;
	t_large	*new;
	t_large	*tmp;

	if ((new = g_stock.large) == NULL)
		tmp = new;
	else
	{
		while (new)
		{
			tmp = new;
			new = new->next;
		}
	}
	check = (tmp == new);
	if ((new = mmap(MMAP_ARG(sizeof(t_large)))) == (void *)-1)
		return ((void *)-1);
	if (check)
		g_stock.large = new;
	else
		tmp->next = new;
	new->next = NULL;
	if ((new->ptr = mmap(MMAP_ARG(size))) == (void *)-1)
		return ((void *)-1);
	new->size = size;
	return ((void *)new->ptr);
}
