/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:58:23 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:34:08 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * Function: ft_ifduparr
 * ----------------------------
 *   Checks if an array of strings contains duplicate integers. The integers are
 *   converted from the strings and stored in a linked list. If a duplicate is found,
 *   the linked list is cleared and the function returns 1.
 *
 *   argv: The array of strings to be checked.
 *
 *   Returns: 1 if there are duplicate integers, 0 otherwise.
 */
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

/*
 * Function: ft_ifintarr
 * ----------------------------
 *   Checks if an array of strings can be converted to integers. It iterates over the
 *   array and checks each string using the ft_ifintnbr function. If a string cannot
 *   be converted to an integer, the function returns 0.
 *
 *   argv: The array of strings to be checked.
 *
 *   Returns: 1 if all strings can be converted to integers, 0 otherwise.
 */
int	ft_ifintarr(char **argv)
{
	while (*argv)
	{
		if (!ft_ifintnbr(*argv++))
			return (0);
	}
	return (1);
}
