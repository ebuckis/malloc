/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_malloc.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:35:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 12:23:29 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef	MALLOC_H
# define MALLOC_H

# include <string.h>
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

# define TINY_MAX	128
# define SMALL_MAX	4096
# define MMAP_ARG	PROT_READ | PROT_WRITE,	MAP_PRIVATE | MAP_ANONYMOUS, -1, 0

typedef	enum		e_malloc_type
{
	e_tiny_type,
	e_small_type,
	e_large_type
}					t_malloc_type;

typedef struct		s_alloc
{
	short			is_alloc;
	size_t			size;
	void			*ptr;
	struct s_alloc	*next;
}					t_alloc;

typedef struct		s_page
{
	size_t			size;
	int				type;
	t_alloc			*alloc;
	struct s_page	*next;

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
void				*ft_malloc(size_t size);
t_page				*little_new_page(t_page *new, int type);
void				*little_alloc(t_page *page, int type, size_t size);
t_alloc				*alloc_init(t_alloc *new, size_t last_ad);
void				*alloc_find_place(t_page *page, size_t size);
t_page				*large_new_page(t_page *new, size_t size);
void				*large_alloc(t_page *page, size_t size);

/*
**	Free
*/
void				ft_free(void *ptr);

size_t				get_size_align(size_t size);
int					get_size_alloc(int type);
size_t				get_size_page(int type);
int					page_is_empty(t_page *page);

void				ft_display(void);

#endif
