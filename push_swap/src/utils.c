/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:35:25 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/12 16:32:05 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	ft_printstack_a(t_list *list)
// {
// 	ft_printf(GREEN "\nSTACK_A: ");
// 	while (list)
// 	{
// 		ft_printf("%d ", *(int *)list->content);
// 		list = list->next;
// 	}
// 	ft_printf("\n\n" RESET);
// }

// void	ft_printstack_b(t_list *list)
// {
// 	ft_printf(GREEN "\nSTACK_B: ");
// 	while (list)
// 	{
// 		ft_printf("%d ", *(int *)list->content);
// 		list = list->next;
// 	}
// 	ft_printf("\n\n" RESET);
// }

int	sorted_stack(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stack_len(t_list **stack)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	ft_dellistcontent(void *content)
{
	free(content);
}

void	ft_lstremove_last(t_list **lst)
{
	t_list	*current;
	t_list	*previous;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	current = *lst;
	previous = NULL;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	if (previous)
		previous->next = NULL;
}
