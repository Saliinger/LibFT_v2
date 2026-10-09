/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-07 12:13:40 by alnoukan          #+#    #+#             */
/*   Updated: 2026-10-08 12:10:16 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnstr_2(const char *cstr, const char *cto_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	while (i < len && cstr[i] != '\0')
	{
		n = i;
		j = 0;
		while (cstr[n] == cto_find[j] && cstr[n] && cto_find[j] && n < len)
		{
			n++;
			j++;
		}
		if (cto_find[j] == '\0')
			return ((char *)(cstr + i));
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	if (to_find[0] == '\0')
		return ((char *)str);
	return (ft_strnstr_2(str, to_find, len));
}
