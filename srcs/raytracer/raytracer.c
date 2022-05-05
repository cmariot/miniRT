/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/05 01:00:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define PI 3.14159265359

t_3d	ray_generator(t_cam *camera, size_t x, size_t y)
{
	t_3d	ray_direction;

	ray_direction.x = -(x - (camera->screen_width * 0.5));
	ray_direction.y = (camera->screen_height * 0.5) - y;
	ray_direction.z = -(camera->screen_width * 0.5)
		/ tan(camera->fov_horizontal * PI / 180 * 0.5);
	return (normalize(ray_direction));
}

int	check_intersection(t_cam *camera, t_obj_list *obj_list,
	t_3d *position, t_3d *normale)
{
	int		pixel_color;
	size_t	i;
	double	max_distance;
	double	distance;

	i = 0;
	max_distance = INT_MAX;
	pixel_color = trgb_color(0, 42, 42, 42);
	while (i < obj_list->nb_objs)
	{
		if (obj_list->objs[i].intersection(obj_list->objs[i],
				camera[0], position, normale))
		{
			distance = length(camera->position, *position);
			if (distance < max_distance)
			{
				pixel_color = obj_list->objs[i].color.trgb;
				max_distance = distance;
			}
		}
		i++;
	}
	return (pixel_color);
}

void	raytracer(t_world *world, t_mlx *mlx,
	t_obj_list *obj_list, t_cam *camera)
{
	size_t	pixel[2];
	int		color;
	t_3d	position;
	t_3d	normale;

	create_images(mlx, 1, world);
	pixel[Y] = 0;
	while (pixel[Y] < camera->screen_height)
	{
		pixel[X] = 0;
		while (pixel[X] < camera->screen_width)
		{
			camera->ray = ray_generator(camera, pixel[X], pixel[Y]);
			color = check_intersection(camera, obj_list, &position, &normale);
			mlx_putpixel(&mlx->image[0], pixel, color);
			pixel[X]++;
		}
		pixel[Y]++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->image[0].img, 0, 0);
}
