#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
		++i;
	return (i);
}
