/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cylindre.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:25:48 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/13 22:33:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//static bool	updated_values(t_v3 *p, t_v3 *n, t_v3 obj_position)
//{
//	*n = normalize(sub_vector(*p, obj_position));
//	return (true);
//}

static bool	intersection(t_v3 position, t_obj cyl)
{
	if (scalar_product(sub_vector(position, cyl.ext1), cyl.axe) > 0
		&& scalar_product(sub_vector(position, cyl.ext2), cyl.axe) < 0)
		return (true);
	return (false);
}

static double	get_delta(double *abc, t_obj cyl, t_ray ray)
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
 * S = div_vector(sub_vector(RA2, RA1),
 *		absolute_vector(sub_vector(RA2, RA1)))
 * VA = mul_vector(mul_vector(S, ray.direction), S);
 * RA0 = mul_vector(mul_vector(S, sub_vector(ray.position, RA1)), S);
 *
 * LE CYLINDRE EST DELIMITE PAR DEUX POINTS, RA1 et RA2 :
 * RA1 = mul_vector(add_vector(obj.position, obj.direction), obj.height / 2)
 * RA2 = mul_vector(add_vector(obj.position, obj.direction), -obj.height / 2)
 *
 */

bool	intersection_cylinder(t_obj cyl, t_ray *ray)
{
	double	abc[3];
	double	delta;

	return (false);
	delta = get_delta(abc, cyl, *ray);
	if (delta < 0)
		return (false);
	else if (delta == 0)
		ray->t = t1(delta, abc);
	else
		ray->t = min_double(t1(delta, abc), t2(delta, abc));
	if (ray->t < 0)
		return (false);
	ray->intersection = add_vector(ray->position,
			mul_vector(ray->direction, ray->t));
	if (intersection(ray->intersection, cyl))
		return (true);
	else if (delta != 0)
	{
		ray->intersection = add_vector(ray->position,
				mul_vector(ray->direction, t2(delta, abc)));
		if (intersection(ray->intersection, cyl))
			return (true);
	}
	return (false);
}
