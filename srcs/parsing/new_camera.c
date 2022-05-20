/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:16:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 18:56:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_camera(t_cam *cam, char **array)
{
	cam->print = &print_camera;
	if (ft_arraylen(array) != 4)
		return (rt_error("Invalid cam declaration."));
	if (set_position(&(cam->position), array[1]))
		return (rt_error("Syntax error : cam position"));
	if (set_direction(&(cam->direction), array[2]))
		return (rt_error("Syntax error : cam direction"));
	if (set_double(&(cam->fov_horizontal), array[3], 0.0, 180.0))
		return (rt_error("Syntax error : cam FOV"));
	cam->screen_width = round(SCREEN_WIDTH);
	cam->screen_height = round(cam->screen_width / 1.6);
	cam->constant_x = 0.5 - cam->screen_width / 2.0;
	cam->constant_y = 0.5 - cam->screen_height / 2.0;
	cam->constant_z = -(cam->screen_width
			/ (2 * tan((cam->fov_horizontal * M_PI / 180.0) * 0.5)));
	return (0);
}
