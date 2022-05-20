/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:25:43 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 11:54:29 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Origine   : Camera
 * Direction : Pixel (x ; y)
 */

static inline t_v3	la_matmut(double *m, t_v3 p)
{
	t_v3 result;

	result.x = p.x * (m[0]) + p.y * (m[3]) + p.z * (m[6]);
	result.y = p.x * (m[1]) + p.y * (m[4]) + p.z * (m[7]);
	result.z = p.x * (m[2]) + p.y * (m[5]) + p.z * (m[8]);
	return (result);
}

static inline double *lookat(t_v3 cam_dir)
{
	double	*m;
	t_v3	placeholder;
	t_v3	right;
	t_v3	up;

	placeholder.x = 0;
	placeholder.y = 1;
	placeholder.z = 0;
	m = (double *)malloc(sizeof(double) * 9); // need to protect this malloc mais flemme la xD
	right = normalize(cross_product(placeholder, cam_dir));
	up = normalize(cross_product(cam_dir, right));
	*(t_v3 *)(&m[0]) = right;
	*(t_v3 *)(&m[3]) = up;
	*(t_v3 *)(&m[6]) = cam_dir;
	return (m);
}

t_ray	ray_generator(t_cam	*camera, double *x, double *y)
{
	t_ray	ray;
	double *m;

	m = lookat(camera->direction);
	ray.position = camera->position;
	ray.direction = new_vector(
			*x + camera->constant_x,
			*y + camera->constant_y,
			camera->constant_z);
	ray.direction = normalize(la_matmut(m, ray.direction));
	free(m);
	return (ray);
}
