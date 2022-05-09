/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_inter_sphere.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:14:24 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/09 09:18:27 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	scd_intersection_sphere(t_obj sphere, t_ray ray, t_3d *p, t_3d *n)
{
	double		delta;
	double		abc[3];
	double		t;

	delta = get_delta(sphere, ray, abc);
	if (delta < 0)
		return (false);
	else if (delta == 0)
		t = t1(delta, abc);
	else
		t = min_double(t1(delta, abc), t2(delta, abc));
	if (t < 0)
		return (false);
	*p = add_vector(ray.position, mul_vector(ray.direction, t));
	*n = normalize(sub_vector(*p, sphere.position));
	return (true);
}
