/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mainsize.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 10:06:52 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 11:04:21 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_malloc.h"

int main(void)
{
	int a, b, c, d, e, f;

	a = sizeof(size_t);
	b = sizeof(t_stock);
	c = sizeof(t_page);
	d = sizeof(t_alloc);
	e = sizeof(short);
	f = sizeof(void *);

	printf("size t : %d\n", a);
	a = sizeof(int);
	printf("int : %d\n", a);
	printf("stock : %d\n",b);
	printf("page : %d\n", c);
	printf("alloc : %d\n", d);
	printf("short : %d\n", e);
	printf("ptr : %d\n", f);
	
	return 0;
}