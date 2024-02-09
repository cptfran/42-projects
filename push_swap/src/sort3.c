/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:19:33 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/12 16:02:21 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// rotate single stack

void	rotate_single(t_list *node_1, t_list **stack_1,
			t_list *node_2, t_list **stack_2)
{
	int	dist_1;
	int	dist_2;

	dist_1 = find_node_i(node_1, stack_1);
	dist_2 = find_node_i(node_2, stack_2);
	if (dist_1 <= stack_middle(stack_1) && dist_1 != stack_len(stack_1))
	{
		while (dist_1-- > 0)
			ra(stack_1);
	}
	else if (dist_1 > stack_middle(stack_1))
	{
		while (dist_1++ < stack_len(stack_1))
			rra(stack_1);
	}
	if (dist_2 <= stack_middle(stack_2) && dist_2 != stack_len(stack_2))
	{
		while (dist_2-- > 0)
			rb(stack_2);
	}
	else if (dist_2 > stack_middle(stack_2))
	{
		while (dist_2++ < stack_len(stack_2))
			rrb(stack_2);
	}
}

// calculate which number from stack B has the closest distance to move to
//  stack A in ascending order

t_list	*find_closest_in_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;
	t_list	*closest_b;
	t_list	*close_a;
	int		old_dist;
	int		new_dist;

	tmp = *stack_b;
	closest_b = *stack_b;
	close_a = find_close_in_a(*stack_b, stack_a);
	old_dist = distance(stack_b, tmp, stack_a, close_a);
	while (tmp)
	{
		close_a = find_close_in_a(tmp, stack_a);
		new_dist = distance(stack_b, tmp, stack_a, close_a);
		if (new_dist < old_dist)
		{
			closest_b = tmp;
			old_dist = new_dist;
		}
		tmp = tmp->next;
	}
	return (closest_b);
}

// Find closest least bigger number in A stack for number in B stack, if
// no bigger number found, find smallest number in A stack

t_list	*find_close_in_a(t_list *stack_b, t_list **stack_a)
{
	t_list	*least_bigger;
	t_list	*tmp;
	int		b_value;
	int		smallest_diff;
	int		new_diff;

	least_bigger = *stack_a;
	tmp = *stack_a;
	b_value = *(int *)(stack_b)->content;
	smallest_diff = *(int *)(*stack_a)->content - b_value;
	while (tmp)
	{
		new_diff = *(int *)tmp->content - b_value;
		if ((new_diff > 0 && smallest_diff < 0)
			|| (new_diff > 0 && smallest_diff > 0 && new_diff < smallest_diff))
		{
			least_bigger = tmp;
			smallest_diff = new_diff;
		}
		tmp = tmp->next;
	}
	if (smallest_diff < 0)
		least_bigger = find_smallest(stack_a);
	return (least_bigger);
}
