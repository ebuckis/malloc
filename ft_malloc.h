/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:35:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/08 18:49:21 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdint.h>

#define PAGESIZE		4096
#define TINY_TYPE		1
#define SMALL_TYPE		2
#define LARGE_TYPE		3
#define TINY_MIN		1
#define TINY_MAX		992
#define SMALL_MIN		TINY_MAX + 1
#define SMALL_MAX		127000
#define LARGE_MIN		SMALL_MAX + 1
#define TINY_SIZE_AREA	PAGESIZE * ((PAGESIZE / TINY_MAX) + (PAGESIZE % TINY_MAX == 0))
#define SMALL_SIZE_AREA	PAGESIZE * ((PAGESIZE / SMALL_MAX) + (PAGESIZE % SMALL_MAX == 0))

	//adrSize[][0] -> adrSize
	//adrSize[][1] -> size
typedef struct		s_tiny
{
	long			adrSize[TINY_SIZE_AREA];
	void			*ptr;
	struct s_tiny	*next;
}					t_tiny;

typedef struct		s_small
{
	long			adrSize[SMALL_SIZE_AREA];
	void			*ptr;
	struct s_small	*next;
}					t_small;

typedef struct		s_large
{
	void			*ptr;
	struct s_large	*next;
}					t_large;

typedef struct 		s_stock
{
	struct s_large	*large;
	struct s_small	*small;
	struct s_tiny	*tiny;
}					t_stock;

t_stock				g_stock;