#include "libft.h"

int	ft_toupper(int n)
{
	if (n == '\0')
		return (n);
	if (n >= 'A' && n <= 'Z')
		return (n);
	else if (n >= 'a' && n <= 'z')
		return (n - 32);
	return (n);
}
