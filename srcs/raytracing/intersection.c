/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:31:35 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/01 01:15:09 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Solution : (-b - Racine(delta)) / 2a */
double	first_solution(double delta, double *abc)
{
	return ((-abc[1] - ft_sqrt(delta)) / (2 * abc[0]));
}

/* Solution : -b + Racine(delta / 2a) */
double	second_solution(double delta, double *abc)
{
	return ((-abc[1] + ft_sqrt(delta)) / (2 * abc[0]));
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

double	get_delta(t_camera camera, t_sphere sphere, double *abc)
{
	t_3d		origin;
	double		delta;

	origin = sub_vector(camera.point, sphere.point);
	abc[0] = norm_square(camera.ray_direction);
	abc[1] = scalar_product(camera.ray_direction, origin) * 2;
	abc[2] = norm_square(origin) - (sphere.radius * sphere.radius);
	delta = abc[1] * abc[1] - 4 * abc[0] * abc[2];
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

bool	intersection(t_scene *scene, t_sphere sphere)
{
	double		delta;
	double		abc[3];

	delta = get_delta(scene->camera, sphere, abc);
	if (delta < 0)
	{
		return (false);
	}
	else if (delta > 0)
	{
	}
	else
	{
	}
	return (true);
}
