/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mainsize.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 10:06:52 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 10:10:29 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

int main(void)
{
	int a, b, c, d, e;

	a = sizeof(size_t);
	b = sizeof(t_stock);
	c = sizeof(t_page);
	d = sizeof(t_alloc);
	e = sizeof(short);

	printf("size t : %d\n", a);
	printf("stock : %d\n",b);
	printf("page : %d\n", c);
	printf("alloc : %d\n", d);
	printf("short : %d\n", e);
	return 0;
}