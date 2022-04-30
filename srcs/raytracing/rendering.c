/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:27:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/30 08:37:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rendering(t_scene *scene)
{
	size_t		pixel_y;
	size_t		pixel_x;

	pixel_y = 0;
	while (pixel_y < SIZE_Y)
	{
		pixel_x = 0;
		while (pixel_x < SIZE_X)
		{
			mlx_pixel_put(scene->mlx.mlx_ptr, scene->mlx.win_ptr,
				pixel_x, pixel_y, scene->ambient_light.trgb_color);
			pixel_x++;
		}
		pixel_y++;
	}
}
