/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_small.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 18:32:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/09 16:25:50 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*fill_small_table(t_small *lst, size_t i, size_t size)
{
	size_t	lenght;

	lenght = 0;
	while (lenght < size)
	{
		lst->adr_size[i + lenght] = size - lenght;
		lenght++;
	}
	return ((void *)(lst->ptr + i));
}

void		*search_place_in_small(size_t size, t_small *lst)
{
	size_t	i;
	size_t	j;

	if (lst == NULL)
		return ((void *)0);
	i = 0;//hypothese : adresse page % 4096 == 0
	while (i < SMALL_MAX)
	{
		if (lst->adr_size[i] == 0)/* si la case est vide */
		{
			j = 0;
			while (j + i < SMALL_MAX && lst->adr_size[i + j] == 0)/* On verifie qu'on a la place */
				j++;
			if (j >= size || j + i >= SMALL_MAX)
				i = i + go_to_align_pos(j);
			else
				return (fill_small_table(lst, i, size));
		}
		else /* Cas ou on a une size */
			i = i + go_to_align_pos(lst->adr_size[i]);
	}
	return (search_place_in_small(size, lst->next));
}

void		*new_small_area(size_t size)
{
	int		check;
	t_small	*new;
	t_small	*tmp;

	if ((new = g_stock.small) == NULL)
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
	if ((new = mmap(MMAP_ARG(sizeof(t_small)))) == (void *)-1)
		return ((void *)-1);
	if (check)
		g_stock.small = new;
	else
		tmp->next = new;
	new->next = NULL;
	if ((new->ptr = mmap(MMAP_ARG(size))) == (void *)-1)
		return ((void *)-1);

	check = 0;
	printf("------------------++%ld\n", (long)SMALL_SIZE_AREA);
	while (check < size)
		new->adr_size[check++] = 0;

	return (fill_small_table(new, 0, size));
}

void		*ft_small(size_t size)
{
	void	*adr;
	void	*new;

	adr = search_place_in_small(size, g_stock.small);
	if (adr == 0)
		adr = new_small_area(size);
	return (adr);
}
