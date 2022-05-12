/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 22:11:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//pour chaque pixel de l'image 
//generer un rayon
//voir si le rayon percute un objet si oui le pixel prend la couleur de l'objet
void	raytracer(t_obj_list *obj_list, t_cam *camera, t_mlx *mlx)
{
	size_t	x;
	size_t	y;
	int		color;

	(void)obj_list;
	y = 0;
	while (y < camera->screen_height)
	{
		x = 0;
		while (x < camera->screen_width)
		{
			color = 0;
			mlx_putpixel(&mlx->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image.img, 0, 0);
}
