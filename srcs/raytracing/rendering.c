/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:27:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/01 01:25:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Get the direction vector of each ray that starts from the camera
 * and goes to a pixel on the screen.
 * If this vector hits a sphere, color this pixel with
 * the color of the sphere. */

t_3d	ray_engine(int i, int j, t_scene *scene)
{
	t_3d	ray_direction;

	ray_direction.x = j - SIZE_X * 0.5;
	ray_direction.y = i - SIZE_Y * 0.5;
	ray_direction.z = -SIZE_X / (2 * tan(scene->camera.fov * 0.5));
	return (normalize(ray_direction));
}

void	rendering(t_scene *scene)
{
	size_t		pixel_y;
	size_t		pixel_x;
	size_t		index_sphere;

	pixel_y = 0;
	while (pixel_y < SIZE_Y)
	{
		pixel_x = 0;
		while (pixel_x < SIZE_X)
		{
			scene->camera.ray_direction = ray_engine(pixel_y, pixel_x, scene);
			index_sphere = 0;
			while (index_sphere < scene->elements.nb_sphere)
			{
				if (intersection(scene, scene->sphere[index_sphere]))
				{
					mlx_pixel_put(scene->mlx.mlx_ptr, scene->mlx.win_ptr,
						pixel_x, pixel_y, scene->sphere[index_sphere].trgb_color);
				}
				index_sphere++;
			}
			pixel_x++;
		}
		pixel_y++;
	}
}
