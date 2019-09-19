/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_small.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 18:32:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 10:40:19 by kcabus      ###    #+. /#+    ###.fr     */
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
	j = 0;
	while (i < SMALL_SIZE_AREA)
	{
		if (lst->adr_size[j] == 0)/* si la case est vide */
		{
			printf("adresse + %d \n", i);
			lst->adr_size[j] = size;
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
	check = (tmp == g_stock.small);		//sion se trouve sur le premier maillon
	if (( new = (t_small *)mmap( MMAP_ARG(sizeof(t_small)) ) ) == (void *)-1)//allocation du maillon
		return ((void *)-1);
	if (check)
		g_stock.small = new;			//adressage du premier maillon
	else
		tmp->next = new;				//adressage autre maillon
	if ((new->ptr = mmap(MMAP_ARG(SMALL_SIZE_AREA))) == (void *)-1)	//allocation de l'aire
		return ((void *)-1);
	new->next = NULL;					//dernier a null
	check = 0;							//utilisation de check comme incrémentation
	while (check < NB_SMALL)			//peut etre remplacé par bzero
		new->adr_size[check++] = 0;		//remplissage du tableau de 0
	new->adr_size[0] = size;
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
