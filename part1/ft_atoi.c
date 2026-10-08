/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:11:20 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/07 12:11:21 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		c;
	char	*cstr;

	i = 0;
	j = 0;
	c = 1;
	cstr = (char *)str;
	while (cstr[i] == 32 || (cstr[i] >= 9 && cstr[i] <= 13))
		++i;
	if (cstr[i] == '-' || cstr[i] == '+')
	{
		if (cstr[i] == '-')
			c *= -1;
		i++;
	}
	while (cstr[i] >= '0' && cstr[i] <= '9')
	{
		j *= 10;
		j += cstr[i] - '0';
		++i;
	}
	return (j * c);
}
