#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (!cdst && !csrc)
		return (cdst);
	if (cdst > csrc)
		while (len--)
			cdst[len] = csrc[len];
	else
	{
		i = -1;
		while (++i < len)
			cdst[i] = csrc[i];
	}
	return (cdst);
}
