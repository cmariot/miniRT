/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/12 14:48:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_intersection(t_ray *ray, t_obj_list *obj_list)
{
	int		color;
	size_t	i;
	double	distance;

	i = 0;
	color = 0;
	distance = INFINITY;
	while (i < obj_list->nb_obj)
	{
		if (obj_list->obj[i].intersection(obj_list->obj[i], ray))
		{
			if (ray->t < distance)
			{
				color = obj_list->obj[i].color.trgb;
				distance = ray->t;
			}
		}
		i++;
	}
	return (color);
}

t_ray	ray_generator(t_cam	*camera, double x, double y)
{
	t_ray	ray;

	ray.position = camera->position;
	ray.direction.x = x - camera->screen_width * 0.5;
	ray.direction.y = y - camera->screen_height * 0.5;
	ray.direction.z = -1 * ((camera->screen_width) / (2 * tan(camera->fov_horizontal * 0.0174533 * 0.5)));
	return (ray);
}

//pour chaque pixel de l'image 
//generer un rayon
//voir si le rayon percute un objet si oui le pixel prend la couleur de l'objet
void	raytracer(t_obj_list *obj_list, t_cam *camera, t_mlx *mlx)
{
	double	x;
	double	y;
	int		color;

	y = 0;
	while ((size_t)y < camera->screen_height)
	{
		x = 0;
		while ((size_t)x < camera->screen_width)
		{
			camera->ray = ray_generator(camera, x, y);
			color = check_intersection(&camera->ray, obj_list);
			mlx_putpixel(&mlx->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image.img, 0, 0);
}
