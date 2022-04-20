/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ambient_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:56:26 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/19 12:46:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Fill the structure ambient_light element from the splitted_line :
 * Check the number of arguments of the line, 
 * Get the ratio and the color of the ambient_light */

int	fill_ambient_light(char **array, t_ambient_light *ambient_light)
{
	if (ft_arraylen(array) != 3)
	{
		ft_free_array(array);
		return (rt_error("Wrong line syntax for the ambient."));
	}
	if (set_double(array[1], &(ambient_light->ratio), 0.0, 1.0))
	{
		ft_free_array(array);
		return (second_line_error("Ambient light ratio."));
	}
	if (set_colors(array[2], &(ambient_light->color), &(ambient_light->trgb_color)))
	{
		ft_free_array(array);
		return (second_line_error("Ambient light color"));
	}
	ft_free_array(array);
	return (0);
}
