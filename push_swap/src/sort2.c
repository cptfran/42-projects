/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:46:45 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/11 15:28:05 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// move smallest number in stack A on the top of the stack

void	move_smallest_top(t_list **stack_a)
{
	int		smallest_a_dist;

	smallest_a_dist = find_node_i(find_smallest(stack_a), stack_a);
	if (smallest_a_dist == 0)
		return ;
	if (smallest_a_dist <= stack_middle(stack_a))
	{
		while (smallest_a_dist > 0)
		{
			ra(stack_a);
			smallest_a_dist--;
		}
	}
	else
	{
		while (smallest_a_dist < stack_len(stack_a))
		{
			rra(stack_a);
			smallest_a_dist++;
		}
	}
}

// calculate which number from stack A has the closest distance to move to
//  stack B in descending order

t_list	*find_closest_in_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*closest_a;
	t_list	*close_b;
	int		old_dist;
	int		new_dist;

	tmp = *stack_a;
	closest_a = *stack_a;
	close_b = find_close_in_b(*stack_a, stack_b);
	old_dist = distance(stack_a, tmp, stack_b, close_b);
	while (tmp)
	{
		close_b = find_close_in_b(tmp, stack_b);
		new_dist = distance(stack_a, tmp, stack_b, close_b);
		if (new_dist < old_dist)
		{
			closest_a = tmp;
			old_dist = new_dist;
		}
		tmp = tmp->next;
	}
	return (closest_a);
}

// Find closest least smaller number in B stack for number in A stack, if
// no smaller number found, find biggest number in B stack

t_list	*find_close_in_b(t_list *stack_a, t_list **stack_b)
{
	t_list	*least_smaller;
	t_list	*tmp;
	int		a_value;
	int		smallest_diff;
	int		new_diff;

	least_smaller = *stack_b;
	tmp = *stack_b;
	a_value = *(int *)(stack_a)->content;
	smallest_diff = a_value - *(int *)(*stack_b)->content;
	while (tmp)
	{
		new_diff = a_value - *(int *)tmp->content;
		if ((new_diff > 0 && smallest_diff < 0)
			|| (new_diff > 0 && smallest_diff > 0 && new_diff < smallest_diff))
		{
			least_smaller = tmp;
			smallest_diff = new_diff;
		}
		tmp = tmp->next;
	}
	if (smallest_diff < 0)
		least_smaller = find_biggest(stack_b);
	return (least_smaller);
}

// rotate stacks to push correct number

void	rotate_stacks(t_list *node_1, t_list **stack_1,
			t_list *node_2, t_list **stack_2)
{
	rotate_both(node_1, stack_1, node_2, stack_2);
	rotate_single(node_1, stack_1, node_2, stack_2);
}

// move 2 stacks with signle operation if possible

void	rotate_both(t_list *node_1, t_list **stack_1,
			t_list *node_2, t_list **stack_2)
{
	int	dist_1;
	int	dist_2;

	dist_1 = find_node_i(node_1, stack_1);
	dist_2 = find_node_i(node_2, stack_2);
	if (dist_1 <= stack_middle(stack_1) && dist_2 <= stack_middle(stack_2)
		&& dist_1 < stack_len(stack_1) && dist_2 < stack_len(stack_2)
		&& dist_1 > 0 && dist_2 > 0)
	{
		while (dist_1 > 0 && dist_2 > 0)
		{
			rr(stack_1, stack_2);
			dist_1--;
			dist_2--;
		}
	}
	else if (dist_1 > stack_middle(stack_1) && dist_2 > stack_middle(stack_2))
	{
		while (dist_1 < stack_len(stack_1) && dist_2 < stack_len(stack_2))
		{
			rrr(stack_1, stack_2);
			dist_1++;
			dist_2++;
		}
	}
}
