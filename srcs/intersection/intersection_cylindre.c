/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cylindre.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:25:48 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/09 21:34:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	updated_values(t_3d *p, t_3d *n, t_3d obj_position)
{
	*n = normalize(sub_vector(*p, obj_position));
	return (true);
}

static bool	intersection(t_3d position, t_obj cyl)
{
	if (scalar_product(sub_vector(position, cyl.ra1), cyl.s) > 0
		&& scalar_product(sub_vector(position, cyl.ra2), cyl.s) < 0)
		return (true);
	return (false);
}

static double	get_delta(double *abc, t_obj cyl, t_ray ray)
{
	t_3d	va;
	t_3d	ra0;

	va = cross_product(cross_product(ray.direction, cyl.s), cyl.s);
	ra0 = cross_product(cross_product(sub_vector(ray.position, cyl.ra1), cyl.s), cyl.s);
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
 * S = div_vector(sub_vector(RA2, RA1), absolute_vector(sub_vector(RA2, RA1)))
 * VA = mul_vector(mul_vector(S, ray.direction), S);
 * RA0 = mul_vector(mul_vector(S, sub_vector(ray.position, RA1)), S);
 *
 * LE CYLINDRE EST DELIMITE PAR DEUX POINTS, RA1 et RA2 :
 * RA1 = multiply_vector(add_vector(obj.position, obj.direction), obj.height / 2)
 * RA2 = multiply_vector(add_vector(obj.position, obj.direction), -obj.height / 2)
 *
 */

bool	intersection_cylinder(t_obj cyl, t_ray ray, t_3d *p, t_3d *n)
{
	double	abc[3];
	double	delta;
	float	t;

	delta = get_delta(abc, cyl, ray);
	if (delta < 0)
		return (false);
	else if (delta == 0)
		t = t1(delta, abc);
	else
		t = min_double(t1(delta, abc), t2(delta, abc));
	if (t < 0)
		return (false);
	*p = add_vector(ray.position, mul_vector(ray.direction, t));
	//intersection sur le cote externe
	if (intersection(*p, cyl))
		return (updated_values(p, n, cyl.position));
	//intersection sur le cote interne
	else if (delta != 0)
	{
		*p = add_vector(ray.position, mul_vector(ray.direction, t2(delta, abc)));
		if (intersection(*p, cyl))
			return (updated_values(p, n, cyl.position));
	}
	return (false);
}
