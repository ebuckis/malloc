/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:39:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 16:27:22 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

//enum error free
void	ft_lst_manage(t_tiny * lst)
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

int		search_in_this_page(t_tiny *lst, void *ptr)
{
	int		diff;

	diff = (unsigned long)ptr - (unsigned long)lst->ptr;
	diff /= TINY_MAX;

	if (lst->adr_size[diff] != 0)
	{
		lst->adr_size[diff] = 0;
		lst->nbr_alloc--;
		if (lst->nbr_alloc == 0 && lst != g_stock.tiny)
		{
			/* On free la page et on joue avec la liste chainée */
			munmap(ptr, TINY_SIZE_AREA);
			ft_lst_manage(lst);
		}
		return (1);
	}
	else (/* pas d'alloc a cette adresse */)
	{
		/* gestion de l'erreur */
		return (0)
	}
}

int		ft_free_in_tiny(void *ptr)
{
	t_tiny	*l;
	t_tiny	*tmp;

	if ((unsigned long)ptr % TINY_MAX != 0)
		return (0);
	l = g_stock.tiny;
	tmp = l->next;
	while (l)
	{
		if ((unsigned long)ptr >= (unsigned long)l->ptr &&
			(unsigned long)ptr < (unsigned long)l->ptr + TINY_SIZE_AREA )
		{
			// On se trouve sur la bonne page
			if (!search_in_this_page())
			{
				// pas de pointeur aloué sur cette plage d'adresse
				return (0);
			}
		}

		l = tmp;
		tmp = tmp->next;
	}
	return (1);
}

int		ft_free_in_small(void *ptr)
{
//		ptr % SMALL_MAX != 0
	
}

int		ft_free_in_large(void *ptr)
{
//		ptr % PAGESIZE != 0
	
}

void	ft_free(void *ptr)
{
	//recoit un adress
	//boucle sur tiny
	//boucle sur small
	//boucle sur large
	//retour si error
	ft_free_in_tiny();
	ft_free_in_small();
	ft_free_in_large();
}
