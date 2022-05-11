/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_linux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:26:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 15:50:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	close_window(t_world *world)
{
	free_structure(world);
	mlx_destroy_image(world->mlx.mlx_ptr, world->mlx.image.img);
	mlx_clear_window(world->mlx.mlx_ptr, world->mlx.win_ptr);
	mlx_destroy_window(world->mlx.mlx_ptr, world->mlx.win_ptr);
	mlx_destroy_display(world->mlx.mlx_ptr);
	free(world->mlx.mlx_ptr);
	exit(EXIT_SUCCESS);
	return (1);
}
