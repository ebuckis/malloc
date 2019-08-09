/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tiny.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 18:32:04 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/09 09:17:18 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*fill_tiny_table(t_tiny *lst, size_t i, size_t size)
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

void	*search_place_in_tiny(size_t size, t_tiny lst)
{
	size_t		i;
	size_t		j;

	if (lst = NULL)
		return ((void *)0);
	i = (size - ((long)lst->ptr % size));/* On va sur une adresse pour l'alignement des variables */
	while (i < tiny_MAX)
	{
		if (lst->adrSize[i] == 0)/* si la case est vide */
		{
			j = 0;
			while (j + i < tiny_MAX && lst->adrSize[i + j] == 0)/* On verifie qu'on a la place */
				j++;
			if (j < size || j + i >= tiny_MAX)
				i += j;
			else
				return (fill_tiny_table(lst, i, size));
		}
		else /* Cas ou on a une size */
			i += lst->adrSize[i];
		i = (size - (((long)lst->ptr + i) % size));//verifier la valeur de i
	}
	return (search_place_in_tiny(size, lst->next));
}

void	*new_tiny_area()
{

}

void    *ft_tiny(size_t size)
{
	void    *adr;

	adr = search_place_in_tiny(size, g_stock.tiny);
	if (adr != 0)
		return (adr);
	else
		adr = new_tiny_area(size);
	

}
