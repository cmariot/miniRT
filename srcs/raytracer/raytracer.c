/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/16 11:20:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Générer un rayon partant de la camera en direction de chaque pixel de l'écran,
 * regarder si ce rayon percute un objet, si oui calculer la couleur de ce pixel
 */

void	raytracer(t_obj_list *obj_list, t_cam *camera, t_mlx *mlx)
{
	int		color;
	double	x;
	double	y;

	//matrice rotation
	y = 0;
	while (y < (double)camera->screen_height)
	{
		x = 0;
		while (x < (double)camera->screen_width)
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
