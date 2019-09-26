/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_small.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/26 15:07:43 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/26 15:07:46 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

static int	ft_other_lst(void)
{
	t_small	*new;

	if (!g_stock.small)
		return (0);
	if (g_stock.small->next)
		return (1);
	return (0);
}

static void	ft_lst_manage(t_small *lst)
{
	t_small	*prev;
	t_small	*post;

	if (lst == g_stock.small)
	{
		post = g_stock.small->next;
		munmap(g_stock.small, sizeof(t_small *));
		g_stock.small = post;
	}
	else
	{
		prev = g_stock.small;
		while (prev->next != lst)
			prev = prev->next;
		post = lst->next;
		munmap(lst, sizeof(t_small *));
		prev->next = post;
	}
}

static int	search_in_this_page(t_small *lst, void *ptr)
{
	int		diff;

	diff = (unsigned long)ptr - (unsigned long)lst->ptr;
	diff /= SMALL_MAX;
	if (diff <= NB_SMALL && lst->adr_size[diff] != 0)
	{
		lst->adr_size[diff] = 0;
		lst->nbr_alloc--;
		if (lst->nbr_alloc == 0 && ft_other_lst())
		{
			munmap(ptr, SMALL_SIZE_AREA);
			ft_lst_manage(lst);
		}
		return (1);
	}
	return (0);
}

int			ft_free_in_small(void *ptr)
{
	t_small	*l;
	t_small	*tmp;

	if (!g_stock.small || (unsigned long)ptr % SMALL_MAX != 0)
		return (0);
	l = g_stock.small;
	while (l)
	{
		if ((unsigned long)ptr >= (unsigned long)l->ptr &&
			(unsigned long)ptr < (unsigned long)l->ptr + SMALL_SIZE_AREA)
		{
			return (search_in_this_page(l, ptr));
		}
		l = l->next;
	}
	return (0);
}
