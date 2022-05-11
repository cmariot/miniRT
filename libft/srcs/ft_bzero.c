/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:08:10 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/10 20:28:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_bzero() writes n zeroed bytes to the string s. */

void	ft_bzero(void *ptr, size_t nb_bytes)
{
	size_t	i;

	i = 0;
	while (i < nb_bytes)
		((char *)ptr)[i++] = 0;
}
