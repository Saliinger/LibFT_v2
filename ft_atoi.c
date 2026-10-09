/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-07 12:11:20 by alnoukan          #+#    #+#             */
/*   Updated: 2026-10-08 12:10:16 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static int	ft_result(int neg, unsigned long nb)
{
	if (neg == -1)
		return ((int)(-(long)nb));
	return ((int)nb);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	nb;
	int				neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (unsigned long)(str[i] - '0');
		if (nb > (unsigned long)LONG_MAX)
			nb = (unsigned long)LONG_MAX;
		i++;
	}
	return (ft_result(neg, nb));
}
