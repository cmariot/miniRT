/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:36:54 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/06 11:32:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_3d	absolute_vector(t_3d a)
{
	t_3d	b;

	if (a.x > 0)
		b.x = a.x;
	else
		b.x = -a.y;
	if (a.y > 0)
		b.y = a.y;
	else
		b.y = -a.y;
	if (a.z > 0)
		b.z = a.z;
	else
		b.z = -a.z;
	return (b);
}

bool	cylinder_intersection(t_obj obj, t_cam camera, t_3d *p, t_3d *n)
{
	(void)obj;
	(void)camera;
	(void)p;
	(void)n;
	return (false);
}

int	new_cylinder(t_obj *cylinder, char **array)
{
	cylinder->intersection = &cylinder_intersection;
	cylinder->print = &print_cylinder;
	if (ft_arraylen(array) != 6)
		return (rt_error("Too much arguments in cylinder declaration."));
	if (set_position(&cylinder->position, array[1]))
		return (1);
	if (set_direction(&cylinder->direction, array[2]))
		return (1);
	if (set_double(&cylinder->radius, array[3], 0.0, INT_MAX))
		return (second_line_error("Syntax error : Cylinder radius"));
	if (set_double(&cylinder->height, array[4], 0.0, INT_MAX))
		return (second_line_error("Syntax error : Cylinder height"));
	if (set_colors(&cylinder->color, array[5]))
		return (1);
	cylinder->radius /= 2.0;
	return (0);
}
