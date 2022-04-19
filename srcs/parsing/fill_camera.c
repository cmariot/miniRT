/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:04:53 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/19 12:57:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_camera(char **array, t_camera *camera)
{
	if (ft_arraylen(array) != 4)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Camera line syntax."));
	}
	if (set_point(&(camera->point), array[1]))
	{
		ft_free_array(array);
		return (second_line_error("Invalid camera point of vue."));
	}
	if (set_orientation(&(camera->direction), array[2]))
	{
		ft_free_array(array);
		return (1);
	}
	if (set_double(array[3], &(camera->fov), 0.0, 180.0))
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Camera FOV"));
	}
	camera->fov = camera->fov * PI / 180;
	ft_free_array(array);
	return (0);
}
