/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:05:46 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/12 17:27:39 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// sort numbers using 2 stacks

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	stack_a_len;

	stack_a_len = stack_len(stack_a);
	if (stack_a_len == 2)
		sa(stack_a);
	if (stack_a_len == 3)
		sort_3(stack_a);
	if (stack_a_len > 3)
		sort_big(stack_a, stack_b);
}

// sort if 3 numbers are in stack A

void	sort_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack_a)->content;
	second = *(int *)(*stack_a)->next->content;
	third = *(int *)(ft_lstlast(*stack_a))->content;
	if (first > second && third > first && third > second)
		sa(stack_a);
	if (first > second && first > third && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (first > second && first > third && third > second)
		ra(stack_a);
	if (second > first && second > third && third > first)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (second > first && first > third && second > third)
		rra(stack_a);
}

// sort numbers for stack bigger than 3

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int		stack_a_len;
	int		stack_b_len;

	stack_a_len = stack_len(stack_a);
	if (stack_a_len == 4)
	{
		pb(stack_a, stack_b);
		stack_a_len--;
	}
	else
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		stack_a_len -= 2;
	}
	while (stack_a_len-- > 3)
		move_to_b(stack_a, stack_b);
	sort_3(stack_a);
	stack_b_len = stack_len(stack_b);
	while (stack_b_len-- > 0)
		move_to_a(stack_b, stack_a);
	move_smallest_top(stack_a);
}

// move numbers from stack A to stack B in descending order

void	move_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*close_a;
	t_list	*close_b;

	close_a = find_closest_in_a(stack_a, stack_b);
	close_b = find_close_in_b(close_a, stack_b);
	rotate_stacks(close_a, stack_a, close_b, stack_b);
	pb(stack_a, stack_b);
}

// move numbers from stack B to stack A in ascending order

void	move_to_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*close_b;
	t_list	*close_a;

	close_b = find_closest_in_b(stack_b, stack_a);
	close_a = find_close_in_a(close_b, stack_a);
	rotate_stacks(close_a, stack_a, close_b, stack_b);
	pa(stack_a, stack_b);
}
