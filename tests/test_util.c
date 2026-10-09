/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:20:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 14:20:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

int	g_pass;
int	g_fail;
int	g_del;

void	check(int ok, const char *what)
{
	if (ok)
		g_pass++;
	else
	{
		g_fail++;
		printf("  FAIL  %s\n", what);
	}
}

static const char	*safe(const char *s)
{
	if (!s)
		return ("(null)");
	return (s);
}

void	check_str(const char *got, const char *want, const char *what)
{
	if (got && strcmp(got, want) == 0)
		g_pass++;
	else
	{
		g_fail++;
		printf("  FAIL  %-34s want \"%s\" got \"%s\"\n", what, want, safe(got));
	}
}

void	check_num(size_t got, size_t want, const char *what)
{
	if (got == want)
		g_pass++;
	else
	{
		g_fail++;
		printf("  FAIL  %-34s want %zu got %zu\n", what, want, got);
	}
}

int	same_sign(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0) || (a == 0 && b == 0))
		return (1);
	return (0);
}
