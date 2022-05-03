/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:11:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 16:25:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_light	new_light(char **array, int *error)
{
	t_light	light;

	light.ratio = 0;
	if (ft_arraylen(array) != 4)
		*error = rt_error("Too much arguments in light declaration.");
	else if (set_position(&(light.position), array[1]))
		*error = second_line_error("Spot light position");
	else if (set_double(&(light.ratio), array[2], 0.0, 1.0))
		*error = second_line_error("Spot light ratio");
	else if (set_colors(&(light.color), array[3]))
		*error = second_line_error("Spot light color");
	return (light);
}
