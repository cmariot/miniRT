/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_inter_sphere_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:30:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 21:37:24 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	get_sphere_solution(t_ray *ray, t_obj *sphere)
{
	t_v3		origin;
	double		abc[3];
	double		delta;

	origin = sub_lvalue(&ray->position, &sphere->position);
	abc[0] = norm_square_lvalue(&ray->direction);
	abc[1] = dot_lvalue(&ray->direction, &origin) * 2.0;
	abc[2] = norm_square_lvalue(&origin) - pow(sphere->radius, 2);
	delta = pow(abc[1], 2) - (4.0 * abc[0] * abc[2]);
	if (delta < 0)
		ray->t = -1;
	else
		ray->t = t2(delta, abc);
}

bool	second_intersection_sphere(t_obj *sphere, t_ray *ray)
{
	get_sphere_solution(ray, sphere);
	if (ray->t < 0)
		return (false);
	return (true);
}
