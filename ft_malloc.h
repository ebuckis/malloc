/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:35:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 17:51:38 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <sys/mman.h>

#define PAGESIZE		getpagesize()
#define TINY_TYPE		1
#define SMALL_TYPE		
#define LARGE_TYPE		32
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


typedef struct		s_alloc
{
	int				size;
	struct s_alloc	*next;
	struct s_alloc	*prev;
}					t_alloc;

typedef struct		s_page 
{
	int				size;
	int				type;
	struct s_page	*prev;
	struct s_page	*next;
	
	/* data */
}					t_page;

typedef struct		s_stock
{
	t_page			*large;
	t_page			*small;
	t_page			*tiny;
}					t_stock;

t_stock				g_stock;
/*
** Malloc
*/
void		*ft_malloc(size_t size);
void		*ft_tiny(size_t size);
void		*ft_small(size_t size);
void		*ft_large(size_t size);
size_t		go_to_align_pos(size_t add);
/*
**	Free
*/
void	ft_free(void *ptr);
int		ft_free_in_tiny(void *ptr);
int		ft_free_in_small(void *ptr);
int		ft_free_in_large(void *ptr);

void	ft_display(void);
