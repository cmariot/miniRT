/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:15:07 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 10:08:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_mlx(t_mlx *mlx, t_img *image)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	image->img = NULL;
	image->addr = NULL;
}

int	open_window(t_world *world)
{
	init_mlx(&world->mlx, &world->mlx.image);
	world->mlx.mlx_ptr = mlx_init();
	if (!world->mlx.mlx_ptr)
	{
		rt_error("MLX: mlx_init() failed.");
		return (free_structure(world));
	}
	mlx_do_key_autorepeaton(world->mlx.mlx_ptr);
	world->mlx.win_ptr = mlx_new_window(world->mlx.mlx_ptr,
			world->obj_list.camera.screen_width,
			world->obj_list.camera.screen_height,
			"miniRT");
	if (!world->mlx.win_ptr)
	{
		rt_error("MLX: mlx_open_window() failed.");
		return (close_window(world));
	}
	create_image(&world->mlx, world);
	raytracer(&world->obj_list, &world->obj_list.camera, &world->mlx);
	//mlx_mouse_hook(world->mlx.win_ptr, &mouse_hook, world);
	mlx_hook(world->mlx.win_ptr, 02, 1L << 0, key_handler, world);
	mlx_hook(world->mlx.win_ptr, 17, 1L << 8, close_window, world);
	mlx_loop(world->mlx.mlx_ptr);
	return (0);
}
