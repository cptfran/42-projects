/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:58:23 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/11 14:23:26 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ifduparr(char **argv)
{
	t_list	*node;
	t_list	*repeats;
	int		curr_val;

	repeats = NULL;
	while (*argv)
	{
		curr_val = ft_atoi(*argv);
		node = repeats;
		while (node)
		{
			if (*(int *)node->content == curr_val)
				return (ft_lstclear(&repeats, ft_dellistcontent), 1);
			node = node->next;
		}
		node = ft_lstnew(NULL);
		node->content = malloc(sizeof(int));
		*(int *)node->content = curr_val;
		ft_lstadd_front(&repeats, node);
		argv++;
	}
	ft_lstclear(&repeats, ft_dellistcontent);
	return (0);
}

int	ft_ifintarr(char **argv)
{
	while (*argv)
	{
		if (!ft_ifintnbr(*argv++))
			return (0);
	}
	return (1);
}

// int ft_ifonenbrinstr(char *argv)
// {
// 	while (!ft_isdigit(*argv) && *argv)
// 		argv++;
// 	while (ft_isdigit(*argv) && *argv)
// 		argv++;
// 	while (!ft_isdigit(*argv) && *argv)
// 		argv++;
// 	if (*argv == 0)
// 		return (1);
// 	return (0);
// }
