/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/31 20:54:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	print_percentage(t_cam *camera, double y)
{
	write(1, "\t", 1);
	ft_putnbr((int)(y / camera->screen_height * 100));
	write(1, "%\r", 2);
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
	double	start;

	start = (double)clock();
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
		print_percentage(camera, y);
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image.img, 0, 0);
	printf("Done in %.3f seconds\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}
