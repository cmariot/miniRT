/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/04 16:46:28 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_3d	ray_engine(t_cam *camera, size_t x, size_t y)
{
	t_3d	ray_direction;

	(void)camera;
	ray_direction.x = x;
	ray_direction.y = y;
	ray_direction.z = 0;
	return (ray_direction);
}

void	raytracer(t_world *world, t_mlx *mlx,
	t_obj_list *obj_list, t_cam *camera)
{
	size_t	pixel[2];
	int		color;
	size_t	i;
	bool	collision;

	create_images(mlx, 1, world);
	pixel[Y] = 0;
	while (pixel[Y] < SCREEN_SIZE_Y)
	{
		pixel[X] = 0;
		while (pixel[X] < SCREEN_SIZE_X)
		{
			camera->ray = ray_engine(camera, pixel[X], pixel[Y]);
			i = 0;
			collision = false;
			while (i < obj_list->nb_objs)
			{
				if (obj_list->objs[i].intersection() == true)
				{
					collision = true;
					//change color
				}
				i++;
			}
			if (collision == false)
				color = trgb_color(0, pixel[Y] % 255, pixel[X] % 255,
						(pixel[X] + 255) % 255);
			else
				color = 0;
			mlx_putpixel(&mlx->image[0], pixel, color);
			pixel[X]++;
		}
		pixel[Y]++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->image[0].img, 0, 0);
}
