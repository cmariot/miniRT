/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:38:18 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 12:43:58 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	create_image_error(int error, t_world *world)
{
	if (error == 1)
		rt_error("create_images() failed");
	else if (error == 2)
		rt_error("mlx_get_data_addr() failed");
	close_window(world);
	return (1);
}

int	create_image(t_mlx *mlx, t_world *world)
{
	mlx->image.img = mlx_new_image(mlx->mlx_ptr,
			world->obj_list.camera.screen_width,
			world->obj_list.camera.screen_height);
	if (!mlx->image.img)
		return (create_image_error(1, world));
	mlx->image.addr = mlx_get_data_addr(mlx->image.img,
			&mlx->image.bits_per_pixel,
			&mlx->image.line_length, &mlx->image.endian);
	if (!mlx->image.addr)
		return (create_image_error(2, world));
	return (0);
}
