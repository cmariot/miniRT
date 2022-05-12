/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:38:18 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 21:51:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	create_image(t_mlx *mlx, t_world *world)
{
	mlx->image.img = mlx_new_image(mlx->mlx_ptr,
			world->obj_list.camera.screen_width,
			world->obj_list.camera.screen_height);
	if (!mlx->image.img)
	{
		rt_error("mlx_new_image() failed");
		return (close_window(world));
	}
	mlx->image.addr = mlx_get_data_addr(mlx->image.img,
			&mlx->image.bits_per_pixel,
			&mlx->image.line_length, &mlx->image.endian);
	if (!mlx->image.addr)
	{
		rt_error("mlx_get_data_addr() failed");
		return (close_window(world));
	}
	return (0);
}
