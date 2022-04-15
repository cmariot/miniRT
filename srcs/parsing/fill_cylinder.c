/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 01:24:49 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/15 09:05:14 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_cylinder(char **array, size_t *index, t_cylinder *cylinder)
{
	if (ft_arraylen(array) != 6)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Cylinder number of arguments.", true));
	}
	if (set_point(&(cylinder->point), array[1])
		|| set_orientation(&(cylinder->direction), array[2]))
	{
		ft_free_array(array);
		return (1);
	}
	if (set_double(array[3], &(cylinder->diameter), 0.0, INT_MAX)
		|| set_double(array[4], &(cylinder->heigth), 0.0, INT_MAX))
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Ambient light ratio", true));
	}
	if (set_colors(array[5], &(cylinder->color)))
	{
		ft_free_array(array);
		return (1);
	}
	ft_free_array(array);
	*index = *index + 1;
	return (0);
}
