/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-09 10:00:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026-10-09 10:00:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Local test harness for libft.a. Not part of the library, not submitted.
** Built by `make test`, never by `make`.
*/

#ifndef FT_TEST_H
# define FT_TEST_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft.h"

extern int	g_pass;
extern int	g_fail;
extern int	g_del;

void	check(int ok, const char *what);
void	check_str(const char *got, const char *want, const char *what);
void	check_num(size_t got, size_t want, const char *what);
int		same_sign(int a, int b);
void	free_split(char **tab);
void	t_cls(void);
void	t_case(void);
void	t_mem_set(void);
void	t_mem_copy(void);
void	t_mem_search(void);
void	t_strlen(void);
void	t_strlcpy(void);
void	t_strlcat(void);
void	t_chr(void);
void	t_ncmp(void);
void	t_strnstr(void);
void	t_atoi(void);
void	t_calloc(void);
void	t_strdup(void);
void	t_substr(void);
void	t_strjoin(void);
void	t_strtrim(void);
void	t_split_basic(void);
void	t_split_edges(void);
void	t_mapi(void);
void	t_itoa(void);
void	t_itoa_neg(void);
void	t_iteri(void);
void	t_fd(void);
void	count_del(void *content);
void	add_int_node(t_list **list, int value, int back);
void	t_lst_new(void);
void	t_lst_build(void);
void	t_lst_iter_delone(void);
void	t_lst_iter_clear(void);
void	t_lst_map(void);
void	t_part3(void);

#endif
