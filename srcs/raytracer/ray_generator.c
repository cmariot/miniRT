/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:25:43 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/14 13:43:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Origine   : Camera 
 * Direction : Pixel (x ; y)
 */

t_ray	ray_generator(t_cam	*camera, double x, double y)
{
	t_ray	ray;

	ray.position = camera->position;
	ray.direction.x = x + camera->constant_x;
	ray.direction.y = y + camera->constant_y;
	ray.direction.z = camera->constant_z;
	ray.intersection = new_vector(0, 0, 0);
	ray.normale = new_vector(0, 0, 0);
	return (ray);
}
