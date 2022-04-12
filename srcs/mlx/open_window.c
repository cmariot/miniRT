/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:15:07 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/11 08:38:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	open_window(t_scene *scene)
{
	scene->mlx.mlx_ptr = mlx_init();
	if (scene->mlx.mlx_ptr == NULL)
		return (rt_error("MLX: mlx_init() failed.", true));
	scene->mlx.win_ptr = mlx_new_window(scene->mlx.mlx_ptr, SIZE_X, SIZE_Y,
			"miniRT");
	if (scene->mlx.win_ptr == NULL)
		return (rt_error("MLX: mlx_open_window() failed.", true));
	draw_circle(scene);
	mlx_key_hook(scene->mlx.win_ptr, key_hook, scene);
	mlx_hook(scene->mlx.win_ptr, 17, 1L << 2, close_window, scene);
	mlx_loop(scene->mlx.mlx_ptr);
	return (0);
}
