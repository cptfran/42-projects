/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 09:15:58 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/29 13:09:15 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst != NULL)
		{
			(f)(lst->content);
			lst = lst->next;
		}
	}
}

// #include <stdio.h>
// void	f(void *content)
// {
// 	printf("%s", (char *)content);
// }
// int	main(void)
// {
// 	t_list	*lst = malloc(sizeof(t_list));

// 	lst->content = "Good ";
// 	lst->next = malloc(sizeof(t_list));
// 	lst->next->content = "Morning";
// 	lst->next->next = NULL;
// 	ft_lstiter(lst, f);
// 	printf("\n");

// 	return (0);
// }