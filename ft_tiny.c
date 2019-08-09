/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tiny.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/09 11:24:07 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/09 11:53:06 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*fill_tiny_table(t_tiny *lst, size_t i, size_t size)
{
	size_t	lenght;

	lenght = 0;
	while (lenght < size)
	{
		lst->adrSize[i + lenght] = size - lenght;
		lenght++;
	}
	return ((void *)(lst->ptr + i));
}

size_t			go_to_align_pos(size_t add)
{
	size_t	result;

	result = add % ALIGN_POS;
	result = (result == 0) ? add : add + ALIGN_POS - result;
	return (result);
}

void		*search_place_in_tiny(size_t size, t_tiny lst)
{
	size_t	i;
	size_t	j;

	if (lst = NULL)
		return ((void *)0);
	i = 0;//hypothese : adresse page % 4096 == 0
	while (i < tiny_MAX)
	{
		if (lst->adrSize[i] == 0)/* si la case est vide */
		{
			j = 0;
			while (j + i < TINY_MAX && lst->adrSize[i + j] == 0)/* On verifie qu'on a la place */
				j++;
			if (j >= size || j + i >= TINY_MAX)
				i = i + go_to_align_pos(j);
			else
				return (fill_tiny_table(lst, i, size));
		}
		else /* Cas ou on a une size */
			i = i + go_to_align_pos(lst->adrSize[i]);
	}
	return (search_place_in_tiny(size, lst->next));
}

void		*new_tiny_area(size_t size)
{
	t_tiny	*new;
	t_tiny	*tmp;

	if ((new = g_stock.tiny) == NULL)
		tmp = new;
	else
	{
		while (new)
		{
			tmp = new;
			new = new->next
		}
	}
	check = (tmp == new);
	new = ();//new alloc
	if (check)
		g_stock.tiny = new;
	else
		tmp->next = new;
	new->next = NULL;
	//new->ptr = mmap();
	return (fill_tiny_table(new, 0, size));
		//mmap(NULL, size, PROT_READ | PROT_WRITE,  MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void		*ft_tiny(size_t size)
{
	void	*adr;
	void	*new;

	adr = search_place_in_tiny(size, g_stock.tiny);
	if (adr == 0)
		adr = new_tiny_area(size);
	return (adr);
}
