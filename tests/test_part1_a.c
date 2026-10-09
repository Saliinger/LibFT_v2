/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part1_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:20:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 14:20:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	t_cls(void)
{
	int	c;
	int	exp;

	c = -128;
	while (c <= 255)
	{
		exp = ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
		check(ft_isalpha(c) == exp, "ft_isalpha");
		exp = (c >= '0' && c <= '9');
		check(ft_isdigit(c) == exp, "ft_isdigit");
		exp = (exp || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
		check(ft_isalnum(c) == exp, "ft_isalnum");
		check(ft_isascii(c) == (c >= 0 && c <= 127), "ft_isascii");
		check(ft_isprint(c) == (c >= 32 && c <= 126), "ft_isprint");
		c++;
	}
}

void	t_case(void)
{
	int	c;
	int	want;

	c = -128;
	while (c <= 255)
	{
		want = c;
		if (c >= 'a' && c <= 'z')
			want = c - 32;
		check(ft_toupper(c) == want, "ft_toupper");
		want = c;
		if (c >= 'A' && c <= 'Z')
			want = c + 32;
		check(ft_tolower(c) == want, "ft_tolower");
		c++;
	}
}

void	t_mem_set(void)
{
	char	buf[16];
	char	ref[16];

	memset(buf, '.', sizeof(buf));
	memset(ref, '.', sizeof(ref));
	ft_memset(buf, 'A', 5);
	memset(ref, 'A', 5);
	check(memcmp(buf, ref, sizeof(buf)) == 0, "ft_memset first 5 bytes");
	ft_memset(buf, 'A' + 256, sizeof(buf));
	memset(ref, 'A', sizeof(ref));
	check(memcmp(buf, ref, sizeof(buf)) == 0, "ft_memset truncates c");
	check(ft_memset(buf, 'z', 0) == buf, "ft_memset n=0 returns s");
	memset(buf, '.', sizeof(buf));
	memset(ref, '.', sizeof(ref));
	ft_bzero(buf, 5);
	memset(ref, 0, 5);
	check(memcmp(buf, ref, sizeof(buf)) == 0, "ft_bzero");
	ft_bzero(buf, 0);
	check(buf[5] == '.', "ft_bzero n=0 writes nothing");
}

void	t_mem_copy(void)
{
	char	a[16];
	char	b[16];

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	strcpy(a, "abcdefghij");
	strcpy(b, "abcdefghij");
	check(ft_memcpy(a, "01234", 5) == a, "ft_memcpy returns dest");
	check(strcmp(a, "01234fghij") == 0, "ft_memcpy bytes + tail intact");
	memcpy(b, "01234", 5);
	check(memcmp(a, b, sizeof(a)) == 0, "ft_memcpy == memcpy");
	check(ft_memcpy(a, a, 0) == a, "ft_memcpy n=0 same pointer");
	ft_memmove(a + 2, a, 5);
	memmove(b + 2, b, 5);
	check(memcmp(a, b, sizeof(a)) == 0, "ft_memmove forward overlap");
	strcpy(a, "abcdefghij");
	strcpy(b, "abcdefghij");
	ft_memmove(a, a + 2, 5);
	memmove(b, b + 2, 5);
	check(memcmp(a, b, sizeof(a)) == 0, "ft_memmove backward overlap");
	check(ft_memmove(a, a, 0) == a, "ft_memmove n=0 returns dest");
	check(ft_memmove(NULL, NULL, 0) == NULL, "ft_memmove NULL NULL");
}

void	t_mem_search(void)
{
	char	buf[16];

	strcpy(buf, "hello world");
	check(ft_memchr(buf, 'w', 11) == buf + 6, "ft_memchr found");
	check(ft_memchr(buf, 'z', 11) == NULL, "ft_memchr absent");
	check(ft_memchr(buf, 'w', 3) == NULL, "ft_memchr stops at n");
	check(ft_memchr(buf, 'w' + 256, 11) == buf + 6, "ft_memchr casts c");
	check(ft_memchr(buf, 0, 11) == NULL, "ft_memchr no NUL in range");
	check(ft_memcmp("abc", "abc", 3) == 0, "ft_memcmp equal");
	check(ft_memcmp("abc", "abd", 3) < 0, "ft_memcmp smaller");
	check(ft_memcmp("b", "a", 1) > 0, "ft_memcmp greater");
	check(ft_memcmp("abc", "abd", 0) == 0, "ft_memcmp n=0");
	check(same_sign(ft_memcmp("\xff", "\x01", 1), memcmp("\xff", "\x01", 1)),
		"ft_memcmp compares unsigned bytes");
}
