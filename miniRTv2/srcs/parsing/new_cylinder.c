/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:36:54 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 08:51:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_cylinder(t_obj *cylinder, char **array)
{
	if (ft_arraylen(array) != 6)
		return (rt_error("Syntax error : Cylinder line syntax."));
	if (set_position(&(cylinder->position), array[1]))
		return (1);
	if (set_direction(&(cylinder->direction), array[2]))
		return (1);
	if (set_double(&(cylinder->radius), array[3], 0.0, INT_MAX)
		|| set_double(&(cylinder->height), array[4], 0.0, INT_MAX))
		return (second_line_error("Syntax error : Cylinder size"));
	cylinder->radius /= 2.0;
	if (set_colors(&(cylinder->color), array[5]))
		return (1);
	return (0);
}

t_obj	new_cylinder(char **array, int *error)
{
	t_obj	cylinder;

	cylinder.print = &print_cylinder;
	*error = fill_cylinder(&cylinder, array);
	return (cylinder);
}
