/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:00:11 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/17 14:33:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	set_double(double *dbl, char *str, double min_limit, double max_limit)
{
	bool	error_checker;

	error_checker = false;
	*dbl = ft_atodouble(str, &error_checker);
	if (error_checker == true || *dbl < min_limit || *dbl > max_limit)
		return (1);
	return (0);
}

int	set_colors(t_color *color, char *rgb)
{
	char	**array;

	array = ft_split(rgb, ',');
	if (!array)
		return (1);
	else if (ft_arraylen(array) != 3)
		return (ft_free_array(array));
	if (set_double(&color->r, array[0], 0.0, 255.0)
		|| set_double(&color->g, array[1], 0.0, 255.0)
		|| set_double(&color->b, array[2], 0.0, 255.0))
		return (ft_free_array(array));
	ft_free_array(array);
	color->trgb = trgb_color(0, color->r, color->g, color->b);
	return (0);
}

int	set_direction(t_v3 *direction, char *str)
{
	char	**array;

	array = ft_split(str, ',');
	if (!array)
		return (1);
	else if (ft_arraylen(array) != 3)
		return (ft_free_array(array));
	if (set_double(&(direction->x), array[0], -1.0, 1.0)
		|| set_double(&direction->y, array[1], -1.0, 1.0)
		|| set_double(&direction->z, array[2], -1.0, 1.0))
		return (ft_free_array(array));
	if (direction->x == 0.0 && direction->y == 0.0 && direction->z == 0.0)
		return (ft_free_array(array));
	*direction = normalize(*direction);
	ft_free_array(array);
	return (0);
}

int	set_position(t_v3 *position, char *str)
{
	char	**array;

	array = ft_split(str, ',');
	if (!array)
		return (1);
	else if (ft_arraylen(array) != 3)
		return (ft_free_array(array));
	if (set_double(&(position->x), array[0], INT_MIN, INT_MAX)
		|| set_double(&(position->y), array[1], INT_MIN, INT_MAX)
		|| set_double(&(position->z), array[2], INT_MIN, INT_MAX))
		return (ft_free_array(array));
	ft_free_array(array);
	return (0);
}
