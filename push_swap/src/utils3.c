/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:38:11 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/10 18:59:25 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// find smallest number in stack A, use this if no bigger number for B was found

t_list	*find_smallest(t_list **stack_a)
{
	t_list	*smallest;
	t_list	*tmp;
	int		curr_smallest;

	tmp = *stack_a;
	smallest = *stack_a;
	curr_smallest = *(int *)(*stack_a)->content;
	while (tmp)
	{
		if (*(int *)tmp->content < curr_smallest)
		{
			smallest = tmp;
			curr_smallest = *(int *)tmp->content;
		}
		tmp = tmp->next;
	}
	return (smallest);
}
