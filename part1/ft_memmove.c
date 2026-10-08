/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:12:46 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 12:10:16 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (!cdst && !csrc)
		return (cdst);
	if (cdst > csrc)
		while (len--)
			cdst[len] = csrc[len];
	else
	{
		i = -1;
		while (++i < len)
			cdst[i] = csrc[i];
	}
	return (cdst);
}
