/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:58:12 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/15 16:00:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_3d	normalize(t_3d a)
{
	t_3d		b;
	double		normalized;

	normalized = 1 / fast_sqrt(norm_square(a));
	b.x = a.x * normalized;
	b.y = a.y * normalized;
	b.z = a.z * normalized;
	return (b);
}
