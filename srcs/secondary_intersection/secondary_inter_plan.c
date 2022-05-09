/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_inter_plan.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:16:40 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/09 09:18:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	scd_intersection_plan(t_obj plan, t_ray ray, t_3d *p, t_3d *n)
{
	float	t;

	t = (scalar_product(plan.direction, plan.position)
		- scalar_product(plan.direction, ray.position))
		/ scalar_product(plan.direction, ray.direction);
	if (t >= 0)
	{
		*p = add_vector(ray.position, mul_vector(ray.direction, t));
		*n = normalize(add_vector(ray.position, mul_vector(*p, t)));
		return (true);
	}
	return (false);
}
