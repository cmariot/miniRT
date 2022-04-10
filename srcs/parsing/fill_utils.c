/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 01:21:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/09 11:20:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	trgb_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	set_colors(char *rgb, int *color)
{
	char	**array;
	int		red;
	int		green;
	int		blue;

	array = ft_split(rgb, ',');
	if (!array)
		return (rt_error("Split failed."));
	else if (ft_arraylen(array) != 3)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Invalid color."));
	}
	red = ft_atoi(array[0]);
	green = ft_atoi(array[1]);
	blue = ft_atoi(array[2]);
	if (red < 0 || red > 255 || green < 0 || green > 255
		|| blue < 0 || blue > 255)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Invalid color."));
	}
	*color = trgb_color(0, red, green, blue);
	ft_free_array(array);
	return (0);
}

int	set_double(char *str, double *to_fill, double min_limit, double max_limit)
{
	bool	error_checker;

	error_checker = false;
	*to_fill = ft_atodouble(str, &error_checker);
	if (error_checker == true || *to_fill < min_limit || *to_fill > max_limit)
		return (rt_error("Syntax error : Invalid double."));
	return (0);
}

int	set_orientation(t_3d *orientation, char *str)
{
	char	**array;

	array = ft_split(str, ',');
	if (!array)
		return (rt_error("Split failed."));
	else if (ft_arraylen(array) != 3)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Invalid orientation vector."));
	}
	if (set_double(array[0], &(orientation->x), -1, 1)
		|| set_double(array[1], &(orientation->y), -1, 1)
		|| set_double(array[2], &(orientation->z), -1, 1))
	{
		print(2, "Invalid orientation vector.");
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
		return (rt_error("Split failed."));
	else if (ft_arraylen(array) != 3)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Invalid point"));
	}
	if (set_double(array[0], &(coordinates->x), INT_MIN, INT_MAX)
		|| set_double(array[1], &(coordinates->y), INT_MIN, INT_MAX)
		|| set_double(array[2], &(coordinates->z), INT_MIN, INT_MAX))
	{
		print(2, "Invalid point.");
		ft_free_array(array);
		return (1);
	}
	ft_free_array(array);
	return (0);
}
