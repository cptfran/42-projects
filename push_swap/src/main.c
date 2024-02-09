/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:06:16 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/12 17:25:42 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
