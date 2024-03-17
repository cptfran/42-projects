/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:03:01 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:42:22 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	void	*content;

	newlst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		newnode = ft_lstnew(content);
		if (!newnode)
		{
			del(content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}

// #include <stdio.h>
// void *f(void *content)
// {
// 	int	*x;
// 	int *y;

// 	x = (int *)content;
// 	y = malloc(sizeof(int));
// 	if (y)
// 		*y = (*x) + 400;
// 	return (y);
// }
// void del(void *content)
// {
// 	free(content);
// }
// int	main(void)
// {
// 	t_list	*lst;
// 	int		*x;
// 	t_list	*newlst;

// 	lst = ft_lstnew(malloc(sizeof(int)));
// 	x = lst->content;
// 	*x = 1;
// 	lst->next = ft_lstnew(malloc(sizeof(int)));
// 	x = lst->next->content;
// 	*x = 2;
// 	lst->next->next = NULL;
// 	newlst = ft_lstmap(lst, f, del);
// 	while (newlst)
// 	{
// 		int *content;

// 		content = newlst->content;
// 		printf("%d ", *content);
// 		newlst = newlst->next;
// 	}
// 	printf("\n");
// 	ft_lstclear(&lst, del);
// 	ft_lstclear(&newlst, del);

// 	return (0);
// }