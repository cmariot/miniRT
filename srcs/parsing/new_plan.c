/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:33:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/05 00:57:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	plan_intersection(t_obj obj, t_cam camera, t_3d *p, t_3d *n)
{
//	(void)obj;
//	(void)camera;
	(void)p;
	(void)n;
	t_3d	r0;
	t_3d	v;
	t_3d	rp;
	t_3d	n2;

	r0 = camera.position;
	v = camera.ray;
	rp = obj.position;
	n2 = obj.direction;
	double A = scalar_product(n2, v);
	double B = scalar_product(n2, sub_vector(r0, rp));
	if (-B / A >= 0)
	{
		printf("%f * t + %f = 0\n", A, B);
		return (true);
	}
	return (false);
}

int	new_plan(t_obj *plan, char **array)
{
	plan->intersection = &plan_intersection;
	plan->print = &print_plan;
	if (ft_arraylen(array) != 4)
		return (rt_error("Too much arguments in plan declaration."));
	else if (set_position(&(plan->position), array[1]))
		return (1);
	else if (set_direction(&(plan->direction), array[2]))
		return (1);
	else if (set_colors(&(plan->color), array[3]))
		return (1);
	return (0);
}
