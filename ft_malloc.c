/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:37:50 by kcabus       #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2019/09/12 13:06:55 by kcabus      ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2019/09/12 13:05:34 by kcabus      ###    #+. /#+    ###.fr     */
>>>>>>> kevin
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

/*
**	go to the right address
*/

size_t		go_to_align_pos(size_t add)
{
	size_t	res;

	res = add % ALIGN_POS;
	res = (res == 0) ? add : add + ALIGN_POS - res;
	return (res);
}

/*
** Define the type of allocation
*/

static int	which_type(size_t alloc_size)
{
	if (alloc_size > SMALL_MAX)
		return (LARGE_TYPE);
	else if (alloc_size < SMALL_MIN)
		return (TINY_TYPE);
	else
		return (SMALL_TYPE);
}

/*
**	initialisation of 3 structures
*/

void		init_ft_malloc(void)
{
	static int		is_init = 0;

	if (is_init)
		return ;
	g_stock.large = NULL;
	g_stock.small = NULL;
	g_stock.tiny = NULL;
	is_init = 1;
}

/*
**	Redirect in function of size and type
*/

void		*search_and_make_alloc(size_t size, int type)
{
	void	*adr;

	if (type == TINY_TYPE)
		adr = ft_tiny(size);
	else if (type == SMALL_TYPE)
		adr = ft_small(size);
	else
		adr = ft_large(size);
	if (adr == (void *)-1)
		return (NULL);
	return (adr);
}

/*
**	init struct
**	detect the type of element
**	return adress
*/

void		*ft_malloc(size_t size)
{
	int		type;

	if (size == 0)
		return (NULL);
	init_ft_malloc();
	type = which_type(size);
	printf("size : %d et type : %d\n", size, type);
	return (search_and_make_alloc(size, type));
}
