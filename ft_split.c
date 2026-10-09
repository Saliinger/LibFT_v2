/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-07 12:13:07 by alnoukan          #+#    #+#             */
/*   Updated: 2026-10-08 12:10:16 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	**ft_split_free(char **dest, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

static char	*ft_split_word(const char *s, size_t len)
{
	char	*word;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **dest,
	size_t count)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (k < count)
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		dest[k] = ft_split_word(s + i, j);
		if (!dest[k])
			return (ft_split_free(dest, k));
		i += j;
		k++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_countword(s, c);
	dest = malloc((count + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	if (!ft_split_words(s, c, dest, count))
		return (NULL);
	dest[count] = NULL;
	return (dest);
}
