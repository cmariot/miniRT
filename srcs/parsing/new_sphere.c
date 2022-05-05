/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:32:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/04 20:38:28 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_sphere(t_obj *sphere, char **array)
{
	sphere->intersection = &intersection_sphere;
	sphere->print = &print_sphere;
	if (ft_arraylen(array) != 4)
		return (rt_error("Too much arguments in sphere declaration."));
	if (set_position(&(sphere->position), array[1]))
		return (1);
	if (set_double(&(sphere->radius), array[2], 0, INT_MAX))
		return (second_line_error("Syntax error : Sphere diameter"));
	if (set_colors(&(sphere->color), array[3]))
		return (1);
	sphere->radius /= 2;
	return (0);
}
