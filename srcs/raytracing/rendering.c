/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:27:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/20 23:48:50 by cmariot          ###   ########.fr       */
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
	return (normalize(direction));
}

/* Pour chaque pixel de coordonnees (x, y),
 * Obtenir la direction du rayon partant du pixel
 * et se dirigeant vers les objets de la scene (Backward Tracking) */
void	rendering(t_scene *scene)
{
	size_t		pixel_y;
	size_t		pixel_x;
	size_t		index_sphere;
	t_3d		p;
	t_3d		n;
	double		object_distance;
	bool		has_intersection = false;

	pixel_y = 0;
	while (pixel_y < SIZE_Y)
	{
		pixel_x = 0;
		while (pixel_x < SIZE_X)
		{
			scene->camera.ray_direction
				= get_camera_ray(pixel_y, pixel_x, scene);
			index_sphere = 0;
			object_distance = 100000000000000000;
			bool print_background = true;
			while (index_sphere < scene->elements.nb_sphere)
			{
				has_intersection = intersection(scene, scene->sphere[index_sphere], &p, &n);
				if (has_intersection)
				{
					print_background = false;
					double distance_cam = distance(scene->camera.point, p);
					if (distance_cam > object_distance)
					{
						index_sphere++;
						continue ;
					}
					object_distance = distance_cam;
					mlx_pixel_put(scene->mlx.mlx_ptr, scene->mlx.win_ptr,
						pixel_x, pixel_y, scene->sphere[index_sphere].trgb_color);
				}
				index_sphere++;
			}
			if (print_background == true)
				mlx_pixel_put(scene->mlx.mlx_ptr, scene->mlx.win_ptr,
					pixel_x, pixel_y, scene->ambient_light.trgb_color);
			pixel_x++;
		}
		pixel_y++;
	}
}
