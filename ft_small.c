/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_small.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 18:32:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 15:44:01 by kcabus      ###    #+. /#+    ###.fr     */
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
	printf("search place\n");
	size_t	i;
	size_t	j;

	if (lst == NULL)
		return ((void *)0);
	i = 0;//hypothese : adresse page % 4096 == 0
	while (i < SMALL_MAX)
	{
		if (lst->adr_size[i] == 0)/* si la case est vide */
		{
			lst->adr_size[i] = size;
			return ((void *)(lst->ptr + i));
		}
		else	/* Cas ou on a une size */
			i += SMALL_MAX;
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
	check = (tmp == g_stock.small);	//sion se trouve sur le premier maillon
	if (( new = (t_small *)mmap( MMAP_ARG(sizeof(t_small)) ) ) == (void *)-1)//allocation du maillon
		return ((void *)-1);
	printf("adress next : %ld\n", (long)new);
	printf("c'est bon\n");
	if (check)
		g_stock.small = new;			//adressage du premier maillon
	else
		tmp->next = new;			//adressage autre maillon
	if ((new->ptr = mmap(MMAP_ARG(SMALL_SIZE_AREA))) == (void *)-1)	//allocation de l'aire
		return ((void *)-1);
	printf("c'est bon\n");
	new->next = NULL;				//dernier a null
	
	printf("------------------++%ld\n", (long)SMALL_SIZE_AREA);
	check = 0;					//utilisation de check comme incrémentation
	while (check < NB_SMALL)		//peut etre remplacé par bzero
		new->adr_size[check++] = 0;//remplissage du tableau de 0

	printf("c'est bon 2\n");
	return (fill_small_table(new, 0, size));//retourne l'adresse de l'aire
}

void		*ft_small(size_t size)
{
	printf("SMALL\n");
	void	*adr;
	void	*new;

	adr = search_place_in_small(size, g_stock.small);
	if (adr == 0)
		adr = new_small_area(size);
	return (adr);
}
