#include "libft.h"

char	*ft_strnstr_2(char *cstr, char *cto_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	while (i < len && cstr[i] != '\0')
	{
		if (!cstr)
			return (NULL);
		n = i;
		j = 0;
		while (cstr[n] == cto_find[j] && cstr[n] && cto_find[j] && n < len)
		{
			n++;
			j++;
		}
		if (cto_find[j] == '\0')
			return (cstr + i);
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	if (to_find[0] == '\0')
		return ((char *)str);
	else
		return (ft_strnstr_2((char *)str, (char *)to_find, len));
}
