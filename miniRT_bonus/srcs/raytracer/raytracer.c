/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 19:15:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
