/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:39:10 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/29 13:28:54 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Counts the number of nodes in a list.

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list node1;
// 	t_list node2;
// 	t_list node3;
// 	t_list node4;

// 	node1.content = "node1";
// 	node1.next = &node2;
// 	node2.content = "node2";
// 	node2.next = &node3;
// 	node3.content = "node3";
// 	node3.next = &node4;
// 	node4.content = "node4";
// 	node4.next = NULL;

// 	printf("size: %i\n", ft_lstsize(&node1));

// 	return (0);
// }