/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/04 15:19:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	raytracer(t_world *world, t_mlx *mlx,
	t_obj_list *obj_list, t_cam *camera)
{
	size_t	pixel[2];
	int		color;

	(void)obj_list;
	create_images(mlx, 1, world);
	pixel[Y] = 0;
	while (pixel[Y] < SCREEN_SIZE_Y)
	{
		pixel[X] = 0;
		while (pixel[X] < SCREEN_SIZE_X)
		{
			camera->ray = ray_engine(camera);
			color = trgb_color(0, pixel[Y] % 255, pixel[X] % 255,
					(pixel[X] + 255) % 255);
			mlx_putpixel(&mlx->image[0], pixel, color);
			pixel[X]++;
		}
		pixel[Y]++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->image[0].img, 0, 0);
}
