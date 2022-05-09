/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/08 21:24:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

# define X 0
# define Y 1

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
