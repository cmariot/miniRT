/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 01:11:16 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/19 12:48:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_light(char **array, t_light *light)
{
	if (ft_arraylen(array) != 4)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Light line syntax."));
	}
	if (set_point(&(light->point), array[1]))
	{
		ft_free_array(array);
		return (1);
	}
	if (set_double(array[2], &(light->ratio), 0.0, 1.0))
	{
		ft_free_array(array);
		return (second_line_error("Syntax error : Light ratio"));
	}
	if (set_colors(array[3], &(light->color), &(light->trgb_color)))
	{
		ft_free_array(array);
		return (1);
	}
	ft_free_array(array);
	return (0);
}
