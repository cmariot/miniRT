/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:16:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/04 18:36:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_camera(t_cam *camera, char **array)
{
	camera->screen_height = 872;
	camera->screen_width = 1440;
	camera->print = &print_camera;
	if (ft_arraylen(array) != 4)
		return (rt_error("Too much arguments in camera declaration."));
	if (set_position(&(camera->position), array[1]))
		return (second_line_error("Invalid camera position."));
	if (set_direction(&(camera->direction), array[2]))
		return (1);
	if (set_double(&(camera->fov_horizontal), array[3], 0.0, 180.0))
		return (rt_error("Syntax error : Camera FOV"));
	camera->fov_vertical = camera->fov_horizontal
		/ (camera->screen_width / camera->screen_height);
	return (0);
}
