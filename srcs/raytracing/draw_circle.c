/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:27:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/16 18:02:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Get the direction vector of each ray that starts from the camera
 * and goes to a pixel on the screen.
 * If this vector hits a sphere, color this pixel with
 * the color of the sphere. */

t_3d	get_camera_ray(int i, int j, t_scene *scene)
{
	t_3d	direction;

	direction.x = j - SIZE_X * 0.5;
	direction.y = i - SIZE_Y * 0.5;
	direction.z = -SIZE_X / (2 * tan(scene->camera.fov * 0.5));
	direction = normalize(direction);
	return (direction);
}

void	draw_circle(t_scene *scene)
{
	size_t		pixel_y;
	size_t		pixel_x;
	size_t		k;
	t_3d		p;
	t_3d		n;

	pixel_y = 0;
	while (pixel_y < SIZE_Y - 1)
	{
		pixel_x = 0;
		while (pixel_x < SIZE_X - 1)
		{
			scene->camera.ray_direction = get_camera_ray(pixel_y, pixel_x, scene);
			k = 0;
			while (k < scene->elements.nb_sphere)
			{
				if (intersection(scene, scene->sphere[k], &p, &n) == true)
					mlx_pixel_put(scene->mlx.mlx_ptr, scene->mlx.win_ptr,
						pixel_x, pixel_y, trgb_color(0, scene->sphere[k].color.x, scene->sphere[k].color.y,
							scene->sphere[k].color.z));
				k++;
			}
			pixel_x++;
		}
		pixel_y++;
	}
}
