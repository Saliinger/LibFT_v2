/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part3_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:20:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 14:20:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static void	*dbl_content(void *content)
{
	int	*out;

	out = malloc(sizeof(int));
	if (out)
		*out = *(int *)content * 2;
	return (out);
}

static void	bump_content(void *content)
{
	int	*n;

	n = content;
	*n = *n + 1;
}

void	t_lst_iter_clear(void)
{
	t_list	*list;
	t_list	*node;

	list = NULL;
	add_int_node(&list, 1, 1);
	add_int_node(&list, 2, 1);
	ft_lstiter(list, bump_content);
	node = list;
	check(node && *(int *)node->content == 2, "ft_lstiter first content");
	check(node && node->next && *(int *)node->next->content == 3,
		"ft_lstiter second content");
	ft_lstiter(NULL, bump_content);
	g_del = 0;
	ft_lstclear(&list, count_del);
	check(g_del == 2, "ft_lstclear calls del for every node");
	check(list == NULL, "ft_lstclear NULLs the head pointer");
	ft_lstclear(&list, count_del);
	check(g_del == 2, "ft_lstclear on NULL list does nothing");
}

void	t_lst_map(void)
{
	t_list	*list;
	t_list	*copy;

	list = NULL;
	add_int_node(&list, 21, 1);
	add_int_node(&list, 5, 1);
	copy = ft_lstmap(list, dbl_content, free);
	check(copy != NULL, "ft_lstmap allocates a new list");
	check(ft_lstsize(copy) == 2, "ft_lstmap keeps the size");
	check(copy && *(int *)copy->content == 42, "ft_lstmap mapped first");
	check(copy && copy->next && *(int *)copy->next->content == 10,
		"ft_lstmap mapped second");
	check(copy && list && copy != list && copy->content != list->content,
		"ft_lstmap does not reuse the source nodes");
	check(list && *(int *)list->content == 21,
		"ft_lstmap leaves the source list intact");
	ft_lstclear(&copy, free);
	ft_lstclear(&list, free);
	check(ft_lstmap(NULL, dbl_content, free) == NULL, "ft_lstmap empty list");
}

void	t_part3(void)
{
	printf("part 3\n");
	t_lst_new();
	t_lst_build();
	t_lst_iter_delone();
	t_lst_iter_clear();
	t_lst_map();
}
