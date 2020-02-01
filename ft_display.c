/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/20 11:42:29 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 14:55:04 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

char 	*bool_print(short val)
{
	if (val)
		return ("true");
	else
		return ("false");
}

void	ft_display(void)
{
	int i, j;
	t_page	*tmp_page;
	t_alloc	*tmp_alloc;

	i = 1;
	tmp_page = g_stock.tiny;
	printf("********************TINY********************\n");
	while (tmp_page)
	{
		printf("__________________________\n");
		printf("|       page n%d\n", i);
		printf("__________________________\n");
		tmp_alloc = tmp_page->alloc;
		while (tmp_alloc)
		{
			printf("+------------------------------------------------\n");
			printf("|	Block address		: %p\n", tmp_alloc->ptr);
			printf("|	Block size		: %d\n", tmp_alloc->size);
			printf("|	This block is used	: %s\n", bool_print(tmp_alloc->is_alloc));
			printf("+------------------------------------------------\n");

			tmp_alloc = tmp_alloc->next;
		}
		tmp_page = tmp_page->next;
		i++;
	}
	printf("********************************************\n\n");


//	tmp_page = g_stock.small;
//	tmp_page = g_stock.large;


}
