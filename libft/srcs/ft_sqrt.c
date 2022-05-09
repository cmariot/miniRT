/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:27:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/08 22:20:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double number)
{
    long i;
    float y;

	i = 0x5f3759df - ( (*(long *) &number) >> 1);
	y= *(float *) &i;
    y *= (1.5F - (number * 0.5F * y * y));
    return (number * y);
}
