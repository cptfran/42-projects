/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:12:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:42:03 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Adds the node ’new’ at the beginning of the list.

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list *lst = malloc(sizeof(t_list));

// 	if (lst == NULL)
// 	{
// 		printf("error\n");
// 		return 1;
// 	}

// 	lst->content = "first";
// 	lst->next = NULL;

// 	t_list *new = malloc(sizeof(t_list));
// 	if (new == NULL)
// 	{
// 		printf("error\n");
// 		return 1;
// 	}

// 	new->content = "new";
// 	new->next = NULL;

// 	ft_lstadd_front(&lst, new);

// 	while (lst != NULL)
// 	{
// 		printf("node: %s\n", (char*)lst->content);
// 		lst = lst->next;
// 	}

// 	return (0);
// }