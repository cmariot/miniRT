/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_inter_plan.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42/fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:59:38 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 21:37:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	get_plan_solution(t_ray *ray, t_obj *plan)
{
	ray->t = (scalar_product(plan->direction, plan->position)
			- scalar_product(plan->direction, ray->position))
		/ scalar_product(plan->direction, ray->direction);
}

bool	second_intersection_plan(t_obj *plan, t_ray *ray)
{
	get_plan_solution(ray, plan);
	if (ray->t < 0)
		return (false);
	return (true);
}
