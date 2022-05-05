/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:36:10 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/05 20:37:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define PI 3.14159265359

t_3d	ray_generator(t_cam *camera, size_t x, size_t y)
{
	t_3d	ray_direction;

	ray_direction.x = (x - (camera->screen_width * 0.5));
	ray_direction.y = (camera->screen_height * 0.5) - y;
	ray_direction.z = -(camera->screen_width * 0.5)
		/ tan(camera->fov_horizontal * PI / 180 * 0.5);
	return (normalize(ray_direction));
}
