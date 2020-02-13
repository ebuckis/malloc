/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 13:35:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 11:46:40 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define TINY_MAX	128
# define SMALL_MAX	4096
# include <string.h>
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

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
void				*malloc(size_t size);
t_page				*little_new_page(t_page *new, int type);
void				*little_alloc(t_page *page, int type, size_t size);
t_alloc				*alloc_init(t_alloc *new, size_t last_ad);
void				*alloc_find_place(t_page *page, size_t size);
t_page				*large_new_page(t_page *new, size_t size);
void				*large_alloc(t_page *page, size_t size);

/*
**	Free
*/
void				free(void *ptr);

int					page_is_empty(t_page *page);

void				*realloc(void *ptr, size_t new_size);

void 				*calloc(size_t number, size_t size);

void				show_alloc_mem(void);

/*
**	Tools
*/
size_t				get_size_align(size_t size);
size_t				get_size_alloc(int type);
size_t				get_size_page(int type);
/*
**	Display Tools
*/
void				ft_putaddress(size_t add);
void				ft_puthexa(size_t n);
void				ft_putnb(size_t n);
void				ft_putstr(char *str);
size_t				ft_strlen(char *str);

#endif
