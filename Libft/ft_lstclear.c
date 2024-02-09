/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:12:16 by sfrankie          #+#    #+#             */
/*   Updated: 2023/12/04 09:07:31 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (*lst == NULL || lst == NULL || del == NULL)
		return ;
	while ((*lst) != NULL)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		(*lst) = next;
	}
	*lst = NULL;
}

// #include <stdio.h>
// void	del(void *content)
// {
// 	free(content);
// }
// int	main(void)
// {
// 	t_list	*lst;
// 	int	*lst1;
// 	int	*lst2;
// 	int	*lst3;

// 	lst1 = malloc(sizeof(int));
// 	lst2 = malloc(sizeof(int));
// 	lst3 = malloc(sizeof(int));
// 	*lst1 = 1;
// 	*lst2 = 2;
// 	*lst3 = 3;
// 	lst = malloc(sizeof(t_list));
// 	lst->content = lst1;
// 	lst->next = malloc(sizeof(t_list));
// 	lst->next->content = lst2;
// 	lst->next->next = malloc(sizeof(t_list));
// 	lst->next->next->content = lst3;
// 	lst->next->next->next = NULL;

// 	ft_lstclear(&lst, del);

// 	if (lst == NULL)
// 		printf("list deleted\n");
// 	else
// 		printf("error!\n");

// 	return (0);	
// }