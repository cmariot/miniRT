/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:36:54 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 16:53:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	new_cylinder(char **array, int *error)
{
	t_obj	cylinder;

	cylinder.print = &print_cylinder;
	if (ft_arraylen(array) != 6)
		*error = rt_error("Too much arguments in cylinder declaration.");
	else if (set_position(&(cylinder.position), array[1]))
		*error = 1;
	else if (set_direction(&(cylinder.direction), array[2]))
		*error = 1;
	else if (set_double(&(cylinder.radius), array[3], 0.0, INT_MAX))
		*error = second_line_error("Syntax error : Cylinder radius");
	else if (set_double(&(cylinder.height), array[4], 0.0, INT_MAX))
		*error = second_line_error("Syntax error : Cylinder height");
	else if (set_colors(&(cylinder.color), array[5]))
		*error = 1;
	else
		cylinder.radius /= 2.0;
	return (cylinder);
}
