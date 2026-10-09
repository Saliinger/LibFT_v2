/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part3_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:20:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026/10/08 14:20:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	count_del(void *content)
{
	g_del++;
	free(content);
}

void	add_int_node(t_list **list, int value, int back)
{
	int		*content;
	t_list	*node;

	content = malloc(sizeof(int));
	if (!content)
		return ;
	*content = value;
	node = ft_lstnew(content);
	if (!node)
		return ;
	if (back)
		ft_lstadd_back(list, node);
	else
		ft_lstadd_front(list, node);
}

void	t_lst_new(void)
{
	int		value;
	t_list	*node;

	value = 42;
	node = ft_lstnew(&value);
	check(node != NULL, "ft_lstnew allocates");
	check(node && node->content == &value, "ft_lstnew sets content");
	check(node && node->next == NULL, "ft_lstnew sets next to NULL");
	free(node);
}

void	t_lst_build(void)
{
	t_list	*list;

	list = NULL;
	add_int_node(&list, 1, 0);
	check(list && list->content != NULL, "ft_lstadd_front on empty list");
	check(ft_lstsize(list) == 1, "ft_lstsize one node");
	add_int_node(&list, 2, 0);
	check(ft_lstsize(list) == 2, "ft_lstsize two nodes");
	check(list && *(int *)list->content == 2, "ft_lstadd_front prepends");
	add_int_node(&list, 3, 1);
	check(ft_lstsize(list) == 3, "ft_lstsize three nodes");
	check(list && list->next && list->next->next
		&& *(int *)list->next->next->content == 3,
		"ft_lstadd_back appends last");
	check(list && ft_lstlast(list) == list->next->next,
		"ft_lstlast returns the tail");
	check(ft_lstsize(NULL) == 0, "ft_lstsize NULL is 0");
	check(ft_lstlast(NULL) == NULL, "ft_lstlast NULL");
	add_int_node(&list, 4, 1);
	check(ft_lstlast(list) != NULL
		&& *(int *)ft_lstlast(list)->content == 4,
		"ft_lstadd_back after tail lookup");
	ft_lstclear(&list, free);
	check(list == NULL, "ft_lstclear NULLs the head pointer");
}

void	t_lst_iter_delone(void)
{
	t_list	*list;
	t_list	*rest;

	list = NULL;
	add_int_node(&list, 10, 1);
	add_int_node(&list, 20, 1);
	rest = list->next;
	g_del = 0;
	ft_lstdelone(list, count_del);
	check(g_del == 1, "ft_lstdelone calls del once");
	check(rest != NULL && *(int *)rest->content == 20,
		"ft_lstdelone leaves the rest of the list");
	free(rest->content);
	free(rest);
	ft_lstdelone(NULL, count_del);
	check(g_del == 1, "ft_lstdelone NULL does nothing");
}
