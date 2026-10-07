#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*str;

	str = s;
	while (len--)
		*str++ = c;
	return (s);
}
