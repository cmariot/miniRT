/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_putpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:42:49 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/04 14:44:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	mlx_putpixel(t_img *data, size_t *pixel, int color)
{
	char	*dst;

	dst = data->addr + (pixel[Y] * data->line_length
			+ pixel[X] * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
