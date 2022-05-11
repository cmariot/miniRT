/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:11:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 16:48:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_light(t_light *light, char **array)
{
	light->print = &print_light;
	if (ft_arraylen(array) != 3)
		return (rt_error("Invalid light declaration."));
	if (set_position(&(light->position), array[1]))
		return (rt_error("Syntax error : Light position"));
	if (set_double(&(light->ratio), array[2], 0.0, 1.0))
		return (rt_error("Syntax error : Light ratio"));
	return (0);
}
