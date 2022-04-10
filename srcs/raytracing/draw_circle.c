/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:27:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/09 18:25:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Get the direction vector of each ray that starts from the camera
 * and goes to a pixel on the screen.
 * If this vector hits a sphere, color this pixel with
 * the color of the sphere. */

t_3d	get_ray(int i, int j, t_scene *scene)
{
	t_3d	direction;

	direction.x = j - SIZE_X / 2;
	direction.y = i - SIZE_Y / 2;
	direction.z = -SIZE_X / (2 * tan((scene->camera.fov * PI / 180) / 2));
	direction = normalize(direction);
	return (direction);
}

void	draw_circle(t_scene *scene)
{
	int			i;
	int			j;

	i = 0;
	while (i < SIZE_Y - 1)
	{
		j = 0;
		while (j < SIZE_X - 1)
		{
			scene->camera.ray_direction = get_ray(i, j, scene);
			if (intersection(scene, scene->sphere[0]))
				mlx_pixel_put(scene->mlx.mlx_ptr, scene->mlx.win_ptr,
					j, i, scene->sphere[0].color);
			else
				mlx_pixel_put(scene->mlx.mlx_ptr, scene->mlx.win_ptr,
					j, i, scene->ambient_light.color);
			j++;
		}
		i++;
	}
}
