/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:06:16 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:34:59 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * Function: ft_makestack
 * ----------------------------
 *   Converts an array of strings to a linked list of integers. If there is only one
 *   string, it is split into substrings using spaces as delimiters. Each string is
 *   converted to an integer and added to the end of the linked list.
 *
 *   stack: The linked list to be filled.
 *   argc: The number of strings.
 *   argv: The array of strings.
 *
 *   Returns: void
 */
void	ft_makestack(t_list **stack, int argc, char **argv)
{
	t_list	*node;
	char	**arr;
	int		val;

	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = argv + 1;
	while (*arr)
	{
		val = ft_atoi(*arr++);
		node = ft_lstnew(NULL);
		node->content = malloc(sizeof(int));
		ft_memcpy(node->content, &val, sizeof(int));
		ft_lstadd_back(stack, node);
	}
}

/*
 * Function: main
 * ----------------------------
 *   The main function of the program. It checks the command line arguments, converts
 *   them to a linked list of integers, and performs the push_swap algorithm.
 *
 *   argc: The number of command line arguments.
 *   argv: The array of command line arguments.
 *
 *   Returns: 0 if the program runs successfully, 1 otherwise.
 */
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_iferror(argc, argv))
		return (ft_printf("Error\n"), 1);
	ft_makestack(&stack_a, argc, argv);
	if (!sorted_stack(&stack_a))
		sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, ft_dellistcontent);
	ft_lstclear(&stack_b, ft_dellistcontent);
	return (0);
}
