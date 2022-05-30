/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cylindre.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:25:48 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 17:14:53 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	get_cyl_normale(t_obj *cyl, t_ray *ray)
{
	t_v3	origine;
	double	ext_distance;
	t_v3	axe_point;
	t_v3	inverse_normale;

	origine = sub(cyl->position, ray->intersection);
	ext_distance = dot(origine, cyl->direction);
	if (fabs(ext_distance) > cyl->demi_height)
		return (false);
	axe_point = get_position(cyl->position, cyl->direction, -ext_distance);
	ray->normale = normalize(sub(axe_point, ray->intersection));
	inverse_normale = multiply(ray->normale, -1);
	if (norm_square(sub(ray->position,
				add(ray->intersection, ray->normale)))
		>= norm_square(sub(ray->position,
				add(ray->intersection, inverse_normale))))
		ray->normale = inverse_normale;
	return (true);
}

static void	get_cyl_solution(t_obj *cyl, t_ray *ray, t_discriminant *delta)
{
	t_v3	va;
	t_v3	ra0;

	va = cross(cross(ray->direction, cyl->axe), cyl->axe);
	ra0 = cross(cross(sub(ray->position, cyl->ext1),
				cyl->axe), cyl->axe);
	delta->abc[0] = dot(va, va);
	delta->abc[1] = 2 * dot(ra0, va);
	delta->abc[2] = dot(ra0, ra0) - pow(cyl->radius, 2);
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

/*
 * SYSTEME D'ÉQUATION PARAMETRIQUES DU RAYON :
 * x(t) -> U * t + xa
 * y(t) -> V * t + ya
 * z(t) -> W * t + za
 *
 * U, V et W correspondent a la direction,
 * xa, ya, et za sa position.
 *
 * EQUATION CARTESIENNE D'UN CYLINDRE PASSANT PAR cyl.position
 * AVEC UN AXE ORIENTE SELON cyl.direction,
 * DE RAYON cyl.radius ET DE HAUTEUR cyl.height :
 * At^2 + Bt + C = 0
 *
 * AVEC :
 *
 * A = dot(VA, VA)
 * B = 2 * dot(RA0, VA)
 * C = dot(RA0, RA0) - pow(obj.height, 2)
 *
 * S   = divide(sub(RA2, RA1),
 *		 absolute_vector(sub(RA2, RA1)))
 * VA  = multiply(multiply(S, ray.direction), S);
 * RA0 = multiply(multiply(S, sub(ray.position, RA1)), S);
 *
 * LE CYLINDRE EST DELIMITE PAR DEUX POINTS, RA1 et RA2 :
 * RA1 = multiply(add(obj.position, obj.direction), obj.height / 2)
 * RA2 = multiply(add(obj.position, obj.direction), -obj.height / 2)
 */

bool	intersection_cylinder(t_obj *cyl, t_ray *ray)
{
	t_discriminant	delta;

	get_cyl_solution(cyl, ray, &delta);
	if (ray->t < 0)
		return (false);
	ray->intersection = get_position(ray->position, ray->direction, ray->t);
	if (get_cyl_normale(cyl, ray))
		return (true);
	else if (delta.delta != 0)
	{
		ray->t = t2(delta.delta, delta.abc);
		ray->intersection = get_position(ray->position, ray->direction, ray->t);
		if (get_cyl_normale(cyl, ray))
			return (true);
	}
	return (false);
}
