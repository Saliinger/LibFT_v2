/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part1_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:20:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 14:20:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	t_strnstr(void)
{
	const char	*h;
	char		hay[8];

	h = "hello world";
	check(ft_strnstr(h, "world", 11) == h + 6, "ft_strnstr found");
	check(ft_strnstr(h, "hello", 5) == h, "ft_strnstr match at start");
	check(ft_strnstr(h, "world", 10) == NULL, "ft_strnstr match beyond len");
	check(ft_strnstr(h, "", 0) == h, "ft_strnstr empty needle returns hay");
	check(ft_strnstr(h, "z", 11) == NULL, "ft_strnstr absent");
	check(ft_strnstr(h, "world!", 11) == NULL, "ft_strnstr needle too long");
	check(ft_strnstr("abc", "abc", 2) == NULL, "ft_strnstr partial within len");
	strcpy(hay, "ab");
	check(ft_strnstr(hay, "b", 2) == hay + 1, "ft_strnstr single char");
}

void	t_atoi(void)
{
	check(ft_atoi("42") == 42, "ft_atoi plain");
	check(ft_atoi("  -123abc") == -123, "ft_atoi spaces and trailing");
	check(ft_atoi("+42") == 42, "ft_atoi leading +");
	check(ft_atoi("\t\n\v\f\r 42") == 42, "ft_atoi all whitespace");
	check(ft_atoi("00042") == 42, "ft_atoi leading zeros");
	check(ft_atoi("-0") == 0, "ft_atoi negative zero");
	check(ft_atoi("abc") == 0, "ft_atoi no digit");
	check(ft_atoi("") == 0, "ft_atoi empty");
	check(ft_atoi("   -+12") == 0, "ft_atoi sign after sign");
	check(ft_atoi("12.34") == 12, "ft_atoi stops at dot");
	check(ft_atoi("2147483647") == INT_MAX, "ft_atoi INT_MAX");
	check(ft_atoi("-2147483648") == INT_MIN, "ft_atoi INT_MIN");
}

void	t_calloc(void)
{
	int		*tab;
	void	*p;
	int		i;

	tab = ft_calloc(10, sizeof(int));
	check(tab != NULL, "ft_calloc allocates");
	if (!tab)
		return ;
	i = 0;
	while (i < 10)
	{
		check(tab[i] == 0, "ft_calloc zeroes memory");
		i++;
	}
	free(tab);
	p = ft_calloc(0, 0);
	check(p != NULL, "ft_calloc(0, 0) returns a freeable pointer");
	free(p);
	check(ft_calloc(SIZE_MAX, SIZE_MAX) == NULL, "ft_calloc SIZE_MAX overflow");
	check(ft_calloc(SIZE_MAX, 1) == NULL, "ft_calloc SIZE_MAX 1");
	check(ft_calloc(1, SIZE_MAX) == NULL, "ft_calloc 1 SIZE_MAX");
	p = ft_calloc(1, 3000000000u);
	check(p != NULL, "ft_calloc larger than INT_MAX still allocates");
	free(p);
}

void	t_strdup(void)
{
	char	*dup;
	char	src[8];

	dup = ft_strdup("hello");
	check_str(dup, "hello", "ft_strdup content");
	free(dup);
	dup = ft_strdup("");
	check_str(dup, "", "ft_strdup empty string");
	free(dup);
	strcpy(src, "abc");
	dup = ft_strdup(src);
	strcpy(src, "zzz");
	check_str(dup, "abc", "ft_strdup owns its own buffer");
	free(dup);
}
