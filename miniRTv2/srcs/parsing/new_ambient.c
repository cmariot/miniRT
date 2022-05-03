/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:36:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 12:11:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_ambient(t_amb *ambient_light, char **array)
{
	if (ft_arraylen(array) != 3)
		return (rt_error("Wrong line syntax for the ambient."));
	if (set_double(&(ambient_light->ratio), array[1], 0.0, 1.0))
		return (second_line_error("Ambient light ratio."));
	if (set_colors(&(ambient_light->color), array[2]))
		return (second_line_error("Ambient light color"));
	return (0);
}

t_amb	new_ambient(char **array, int *error)
{
	t_amb	ambient;

	*error = fill_ambient(&ambient, array);
	return (ambient);
}
