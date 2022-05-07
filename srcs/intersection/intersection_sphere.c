/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:30:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/07 15:38:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Solution : (-b - Racine(delta)) / 2a */
static double	t1(double delta, double *abc)
{
	return ((-abc[1] - sqrt(delta)) / (2 * abc[0]));
}

/* Solution : (-b + Racine(delta)) / 2a */
static double	t2(double delta, double *abc)
{
	return ((-abc[1] + sqrt(delta)) / (2 * abc[0]));
}

/* Si a et b sont positifs, on retourne le plus petit,
 * sinon on retourne le plus grand */

static double	min_double(double t1, double t2)
{
	if (t1 > 0)
		return (t1);
	else
		return (t2);
}
/* 
 * SOIT D LE RAYON PASSANT PAR LE POINT D'ORIGINE
 * DU VECTEUR O (xO ; yO ; zO)
 * ET DE VECTEUR DIRECTEUR U (u ; v ; w),
 * on soustrait l'origine de la sphere a l'origine du rayon
 *
 * SYSTEME D'ÉQUATION PARAMETRIQUES DU RAYON :
 * x(t) -> U * t + xa
 * y(t) -> V * t + ya
 * z(t) -> W * t + za
 *
 * EQUATION SPHERE : 
 * (sphere.center.x)^2 + (sphere.center.y)^2 + (sphere.center.z)^2
 * = (sphere.rayon)^2
 *
 * EN REMPLACANT LES ELEMENTS DANS L'EQUATION SPHERE
 * (U * t + xO)^2 + (V * t + yO)^2 + (W * t + zO)^2 - (sphere.rayon)^2 = 0
 *
 * ON DEVELOPPE AVEC LES IDENTITES REMARQUABLES (A+B)^2 = A^2 + 2AB + B^2
 *   (U * t)^2 + 2(U * t * xO) + xO^2
 * + (V * t)^2 + 2(V * t * yO) + yO^2
 * + (W * t)^2 + 2(W * t * zO) + zO^2
 * - (sphere.rayon)^2 = 0
 * 
 * ON REFORMULE POUR FORMER UNE EQUATION DE TYPE ax^2 + bx + c = 0
 *   (U * t)^2 + (V * t)^2 + (W * t)^2
 * + 2(U * t * xO) + 2(V * t * yO) + 2(W * t * zO)
 * + xO^2 + yO^2 + zO^2 - (sphere.rayon)^2
 * = 0
 *
 *   (U^2 + V^2 + W^2)t^2
 * + ((U * xO) + (V * yO) + (W * zO)) * 2 * t
 * + xO^2 + yO^2 + zO^2 - (sphere.rayon)^2
 * = 0
 *
 * ON DETERMINE A B ET C DU DISCRIMINANT 
 * a = (U^2 + V^2 + W^2)
 * b = ((U * xO) + (V * yO) + (W * zO)) * 2
 * c = (xO^2 + yO^2 + zO^2) - (sphere.rayon)^2
 *
 * DELTA = B^2 - 4AC
 */

static double	get_delta(t_obj sphere, t_cam camera, double *abc)
{
	t_3d		origin;
	double		delta;

	origin = sub_vector(camera.position, sphere.position);
	abc[0] = norm_square(camera.ray);
	abc[1] = scalar_product(camera.ray, origin) * 2.0;
	abc[2] = norm_square(origin) - (sphere.radius * sphere.radius);
	delta = pow(abc[1], 2) - (4.0 * abc[0] * abc[2]);
	return (delta);
}

/* On a un rayon caracterisé par son point d'origine (position camera)
 * et sa direction (normalisée).
 * - origine : scene->camera.point.x, scene->camera.point.y
 *   et scene->camera.point.z
 * - direction :	*p.x, *p.y et *p.z
 *
 * On cherche a trouver si ce rayon va toucher une sphere,
 * dont on connait la position du centre et le rayon.
 * - origine : sphere.point.x, sphere.point.y, sphere.point.z
 * - rayon : sphere.rayon */

bool	intersection_sphere(t_obj sphere, t_cam camera, t_3d *p, t_3d *n)
{
	double		delta;
	double		abc[3];
	double		t;

	delta = get_delta(sphere, camera, abc);
	if (delta < 0)
		return (false);
	else if (delta == 0)
		t = t1(delta, abc);
	else
		t = min_double(t1(delta, abc), t2(delta, abc));
	if (t < 0)
		return (false);
	*p = add_vector(camera.position, mul_vector(camera.ray, t));
	*n = normalize(sub_vector(*p, sphere.position));
	return (true);
}
