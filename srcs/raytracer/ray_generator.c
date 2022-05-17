/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:25:43 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/17 17:50:50 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Origine   : Camera
 * Direction : Pixel (x ; y)
 */

t_v3 get_direction(t_cam *cam, double x, double y)
{
	t_v3	dir;
	double	a;
	double	b;
	static double	c;

	a = x + cam->constant_x;
	b = y + cam->constant_y;
	c = cam->constant_z;
	dir.x = 1 * a + 0 * b + 0 * c;
	dir.y = 0 * a + 1 * b + 0 * c;
	dir.z = 0 * a + 0 * b + -1 * c;
	return (dir);
}

t_ray	ray_generator(t_cam	*camera, double x, double y)
{
	t_ray	ray;

	ray.position = camera->position;
	ray.direction = get_direction(camera, x, y);
	return (ray);
}
