/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:35:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 14:51:19 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <sys/mman.h>

#define PAGESIZE		getpagesize()
#define TINY_TYPE		1
#define SMALL_TYPE		2
#define LARGE_TYPE		3
#define TINY_MIN		1
#define TINY_MAX		16
#define SMALL_MIN		TINY_MAX + 1
#define SMALL_MAX		128
#define LARGE_MIN		SMALL_MAX + 1
#define	ALIGN_POS		16
#define TINY_SIZE_AREA	4096
#define SMALL_SIZE_AREA	16384
#define NB_TINY			TINY_SIZE_AREA / TINY_MAX
#define NB_SMALL		SMALL_SIZE_AREA / SMALL_MAX
#define	MMAP_ARG(size)	NULL, size, PROT_READ | PROT_WRITE,	MAP_PRIVATE | MAP_ANONYMOUS, -1, 0

typedef struct		s_tiny
{
	int				adr_size[NB_TINY];
	int				nbr_alloc;
	void			*ptr;
	struct s_tiny	*next;
}					t_tiny;

typedef struct		s_small
{
	int				adr_size[NB_SMALL];
	int				nbr_alloc;
	void			*ptr;
	struct s_small	*next;
}					t_small;

typedef struct		s_large
{
	size_t			size;
	void			*ptr;
	struct s_large	*next;
}					t_large;

typedef struct		s_stock
{
	struct s_large	*large;
	struct s_small	*small;
	struct s_tiny	*tiny;
}					t_stock;

t_stock				g_stock;

void		*ft_malloc(size_t size);
void		*ft_tiny(size_t size);
void		*ft_small(size_t size);
void		*ft_large(size_t size);
size_t		go_to_align_pos(size_t add);