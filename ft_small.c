/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_small.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 18:32:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 18:49:21 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*fillSmallTable(t_small *lst, size_t i, size_t size)
{
	lst->
	return ();
}

void	*searchPlaceInSmall(size_t size)
{
	size_t		i;
	size_t		j;

	if (lst = NULL)
		return ((void *)0);
	i = (size - ((long)lst->ptr % size));/* On va sur une adresse pour l'alignement des variables */
	while(i < SMALL_MAX)
	{
		if (lst->adrSize[i] == 0)/* si la case est vide */
		{
			j = 0;
			while (j + i < SMALL_MAX && lst->adrSize[i + j] == 0)/* On verifie qu'on a la place */
				j++;
			if (j < size || j + i >= SMALL_MAX)
				i += j;
			else
			{
				return (fillSmallTable(lst, i, size));
				//return ((void *)(lst->ptr + i));
			}
		}
		else /* Cas ou on a une size */
			i += lst->adrSize[i];
		i = (size - (((long)lst->ptr + i) % size));//verifier la valeur de i
	}
	return (searchPlaceInSmall(size, lst->next));
}

void	*newSmallArea()
{

}

void    *ft_small(size_t size)
{
	void    *adr;

	adr = searchPlaceInSmall(size);
	if (adr != 0)
		return (adr);
	else
		adr = newSmallArea(size);
	

}