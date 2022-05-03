/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:11:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 12:16:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_light(t_light *light, char **array)
{
	if (ft_arraylen(array) != 4)
		return (rt_error("Wrong line syntax for the ambient."));
	if (set_position(&(light->position), array[1]))
		return (second_line_error("Ambient light position."));
	if (set_double(&(light->ratio), array[2], 0.0, 1.0))
		return (second_line_error("Ambient light ratio."));
	if (set_colors(&(light->color), array[3]))
		return (second_line_error("Ambient light color"));
	return (0);
}

t_light	new_light(char **array, int *error)
{
	t_light	light;

	*error = fill_light(&light, array);
	return (light);
}
