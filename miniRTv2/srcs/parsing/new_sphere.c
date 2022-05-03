/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:32:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 16:24:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	new_sphere(char **array, int *error)
{
	t_obj	sphere;

	sphere.print = &print_sphere;
	if (ft_arraylen(array) != 4)
		*error = rt_error("Too much arguments in sphere declaration.");
	else if (set_position(&(sphere.position), array[1]))
		*error = 1;
	else if (set_double(&(sphere.radius), array[2], 0, INT_MAX))
		*error = second_line_error("Syntax error : Sphere diameter");
	else if (set_colors(&(sphere.color), array[3]))
		*error = 1;
	sphere.radius /= 2;
	return (sphere);
}
