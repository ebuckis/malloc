/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_small.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 18:32:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/20 12:19:34 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*search_place_in_small(size_t size, t_small *lst)
{
	size_t	i;
	size_t	j;

	if (lst == NULL)
		return ((void *)0);
	i = 0;//hypothese : adresse page % 4096 == 0
	j = 0;
	while (i < SMALL_SIZE_AREA)
	{
		if (lst->adr_size[j] == 0)/* si la case est vide */
		{
			printf("adresse + %zu \n", i);
			lst->adr_size[j] = size;
			lst->nbr_alloc++;
			return ((void *)(lst->ptr + i));
		}
		i += SMALL_MAX;
		j++;
	}
	return (search_place_in_small(size, lst->next));
}

void		*new_small_area(size_t size)
{
	int		check;
	t_small	*new;
	t_small	*tmp;

//on va sur le dernier maillon
	printf("new area\n");
	if ((new = g_stock.small) == NULL)//si rien n'est alloué
		tmp = new;
	else
	{
		while (new)
		{
			tmp = new;
			new = new->next;
		}
	}
	if (( new = (t_small *)mmap( MMAP_ARG(sizeof(t_small)) ) ) == (void *)-1)//allocation du maillon
		return ((void *)-1);
	if (g_stock.small == NULL)		//sion se trouve sur le premier maillon
		g_stock.small = new;			//adressage du premier maillon
	else
		tmp->next = new;				//adressage autre maillon
	if ((new->ptr = mmap(MMAP_ARG(SMALL_SIZE_AREA))) == (void *)-1)	//allocation de l'aire
		return ((void *)-1);
	new->next = NULL;					//dernier a null
	new->nbr_alloc = 0;
	check = 0;							//utilisation de check comme incrémentation
	while (check < NB_SMALL)			//peut etre remplacé par bzero
		new->adr_size[check++] = 0;		//remplissage du tableau de 0
	new->adr_size[0] = size;
	new->nbr_alloc++;
	return ((void *)(new->ptr));
}

void		*ft_small(size_t size)
{
	printf("SMALL\n");
	void	*adr;

	adr = search_place_in_small(size, g_stock.small);
	if (adr == 0)
		adr = new_small_area(size);
	return (adr);
}
