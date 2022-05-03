/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:00:11 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 12:09:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	trgb_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	set_double(double *dbl, char *str, double min_limit, double max_limit)
{
	bool	error_checker;

	if (str == NULL)
		return (1);
	error_checker = false;
	*dbl = ft_atodouble(str, &error_checker);
	if (error_checker == true || *dbl < min_limit || *dbl > max_limit)
		return (rt_error("Syntax error : Invalid double,"));
	return (0);
}

int	set_colors(t_color *color, char *rgb)
{
	char	**array;

	array = ft_split(rgb, ',');
	if (!array)
		return (rt_error("Split failed."));
	else if (ft_arraylen(array) != 3)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Invalid color,"));
	}
	color->r = ft_atoi(array[0]);
	color->g = ft_atoi(array[1]);
	color->b = ft_atoi(array[2]);
	if (color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Invalid color"));
	}
	color->trgb = trgb_color(0, color->r, color->g, color->b);
	ft_free_array(array);
	return (0);
}

int	set_direction(t_3d *direction, char *str)
{
	char	**array;

	array = ft_split(str, ',');
	if (!array)
		return (rt_error("Split failed."));
	else if (ft_arraylen(array) != 3)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Invalid direction"));
	}
	if (set_double(&direction->x, array[0], -1, 1)
		|| set_double(&direction->y, array[1], -1, 1)
		|| set_double(&direction->z, array[2], -1, 1))
	{
		second_line_error("Invalid direction");
		ft_free_array(array);
		return (1);
	}
	*direction = normalize(*direction);
	ft_free_array(array);
	return (0);
}

int	set_position(t_3d *position, char *str)
{
	char	**array;

	array = ft_split(str, ',');
	if (!array)
		return (rt_error("Split failed."));
	else if (ft_arraylen(array) != 3)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Invalid position"));
	}
	if (set_double(&(position->x), array[0], INT_MIN, INT_MAX)
		|| set_double(&(position->y), array[1], INT_MIN, INT_MAX)
		|| set_double(&(position->z), array[2], INT_MIN, INT_MAX))
	{
		second_line_error("Invalid double");
		ft_free_array(array);
		return (1);
	}
	ft_free_array(array);
	return (0);
}
