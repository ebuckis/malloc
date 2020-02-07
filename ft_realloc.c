



#include "ft_malloc.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	t_alloc 		*alloc;
	t_malloc_type	type;
//verif sur new_size ?
	if (!find_alloc_ptr(ptr, &alloc, &type))
		return (NULL);
	if (verif_type(new_size, type))
	{
		if (try_to_expand(ptr, alloc->size, new_size))
			return (ptr);
	}
	ft_free(ptr);
	return (ft_malloc(new_size));
}