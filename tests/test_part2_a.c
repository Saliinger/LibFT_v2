/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part2_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:20:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 14:20:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	free_split(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	t_substr(void)
{
	char	*out;

	out = ft_substr("abcdef", 0, 3);
	check_str(out, "abc", "ft_substr from 0");
	free(out);
	out = ft_substr("abcdef", 2, 3);
	check_str(out, "cde", "ft_substr from middle");
	free(out);
	out = ft_substr("abcdef", 4, 100);
	check_str(out, "ef", "ft_substr len past end is clamped");
	free(out);
	out = ft_substr("abcdef", 0, 100);
	check_str(out, "abcdef", "ft_substr whole string");
	free(out);
	out = ft_substr("abcdef", 10, 3);
	check_str(out, "", "ft_substr start past end returns empty");
	free(out);
	out = ft_substr("abcdef", 2, 0);
	check_str(out, "", "ft_substr len 0 returns empty");
	free(out);
	check(ft_substr(NULL, 0, 1) == NULL, "ft_substr NULL returns NULL");
}

void	t_strjoin(void)
{
	char	*out;

	out = ft_strjoin("hello", " world");
	check_str(out, "hello world", "ft_strjoin two strings");
	free(out);
	out = ft_strjoin("", "b");
	check_str(out, "b", "ft_strjoin empty prefix");
	free(out);
	out = ft_strjoin("a", "");
	check_str(out, "a", "ft_strjoin empty suffix");
	free(out);
	out = ft_strjoin("", "");
	check_str(out, "", "ft_strjoin two empties");
	free(out);
}

void	t_strtrim(void)
{
	char	*out;

	out = ft_strtrim("  abc  ", " ");
	check_str(out, "abc", "ft_strtrim both ends");
	free(out);
	out = ft_strtrim("  hello  world  ", " ");
	check_str(out, "hello  world", "ft_strtrim keeps inner characters");
	free(out);
	out = ft_strtrim("abc", " ");
	check_str(out, "abc", "ft_strtrim nothing to trim");
	free(out);
	out = ft_strtrim("xxabcxx", "x");
	check_str(out, "abc", "ft_strtrim custom set");
	free(out);
	out = ft_strtrim("   ", " ");
	check_str(out, "", "ft_strtrim everything trimmed returns empty");
	free(out);
	out = ft_strtrim("abc", "");
	check_str(out, "abc", "ft_strtrim empty set copies s1");
	free(out);
	out = ft_strtrim("", "abc");
	check_str(out, "", "ft_strtrim empty s1");
	free(out);
}

void	t_split_basic(void)
{
	char	**tab;

	tab = ft_split("one-two-three", '-');
	check(tab != NULL, "ft_split allocates");
	if (!tab)
		return ;
	check_str(tab[0], "one", "ft_split [0]");
	check_str(tab[1], "two", "ft_split [1]");
	check_str(tab[2], "three", "ft_split [2]");
	check(tab[3] == NULL, "ft_split NULL terminated");
	free_split(tab);
}
