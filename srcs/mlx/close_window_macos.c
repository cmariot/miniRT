/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_macos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:26:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/07 14:14:27 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	close_window(t_world *world)
{
	size_t	i;

	free_world(world);
	i = 0;
	while (i < world->mlx.nb_images)
		mlx_destroy_image(world->mlx.mlx_ptr, world->mlx.image[i++].img);
	mlx_clear_window(world->mlx.mlx_ptr, world->mlx.win_ptr);
	mlx_destroy_window(world->mlx.mlx_ptr, world->mlx.win_ptr);
	free(world->mlx.mlx_ptr);
	free(world->mlx.image);
	exit(EXIT_SUCCESS);
	return (1);
}
