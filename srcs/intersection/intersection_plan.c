/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_plan.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42/fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:59:38 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/05 22:57:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * L'equation vectorielle d'un plan passant par le point P (x, y, z)
 * et dont la normale est orientee selon a b et c est :
 *
 *		ax + by + cz + d = 0
 *
 *	On a d = a * xp + b * yp + c*zp
 *
 *   
 */
//printf("ETAPE1 : obj.pos - cam.pos : %.1f = %.1f - %.1f ; %.1f = %.1f - %.1f ; %.1f = %.1f - %.1f\n",
//		etape1.x, obj.position.x, camera.position.x, 
//		etape1.y, obj.position.y, camera.position.y, 
//		etape1.z, obj.position.z, camera.position.z);

/* 
 * SOIT D LE RAYON PASSANT PAR LE POINT D'ORIGINE
 * DU VECTEUR O (xO ; yO ; zO)
 * ET DE VECTEUR DIRECTEUR U (u ; v ; w),
 * on soustrait l'origine du plan a l'origine du rayon
 *
 * SYSTEME D'ÉQUATION PARAMETRIQUES DU RAYON :
 * x(t) -> U * t + xa
 * y(t) -> V * t + ya
 * z(t) -> W * t + za
 *
 * EQUATION PLAN : 
 * ax + by + cz + d = 0
 *
 * EN REMPLACANT LES ELEMENTS DANS L'EQUATION PLAN
 * a * (U * t + xa) + b * (V * t + ya) + c * (W * t + za) + d = 0
 *
 * ON REFORMULE
 *
 */
bool	intersection_plan(t_obj plan, t_cam camera, t_3d *p, t_3d *n)
{
	t_3d	origin;
	t_3d	etape1;
	float	etape2;
	float	etape3;

	origin = sub_vector(camera.position, plan.position);
	etape1 = sub_vector(plan.position, origin);
	etape2 = scalar_product(plan.direction, camera.ray);
	etape3 = scalar_product(plan.direction, etape1) / etape2;
	if (etape3 > 0)
	{
		*p = add_vector(camera.position, mul_vector(camera.ray, etape3));
		*n = normalize(sub_vector(*p, plan.position));
		return (true);
	}
	return (false);
}
