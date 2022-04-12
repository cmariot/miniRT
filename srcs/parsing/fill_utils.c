/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 01:21:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/11 08:34:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	trgb_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	set_colors(char *rgb, t_3d *color)
{
	char	**array;

	array = ft_split(rgb, ',');
	if (!array)
		return (rt_error("Split failed.", true));
	else if (ft_arraylen(array) != 3)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Invalid color.", true));
	}
	if (set_double(array[0], &(color->x), 0.0, 255.5)
		|| set_double(array[1], &(color->y), 0.0, 255.5)
		|| set_double(array[2], &(color->z), 0.0, 255.5))
	{
		ft_free_array(array);
		return (rt_error("Invalid color.\n", false));
	}
	ft_free_array(array);
	return (0);
}

int	set_double(char *str, double *to_fill, double min_limit, double max_limit)
{
	bool	error_checker;

	error_checker = false;
	*to_fill = ft_atodouble(str, &error_checker);
	if (error_checker == true || *to_fill < min_limit || *to_fill > max_limit)
		return (rt_error("Syntax error : Invalid double.", true));
	return (0);
}

int	set_orientation(t_3d *orientation, char *str)
{
	char	**array;

	array = ft_split(str, ',');
	if (!array)
		return (rt_error("Split failed.", true));
	else if (ft_arraylen(array) != 3)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Invalid orientation vector.", true));
	}
	if (set_double(array[0], &(orientation->x), -1, 1)
		|| set_double(array[1], &(orientation->y), -1, 1)
		|| set_double(array[2], &(orientation->z), -1, 1))
	{
		rt_error("Invalid orientation vector.", false);
		ft_free_array(array);
		return (1);
	}
	ft_free_array(array);
	return (0);
}

int	set_point(t_3d *coordinates, char *str)
{
	char	**array;

	array = ft_split(str, ',');
	if (!array)
		return (rt_error("Split failed.", true));
	else if (ft_arraylen(array) != 3)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Invalid point", true));
	}
	if (set_double(array[0], &(coordinates->x), INT_MIN, INT_MAX)
		|| set_double(array[1], &(coordinates->y), INT_MIN, INT_MAX)
		|| set_double(array[2], &(coordinates->z), INT_MIN, INT_MAX))
	{
		rt_error("Invalid point.", false);
		ft_free_array(array);
		return (1);
	}
	ft_free_array(array);
	return (0);
}
