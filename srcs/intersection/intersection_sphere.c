/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:30:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 23:27:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Solution 1 : (-b - racine(delta)) / 2a
 */
double	t1(double delta, double *abc)
{
	return ((-abc[1] - sqrt(delta)) / (2 * abc[0]));
}

/* 
 * Solution 2 : (-b + racine(delta)) / 2a
 * Racine de delta étant positif, on a t2 > t1
 */
double	t2(double delta, double *abc)
{
	return ((-abc[1] + sqrt(delta)) / (2 * abc[0]));
}

/* En supposant que t1 < t2 */
double	min_double(const double t1, const double t2)
{
	if (t1 > 0)
		return (t1);
	return (t2);
}

/*
 * SYSTEME D'ÉQUATION PARAMETRIQUES DU RAYON :
 *  x(t) -> ray->direction.x * t + ray->position.x
 *  y(t) -> ray->direction.y * t + ray->position.y
 *  z(t) -> ray->direction.z * t + ray->position.z
 *
 * EQUATION SPHERE : UN POINT EST SUR LA SPHERE SI IL Y A UNE SOLUTION
 *   (sphere->position.x)^2 + (sphere->position.y)^2 + (sphere->position.z)^2
 * = (sphere.radius)^2
 *
 * EN REMPLACANT LES ELEMENTS DANS L'EQUATION SPHERE :
 *   (ray->direction.x * t + ray->position.x)^2
 * + (ray->direction.y * t + ray->position.y)^2
 * + (ray->direction.z * t + ray->position.z)^2 - (sphere.radius)^2 = 0
 *
 * ON DEVELOPPE AVEC LES IDENTITES REMARQUABLES (A+B)^2 = A^2 + 2AB + B^2
 * (ray->direction.x * t)^2 + (ray->direction.y * t)^2 + (ray->direction.z * t)^2
 * + 2(ray->direction.x * t * ray->position.x)
 * + 2(ray->direction.y * t * ray->position.y)
 * + 2(ray->direction.z * t * ray->position.z)
 * + ray->position.x^2 + ray->position.y^2 + ray->position.z^2
 * - (sphere.radius)^2 = 0
 *
 * REFORMULATION :
 *   ((ray->direction.x)^2 + (ray->direction.y)^2 + (ray->direction.z)^2) * t^2
 * + ((ray->direction.x * ray->position.x)
 * + (ray->direction.y * ray->position.y)
 * + (ray->direction.z * ray->position.z) * 2 * t)
 * + ray->position.x^2 + ray->position.y^2 + ray->position.z^2
 * - (sphere.radius)^2 = 0
 *
 * ON DETERMINE A B ET C DU DISCRIMINANT 
 * A = ((ray->direction.x)^2 + (ray->direction.y)^2 + (ray->direction.z)^2)
 * B = ((ray->direction.x * ray->position.x)
 *     + (ray->direction.y * ray->position.y)
 *     + (ray->direction.z * ray->position.z)) * 2
 * C = ray->position.x^2 + ray->position.y^2 + ray->position.z^2
 *     - (sphere.radius)^2
 *
 * DELTA = B^2 - 4AC
 */

static double	get_delta(t_obj sphere, t_ray ray, double *abc)
{
	t_v3		origin;
	double		delta;

	origin = sub_vector(ray.position, sphere.position);
	abc[0] = norm_square(ray.direction);
	abc[1] = scalar_product(ray.direction, origin) * 2.0;
	abc[2] = norm_square(origin) - (sphere.radius * sphere.radius);
	delta = pow(abc[1], 2) - (4.0 * abc[0] * abc[2]);
	return (delta);
}

/*
 * On a un rayon caracterisé par son point d'origine (position camera)
 * et sa direction (normalisée).
 * - origine : ray->position.x, ray->position.y, ray->position.z
 * - direction : ray->direction.x, ray->direction.y, ray->direction.z
 *
 * On cherche a trouver si ce rayon va toucher une sphere,
 * dont on connait la position du centre et le rayon.
 * - origine : sphere->position.x, sphere->position.y, sphere->position.z
 * - rayon : sphere->radius
 */

bool	intersection_sphere(t_obj sphere, t_ray *ray)
{
	double		delta;
	double		abc[3];

	delta = get_delta(sphere, *ray, abc);
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
	ray->normale = normalize(sub_vector(ray->intersection, sphere.position));
	return (true);
}
