int	ft_tolower(int n)
{
	if (n == '\0')
		return (n);
	if (n >= 'a' && n <= 'z')
		return (n);
	else if (n >= 'A' && n <= 'Z')
		return (n + 32);
	return (n);
}
