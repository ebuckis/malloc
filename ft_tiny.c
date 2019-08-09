/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tiny.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 18:32:04 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 18:49:21 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*searchPlaceInTiny(size_t size, t_tiny *lst)
{
	size_t		i;
	size_t		j;

	if (lst = NULL)
		return ((void *)0);
	/* On va sur une adresse pour l'alignement des variables */
	i = (size - ((long)lst->ptr % size));
	while(i < TINY_MAX)
	{
		if (lst->adrSize[i] == 0)/* si la case est vide */
		{
			j = 0;
			while (j + i < SMALL_MAX && lst->adrSize[i + j] == 0)/* On verifie qu'on a la place */
				j++;
			if (j < size || j + i >= SMALL_MAX)
				i += j;
			else
				return ((void *)(lst->ptr + i));
		}
		else /* Cas ou on a une size */
			i += lst->adrSize[i];
		/* On va sur une adresse pour l'alignement des variables */
		i = (size - (((long)lst->ptr + i) % size));//verifier la valeur de i
	}
	return (searchPlaceInTiny(size, lst->next));
}

void	*newTinyArea()
{

}
