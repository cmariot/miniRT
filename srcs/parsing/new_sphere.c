/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:32:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 14:49:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_sphere(t_obj *sphere, char **array)
{
	sphere->intersection = &intersection_sphere;
	sphere->second_intersection = &second_intersection_sphere;
	sphere->print = &print_sphere;
	sphere->translate = &translate_sphere;
	if (ft_arraylen(array) != 4)
		return (rt_error("Invalid sphere declaration."));
	if (set_position(&(sphere->position), array[1]))
		return (rt_error("Syntax error : Sphere position"));
	if (set_double(&(sphere->radius), array[2], 0.0, INT_MAX))
		return (rt_error("Syntax error : Sphere diameter"));
	if (set_colors(&(sphere->color), array[3]))
		return (rt_error("Syntax error : Sphere color"));
	sphere->radius /= 2.0;
	return (0);
}
