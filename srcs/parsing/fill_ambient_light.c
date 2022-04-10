/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ambient_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:56:26 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/09 11:19:21 by cmariot          ###   ########.fr       */
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
		return (rt_error("Syntax error : Ambient light number of arguments."));
	}
	if (set_double(array[1], &(ambient_light->ratio), 0.0, 1.0))
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Ambient light ratio"));
	}
	if (set_colors(array[2], &(ambient_light->color)))
	{
		ft_free_array(array);
		return (1);
	}
	ft_free_array(array);
	return (0);
}
