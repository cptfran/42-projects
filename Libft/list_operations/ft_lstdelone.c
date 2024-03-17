/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:40:24 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:42:10 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Takes as a parameter a node and frees the memory of
// the node’s content using the function ’del’ given
// as a parameter and free the node. The memory of
// ’next’ must not be freed.

#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

// #include <stdio.h>
// #include <string.h>
// void	del(void *content)
// {
// 	free(content);
// }
// int	main(void)
// {
//     t_list *node = malloc(sizeof(t_list));
//     if (node == NULL)
// 	{
//         printf("Memory allocation error\n");
//         return 1;
//     }

//     node->content = strdup("Hello, World!");
//     node->next = NULL;

//     printf("Before deletion:\n");
//     printf("Content: %s\n", (char *)node->content);

//     ft_lstdelone(node, del);

//     printf("After deletion:\n");
//     printf("Content: %s\n", (char *)node->content);

//     return 0;
// }