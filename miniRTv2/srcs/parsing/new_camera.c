/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:16:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 11:32:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_camera(t_cam *camera, char **array)
{
	if (ft_arraylen(array) != 4)
		return (rt_error("Syntax error : Camera line syntax."));
	if (set_position(&(camera->position), array[1]))
		return (second_line_error("Invalid camera point of vue."));
	if (set_direction(&(camera->direction), array[2]))
		return (1);
	if (set_double(&(camera->fov_horizontal), array[3], 0.0, 180.0))
		return (rt_error("Syntax error : Camera FOV"));
	camera->fov_vertical = camera->fov_horizontal
		/ (camera->screen_size_x / camera->screen_size_y);
	return (0);
}

t_cam	new_camera(char **array, int *error)
{
	t_cam	camera;

	camera.screen_size_x = SCREEN_SIZE_X;
	camera.screen_size_y = SCREEN_SIZE_Y;
	*error = fill_camera(&camera, array);
	return (camera);
}
