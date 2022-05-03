/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:32:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 10:44:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_sphere(t_obj *sphere, char **array)
{
	if (ft_arraylen(array) != 4)
		return (rt_error("Syntax error : Sphere line syntax."));
	if (set_position(&(sphere->position), array[1]))
		return (1);
	if (set_double(&(sphere->radius), array[2], 0, INT_MAX))
		return (second_line_error("Syntax error : Sphere diameter"));
	sphere->radius /= 2;
	if (set_colors(&(sphere->color), array[3]))
		return (1);
	return (0);
}

t_obj	new_sphere(char **array, int *error)
{
	t_obj	sphere;

	sphere.print = &print_sphere;
	*error = fill_sphere(&sphere, array);
	return (sphere);
}
