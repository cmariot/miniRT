/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:25:43 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 18:19:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Origine   : Camera
 * Direction : Pixel (x ; y)
 */

t_ray	ray_generator(t_cam	*camera, float *x, float *y)
{
	t_ray	ray;

	ray.position = camera->position;
	ray.direction = new_vector(*x + camera->constant_x,
			*y + camera->constant_y,
			camera->constant_z);
	return (ray);
}
