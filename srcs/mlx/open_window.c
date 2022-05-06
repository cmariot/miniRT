/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:15:07 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/06 11:27:09 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	open_window(t_world *world)
{
	world->mlx.mlx_ptr = mlx_init();
	if (world->mlx.mlx_ptr == NULL)
		return (rt_error("MLX: mlx_init() failed."));
	world->mlx.win_ptr = mlx_new_window(world->mlx.mlx_ptr,
			world->obj_list.camera[0].screen_width,
			world->obj_list.camera[0].screen_height,
			"miniRT");
	if (world->mlx.win_ptr == NULL)
		return (rt_error("MLX: mlx_open_window() failed."));
	raytracer(world, &world->mlx, &world->obj_list, &world->obj_list.camera[0]);
	mlx_key_hook(world->mlx.win_ptr, key_hook, world);
	mlx_hook(world->mlx.win_ptr, 33, 1L << 5, close_window, world);
	mlx_loop(world->mlx.mlx_ptr);
	return (0);
}
