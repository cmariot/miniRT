/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:36:10 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/08 19:36:09 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* M_PI is pi, defined in math.h */

t_ray	ray_generator(t_cam *camera, size_t x, size_t y)
{
	t_ray	ray;

	ray.direction.x = x - (camera->screen_width / 2.0) + 0.5;
	ray.direction.y = camera->screen_height / 2.0 - y + 0.5;
	ray.direction.z = -(camera->screen_width / 2.0)
		/ tan(camera->fov_horizontal * M_PI / 180 / 2.0);
	ray.direction = normalize(ray.direction);
	ray.position = camera->position;
	return (ray);
}
