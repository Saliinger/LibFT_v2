/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:11:41 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/07 12:11:42 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	if (count * size > INT_MAX || count > INT_MAX || size > INT_MAX)
		return (NULL);
	i = malloc(count * size);
	if (i)
		ft_bzero(i, count * size);
	return (i);
}
