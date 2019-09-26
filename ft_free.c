/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:39:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/26 15:19:54 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_free(void *ptr)
{
	int i;

	if (ptr != NULL)
	{
		i = ft_free_in_tiny(ptr);
		if (i == 0)
			i = ft_free_in_small(ptr);
		if (i == 0)
			i = ft_free_in_large(ptr);
		//else
		/* gestion d'erreur
			1 -> i == 0 pas de ptr 
			2 -> i == -1 error
			*/
	}
}
