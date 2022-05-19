/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_plan.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42/fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:59:38 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 09:17:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	get_plan_normale(t_ray *ray, t_obj *obj)
{
	t_v3	origine;
	t_v3	inverse_normale;

	origine = add_vector(ray->position, ray->intersection);
	ray->normale = obj->direction;
	inverse_normale = mul_vector(ray->normale, -1.0);
	if (norm_square(add_vector(origine, ray->normale))
		>= norm_square(add_vector(origine, inverse_normale)))
		ray->normale = inverse_normale;
}

/*
 * SYSTEME D'ÉQUATION PARAMETRIQUES DU RAYON :
 *  x(t) -> ray->direction.x * t + ray->position.x
 *  y(t) -> ray->direction.y * t + ray->position.y
 *  z(t) -> ray->direction.z * t + ray->position.z
 *
 * EQUATION PLAN :
 * A(x - plan.position.x) + B(y - plan.position.y) + C(z - plan.position.z) = 0
 *
 * AVEC :
 * A = plan.direction.x
 * B = plan.direction.y
 * C = plan.direction.z
 *
 * EQUATION DU PLAN EN FONCTION DE SA POSITION ET SA DIRECTION:
 *   plan.direction.x * (x - plan.position.x)
 * + plan.direction.y * (y - plan.position.y)
 * + plan.direction.z * (z - plan.position.z) = 0
 *
 * ON CHERCHE A SAVOIR SI NOTRE RAYON COUPE LE PLAN,
 * ON REMPLACE x, y et z PAR x(t), y(t) et z(t)
 *
 *   plan.direction.x * x(t)
 * + plan.direction.y * y(t)
 * + plan.direction.z * z(t)
 * - scalar_product(plan.direction, plan.position) = 0
 *
 *   plan.direction.x * (ray.direction.x * t + ray.position.x)
 * + plan.direction.y * (ray.direction.y * t + ray.position.y)
 * + plan.direction.z * (ray.direction.z * t + ray.position.z)
 * - scalar_product(plan.direction, plan.position) = 0
 *
 *   plan.direction.x * ray.direction.x * t + plan.direction.x * ray.position.x
 * + plan.direction.y * ray.direction.y * t + plan.direction.y * ray.position.y
 * + plan.direction.z * ray.direction.z * t + plan.direction.z * ray.position.z
 * - scalar_product(plan.direction, plan.position) = 0
 *
 *   plan.direction.x * ray.direction.x * t
 * + plan.direction.y * ray.direction.y * t
 * + plan.direction.z * ray.direction.z * t
 * - scalar_product(plan.direction, plan.position)
 * + scalar_product(plan.direction, ray.position) = 0
 *
 *   t * (scalar_product(plan.direction, ray.direction))
 * - scalar_product(plan.direction, plan.position)
 * + scalar_product(plan.direction, ray.position) = 0
 *
 * t = (scalar_product(plan.direction, plan.position)
 *     - scalar_product(plan.direction, ray.position))
 *     / scalar_product(plan.direction, ray.direction)
 *
 * Dans le cas d'un plan on a deux normales pour un point,
 * on va selectionner celle qui est dirigee vers la camera
 */

static void	get_plan_solution(t_ray *ray, t_obj *plan)
{
	ray->t = (scalar_product(plan->direction, plan->position)
			- scalar_product(plan->direction, ray->position))
		/ scalar_product(plan->direction, ray->direction);
}

bool	intersection_plan(t_obj *plan, t_ray *ray)
{
	get_plan_solution(ray, plan);
	if (ray->t < 0)
		return (false);
	ray->intersection = get_position(ray->position, ray->direction, ray->t);
	get_plan_normale(ray, plan);
	return (true);
}
