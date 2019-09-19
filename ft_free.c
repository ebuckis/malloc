/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:39:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 17:19:59 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"


int		ft_free_in_small(void *ptr)
{
//		ptr % SMALL_MAX != 0
	
}

int		ft_free_in_large(void *ptr)
{
//		ptr % PAGESIZE != 0
	
}

void	ft_free(void *ptr)
{
	//recoit un adress
	//boucle sur tiny
	//boucle sur small
	//boucle sur large
	//retour si error
	ft_free_in_tiny();
	ft_free_in_small();
	ft_free_in_large();
}
