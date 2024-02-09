/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:35:50 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/11 14:54:36 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// find middle of the stack to calculate if it's better to use ra/rb or rra/rrb

int	stack_middle(t_list **stack)
{
	return (stack_len(stack) / 2);
}

// iterate through list to find given node index

int	find_node_i(t_list *node, t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	tmp = *stack;
	tmp2 = node;
	i = 0;
	while (tmp)
	{
		if (tmp == tmp2)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

// calculate the distance for moving the number from stack to correct place

int	distance(t_list **stack_1, t_list *node_1, t_list **stack_2, t_list *node_2)
{
	int	dist_1;
	int	dist_2;
	int	i_1;
	int	i_2;

	i_1 = find_node_i(node_1, stack_1);
	if (i_1 == stack_len(stack_1))
		dist_1 = 1;
	if (i_1 <= stack_middle(stack_1))
		dist_1 = i_1;
	if (i_1 > stack_middle(stack_1))
		dist_1 = stack_len(stack_1) - i_1;
	i_2 = find_node_i(node_2, stack_2);
	if (i_2 == stack_len(stack_2))
		dist_2 = 1;
	if (i_2 <= stack_middle(stack_2))
		dist_2 = i_2;
	if (i_2 > stack_middle(stack_2))
		dist_2 = stack_len(stack_2) - i_2;
	return (dist_1 + dist_2);
}

// find biggest number in stack B, use this if no smaller number for A was found

t_list	*find_biggest(t_list **stack_b)
{
	t_list	*biggest;
	t_list	*tmp;
	int		curr_biggest;

	tmp = *stack_b;
	biggest = *stack_b;
	curr_biggest = *(int *)(*stack_b)->content;
	while (tmp)
	{
		if (*(int *)tmp->content > curr_biggest)
		{
			biggest = tmp;
			curr_biggest = *(int *)tmp->content;
		}
		tmp = tmp->next;
	}
	return (biggest);
}
