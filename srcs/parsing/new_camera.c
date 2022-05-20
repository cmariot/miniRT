/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:16:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 14:11:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	lookat(t_v3 cam_dir, double *m)
{
	t_v3	placeholder;
	t_v3	right;
	t_v3	up;

	placeholder.x = 0;
	placeholder.y = 1;
	placeholder.z = 0;
	if (cam_dir.x == 0 && cam_dir.z == 0)
		placeholder.z = 0.000001;
	right = normalize(cross_product(placeholder, cam_dir));
	up = normalize(cross_product(cam_dir, right));
	*(t_v3 *)(&m[0]) = right;
	*(t_v3 *)(&m[3]) = up;
	*(t_v3 *)(&m[6]) = cam_dir;
}

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
	lookat(cam->direction, cam->matrix);
	return (0);
}
