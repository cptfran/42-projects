/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:05:45 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/10 11:03:47 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

void	sa(t_list **stack_a)
{
	int		tmp;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = *(int *)(*stack_a)->content;
	*(int *)(*stack_a)->content = *(int *)(*stack_a)->next->content;
	*(int *)(*stack_a)->next->content = tmp;
	ft_printf("sa\n");
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

void	sb(t_list **stack_b)
{
	int		tmp;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = *(int *)(*stack_b)->content;
	*(int *)(*stack_b)->content = *(int *)(*stack_b)->next->content;
	*(int *)(*stack_b)->next->content = tmp;
	ft_printf("sb\n");
}

// ss : sa and sb at the same time.

void	ss(t_list **stack_a, t_list **stack_b)
{
	int		tmp;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next
		|| !stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = *(int *)(*stack_a)->content;
	*(int *)(*stack_a)->content = *(int *)(*stack_a)->next->content;
	*(int *)(*stack_a)->next->content = tmp;
	tmp = *(int *)(*stack_b)->content;
	*(int *)(*stack_b)->content = *(int *)(*stack_b)->next->content;
	*(int *)(*stack_b)->next->content = tmp;
	ft_printf("ss\n");
}

// pa (push a): Take the first element at the top of b and put it at the
//  top of a. Do nothing if b is empty.

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*t_node;

	if (!stack_b || !*(stack_b))
		return ;
	t_node = ft_lstnew((*stack_b)->content);
	ft_lstadd_front(stack_a, t_node);
	*stack_b = (*stack_b)->next;
	ft_printf("pa\n");
}

// pb (push b): Take the first element at the top of a and put it at the
//  top of b. Do nothing if a is empty.

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*t_node;

	if (!stack_a || !*(stack_a))
		return ;
	t_node = ft_lstnew((*stack_a)->content);
	ft_lstadd_front(stack_b, t_node);
	*stack_a = (*stack_a)->next;
	ft_printf("pb\n");
}
