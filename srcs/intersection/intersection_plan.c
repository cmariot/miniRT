/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_plan.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42/fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:59:38 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/05 16:37:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	intersection_plan(t_obj obj, t_cam camera, t_3d *p, t_3d *n)
{
	float	t;
	
	(void)p;
	(void)n;
	t = scalar_product(sub_vector(normalize(obj.position), normalize(camera.position)), obj.direction)
		/ scalar_product(camera.ray, obj.direction);
	printf("T = %f\n", t);
	if (t == 0)
		return (true);
	return (false);
}
