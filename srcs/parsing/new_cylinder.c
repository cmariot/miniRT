/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:36:54 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 08:44:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_cylinder(t_obj *cylinder, char **array)
{
	cylinder->intersection = &intersection_cylinder;
	cylinder->print = &print_cylinder;
	cylinder->type = "cy";
	if (ft_arraylen(array) != 6)
		return (rt_error("Invalid cylinder declaration."));
	if (set_position(&cylinder->position, array[1]))
		return (rt_error("Syntax error : Cylinder position"));
	if (set_direction(&cylinder->direction, array[2]))
		return (rt_error("Syntax error : Cylinder direction"));
	if (set_double(&cylinder->radius, array[3], 0.0, INT_MAX))
		return (rt_error("Syntax error : Cylinder diameter"));
	if (set_double(&cylinder->height, array[4], 0.0, INT_MAX))
		return (rt_error("Syntax error : Cylinder height"));
	if (set_colors(&cylinder->color, array[5]))
		return (rt_error("Syntax error : Cylinder color"));
	cylinder->radius /= 2.0;
	cylinder->ext1 = add_vector(cylinder->position,
			mul_vector(cylinder->direction, cylinder->height / 2.0));
	cylinder->ext2 = add_vector(cylinder->position,
			mul_vector(cylinder->direction, -cylinder->height / 2.0));
	cylinder->axe = normalize(div_vector(sub_vector(cylinder->ext2,
					cylinder->ext1), length(cylinder->ext1, cylinder->ext2)));
	return (0);
}
