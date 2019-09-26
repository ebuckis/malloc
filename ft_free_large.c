/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_large.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/20 16:42:09 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/26 14:55:49 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

int		ft_free_in_large(void *ptr)
{
	t_large *lst;
	t_large *prev;

	if ((lst = g_stock.large) == NULL)
		return (0);
	prev = NULL;
	while (lst)
	{
		if (lst->ptr == ptr)
		{
			munmap(lst->ptr, lst->size);
			if (prev)
				prev->next = lst->next;
			else
				g_stock.large = lst->next;
			munmap(lst, sizeof(t_large));
			return (1);
		}
		prev = lst;
		lst = lst->next;
	}
	return (0);
}
