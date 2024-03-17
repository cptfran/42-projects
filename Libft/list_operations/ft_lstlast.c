/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:10:45 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:42:17 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns the last node of the list.

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list *node1 = malloc(sizeof(t_list));
// 	t_list *node2 = malloc(sizeof(t_list));
// 	t_list *node3 = malloc(sizeof(t_list));
// 	t_list *node4 = malloc(sizeof(t_list));

// 	node1->content = "node1";
// 	node2->content = "node2";
// 	node3->content = "node3";
// 	node4->content = "node4";

// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = node4;
// 	node4->next = NULL;

// 	t_list *last = ft_lstlast(node1);

// 	if (last != NULL)
// 		printf("%s\n", (char *)last->content);
// 	else
// 		printf("error\n");

// 	free(node1);
// 	free(node2);
// 	free(node3);

// 	return (0);
// }