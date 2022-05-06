/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:16:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/06 11:31:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_camera(t_cam *camera, char **array)
{
	camera->screen_width = 1440;
	camera->screen_height = 872;
	camera->print = &print_camera;
	if (ft_arraylen(array) != 4)
		return (rt_error("Too much arguments in camera declaration."));
	if (set_position(&(camera->position), array[1]))
		return (second_line_error("Invalid camera position."));
	if (set_direction(&(camera->direction), array[2]))
		return (1);
	if (set_double(&(camera->fov_horizontal), array[3], 0.0, 180.0))
		return (rt_error("Syntax error : Camera FOV"));
	camera->screen_distance = (camera->screen_height / 2)
		/ (tan(camera->fov_horizontal / 2));
	camera->pos_screen_center = add_vector(camera->position,
			mul_vector(camera->direction, camera->screen_distance));
	return (0);
}
