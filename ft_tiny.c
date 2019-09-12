/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tiny.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/09 11:24:07 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 16:57:12 by kcabus      ###    #+. /#+    ###.fr     */
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
	j = 0;
	while (i < TINY_SIZE_AREA)
	{
		if (lst->adr_size[j] == 0)/* si la case est vide */
		{
			printf("adresse + %d \n", i);
			lst->adr_size[j] = size;
			return ((void *)(lst->ptr + i));
		}
		i += TINY_MAX;
		j++;
	}
	return (search_place_in_tiny(size, lst->next));
}

void		*new_tiny_area(size_t size)
{
	int		check;
	t_tiny	*new;
	t_tiny	*tmp;

//on va sur le dernier maillon
	printf("new area\n");
	if ((new = g_stock.tiny) == NULL)//si rien n'est alloué
		tmp = new;
	else
	{
		while (new)
		{
			tmp = new;
			new = new->next;
		}
	}
	check = (tmp == g_stock.tiny);		//sion se trouve sur le premier maillon
	if (( new = (t_tiny *)mmap( MMAP_ARG(sizeof(t_tiny)) ) ) == (void *)-1)//allocation du maillon
		return ((void *)-1);
	if (check)
		g_stock.tiny = new;			//adressage du premier maillon
	else
		tmp->next = new;				//adressage autre maillon
	if ((new->ptr = mmap(MMAP_ARG(TINY_SIZE_AREA))) == (void *)-1)	//allocation de l'aire
		return ((void *)-1);
	new->next = NULL;					//dernier a null
	check = 0;							//utilisation de check comme incrémentation
	while (check < NB_TINY)			//peut etre remplacé par bzero
		new->adr_size[check++] = 0;		//remplissage du tableau de 0
	new->adr_size[0] = size;
	return ((void *)(new->ptr));
}

void		*ft_tiny(size_t size)
{
	printf("TINY\n");
	void	*adr;
	void	*new;

	adr = search_place_in_tiny(size, g_stock.tiny);
	if (adr == 0)
		adr = new_tiny_area(size);
	return (adr);
}