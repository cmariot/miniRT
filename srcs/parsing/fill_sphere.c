/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 01:25:13 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/15 09:05:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_sphere(char **array, size_t *index, t_sphere *sphere)
{
	if (ft_arraylen(array) != 4)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Sphere number of arguments.", true));
	}
	if (set_point(&(sphere->point), array[1]))
	{
		ft_free_array(array);
		return (1);
	}
	if (set_double(array[2], &(sphere->diameter), 0, INT_MAX))
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Sphere dianeter", true));
	}
	if (set_colors(array[3], &(sphere->color)))
	{
		ft_free_array(array);
		return (1);
	}
	ft_free_array(array);
	*index = *index + 1;
	return (0);
}
