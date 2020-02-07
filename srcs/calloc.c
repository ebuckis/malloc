/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calloc.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 14:39:36 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 14:42:41 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "malloc.h"

void	*calloc(size_t number, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(number * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < number * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
