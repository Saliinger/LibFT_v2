/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:13:07 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 14:22:06 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	ft_split_free(char **dest, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

static char	*ft_split_word(const char *s, size_t len)
{
	char	*word;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	count;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	count = ft_countword(s, c);
	dest = (char **)malloc((count + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	if (count == 0)
	{
		dest[0] = ft_split_word("", 0);
		if (!dest[0])
		{
			free(dest);
			return (NULL);
		}
		dest[1] = NULL;
		return (dest);
	}
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		dest[k] = ft_split_word(s + i, j);
		if (!dest[k])
		{
			ft_split_free(dest, k);
			return (NULL);
		}
		i += j;
		k++;
	}
	dest[k] = NULL;
	return (dest);
}
