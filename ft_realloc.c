



#include "ft_malloc.h"

int	try_to_expand(t_alloc *alloc, size_t last_size, size_t new_size, size_t )
{
//next null -> verif page size
//next pas null -> on additionne les tailles des alloc libres

}

static int	verif_type(size_t size, int type)
{
	int		new_type;

	if (size + sizeof(t_page) <= TINY_MAX)
		new_type = e_tiny_type;
	else if (size + sizeof(t_page) <= SMALL_MAX)
		new_type = e_small_type;
	else
		new_type = e_large_type;

	return (new_type == type);
}

static int	find_ptr(void *ptr, t_alloc **al, int *type, t_page *tmp)
{
	while (tmp)
	{
		if (ptr >= (void *)tmp && ptr <= (void *)((size_t)tmp + tmp->size))
		{
			*al = tmp->alloc;
			while (*al)
			{
				if ((*al)->ptr == ptr)
				{
					type = tmp->type;
					return (1);
				}
				*al = (*al)->next;
			}
			return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			find_alloc_ptr(void *ptr, t_alloc **al, int *type)
{
	if (find_ptr(ptr, al, type, g_stock.tiny)
		|| find_ptr(ptr, al, type, g_stock.small)
		|| find_ptr(ptr, al, type, g_stock.large))
		return (1);
	return (0);
}


void		*ft_realloc(void *ptr, size_t new_size)
{
	t_alloc	*alloc;
	int		type;
//verif sur new_size ?
	if (new_size < 1
		|| new_size >= 0xFFFFFFFFFFFFFFFF - (sizeof(t_page) + sizeof(t_alloc)))
		return (NULL);
	if (!find_alloc_ptr(ptr, &alloc, &type))
		return (NULL);
	//besoin de page pour connaitre la limite de taille
	if (verif_type(new_size, type))
	{
		if (try_to_expand(alloc, alloc->size, new_size))
			return (ptr);
	}
	ft_free(ptr);
	return (ft_malloc(new_size));
}