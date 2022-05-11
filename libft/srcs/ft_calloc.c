/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:58:09 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/10 20:27:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The calloc() function contiguously allocates enough
 * space for count objects that are size bytes of memory each
 * and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero. */

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;
	size_t	nb_bytes;

	nb_bytes = size * count;
	new = malloc(nb_bytes);
	if (!new)
		return (NULL);
	ft_bzero(new, nb_bytes);
	return (new);
}
