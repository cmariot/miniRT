/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:16:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 16:42:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_image(t_cam *camera)
{
	camera->image = malloc(sizeof(t_image));
	if (!camera->image)
		return (1);
	camera->nb_image = 1;
	camera->image[0].str_image = ft_calloc(sizeof(char),
			camera->screen_size_x * camera->screen_size_y * 4 + 1);
	if (!camera->image[0].str_image)
	{
		free(camera->image);
		return (1);
	}
	return (0);
}

t_cam	new_camera(char **array, int *error)
{
	t_cam	camera;

	camera.screen_size_x = SCREEN_SIZE_X;
	camera.screen_size_y = SCREEN_SIZE_Y;
	if (ft_arraylen(array) != 4)
		*error = rt_error("Too much arguments in camera declaration.");
	else if (set_position(&(camera.position), array[1]))
		*error = second_line_error("Invalid camera position.");
	else if (set_direction(&(camera.direction), array[2]))
		*error = 1;
	else if (new_image(&camera))
		*error = 1;
	else if (set_double(&(camera.fov_horizontal), array[3], 0.0, 180.0))
		*error = rt_error("Syntax error : Camera FOV");
	else
		camera.fov_vertical = camera.fov_horizontal
			/ (camera.screen_size_x / camera.screen_size_y);
	return (camera);
}
