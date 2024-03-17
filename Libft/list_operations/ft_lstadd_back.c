/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:24:34 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:41:59 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Adds the node ’new’ at the end of the list

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
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

// 	ft_lstadd_back(&lst, new);

// 	while (lst != NULL)
// 	{
// 		printf("node: %s\n", (char*)lst->content);
// 		lst = lst->next;
// 	}

// 	return (0);
// }