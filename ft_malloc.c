/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:37:50 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/09 11:34:48 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

static int  whichType(size_t allocSize)
{
	if (allocSize > SMALL_MAX)
		return (LARGE_TYPE);
	else if (allocSize < SMALL_MIN)
		return (TINY_TYPE);
	else
		return (SMALL_TYPE);
}

void		init_ft_malloc(void)
{
	static int		isInit = 0;

	if (isInit)
		return ;
	g_stock.large = NULL;
	g_stock.small = NULL;
	g_stock.tiny = NULL;
	isInit = 1;
}
// /!\ remplir le tableau en decrémentant

void	*largeAllocation(size_t size)
{
	return (ptr);
}

void	*searchAndMakeAlloc(size_t size, int type)
{
	void	*adr;

	if (type == TINY_TYPE)
		adr = searchInTiny(size, g_stock.tiny);
	else if (type == SMALL_TYPE)
	else
		return (largeAllocation(size));
	if (adr != 0)
		return (adr);
	if (type == TINY_TYPE)
		adr = newTinyArea(size);
	else if (type == SMALL_TYPE)
	return (adr);
}

void 	   *ft_malloc(size_t size)
{
	void	*ptr;

	init_malloc();

	return ();
}