/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:43:39 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/30 11:23:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_atoi converts an array of char into an integer */

long	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	n;

	sign = 1;
	n = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	while ((ft_isdigit(*str) || *str == '+' || *str == '-') && *str != '\0')
	{
		if ((*str == '-' || *str == '+') && n)
			break ;
		if ((*str == '-' || *str == '+') && !(ft_isdigit(str[1])))
			return (0);
		if (*str == '-' && ft_isdigit(str[1]))
			sign = -1;
		else if (ft_isdigit(*str))
			n = n * 10 + (*str - 48);
		str++;
	}
	if (n > 9223372036854775807 && sign == -1)
		return (0);
	else if (n > 9223372036854775807 && sign == 0)
		return (-1);
	return ((long)(n * sign));
}
