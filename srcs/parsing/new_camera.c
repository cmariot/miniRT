/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:16:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/12 13:08:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_camera(t_cam *camera, char **array)
{
	camera->print = &print_camera;
	if (ft_arraylen(array) != 4)
		return (rt_error("Invalid camera declaration."));
	if (set_position(&(camera->position), array[1]))
		return (rt_error("Syntax error : Camera position"));
	if (set_direction(&(camera->direction), array[2]))
		return (rt_error("Syntax error : Camera direction"));
	if (set_double(&(camera->fov_horizontal), array[3], 0.0, 180.0))
		return (rt_error("Syntax error : Camera FOV"));
	camera->screen_width = SCREEN_WIDTH;
	camera->screen_height = camera->screen_width / 1.6;
	return (0);
}
