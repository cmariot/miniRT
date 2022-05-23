/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:30:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 15:25:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	get_sphere_normale(t_ray *ray, t_obj *sphere)
{
	t_v3	origine;
	t_v3	inverse_normale;

	origine = sub_vector(ray->position, ray->intersection);
	ray->normale = normalize(sub_vector(ray->intersection, sphere->position));
	inverse_normale = mul_vector(ray->normale, -1);
	if (norm_square(sub_vector(origine, ray->normale))
		>= norm_square(sub_vector(origine, inverse_normale)))
		ray->normale = inverse_normale;
}

/*
 * SYSTEME D'ÉQUATION PARAMETRIQUES DU RAYON :
 *  x(t) -> ray->direction.x * t + ray->position.x
 *  y(t) -> ray->direction.y * t + ray->position.y
 *  z(t) -> ray->direction.z * t + ray->position.z
 *
 * EQUATION SPHERE : UN POINT EST SUR LA SPHERE SI IL Y A UNE SOLUTION
 *   x^2 + y^2 + z^2 = (sphere.radius)^2
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
 * REFORMULATION SOUS LA FORME At^2 + Bt + C = 0:
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

static void	get_triangle_solution(t_v3 a, t_v3 b, t_v3 c, t_ray *ray)
{
	t_v3		v1v0;
	t_v3		v2v0;
	t_v3		rov0;
	t_v3		n;
	t_v3		q;
	double		delta;
	double		uvt[3];

	v1v0 = sub_vector(b, a);
	v2v0 = sub_vector(c, a);
	rov0 = sub_vector(ray->origin, a);
	n = cross_product(v1v0, v2v0);
	q = cross_product(rov0, ray->direction);
	delta = 1.0 / scalar_product(ray->direction, n);
	uvt[0] = delta * cross_product(mul_vector(q, -1.0), v2v0);
	uvt[1] = delta * cross_product(q, v1v0);
	uvt[2] = delta * cross_product(mul_vector(n, -1.0), rov0);
	if (uvt[0] < 0.0 || uvt[1] < 0.0 || (uvt[0] + uvt[1]) > 1.0 )
		uvt[2] = -1;
	ray->t = new_vector(uvt[2], uvt[1], uvt[0]);
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
 */ return (intertriangle(triangle->ext1, triangle->ext2, triangle->axe, ray));
//
//Vecteur(x) =  direction * x + t
bool	intersection_sphere(t_obj *sphere, t_ray *ray)
{
	get_sphere_solution(ray, sphere);
	if (ray->t < 0)
		return (false);
	ray->intersection = get_position(ray->position, ray->direction, ray->t);
	get_sphere_normale(ray, sphere);
	return (true);
}
