#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (!dst && src && dstsize == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	if (i >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[j] && j < (dstsize - i - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
