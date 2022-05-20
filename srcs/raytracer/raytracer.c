/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 18:57:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	lookat(t_v3 cam_dir, double *m)
{
	t_v3	placeholder;
	t_v3	right;
	t_v3	up;

	placeholder.x = 0;
	placeholder.y = 1;
	placeholder.z = 0;
	if (cam_dir.x == 0 && cam_dir.z == 0)
		placeholder.z = 0.000001;
	right = normalize(cross_product(placeholder, cam_dir));
	up = normalize(cross_product(cam_dir, right));
	*(t_v3 *)(&m[0]) = right;
	*(t_v3 *)(&m[3]) = up;
	*(t_v3 *)(&m[6]) = cam_dir;
}

/*
 * Générer un rayon partant de la camera en direction de chaque pixel de l'écran,
 * regarder si ce rayon percute un objet, si oui calculer la couleur de ce pixel
 *
 * move scene (all objs) so the camera is on origin,
 * rotate each determining vectors of each object along all axis of
 * camera direction
 * ex: sphere needs only its center rotated
 */

void	raytracer(t_obj_list *obj_list, t_cam *camera, t_mlx *mlx)
{
	int		color;
	double	x;
	double	y;

	lookat(obj_list->camera.direction, obj_list->camera.matrix);
	translate_all(obj_list, camera);
	y = 0;
	while (y < camera->screen_height)
	{
		x = 0;
		while (x < camera->screen_width)
		{
			camera->ray = ray_generator(camera, &x, &y);
			compute_color(&color, &camera->ray, obj_list);
			mlx_putpixel(&mlx->image, &x, &y, &color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image.img, 0, 0);
}
