/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:28:22 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/17 15:09:52 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Return the distance between two points, a and b, 
 * which have 3d positions */
double	length(t_v3 point_a, t_v3 point_b)
{
	return (sqrt((point_b.x - point_a.x) * (point_b.x - point_a.x)
			+ (point_b.y - point_a.y) * (point_b.y - point_a.y)
			+ (point_b.z - point_a.z) * (point_b.z - point_a.z)));
}
