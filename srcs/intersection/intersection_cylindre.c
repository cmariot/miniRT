/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cylindre.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:25:48 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 20:39:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	get_cyl_normale(t_obj cyl, t_ray *ray)
{
	t_v3	origine;
	float	ext_distance;
	t_v3	axe_point;
	t_v3	normale1;
	t_v3	normale2;

	origine = sub_vector(cyl.position, ray->intersection);
	ext_distance = scalar_product(origine, cyl.direction);
	if (fabs(ext_distance) > cyl.height / 2.0)
		return (false);
	axe_point = get_position(cyl.position, cyl.direction, -ext_distance);
	normale1 = normalize(sub_vector(axe_point, ray->intersection));
	normale2 = mul_vector(normale1, -1);
	if (norm_square(sub_vector(ray->position,
				add_vector(ray->intersection, normale1)))
		< norm_square(sub_vector(ray->position,
				add_vector(ray->intersection, normale2))))
		ray->normale = normale1;
	else
		ray->normale = normale2;
	return (true);
}

static float	get_cyl_delta(float *abc, t_obj cyl, t_ray ray)
{
	t_v3	va;
	t_v3	ra0;

	va = cross_product(cross_product(ray.direction, cyl.axe), cyl.axe);
	ra0 = cross_product(cross_product(sub_vector(ray.position, cyl.ext1),
				cyl.axe), cyl.axe);
	abc[0] = scalar_product(va, va);
	abc[1] = 2 * scalar_product(ra0, va);
	abc[2] = scalar_product(ra0, ra0) - pow(cyl.radius, 2);
	return (pow(abc[1], 2) - (4.0 * abc[0] * abc[2]));
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
 * A = scalar_product(VA, VA)
 * B = 2 * scalar_product(RA0, VA)
 * C = scalar_product(RA0, RA0) - pow(obj.height, 2)
 *
 * S   = div_vector(sub_vector(RA2, RA1),
 *		 absolute_vector(sub_vector(RA2, RA1)))
 * VA  = mul_vector(mul_vector(S, ray.direction), S);
 * RA0 = mul_vector(mul_vector(S, sub_vector(ray.position, RA1)), S);
 *
 * LE CYLINDRE EST DELIMITE PAR DEUX POINTS, RA1 et RA2 :
 * RA1 = mul_vector(add_vector(obj.position, obj.direction), obj.height / 2)
 * RA2 = mul_vector(add_vector(obj.position, obj.direction), -obj.height / 2)
 */

bool	intersection_cylinder(t_obj *cyl, t_ray *ray)
{
	float	abc[3];
	float	delta;

	delta = get_cyl_delta(abc, *cyl, *ray);
	if (delta < 0)
		return (false);
	else if (delta == 0)
		ray->t = t1(delta, abc);
	else
		ray->t = min_positive(t1(delta, abc), t2(delta, abc));
	if (ray->t < 0)
		return (false);
	ray->intersection = get_position(ray->position, ray->direction, ray->t);
	if (get_cyl_normale(*cyl, ray))
		return (true);
	else if (delta != 0)
	{
		ray->t = t2(delta, abc);
		ray->intersection = get_position(ray->position, ray->direction, ray->t);
		if (get_cyl_normale(*cyl, ray))
			return (true);
	}
	return (false);
}
