/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/12 16:32:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	check_light(t_ray *ray, t_obj_list *obj_list, int trgb)
{
	size_t	i;

	i = 0;
	while (i < obj_list->nb_obj)
	{
		if (obj_list->obj[i].intersection(obj_list->obj[i], ray))
			return (0);
		i++;
	}
	return (trgb);
}

static t_ray	ray_generator_from_inter(t_ray *primary, t_light light)
{
	t_ray	ray;

	ray.position = primary->intersection;
	ray.direction = sub_vector(light.position, primary->intersection);
	ray.direction = normalize(ray.direction);
	//printf("2nd RAY : origine (%f, %f, %f) / direction (%f, %f, %f)\n", ray.position.x, ray.position.y, ray.position.z, ray.direction.x, ray.direction.y, ray.direction.z);
	return (ray);
}

int	check_intersection(t_ray *ray, t_obj_list *obj_list)
{
	int		color;
	size_t	i;
	double	distance;
	t_ray	dir_light;

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
				dir_light = ray_generator_from_inter(ray, obj_list->light);
				color = check_light(&dir_light, obj_list, color);
			}
		}
		i++;
	}
	return (color);
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
