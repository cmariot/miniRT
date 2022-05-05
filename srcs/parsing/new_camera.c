/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:16:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/05 15:19:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_camera(t_cam *camera, char **array)
{
	t_3d	screen_origine;

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
	printf("SCREEN_CENTER : x = %f, y = %f, z = %f\n",
		camera->pos_screen_center.x, camera->pos_screen_center.y, camera->pos_screen_center.z);
	screen_origine = 
		sub_vector(sub_vector(camera->pos_screen_center,
		mul_vector(normalize (new_vector(1, 1, 1)), camera->screen_width)),
		mul_vector(normalize(new_vector(1, 1, 1)), camera->screen_height));
	
	//equation cartesienne plan : 
	printf("Equation cartesienne ecran : %.2fX + %.2fY + %.2f Z + %.2f = 0\n",
			camera->direction.x,
			camera->direction.y,
			camera->direction.z,
			camera->direction.x * screen_origine.x + camera->direction.y * screen_origine.y + camera->direction.z * screen_origine.z);
	return (0);
}
