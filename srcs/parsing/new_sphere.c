/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:32:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 08:44:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_sphere(t_obj *o_sphere, char **array)
{
	o_sphere->intersection = &intersection_sphere;
	o_sphere->print = &print_sphere;
	o_sphere->type = sphere;
	if (ft_arraylen(array) != 4)
		return (rt_error("Invalid sphere declaration."));
	if (set_position(&(o_sphere->position), array[1]))
		return (rt_error("Syntax error : Sphere position"));
	if (set_double(&(o_sphere->radius), array[2], 0.0, INT_MAX))
		return (rt_error("Syntax error : Sphere diameter"));
	if (set_colors(&(o_sphere->color), array[3]))
		return (rt_error("Syntax error : Sphere color"));
	o_sphere->radius /= 2.0;
	return (0);
}
