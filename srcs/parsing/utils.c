/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:00:11 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 18:17:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	set_float(float *dbl, char *str, float min_limit, float max_limit)
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
	if (set_float(&color->r, array[0], 0.0, 255.0)
		|| set_float(&color->g, array[1], 0.0, 255.0)
		|| set_float(&color->b, array[2], 0.0, 255.0))
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
	if (set_float(&(direction->x), array[0], -1.0, 1.0)
		|| set_float(&direction->y, array[1], -1.0, 1.0)
		|| set_float(&direction->z, array[2], -1.0, 1.0))
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
	if (set_float(&(position->x), array[0], INT_MIN, INT_MAX)
		|| set_float(&(position->y), array[1], INT_MIN, INT_MAX)
		|| set_float(&(position->z), array[2], INT_MIN, INT_MAX))
		return (ft_free_array(array));
	ft_free_array(array);
	return (0);
}
