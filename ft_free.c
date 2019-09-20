/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:39:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/20 11:33:47 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

int		ft_free_in_large(void *ptr)
{
//		ptr % PAGESIZE != 0
	return (1);
}

void	ft_free(void *ptr)
{
	//recoit un adress
	//boucle sur tiny
	//boucle sur small
	//boucle sur large
	//retour si error
	ft_free_in_tiny(ptr);
	ft_free_in_small(ptr);
	ft_free_in_large(ptr);
}
