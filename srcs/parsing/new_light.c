/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:11:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 23:00:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_light(t_light *light, char **array)
{
	light->print = &print_light;
	if (ft_arraylen(array) != 4)
		return (rt_error("Too much arguments in light declaration."));
	if (set_position(&(light->position), array[1]))
		return (second_line_error("Spot light position"));
	if (set_double(&(light->ratio), array[2], 0.0, 1.0))
		return (second_line_error("Spot light ratio"));
	if (set_colors(&(light->color), array[3]))
		return (second_line_error("Spot light color"));
	return (0);
}
