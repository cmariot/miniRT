/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_putpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:42:49 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 18:18:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	mlx_putpixel(t_img *data, float *x, float *y, int *color)
{
	char	*dst;

	dst = data->addr
		+ ((int)*y * data->line_length + (int)*x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = *color;
}
