/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_macos_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:26:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/02 11:02:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	close_window(t_world *world)
{
	if (world)
		free_structure(world);
	if (world->mlx.image.img)
		mlx_destroy_image(world->mlx.mlx_ptr, world->mlx.image.img);
	if (world->mlx.win_ptr)
		mlx_clear_window(world->mlx.mlx_ptr, world->mlx.win_ptr);
	if (world->mlx.win_ptr)
		mlx_destroy_window(world->mlx.mlx_ptr, world->mlx.win_ptr);
	if (world->mlx.mlx_ptr)
		free(world->mlx.mlx_ptr);
	exit(EXIT_SUCCESS);
	return (1);
}
