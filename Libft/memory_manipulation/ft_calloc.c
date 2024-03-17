/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:53:04 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:41:33 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The calloc() function contiguously allocates enough space for count objects
// that are size bytes of memory each and returns a pointer to the allocated 
// memory. The allocated memory is filled with bytes of value zero.

#include "../libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
