/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part1_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:20:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 14:20:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	t_strlen(void)
{
	check(ft_strlen("") == 0, "ft_strlen empty");
	check(ft_strlen("a") == 1, "ft_strlen one char");
	check(ft_strlen("hello world") == 11, "ft_strlen plain");
	check(ft_strlen("a\tb\nc") == 5, "ft_strlen counts escapes");
}

void	t_strlcpy(void)
{
	char	dst[16];
	size_t	n;
	size_t	stop;

	memset(dst, '@', sizeof(dst));
	check_num(ft_strlcpy(dst, "abcdef", 0), 6, "ft_strlcpy n=0 returns len");
	check(dst[0] == '@', "ft_strlcpy n=0 writes nothing");
	n = 1;
	while (n <= 9)
	{
		memset(dst, '@', sizeof(dst));
		check_num(ft_strlcpy(dst, "abcdef", n), 6, "ft_strlcpy return");
		stop = 6;
		if (n - 1 < stop)
			stop = n - 1;
		check(strncmp(dst, "abcdef", stop) == 0, "ft_strlcpy copied prefix");
		check(dst[stop] == '\0', "ft_strlcpy always NUL terminates");
		check(dst[stop + 1] == '@', "ft_strlcpy never writes past size");
		n++;
	}
}

void	t_strlcat(void)
{
	char	dst[16];

	strcpy(dst, "abc");
	check_num(ft_strlcat(dst, "defg", 16), 7, "ft_strlcat return");
	check_str(dst, "abcdefg", "ft_strlcat full copy");
	strcpy(dst, "abc");
	check_num(ft_strlcat(dst, "defg", 5), 7, "ft_strlcat truncating return");
	check_str(dst, "abcd", "ft_strlcat truncating result");
	strcpy(dst, "abc");
	check_num(ft_strlcat(dst, "defg", 4), 7, "ft_strlcat no room return");
	check_str(dst, "abc", "ft_strlcat no room appends nothing");
	strcpy(dst, "abc");
	check_num(ft_strlcat(dst, "defg", 3), 7, "ft_strlcat size==len return");
	check_str(dst, "abc", "ft_strlcat size==len leaves dst");
	strcpy(dst, "abc");
	check_num(ft_strlcat(dst, "defg", 0), 4, "ft_strlcat size 0 return");
	check_str(dst, "abc", "ft_strlcat size 0 leaves dst");
	check_num(ft_strlcat(dst, "", 16), 3, "ft_strlcat empty src return");
	strcpy(dst, "");
	check_num(ft_strlcat(dst, "abc", 8), 3, "ft_strlcat empty dst return");
	check_str(dst, "abc", "ft_strlcat empty dst result");
}

void	t_chr(void)
{
	const char	*s;

	s = "hello world";
	check(ft_strchr(s, 'w') == s + 6, "ft_strchr found");
	check(ft_strchr(s, 'h') == s, "ft_strchr first char");
	check(ft_strchr(s, 'z') == NULL, "ft_strchr absent");
	check(ft_strchr(s, '\0') == s + 11, "ft_strchr finds the NUL");
	check(ft_strchr(s, 'w' + 256) == s + 6, "ft_strchr casts c to char");
	check(ft_strchr("", '\0') != NULL, "ft_strchr empty string NUL");
	check(ft_strrchr(s, 'o') == s + 7, "ft_strrchr last occurrence");
	check(ft_strrchr(s, 'h') == s, "ft_strrchr first char");
	check(ft_strrchr(s, 'z') == NULL, "ft_strrchr absent");
	check(ft_strrchr(s, '\0') == s + 11, "ft_strrchr finds the NUL");
}

void	t_ncmp(void)
{
	check(ft_strncmp("abc", "abd", 3) < 0, "ft_strncmp smaller");
	check(ft_strncmp("abd", "abc", 3) > 0, "ft_strncmp greater");
	check(ft_strncmp("abc", "abc", 3) == 0, "ft_strncmp equal");
	check(ft_strncmp("abc", "abd", 2) == 0, "ft_strncmp stops at n");
	check(ft_strncmp("abc", "abc", 0) == 0, "ft_strncmp n=0");
	check(ft_strncmp("abcd", "abc", 4) > 0, "ft_strncmp past s1 NUL");
	check(ft_strncmp("abc", "abcd", 4) < 0, "ft_strncmp past s2 NUL");
	check(ft_strncmp("", "", 5) == 0, "ft_strncmp two empties");
	check(ft_strncmp("a", "", 1) > 0, "ft_strncmp vs empty s2");
	check(same_sign(ft_strncmp("\xff", "\x01", 1), strncmp("\xff", "\x01", 1))
		&& ft_strncmp("\xff", "\x01", 1) > 0,
		"ft_strncmp compares unsigned bytes");
}
