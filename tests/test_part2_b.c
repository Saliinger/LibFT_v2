/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part2_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:20:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 14:20:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	t_split_edges(void)
{
	char	**tab;

	tab = ft_split("  keep  hide   more", ' ');
	check_str(tab[0], "keep", "ft_split collapses repeats [0]");
	check_str(tab[1], "hide", "ft_split collapses repeats [1]");
	check_str(tab[2], "more", "ft_split collapses repeats [2]");
	check(tab[3] == NULL, "ft_split repeats NULL terminated");
	free_split(tab);
	tab = ft_split("-a-b-", '-');
	check_str(tab[0], "a", "ft_split leading delimiter [0]");
	check_str(tab[1], "b", "ft_split trailing delimiter ignored");
	check(tab[2] == NULL, "ft_split edge delimiters NULL terminated");
	free_split(tab);
	tab = ft_split("abc", ',');
	check_str(tab[0], "abc", "ft_split no delimiter");
	check(tab[1] == NULL, "ft_split single word NULL terminated");
	free_split(tab);
	check(ft_split(NULL, ',') == NULL, "ft_split NULL returns NULL");
	tab = ft_split("", ',');
	check(tab != NULL && tab[0] == NULL, "ft_split no word returns { NULL }");
	free_split(tab);
	tab = ft_split(",,,", ',');
	check(tab != NULL && tab[0] == NULL,
		"ft_split only delimiters returns { NULL }");
	free_split(tab);
}

static char	idx_char(unsigned int i, char c)
{
	(void)c;
	return ((char)(i + '0'));
}

static char	up_char(unsigned int i, char c)
{
	(void)i;
	return ((char)ft_toupper(c));
}

void	t_mapi(void)
{
	char	*out;

	out = ft_strmapi("abcd", idx_char);
	check_str(out, "0123", "ft_strmapi passes the index");
	free(out);
	out = ft_strmapi("abc", up_char);
	check_str(out, "ABC", "ft_strmapi applies f");
	free(out);
	out = ft_strmapi("", up_char);
	check_str(out, "", "ft_strmapi empty string");
	free(out);
}

void	t_itoa(void)
{
	char	*out;

	out = ft_itoa(0);
	check_str(out, "0", "ft_itoa 0");
	free(out);
	out = ft_itoa(5);
	check_str(out, "5", "ft_itoa single digit");
	free(out);
	out = ft_itoa(-7);
	check_str(out, "-7", "ft_itoa negative single digit");
	free(out);
	out = ft_itoa(42);
	check_str(out, "42", "ft_itoa two digits");
	free(out);
	out = ft_itoa(-12345);
	check_str(out, "-12345", "ft_itoa negative");
	free(out);
	out = ft_itoa(INT_MAX);
	check_str(out, "2147483647", "ft_itoa INT_MAX");
	free(out);
}
