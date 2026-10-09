/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:12:04 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 12:10:16 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_digits(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	void	ft_itoa_2(long nbr, char *dest, size_t *i)
{
	if (nbr >= 10)
	{
		ft_itoa_2(nbr / 10, dest, i);
		ft_itoa_2(nbr % 10, dest, i);
	}
	if (nbr < 10)
		dest[(*i)++] = nbr + '0';
}

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	i;
	long	nbr;

	nbr = n;
	dest = malloc(ft_digits(nbr) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		dest[i++] = '-';
		nbr = -nbr;
	}
	ft_itoa_2(nbr, dest, &i);
	dest[i] = '\0';
	return (dest);
}
