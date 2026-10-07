#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst && del)
	{
		temp = lst;
		lst = temp->next;
		(*del)(temp->content);
		free(temp);
	}
}
