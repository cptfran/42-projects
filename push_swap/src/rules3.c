/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:45:59 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/10 11:07:04 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

void	rra(t_list **stack_a)
{
	t_list	*t_node;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	t_node = ft_lstlast(*stack_a);
	ft_lstremove_last(stack_a);
	ft_lstadd_front(stack_a, t_node);
	ft_printf("rra\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

void	rrb(t_list **stack_b)
{
	t_list	*t_node;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	t_node = ft_lstlast(*stack_b);
	ft_lstremove_last(stack_b);
	ft_lstadd_front(stack_b, t_node);
	ft_printf("rrb\n");
}

// rrr : rra and rrb at the same time.

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_a;
	t_list	*node_b;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next
		|| !stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	node_a = ft_lstlast(*stack_a);
	ft_lstremove_last(stack_a);
	ft_lstadd_front(stack_a, node_a);
	node_b = ft_lstlast(*stack_b);
	ft_lstremove_last(stack_b);
	ft_lstadd_front(stack_b, node_b);
	ft_printf("rrr\n");
}
