/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:14:16 by sfrankie          #+#    #+#             */
/*   Updated: 2024/01/12 16:59:39 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # define GREEN "\x1B[32m"
// # define RESET "\x1B[0m"
# include "../libft/libft.h"

// void	ft_printstack_a(t_list *list);
// void	ft_printstack_b(t_list *list);

t_list	*find_biggest(t_list **stack_b);
t_list	*find_close_in_a(t_list *stack_b, t_list **stack_a);
t_list	*find_close_in_b(t_list *stack_a, t_list **stack_b);
t_list	*find_closest_in_a(t_list **stack_a, t_list **stack_b);
t_list	*find_closest_in_b(t_list **stack_b, t_list **stack_a);
int		find_node_i(t_list *node, t_list **stack);
t_list	*find_smallest(t_list **stack_a);
void	ft_dellistcontent(void *content);
int		distance(t_list **stack_1, t_list *node_1,
			t_list **stack_2, t_list *node_2);
int		ft_ifdigitarr(char **argv);
int		ft_ifdigitstr(char *argv);
int		ft_ifduparr(char **argv);
int		ft_ifdupstr(char *argv);
int		ft_iferror(int argc, char **argv);
int		ft_ifintarr(char **argv);
int		ft_ifintnbr(char *argv);
void	ft_lstremove_last(t_list **lst);
void	ft_makestack(t_list **stack, int argc, char **argv);
void	move_smallest_top(t_list **stack_a);
void	move_to_a(t_list **stack_b, t_list **stack_a);
void	move_to_b(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rotate_both(t_list *node_1, t_list **stack_1,
			t_list *node_2, t_list **stack_2);
void	rotate_single(t_list *node_1, t_list **stack_1,
			t_list *node_2, t_list **stack_2);
void	rotate_stacks(t_list *node_1, t_list **stack_1,
			t_list *node_2, t_list **stack_2);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b);
int		sorted_stack(t_list **stack_a);
void	sort_3(t_list **stack_a);
void	sort_big(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
int		stack_len(t_list **stack_a);
int		stack_middle(t_list **stack);

#endif