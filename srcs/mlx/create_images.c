/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:38:18 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/04 13:38:43 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	create_images_error(int error, t_world *world)
{
	if (error == 1)
	{
		rt_error("create_images() failed");
		close_window(world);
		return (0);
	}
	else if (error == 2)
	{
		rt_error("mlx_get_data_addr() failed");
		close_window(world);
		return (0);
	}
	return (1);
}

int	create_images(t_mlx *mlx, size_t nb_images, t_world *world)
{
	size_t	i;

	mlx->image = malloc(sizeof(t_img) * nb_images);
	if (!mlx->image)
		return (create_images_error(1, world));
	mlx->nb_images = nb_images;
	i = 0;
	while (i < nb_images)
	{
		mlx->image[i].img
			= mlx_new_image(mlx->mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
		if (!mlx->image[i].img)
			return (create_images_error(1, world));
		mlx->image[i].addr = mlx_get_data_addr(mlx->image[i].img,
				&mlx->image[i].bits_per_pixel,
				&mlx->image[i].line_length, &mlx->image[i].endian);
		if (!mlx->image[i].addr)
			return (create_images_error(1, world));
		i++;
	}
	return (0);
}
