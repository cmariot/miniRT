/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_inter_cylinder.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:16:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/09 09:17:18 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	scd_intersection_cylinder(t_obj cyl, t_ray ray, t_3d *p, t_3d *n)
{
	double	abc[3];
	double	delta;
	float	t;
	t_3d	position;

	delta = get_delta(abc, cyl, ray);
	if (delta < 0)
		return (false);
	else if (delta == 0)
		t = t1(delta, abc);
	else
		t = min_double(t1(delta, abc), t2(delta, abc));
	if (t < 0)
		return (false);
	position = add_vector(ray.position, mul_vector(ray.direction, t));
	if (intersection(position, cyl))
		return (updated_values(p, n, position, cyl.position));
	else if (delta != 0)
	{
		position = add_vector(ray.position, mul_vector(ray.direction, t2(delta, abc)));
		if (intersection(position, cyl))
			return (updated_values(p, n, position, cyl.position));
	}
	return (false);
}
