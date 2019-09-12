/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tiny.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/09 11:24:07 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 11:51:58 by kcabus      ###    #+. /#+    ###.fr     */
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
	printf("search place\n");
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
			while (j < size && j + i < TINY_MAX && lst->adr_size[i + j] == 0)/* On verifie qu'on a la place */
				j++;
			if (j < size || j + i >= TINY_MAX)
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
	check = (tmp == g_stock.tiny);	//sion se trouve sur le premier maillon
	if (( new = (t_tiny *)mmap( MMAP_ARG(sizeof(t_tiny)) ) ) == (void *)-1)//allocation du maillon
		return ((void *)-1);
	printf("adress next : %ld\n", (long)new);
	printf("c'est bon\n");
	if (check)
		g_stock.tiny = new;			//adressage du premier maillon
	else
		tmp->next = new;			//adressage autre maillon
	if ((new->ptr = mmap(MMAP_ARG(TINY_SIZE_AREA))) == (void *)-1)	//allocation de l'aire
		return ((void *)-1);
	printf("c'est bon\n");
	new->next = NULL;				//dernier a null
	
	printf("------------------++%ld\n", (long)TINY_SIZE_AREA);
	check = 0;					//utilisation de check comme incrémentation
	while (check < size)		//peut etre remplacé par bzero
		new->adr_size[check++] = 0;//remplissage du tableau de 0

	printf("c'est bon 2\n");
	return (fill_tiny_table(new, 0, size));//retourne l'adresse de l'aire
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
