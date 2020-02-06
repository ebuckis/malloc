/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/20 11:42:29 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 14:58:30 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

char 	*bool_print(short val)
{
	if (val)
		return ("Used");
	else
		return ("Free");
}

void	display_list(t_page *tmp_page)
{
	int i;

	i = 1;
	t_alloc	*tmp_alloc;
	while (tmp_page)
	{
		printf("_____________________________________________\n");
		printf("|	Page n%d\n", i);
		printf("|%p - %p|\n", (void *)tmp_page, (void *)((size_t)tmp_page + tmp_page->size));
		printf("_____________________________________________\n");
		tmp_alloc = tmp_page->alloc;
		while (tmp_alloc)
		{
			printf("%p - %p : %zu -> %s\n", tmp_alloc->ptr, (void *)((size_t)tmp_alloc->ptr + tmp_alloc->size), tmp_alloc->size, bool_print(tmp_alloc->is_alloc));
			tmp_alloc = tmp_alloc->next;
		}
		printf("_____________________________________________\n");
		tmp_page = tmp_page->next;
		i++;
	}
}

void	ft_display(void)
{
	printf("********************TINY********************\n");
	display_list(g_stock.tiny);
	printf("********************************************\n\n");
	printf("********************SMALL********************\n");
	display_list(g_stock.small);
	printf("*********************************************\n\n");
	printf("********************LARGE********************\n");
	display_list(g_stock.large);
	printf("*********************************************\n\n");
}
