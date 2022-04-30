/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:44:54 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/30 08:42:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* */
double	scalar_product(t_3d a, t_3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/* Return the distance between two points, a and b, 
 * which have 3d positions */
double	distance(t_3d point_a, t_3d point_b)
{
	return (pow((point_b.x - point_a.x) * (point_b.x - point_a.x)
			+ (point_b.y - point_a.y) * (point_b.y - point_a.y)
			+ (point_b.z - point_a.z) * (point_b.z - point_a.z), 0.5));
}
