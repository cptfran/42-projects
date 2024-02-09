/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:54:17 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/10 18:55:37 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ra(t_list **stack_a)
{
	t_list	*t_node;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	t_node = ft_lstnew((*stack_a)->content);
	ft_lstadd_back(stack_a, t_node);
	*stack_a = (*stack_a)->next;
	ft_printf("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one

void	rb(t_list **stack_b)
{
	t_list	*t_node;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	t_node = ft_lstnew((*stack_b)->content);
	ft_lstadd_back(stack_b, t_node);
	*stack_b = (*stack_b)->next;
	ft_printf("rb\n");
}

// rr : ra and rb at the same time.

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_a;
	t_list	*node_b;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next
		|| !stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	node_a = ft_lstnew((*stack_a)->content);
	ft_lstadd_back(stack_a, node_a);
	*stack_a = (*stack_a)->next;
	node_b = ft_lstnew((*stack_b)->content);
	ft_lstadd_back(stack_b, node_b);
	*stack_b = (*stack_b)->next;
	ft_printf("rr\n");
}
