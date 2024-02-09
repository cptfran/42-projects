/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:48:56 by sfrankie          #+#    #+#             */
/*   Updated: 2023/12/15 12:50:35 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

#include <stdio.h>
int	main(void)
{
	t_list *lst = malloc(sizeof(t_list));

	if (lst == NULL)
	{
		printf("error\n");
		return 1;
	}

	lst->content = "first";
	lst->next = NULL;

	t_list *new = malloc(sizeof(t_list));
	if (new == NULL)
	{
		printf("error\n");
		return 1;
	}

	new->content = "new";
	new->next = NULL;

	ft_lstadd_back(&lst, new);

	while (lst != NULL)
	{
		printf("node: %s\n", (char*)lst->content);
		lst = lst->next;
	}

	return (0);
}