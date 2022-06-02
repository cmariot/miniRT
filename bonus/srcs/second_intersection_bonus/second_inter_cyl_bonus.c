/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_inter_cyl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:25:48 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/31 15:23:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static bool	get_2nd_cyl_normale(t_obj *cyl, t_ray *ray)
{
	double	ext_distance;

	ext_distance = dot(sub_lvalue(&cyl->position,
				&ray->intersection), cyl->direction);
	if (fabs(ext_distance) > cyl->demi_height)
		return (false);
	return (true);
}

static void	get_2nd_cyl_solution(t_obj *cyl, t_ray *ray, t_discriminant *delta)
{
	t_v3	va;
	t_v3	ra0;

	va = cross(cross_lvalue(&ray->direction, &cyl->axe), cyl->axe);
	ra0 = cross(cross(sub_lvalue(&ray->position, &cyl->ext1),
				cyl->axe), cyl->axe);
	delta->abc[0] = dot_lvalue(&va, &va);
	delta->abc[1] = 2 * dot_lvalue(&ra0, &va);
	delta->abc[2] = dot_lvalue(&ra0, &ra0) - pow(cyl->radius, 2);
	delta->delta = pow(delta->abc[1], 2)
		- (4.0 * delta->abc[0] * delta->abc[2]);
	if (delta < 0)
		ray->t = -1;
	else if (delta == 0)
		ray->t = t1(delta->delta, delta->abc);
	else
		ray->t = min_positive(t1(delta->delta, delta->abc),
				t2(delta->delta, delta->abc));
}

bool	second_intersection_cylinder(t_obj *cyl, t_ray *ray)
{
	t_discriminant	delta;

	get_2nd_cyl_solution(cyl, ray, &delta);
	if (ray->t < 0)
		return (false);
	ray->intersection = add(ray->position, multiply_lvalue(&ray->direction,
				ray->t));
	if (get_2nd_cyl_normale(cyl, ray))
		return (true);
	if (delta.delta != 0)
	{
		ray->t = t2(delta.delta, delta.abc);
		ray->intersection = add(ray->position, multiply_lvalue(&ray->direction,
					ray->t));
		if (get_2nd_cyl_normale(cyl, ray))
			return (true);
	}
	return (false);
}
