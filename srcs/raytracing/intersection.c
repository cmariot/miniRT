/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:16:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/20 22:43:57 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	get_t1(double delta, t_3d ray_direction, t_3d sphere_origin,
	t_3d ray_origin)
{
	double	t2;
	double	a;
	double	b;

	a = 1;
	b = 2 * scalar_product(ray_direction,
			sub_vector(sphere_origin, ray_origin));
	t2 = (-b - sqrt(delta)) / (2 * a);
	return (t2);
}

double	get_t2(double delta, t_3d ray_direction, t_3d sphere_origin,
	t_3d ray_origin)
{
	double	t2;
	double	a;
	double	b;

	a = 1;
	b = 2 * scalar_product(ray_direction,
			sub_vector(sphere_origin, ray_origin));
	t2 = (-b + sqrt(delta)) / (2 * a);
	return (t2);
}

double	get_delta(t_3d ray_direction, t_3d ray_origin, t_sphere sphere)
{
	double		a;
	double		b;
	double		c;
	double		delta;

	a = 1;
	b = 2 * scalar_product(ray_direction,
			sub_vector(sphere.point, ray_origin));
	c = norm_square(sub_vector(sphere.point, ray_origin))
		- (sphere.diameter * 0.5) * (sphere.diameter * 0.5);
	delta = b * b - 4 * (a * c);
	return (delta);
}

/* If delta < 0 -> No intersections
 * If delta > 0, the object could be behind the camera, need to get t2.
 * If delta and t2 > 0 there is an intersection */

bool	intersection(t_scene *scene, t_sphere sphere, t_3d *p, t_3d *n)
{
	double		delta;
	double		t1;
	double		t2;
	double		t;

	delta = get_delta(scene->camera.ray_direction, scene->camera.point, sphere);
	if (delta < 0)
		return (false);
	t2 = get_t2(delta, scene->camera.ray_direction, sphere.point,
			scene->camera.point);
	if (t2 < 0)
		return (false);
	t1 = get_t1(delta, scene->camera.ray_direction, sphere.point,
			scene->camera.point);
	if (t1 > 0)
		t = t1;
	else
		t = t2;
	*p = add_vector(scene->camera.point,
			mul_vector(t, scene->camera.ray_direction));
	*n = normalize(sub_vector(*p, sphere.point));
	return (true);
}
