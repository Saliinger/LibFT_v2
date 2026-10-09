/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:20:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 14:20:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static void	t_part1(void)
{
	printf("part 1\n");
	t_cls();
	t_case();
	t_mem_set();
	t_mem_copy();
	t_mem_search();
	t_strlen();
	t_strlcpy();
	t_strlcat();
	t_chr();
	t_ncmp();
	t_strnstr();
	t_atoi();
	t_calloc();
	t_strdup();
}

static void	t_part2(void)
{
	printf("part 2\n");
	t_substr();
	t_strjoin();
	t_strtrim();
	t_split_basic();
	t_split_edges();
	t_itoa();
	t_itoa_neg();
	t_mapi();
	t_iteri();
	t_fd();
}

int	main(void)
{
	g_pass = 0;
	g_fail = 0;
	g_del = 0;
	t_part1();
	t_part2();
	t_part3();
	printf("\n%d checks, %d failure(s)\n", g_pass, g_fail);
	if (g_fail == 0)
		printf("libft: all checks passed\n");
	return (g_fail != 0);
}
