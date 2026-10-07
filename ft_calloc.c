#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	if (count * size > INT_MAX || count > INT_MAX || size > INT_MAX)
		return (NULL);
	i = malloc(count * size);
	if (i)
		ft_bzero(i, count * size);
	return (i);
}
