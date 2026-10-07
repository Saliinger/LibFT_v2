#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;
	void	*temp;

	if (!f && !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		temp = (*f)(lst->content);
		current = ft_lstnew(temp);
		if (!current)
		{
			free(temp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, current);
		lst = lst->next;
	}
	return (new);
}
