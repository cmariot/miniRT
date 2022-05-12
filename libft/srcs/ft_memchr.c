/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:25:16 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 19:28:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The ft_memchr() function locates the first occurrence of c
 * (converted to an unsigned char) in string s. */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (unsigned char)c)
			return ((void *)&(s[i]));
		i++;
	}
	return (NULL);
}
