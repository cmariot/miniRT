/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/04 09:02:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define X 0
#define Y 1

int	create_image(t_img *img, t_mlx *mlx, t_world *world)
{
	img->img = mlx_new_image(mlx->mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	if (!img->img)
	{
		rt_error("mlx_new_image() failed");
		close_window(world);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
	{
		rt_error("mlx_get_data_addr() failed");
		close_window(world);
	}
	return (0);
}

void	my_mlx_pixel_put(t_img *data, size_t *pixel, int color)
{
	char	*dst;

	dst = data->addr + (pixel[Y] * data->line_length
			+ pixel[X] * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	raytracer(t_world *world, t_mlx *mlx, t_obj_list *obj_list, t_cam *camera)
{
	size_t	pixel[2];
	t_img	img;
	int		color;

	(void)obj_list;
	(void)camera;
	create_image(&img, mlx, world);
	pixel[Y] = 0;
	while (pixel[Y] < SCREEN_SIZE_Y)
	{
		pixel[X] = 0;
		while (pixel[X] < SCREEN_SIZE_X)
		{
			color = trgb_color(0, pixel[Y] % 255, pixel[X] % 255,
					(pixel[X] + 255) % 255);
			my_mlx_pixel_put(&img, pixel, color);
			pixel[X]++;
		}
		pixel[Y]++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img, 0, 0);
}
