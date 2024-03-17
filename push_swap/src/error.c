/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:10:26 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:32:56 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * Function: ft_iferror
 * ----------------------------
 *   Checks if the command line arguments are valid. If there is less than 2 arguments,
 *   or if the arguments are not valid integers, or if there are duplicate arguments,
 *   it returns 1 to indicate an error.
 *
 *   argc: The number of command line arguments.
 *   argv: The array of command line arguments.
 *
 *   Returns: 1 if there is an error, 0 otherwise.
 */
int	ft_iferror(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (argc == 2 && (!ft_ifdigitstr(argv[1])
			|| ft_ifdupstr(argv[1]) || !ft_ifintnbr(argv[1])))
		return (1);
	if (argc > 2 && (!ft_ifdigitarr(argv + 1)
			|| ft_ifduparr(argv + 1) || !ft_ifintarr(argv + 1)))
		return (1);
	return (0);
}

/*
 * Function: ft_ifdigitstr
 * ----------------------------
 *   Checks if a string is a valid integer. A valid integer can contain digits, spaces,
 *   and a minus sign at the beginning.
 *
 *   argv: The string to be checked.
 *
 *   Returns: 1 if the string is a valid integer, 0 otherwise.
 */
int	ft_ifdigitstr(char *argv)
{
	if (!*argv)
		return (0);
	while (*argv)
	{
		if (ft_isdigit(*argv) || *argv == ' '
			|| (*argv == '-' && ft_isdigit(*(argv + 1))))
			argv++;
		else
			return (0);
	}
	return (1);
}

/*
 * Function: ft_ifdupstr
 * ----------------------------
 *   Checks if a string contains duplicate integers. The integers in the string are
 *   separated by spaces.
 *
 *   argv: The string to be checked.
 *
 *   Returns: 1 if there are duplicate integers, 0 otherwise.
 */
int	ft_ifdupstr(char *argv)
{
	char	**arr;
	t_list	*node;
	t_list	*repeats;
	int		curr_val;

	arr = ft_split(argv, ' ');
	repeats = NULL;
	while (*arr)
	{
		curr_val = ft_atoi(*arr);
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
		arr++;
	}
	ft_lstclear(&repeats, ft_dellistcontent);
	return (0);
}

int	ft_ifintnbr(char *argv)
{
	char	**arr;

	arr = ft_split(argv, ' ');
	while (*arr)
	{
		if (**arr == '0' && ft_strlen(*arr) == 1)
			return (1);
		if (ft_atoi(*arr) == 0)
			return (0);
		arr++;
	}
	return (1);
}

int	ft_ifdigitarr(char **argv)
{
	while (*argv)
	{
		if (!ft_ifdigitstr(*argv++))
			return (0);
	}
	return (1);
}
