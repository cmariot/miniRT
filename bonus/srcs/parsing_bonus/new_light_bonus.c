/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:11:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/02 11:05:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	new_light(t_light *light, char **array)
{
	size_t	array_len;

	array_len = ft_arraylen(array);
	light->print = &print_light;
	light->color_set = false;
	if (array_len < 3 || array_len > 4)
		return (rt_error("Invalid light declaration."));
	if (set_position(&light->position, array[1]))
		return (rt_error("Syntax error : Light position"));
	if (set_double(&light->ratio, array[2], 0.0, 1.0))
		return (rt_error("Syntax error : Light ratio"));
	if (array_len == 4 && set_colors(&light->color, array[3]))
		return (rt_error("Syntax error : Light color"));
	if (array_len == 4)
		light->color_set = true;
	return (0);
}
