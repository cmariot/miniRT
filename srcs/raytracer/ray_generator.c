/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:25:43 by rballage           #+#    #+#            */
/*   Updated: 2022/05/20 14:24:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Origine   : Camera
 * Direction : Pixel (x ; y)
 */

static inline t_v3	la_matmut(double *m, t_v3 p)
{
	t_v3	result;

	result.x = p.x * m[0] + p.y * m[3] + p.z * m[6];
	result.y = p.x * m[1] + p.y * m[4] + p.z * m[7];
	result.z = p.x * m[2] + p.y * m[5] + p.z * m[8];
	return (result);
}

t_ray	ray_generator(t_cam	*camera, double *x, double *y)
{
	t_ray	ray;

	ray.position = camera->position;
	ray.direction = normalize(la_matmut(camera->matrix,
				new_vector(*x + camera->constant_x,
					*y + camera->constant_y,
					-camera->constant_z)));
	return (ray);
}
