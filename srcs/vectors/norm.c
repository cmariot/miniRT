/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:53:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/20 11:48:41 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Fast inverse square root, it's an approximation but it's
 * much faster than sqrt */
float	fast_sqrt(float number)
{
	long		i;
	float		x2;
	float		y;
	float		threehalfs;

	threehalfs = 1.5F;
	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));
	return (1 / y);
}

/* Return the norm of a vetor, aka it's length. 
 * In mathematics, the double bar (||a||) notation indicates the
 * lentgh of a vector. */
double	norm(t_3d a)
{
	return (fast_sqrt(norm_square(a)));
}

/* Return the square of a vector norm */
double	norm_square(t_3d a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}
