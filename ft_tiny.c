/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tiny.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/09 11:24:07 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/09 16:32:07 by kcabus      ###    #+. /#+    ###.fr     */
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
		lst->adr_size[i + lenght] = size - lenght;
		lenght++;
	}
	return ((void *)(lst->ptr + i));
}

void		*search_place_in_tiny(size_t size, t_tiny *lst)
{
	size_t	i;
	size_t	j;

	if (lst == NULL)
		return ((void *)0);
	i = 0;//hypothese : adresse page % 4096 == 0
	while (i < TINY_MAX)
	{
		if (lst->adr_size[i] == 0)/* si la case est vide */
		{
			j = 0;
			while (j + i < TINY_MAX && lst->adr_size[i + j] == 0)/* On verifie qu'on a la place */
				j++;
			if (j >= size || j + i >= TINY_MAX)
				i = i + go_to_align_pos(j);
			else
				return (fill_tiny_table(lst, i, size));
		}
		else /* Cas ou on a une size */
			i = i + go_to_align_pos(lst->adr_size[i]);
	}
	return (search_place_in_tiny(size, lst->next));
}

void		*new_tiny_area(size_t size)
{
	int		check;
	t_tiny	*new;
	t_tiny	*tmp;

	if ((new = g_stock.tiny) == NULL)
		tmp = new;
	else
	{
		while (new)
		{
			tmp = new;
			new = new->next;
		}
	}
	check = (tmp == g_stock.tiny);
	if ((new = (t_tiny *)mmap(MMAP_ARG(sizeof(t_tiny)))) == (void *)-1)
		return ((void *)-1);
	printf("adress next : %ld\n", (long)new);
	printf("c'est bon\n");
	if (check)
		g_stock.tiny = new;
	else
		tmp->next = new;
	if ((new->ptr = mmap(MMAP_ARG(size))) == (void *)-1)
		return ((void *)-1);
	printf("c'est bon\n");
	new->next = NULL;
	
	printf("------------------++%ld\n", (long)TINY_SIZE_AREA);
	printf("------------------++%ld\n", (long)SMALL_SIZE_AREA);
	check = 0;
	while (check < size)
		new->adr_size[check++] = 0;

	printf("c'est bon 2\n");
	return (fill_tiny_table(new, 0, size));
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
