/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/20 11:42:29 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/26 11:16:16 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_display(void)
{
	int i, j;
	t_tiny *tiny_lst;
	t_small *small_lst;
	t_large *large_lst;

	i = 1;
	printf("********TINY********\n");
	tiny_lst = g_stock.tiny;
	while (tiny_lst)
	{
		printf("Maillon [%d] Nombre d'allocation : %d\n", i, tiny_lst->nbr_alloc);
		j = 0;
		while (j < NB_TINY)
		{
			printf("adr_tab[%d] = %d\n", j, tiny_lst->adr_size[j]);
			j++;
		}
		tiny_lst = tiny_lst->next;
		i++;
	}
	printf("********************\n\n");

	i = 1;
	printf("********SMALL********\n");
	small_lst = g_stock.small;
	while (small_lst)
	{
		printf("Maillon [%d] Nombre d'allocation : %d\n", i, small_lst->nbr_alloc);
		j = 0;
		while (j < NB_SMALL)
		{
			printf("adr_tab[%d] = %d\n", j, small_lst->adr_size[j]);
			j++;
		}
		small_lst = small_lst->next;
		i++;
	}
	printf("********************\n\n");



}
