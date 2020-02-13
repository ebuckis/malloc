/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/20 11:42:29 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 15:04:46 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "malloc.h"

static void		ft_print_alloc(t_alloc *tmp)
{
	if (!tmp)
		return ;
	ft_putaddress((size_t)tmp->ptr);
	ft_putstr(" - ");
	ft_putaddress((size_t)tmp->ptr + tmp->size);
	ft_putstr(" : ");
	ft_putnb(tmp->size);
	ft_putstr(" octets\n");
}

static size_t	show_page_alloc(char *title, t_page *page)
{
	t_alloc		*tmp_alloc;
	t_page		*tmp;
	size_t		size;

	size = 0;
	tmp = page;
	while (tmp)
	{
		ft_putstr(title);
		ft_putaddress((size_t)tmp);
		ft_putstr("\n");
		tmp_alloc = tmp->alloc;
		while (tmp_alloc)
		{
			if (tmp_alloc->is_alloc)
			{
				size += tmp_alloc->size;
				ft_print_alloc(tmp_alloc);
			}
			tmp_alloc = tmp_alloc->next;
		}
		tmp = tmp->next;
	}
	return (size);
}

void			show_alloc_mem(void)
{
	size_t	size;

	size = 0;
	size += show_page_alloc("TINY : ", g_stock.tiny);
	size += show_page_alloc("SMALL : ", g_stock.small);
	size += show_page_alloc("LARGE : ", g_stock.large);
	ft_putstr("Total : ");
	ft_putnb(size);
	ft_putstr(" octets\n");
}
