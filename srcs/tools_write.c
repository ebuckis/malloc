/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_write.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 17:11:22 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 14:23:27 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "malloc.h"

size_t		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void		ft_putstr(char *str)
{
	write(0, str, ft_strlen(str));
}

void		ft_putnb(size_t n)
{
	char	c;

	c = 0;
	if (n > 9)
	{
		ft_putnb(n / 10);
		ft_putnb(n % 10);
	}
	else
	{
		c = n + '0';
		write(0, &c, 1);
	}
}

void		ft_puthexa(size_t n)
{
	char c;

	if (n < 10)
		c = '0' + n;
	else
		c = 'A' + (n - 10);
	write(0, &c, 1);
}

void		ft_putaddress(size_t add)
{
	int		i;
	int		j;

	i = 60;
	j = 2;
	ft_putstr("0x");
	while (i >= 0)
	{
		if (((add >> i) & 0xF) || j != 2)
		{
			ft_puthexa((add >> i) & 0xF);
			j++;
		}
		i -= 4;
	}
}
