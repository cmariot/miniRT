/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:53:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 19:25:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	q_rsqrt(float number)
{
	long		i;
	float		x2;
	float		y;
	const float	threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));
	return (y);
}

/* Return the norm of a vetor, aka it's length.
 * In mathematics, the double bar (||a||) notation indicates the
 * lentgh of a vector. */

extern inline double	norm(const t_v3 a)
{
	return (1.0 / q_rsqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}
