/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_tiny.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/26 15:08:12 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/26 15:13:05 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

static int	ft_other_lst(void)
{
	t_tiny	*new;

	if (!g_stock.tiny)
		return (0);
	if (g_stock.tiny->next)
		return (1);
	return (0);
}

static void	ft_lst_manage(t_tiny *lst)
{
	t_tiny	*prev;
	t_tiny	*post;

	if (lst == g_stock.tiny)
	{
		post = g_stock.tiny->next;
		munmap(g_stock.tiny, sizeof(t_tiny *));
		g_stock.tiny = post;
	}
	else
	{
		prev = g_stock.tiny;
		while (prev->next != lst)
			prev = prev->next;
		post = lst->next;
		munmap(lst, sizeof(t_tiny *));
		prev->next = post;
	}
}

static int	search_in_this_page(t_tiny *lst, void *ptr)
{
	int		diff;

	diff = (unsigned long)ptr - (unsigned long)lst->ptr;
	diff /= TINY_MAX;
	if (diff <= NB_TINY && lst->adr_size[diff] != 0)
	{
		lst->adr_size[diff] = 0;
		lst->nbr_alloc--;
		if (lst->nbr_alloc == 0 && ft_other_lst())
		{
			munmap(ptr, TINY_SIZE_AREA);
			ft_lst_manage(lst);
		}
		return (1);
	}
	return (0);
}

int			ft_free_in_tiny(void *ptr)
{
	t_tiny	*l;
	t_tiny	*tmp;

	if (!g_stock.tiny || (unsigned long)ptr % TINY_MAX != 0)
		return (0);
	l = g_stock.tiny;
	while (l)
	{
		if ((unsigned long)ptr >= (unsigned long)l->ptr &&
			(unsigned long)ptr < (unsigned long)l->ptr + TINY_SIZE_AREA)
		{
			return (search_in_this_page(l, ptr));
		}
		l = l->next;
	}
	return (0);
}
