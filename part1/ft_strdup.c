/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:13:13 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/07 12:13:14 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	length;
	char	*dest;
	size_t	i;
	char	*csrc;

	i = 0;
	csrc = (char *)src;
	length = ft_strlen(csrc);
	dest = (char *)malloc((length + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (csrc[i])
	{
		dest[i] = csrc[i];
		i++;
	}
	dest[length] = '\0';
	return (dest);
}
